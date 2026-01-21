#include "entities/entities.h"
#include <string.h>


Subject InitSubject(char *name, int credits, int minor, int major) {
    Subject s;
    strncpy(s.name, name, MAX_SUBJECT_NAME);
    s.credits = credits;
    s.minor = minor;
    s.major = major;
    s.total = 0;
    s.grade_point = 0;
    s.credit_points = 0;
    s.pass = 0;
    strcpy(s.grade, "");
    return s;
}
