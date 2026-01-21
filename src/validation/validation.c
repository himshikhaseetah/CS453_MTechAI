#include <ctype.h>
#include <string.h>
#include "validation/validation.h"

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

int is_valid_subject(char *name, int credits, int minor, int major) {
    if (!name || strlen(name) == 0) return 0;
    if (credits <= 0) return 0;
    if (minor < 0 || minor > 40) return 0;
    if (major < 0 || major > 60) return 0;
    return 1;
}
