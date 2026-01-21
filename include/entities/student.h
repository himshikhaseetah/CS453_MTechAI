#ifndef STUDENT_H
#define STUDENT_H
#include "entities/subject.h"
#define MAX_NAME 50
#define MAX_ID 9

typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];

    Subject subjects[MAX_SUBJECTS];
    int subject_count;

    int total_marks;
    float percentage;
    int total_credits;
    int total_credit_points;
    float cgpa;
    char grade[3];
} Student;

Student InitStudent(char *id, char *name);

#endif
