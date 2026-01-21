#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_SUBJECTS 5
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

Subject InitSubject(char *name, int credits, int minor, int major);

#endif
