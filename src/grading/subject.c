#include "grading/grading.h"
#include <string.h>

void ComputeSubjectResult(Subject *s)
{
    s->total = s->minor + s->major;
    ComputeSubGrade(s);
    s->pass = (s->total >= 50);
    s->credit_points = s->credits * s->grade_point;
}

void ComputeSubGrade(Subject *s)
{
    if (s->total >= 90)
    {
        strcpy(s->grade, "O");
        s->grade_point = 10;
    }
    else if (s->total >= 85)
    {
        strcpy(s->grade, "A+");
        s->grade_point = 9;
    }
    else if (s->total >= 75)
    {
        strcpy(s->grade, "A");
        s->grade_point = 8;
    }
    else if (s->total >= 65)
    {
        strcpy(s->grade, "B+");
        s->grade_point = 7;
    }
    else if (s->total >= 60)
    {
        strcpy(s->grade, "B");
        s->grade_point = 6;
    }
    else if (s->total >= 55)
    {
        strcpy(s->grade, "C");
        s->grade_point = 5;
    }
    else if (s->total >= 50)
    {
        strcpy(s->grade, "D");
        s->grade_point = 4;
    }
    else
    {
        strcpy(s->grade, "F");
        s->grade_point = 0;
    }
}