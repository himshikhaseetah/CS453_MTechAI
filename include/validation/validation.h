#ifndef VALIDATION_H
#define VALIDATION_H
#include "entities/entities.h"

int ValidateId(char *id) ;
int ValidateName(char *name);
int ValidateSubject(char *name, int credits, int minor, int major);
int ValidateFile(char *filename);
int CheckDuplicateId(Student students[], int n, char *id);

#endif