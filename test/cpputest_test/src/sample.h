/* file: sample.h */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char* name;
    int score;
};

void ret_void(void);
int ret_int(int, int);
double ret_double(double, double);
char* ret_pchar(char*, char*);

void init_student(struct Student* s, char* name, int score);

