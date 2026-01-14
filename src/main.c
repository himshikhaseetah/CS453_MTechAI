#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "validation.h"
#include "grading.h"
#include "report.h"
#define MAX_STUDENTS 100

//Usage Example: ./srps input.txt output.txt

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outfp = fopen(argv[2], "w");
    if (!outfp) {
        perror("Error opening output file");
        fclose(fp);
        return 1;
    }
    fprintf(outfp, "\n===================================== STUDENT RESULTS =====================================\n");    

    Student students[MAX_STUDENTS];
    int student_count = 0;

    while (student_count < MAX_STUDENTS) {
        Student st;
        st.subject_count = MAX_SUBJECTS;

        if (fscanf(fp, "%s %[^\n]", st.id, st.name) != 2)
            break;

        if (!is_valid_id(st.id) || !is_valid_name(st.name)) {
            fprintf(stderr, "Invalid student ID or name (%s). Skipping student.\n", st.id);

            for (int i = 0; i < MAX_SUBJECTS; i++)
                fscanf(fp, "%*[^\n]\n");

            continue;
        }

        int valid = 1;
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            Subject *s = &st.subjects[i];

            if (fscanf(fp, "%s %d %d %d",
                       s->name, &s->credits, &s->minor, &s->major) != 4) {
                valid = 0;
                break;
            }

            if (!is_valid_subject(s)) {
                fprintf(stderr, "Invalid marks in subject %s for student %s\n", s->name, st.id);
                valid = 0;
            }
        }

        if (!valid)
            continue;
            
        ComputeStudentResult(&st);
        
        students[student_count++] = st;
        
        PrintResultReport(outfp, &st);
    }

    if (student_count > 0) {
        ComputeClassStatistics(students, student_count, outfp);
    }

    fclose(fp);
    fclose(outfp);

    printf("Results written successfully to %s\n", argv[2]);
    return 0;
}


