#ifndef VALIDATION_H
#define VALIDATION_H
#include "entities/entities.h"

int is_valid_id(char *id) ;
int is_valid_name(char *name);
int is_valid_subject(char *name, int credits, int minor, int major);

#endif