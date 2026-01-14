#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUBJECTS 5
#define MAX_NAME 50
#define MAX_ID 9
#define MAX_SUBJECT_NAME 30

typedef struct {
    char name[MAX_SUBJECT_NAME];
    int credits;
    int minor;
    int major;
    int total;    
    char grade[3];
    int grade_point;      
    int credit_points;
    int pass; 
} Subject;

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

#endif
