#include <string.h>
#include "grading.h"

void ComputeSubjectResult(Subject *s)
{
    s->total = s->minor + s->major;
    ComputeSubGrade(s);
    s->pass = (s->total >= 50);
    s->credit_points = s->credits * s->grade_point;
}

void ComputeStudentResult(Student *st)
{
    st->total_marks = 0;
    st->total_credits = 0;
    st->total_credit_points = 0;

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
    else
    {
        st->cgpa = 0.0f;
    }    
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

void ComputeClassStatistics(Student students[], int n, FILE *fp) {
    float sum = 0, max = students[0].percentage, min = students[0].percentage;
    int grade_count[8] = {0}; 

    for (int i = 0; i < n; i++) {
        sum += students[i].percentage;
        if (students[i].percentage > max) max = students[i].percentage;
        if (students[i].percentage < min) min = students[i].percentage;

        if (!strcmp(students[i].grade, "O")) grade_count[0]++;
        else if (!strcmp(students[i].grade, "A+")) grade_count[1]++;
        else if (!strcmp(students[i].grade, "A")) grade_count[2]++;
        else if (!strcmp(students[i].grade, "B+")) grade_count[3]++;
        else if (!strcmp(students[i].grade, "B")) grade_count[4]++;
        else if (!strcmp(students[i].grade, "C")) grade_count[5]++;
        else if (!strcmp(students[i].grade, "D")) grade_count[6]++;
        else grade_count[7]++;
    }

    fprintf(fp, "\n===================================== CLASS STATISTICS =====================================\n");
    fprintf(fp, "Class Average Percentage: %.2f\n", sum / n);
    fprintf(fp, "Highest Percentage: %.2f\n", max);
    fprintf(fp, "Lowest Percentage : %.2f\n", min);

    fprintf(fp, "\nGrade Distribution:\n");
    fprintf(fp, "O : %d\nA+: %d\nA : %d\nB+: %d\nB : %d\nC : %d\nD : %d\nF : %d\n",
            grade_count[0], grade_count[1], grade_count[2], grade_count[3], 
            grade_count[4], grade_count[5], grade_count[6], grade_count[7]);
}

