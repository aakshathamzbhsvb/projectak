#ifndef MARKS_H
#define MARKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 10
#define MAX_SUBJECTS 6
#define MAX_NAME_LENGTH 50
#define MAX_CLASS_LENGTH 20
struct Subject {
    char name[MAX_NAME_LENGTH];
    int ISA1;
    int ISA2;
    int ESA;
};

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollno;
    int sem;
    char class[MAX_CLASS_LENGTH];
    struct Subject subjects[MAX_SUBJECTS];
};

void marks(struct Student* students, int numStudents) {
    char sub[MAX_SUBJECTS][MAX_NAME_LENGTH];

    strcpy(sub[0], "PHYSICS        ");
    strcpy(sub[1], "MATHS          ");
    strcpy(sub[2], "COMPUTER");
    strcpy(sub[3], "BIOLOGY        ");
    strcpy(sub[4], "CHEMISTRY");
    strcpy(sub[5], "ENGLISH        ");
    int roll;
    printf("\nEnter the roll number to get the information of the student: ");
    scanf("%d", &roll);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollno == roll) {
            printf("\nEnter the exam marks for Roll Number %d:\n", roll);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("Enter ISA1 for %s: ", sub[j]);
                scanf("%d", &students[i].subjects[j].ISA1);
                printf("Enter ISA2 for %s: ", sub[j]);
                scanf("%d", &students[i].subjects[j].ISA2);
                printf("Enter ESA for %s: ", sub[j]);
                scanf("%d", &students[i].subjects[j].ESA);
            }

            printf("\nExam marks for Roll Number %d:\n", roll);
            printf("Subject  \t\tISA1\tISA2\tESA\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%s\t\t%d\t%d\t%d\n", sub[j], students[i].subjects[j].ISA1, students[i].subjects[j].ISA2, students[i].subjects[j].ESA);
            }
            break;
        }
    }
}


#endif
