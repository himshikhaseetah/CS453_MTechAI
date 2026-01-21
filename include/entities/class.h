#ifndef CLASS_H
#define CLASS_H
#include "entities/student.h"
#define MAX_STUDENTS 100
#define GRADE_COUNT 8

typedef struct {
    int student_count;
    float avg_percentage;
    float max_percentage;
    float min_percentage;
    int grade_distribution[GRADE_COUNT];
} Class;

Class InitClass(int count);

void ComputeClassStatistics(Class *c, Student students[], int n);

#endif
