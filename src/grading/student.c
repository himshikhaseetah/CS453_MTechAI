#include "grading/grading.h"
#include <string.h>

void ComputeStudentResult(Student *st)
{    
    for (int i = 0; i < st->subject_count; i++)
    {
        ComputeSubjectResult(&st->subjects[i]);
        st->total_marks += st->subjects[i].total;
        st->percentage = (float)st->total_marks / (st->subject_count * 100) * 100;
        st->total_credits += st->subjects[i].credits;
        st->total_credit_points += st->subjects[i].credit_points;
    }

    ComputeStudentGrade(st);

    if (st->total_credits > 0)
    {
        st->cgpa = (float)st->total_credit_points / st->total_credits;
    }
}

void ComputeStudentGrade(Student *st)
{
    if (st->percentage >= 90)
    {
        strcpy(st->grade, "O");        
    }
    else if (st->percentage >= 85)
    {
        strcpy(st->grade, "A+");
    }
    else if (st->percentage >= 75)
    {
        strcpy(st->grade, "A");
    }
    else if (st->percentage >= 65)
    {
        strcpy(st->grade, "B+");
    }
    else if (st->percentage >= 60)
    {
        strcpy(st->grade, "B");
    }
    else if (st->percentage >= 55)
    {
        strcpy(st->grade, "C");
    }
    else if (st->percentage >= 50)
    {
        strcpy(st->grade, "D");
    }
    else
    {
        strcpy(st->grade, "F");
    }
}