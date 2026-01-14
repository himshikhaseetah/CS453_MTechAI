#ifndef GRADING_H
#define GRADING_H
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

void ComputeSubjectResult(Subject *s);
void ComputeStudentResult(Student *st);
void ComputeSubGrade(Subject *s);
void ComputeStudentGrade(Student *st);
void ComputeClassStatistics(Student students[], int n, FILE *fp);

#endif
