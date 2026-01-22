#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entities/entities.h"
#include "grading/grading.h"
#include "reporting/report.h"
#include "validation/validation.h"
#define MAX_FILENAME 15

// Usage Example: ./srps

int main()
{    
    char inFile[MAX_FILENAME], outFile[MAX_FILENAME];
    FILE *infp, *outfp;
    char buffer[256];

    // Program Description & I/O files validation & initialisations
    printf("===================================== STUDENT RESULTS PROCESSING SYSTEM =====================================\n");
    printf("\n This is a command-line program to calculate individual student results and class performance statistics.\n");
    printf(" List of students along with set of subjects, each having number of credits and the awarded minor and major marks is required as input file.\n");
    printf(" After processing input file, a consolidated results report will be printed to a text file\n");
    
    printf("\n Enter file name for students marks input file (Accepted File Format: .txt): \n");
    scanf("%s", inFile);
    if (!ValidateFile(inFile))
    {
        printf("Invalid input file given. Please ensure filename does not have any special characters and is a .txt file only.\n");
        return 1;
    }
    else
    {
        infp = fopen(inFile, "r");
        if (!infp)
        {
            perror("Error opening input file");
            return 1;
        }
    }

    printf("\n Enter file name for results report (Accepted File Format: .txt): \n");
    scanf("%s", outFile);
    if (!ValidateFile(outFile))
    {
        printf("Invalid output file given. Please ensure filename does not have any special characters and is a .txt file only.\n");
        return 1;
    }
    else
    {
        outfp = fopen(outFile, "w");
        if (!outfp)
        {
            perror("Error opening output file");
            fclose(infp);
            return 1;
        }
    }

    printf("\n");
    fprintf(outfp, "\n===================================== STUDENT RESULTS =====================================\n");

    // Reading input file, validation steps & object creation (Student, Subject, Class)
    Student students[MAX_STUDENTS];
    int student_count = 0;

    while (student_count < MAX_STUDENTS)
    {
        char id[MAX_ID], name[MAX_NAME];

        if (fscanf(infp, "%9s %[^\n]", id, name) != 2)
        {
            break;
        }

        if (!ValidateId(id) || !ValidateName(name))
        {
            fprintf(stderr, "Invalid or missing student ID or name. Skipping student (%s).\n", id);

            // Consume the newline left in buffer from fscanf
            fgetc(infp);
            
            // Skip the subject lines for this invalid student            
            for (int i = 0; i < MAX_SUBJECTS; i++)
            {
                if (fgets(buffer, sizeof(buffer), infp) == NULL)
                    break;
            }                

            continue;
        }

        if (!CheckDuplicateId(students, student_count, id))
        {
            fprintf(stderr, "Duplicate student ID. Skipping duplicate student (%s).\n", id);
            
            // Consume the newline left in buffer from fscanf
            fgetc(infp);

            // Skip the subject lines for this invalid student            
            for (int i = 0; i < MAX_SUBJECTS; i++)
            {
                if (fgets(buffer, sizeof(buffer), infp) == NULL)
                    break;
            }                

            continue;

        }

        Student st = InitStudent(id, name);

        int valid = 1;
        char buffer[256];
        
        for (int i = 0; i < MAX_SUBJECTS; i++)
        {
            char subName[MAX_SUBJECT_NAME];
            int cr, mn, mj;

            if (fscanf(infp, "%s %d %d %d", subName, &cr, &mn, &mj) != 4)
            {
                valid = 0;
                fprintf(stderr, "Expecting subject info as: [subjectName #credits minorMarks majorMarks] Skipping student (%s).\n", id);
                
                // Consume rest of current line
                fgets(buffer, sizeof(buffer), infp);
                
                // Skip remaining subject lines for this student                
                for (int j = i + 1; j < MAX_SUBJECTS; j++)
                {
                    if (fgets(buffer, sizeof(buffer), infp) == NULL)
                        break;
                }
                break;
            }

            if (!ValidateSubject(subName, cr, mn, mj))
            {
                fprintf(stderr, "Invalid or missing subject info for %s. Skipping student (%s).\n", subName, st.id);
                valid = 0;
                
                // Consume rest of current line
                fgets(buffer, sizeof(buffer), infp);
                
                // Skip remaining subject lines for this student
                for (int j = i + 1; j < MAX_SUBJECTS; j++)
                {
                    if (fgets(buffer, sizeof(buffer), infp) == NULL)
                        break;
                }
                break;
            }

            st.subjects[i] = InitSubject(subName, cr, mn, mj);
        }

        if (!valid)
            continue;

        // After reading 1 student and set of marks, results computation:
        ComputeStudentResult(&st);

        students[student_count++] = st;

        // Write to output file
        PrintResultList(outfp, &st);
    }

    // Given a list of students & corresponding results processed, class statistics derived & written to output file:
    if (student_count > 0)
    {
        Class c = InitClass(student_count);
        ComputeClassStatistics(&c, students, student_count);
        PrintClassStats(outfp, &c);
    }

    fclose(infp);
    fclose(outfp);

    printf("Results written successfully to file\n");
    return 0;
}
