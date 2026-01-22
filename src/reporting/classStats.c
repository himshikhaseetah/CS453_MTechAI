#include <stdio.h>
#include "reporting/report.h"
#include "entities/entities.h"

void PrintClassStats(FILE *fp, Class *c)
{
    fprintf(fp, "\n===================================== CLASS STATISTICS =====================================\n");
    fprintf(fp, "Class Average Percentage: %.2f\n", c->avg_percentage);
    fprintf(fp, "Highest Percentage: %.2f\n", c->max_percentage);
    fprintf(fp, "Lowest Percentage : %.2f\n", c->min_percentage);

    fprintf(fp, "\nGrade Distribution:\n");
    fprintf(fp, "O : %d\nA+: %d\nA : %d\nB+: %d\nB : %d\nC : %d\nD : %d\nF : %d\n",
            c->grade_distribution[0], c->grade_distribution[1], c->grade_distribution[2], c->grade_distribution[3], 
            c->grade_distribution[4], c->grade_distribution[5], c->grade_distribution[6], c->grade_distribution[7]);
}