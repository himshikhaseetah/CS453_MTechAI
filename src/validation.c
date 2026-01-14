#include <ctype.h>
#include <string.h>
#include "validation.h"

int is_valid_id(char *id) {
    if (!id || strlen(id) == 0) return 0;
    for (int i = 0; id[i]; i++) {
        if (!isalnum(id[i])) return 0;
    }
    return 1;
}

int is_valid_name(char *name) {
    if (!name || strlen(name) == 0) return 0;
    for (int i = 0; name[i]; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') return 0;
    }
    return 1;
}

int is_valid_subject(Subject *s) {
    if (!s || strlen(s->name) == 0) return 0;
    if (s->credits <= 0) return 0;
    if (s->minor < 0 || s->minor > 40) return 0;
    if (s->major < 0 || s->major > 60) return 0;
    return 1;
}
