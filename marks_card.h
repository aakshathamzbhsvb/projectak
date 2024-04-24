#ifndef MARKS_CARD_H
#define MARKS_CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marks.h"
#include "grades.h"
void printStudentInfo(const struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Rollno: %d\n", student->rollno);
    printf("Sem: %d\n", student->sem);
    printf("Class: %s\n", student->class);
}
void printMarksCard(const struct Student* students, int numStudents) {
    struct SubjectMarks *marksArray = (struct SubjectMarks *)malloc(MAX_SUBJECTS * sizeof(struct SubjectMarks));
    if (marksArray == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

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

    int total_ISA1 = 0;
    int total_ISA2 = 0;
    int total_ESA = 0;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollno == roll) {
            printf("\nEnter the exam marks for Roll Number %d:\n", roll);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("Enter ISA1 for %s: ", sub[j]);
                scanf("%d", &marksArray[j].ISA1);
                printf("Enter ISA2 for %s: ", sub[j]);
                scanf("%d", &marksArray[j].ISA2);
                printf("Enter ESA for %s: ", sub[j]);
                scanf("%d", &marksArray[j].ESA);
                strcpy(marksArray[j].subject, sub[j]);

                total_ISA1 += marksArray[j].ISA1;
                total_ISA2 += marksArray[j].ISA2;
                total_ESA += marksArray[j].ESA;
            }

            float weight_total = (total_ISA1 * 0.25) + (total_ISA2 * 0.25) + (total_ESA * 0.50);
            float CGPA = weight_total / (MAX_SUBJECTS * 10);

            
            for (int i = 0; i < NUM_STUDENTS; i++) {
                if (students[i].rollno == roll) {
                    printStudentInfo(&students[i]);
                    break;
                }
            }

            printf("--------------------------------------------------\n");
            printf("\nMarks card for Roll Number %d:\n", roll);
            printf("--------------------------------------------------\n");
            printf("--------------------------------------------------\n");
            for (int i = 0; i < NUM_STUDENTS; i++) {
                if (students[i].rollno == roll) {
                    printStudentInfo(&students[i]);
                    break;
                }
            }
            printf("Subject  \t\tISA1\tISA2\tESA\n");
            printf("--------------------------------------------------\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%s\t\t%d\t%d\t%d\n", marksArray[j].subject, marksArray[j].ISA1, marksArray[j].ISA2, marksArray[j].ESA);
            }
            printf("--------------------------------------------------\n");
            printf("--------------------------------------------------\n");
            printf("Total:\t\t\t%d\t%d\t%d\nCGPA:\t\t\t%.2f\n", total_ISA1, total_ISA2, total_ESA, CGPA);
            printf("--------------------------------------------------\n");

            break;
        }
    }

    free(marksArray);
}

#endif
