#include "entities/entities.h"
#include "string.h"


Student InitStudent(char *id, char *name) {
    Student st;
    strncpy(st.id, id, MAX_ID);
    strncpy(st.name, name, MAX_NAME);
    st.subject_count = MAX_SUBJECTS;
    st.total_marks = 0;
    st.percentage = 0.0f;
    st.total_credits = 0;
    st.total_credit_points = 0;
    st.cgpa = 0.0f;
    strcpy(st.grade, "");
    return st;
}
