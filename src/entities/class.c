#include "entities/entities.h"
#include <stdio.h>
#include <string.h>

Class InitClass(int count)
{
    Class c;
    c.student_count = count;
    c.avg_percentage = 0.0f;
    c.max_percentage = 0.0f;
    c.min_percentage = 0.0f;
    for (int i = 0; i<GRADE_COUNT; i++)
    {
        c.grade_distribution[i] = 0;
    }
    return c;
}

void ComputeClassStatistics(Class *c, Student students[], int n)
{
    float sum = 0;
    c->max_percentage = students[0].percentage;
    c->min_percentage = students[0].percentage;

    for (int i = 0; i < n; i++)
    {
        sum += students[i].percentage;
        if (students[i].percentage > c->max_percentage)
            c->max_percentage = students[i].percentage;
        if (students[i].percentage < c->min_percentage)
            c->min_percentage = students[i].percentage;

        if (!strcmp(students[i].grade, "O"))
            c->grade_distribution[0]++;
        else if (!strcmp(students[i].grade, "A+"))
            c->grade_distribution[1]++;
        else if (!strcmp(students[i].grade, "A"))
            c->grade_distribution[2]++;
        else if (!strcmp(students[i].grade, "B+"))
            c->grade_distribution[3]++;
        else if (!strcmp(students[i].grade, "B"))
            c->grade_distribution[4]++;
        else if (!strcmp(students[i].grade, "C"))
            c->grade_distribution[5]++;
        else if (!strcmp(students[i].grade, "D"))
            c->grade_distribution[6]++;
        else
            c->grade_distribution[7]++;
    }

    c->avg_percentage = sum/n;
}