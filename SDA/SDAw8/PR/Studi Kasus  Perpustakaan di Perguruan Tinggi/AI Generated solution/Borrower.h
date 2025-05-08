#ifndef BORROWER_H
#define BORROWER_H

typedef enum { STUDENT, TEACHER, PUBLIC } Priority;

typedef struct {
    char* name;
    Priority priority;
} Borrower;

#endif