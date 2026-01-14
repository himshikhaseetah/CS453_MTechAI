#include <stdio.h>
#include "report.h"

void PrintResultReport(FILE *fp, Student *st) {
    fprintf(fp, "\nStudent: %s (%s)\n", st->id, st->name);
    fprintf(fp, "--------------------------------------------------------------------------------------\n");
    // fprintf(fp, "Subject\t\t\t\t\t\tMinor\t\tMajor\t\tTotal\t\tCredits\t\tCP\t\tGrade\t\tGP\t\tResult\n");
    fprintf(fp,
            "%-20s %6s %6s %7s %8s %6s %-8s %5s %-8s\n",
            "Subject", "Minor", "Major", "Total",
            "Credits", "CPts", "Grade", "GPts", "Result");


    for (int i = 0; i < st->subject_count; i++) {
        Subject s = st->subjects[i];
        char * p = s.pass ? "PASS" : "FAIL";
        // fprintf(fp, "%s\t\t\t\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%s\t\t\t%d\t\t\t%s\n",
        //         s.name, s.minor, s.major, s.total,
        //         s.credits, s.credit_points, s.grade, s.grade_point, p);
        fprintf(fp,
                "%-20s %6d %6d %7d %8d %6d %-8s %5d %-8s\n",
                s.name, s.minor, s.major, s.total, s.credits, s.credit_points, s.grade, s.grade_point, p);

    }

    fprintf(fp, "--------------------------------------------------------------------------------------\n");
    fprintf(fp, "Total Marks: %d\n", st->total_marks);
    fprintf(fp, "Percentage : %.2f\n", st->percentage);
    fprintf(fp, "Total Credit Points: %d\n", st->total_credit_points);
    fprintf(fp, "CGPA: %.2f\n", st->cgpa);
    fprintf(fp, "-------------------------------------------------------------------------------------------\n");
    
}
