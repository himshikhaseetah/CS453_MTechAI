#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "validation/validation.h"
#define MAX_ID 9

// ID should not be null, not exceed valid length & have only alphanumeric characters
int ValidateId(char *id)
{
    if (!id || strlen(id) == 0)
        return 0;
    if (strlen(id) > MAX_ID || strlen(id) < MAX_ID - 1)
        return 0;
    for (int i = 0; id[i]; i++)
    {
        if (!isalnum(id[i]))
            return 0;
    }
    return 1;
}

// name should not be null & contain alphabets only
int ValidateName(char *name)
{
    if (!name || strlen(name) == 0)
        return 0;
    if (strlen(name) > MAX_NAME)
        return 0;
    for (int i = 0; name[i]; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

// subject should have non-null name, #credits, minor marks in range 0-40, major marks in range 0-60
int ValidateSubject(char *name, int credits, int minor, int major)
{
    if (!name || strlen(name) == 0)
        return 0;
    if (credits <= 0)
        return 0;
    if (minor < 0 || minor > 40)
        return 0;
    if (major < 0 || major > 60)
        return 0;
    return 1;
}

// filename should not be null & have no special characters, have atleast 1 char before file extension, valid filetype is .txt only
int ValidateFile(char *filename)
{
    int len = strlen(filename);
    if (len < 5)
        return 0;
    if (!filename || len < 5)
        return 0;
    if (strcmp(filename + len - 4, ".txt") != 0)
        return 0;
    for (int i = 0; i < len - 4; i++)
    {
        if (!isalnum((unsigned char)filename[i]))
        {
            return 0;
        }
    }
    return 1;
}

// check for duplicates in student ID
int CheckDuplicateId(Student students[], int n, char *id)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(students[i].id, id))
            return 0;
    }
    return 1;
}