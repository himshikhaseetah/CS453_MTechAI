#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entities/entities.h"
#include "grading/grading.h"
#include "reporting/report.h"
#include "validation/validation.h"

// Usage Example: ./srps input.txt output.txt

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        perror("Error opening input file");
        return 1;
    }

    FILE *outfp = fopen(argv[2], "w");
    if (!outfp)
    {
        perror("Error opening output file");
        fclose(fp);
        return 1;
    }
    fprintf(outfp, "\n===================================== STUDENT RESULTS =====================================\n");

    Student students[MAX_STUDENTS];
    int student_count = 0;

    while (student_count < MAX_STUDENTS)
    {
        char id[MAX_ID], name[MAX_NAME];

        if (fscanf(fp, "%s %[^\n]", id, name) != 2)
            break;

        if (!is_valid_id(id) || !is_valid_name(name))
        {
            fprintf(stderr, "Invalid student ID or name (%s). Skipping student.\n", id);

            for (int i = 0; i < MAX_SUBJECTS; i++)
                fscanf(fp, "%*[^\n]\n");

            continue;
        }

        Student st = InitStudent(id, name);

        int valid = 1;
        for (int i = 0; i < MAX_SUBJECTS; i++)
        {
            char subName[MAX_SUBJECT_NAME];
            int cr, mn, mj;

            if (fscanf(fp, "%s %d %d %d", subName, &cr, &mn, &mj) != 4)
            {
                valid = 0;
                break;
            }

            if (!is_valid_subject(subName, cr, mn, mj))
            {
                fprintf(stderr, "Invalid marks in subject %s for student %s\n", subName, st.id);
                valid = 0;
            }

            st.subjects[i] = InitSubject(subName, cr, mn, mj);
        }

        if (!valid)
            continue;

        ComputeStudentResult(&st);

        students[student_count++] = st;

        PrintResultList(outfp, &st);
    }

    if (student_count > 0) {
        Class c = InitClass(student_count);
        ComputeClassStatistics(&c, students, student_count);
        PrintClassStats(outfp, &c);
    }

    fclose(fp);
    fclose(outfp);

    printf("Results written successfully to %s\n", argv[2]);
    return 0;
}
