#ifndef GRADES_H
#define GRADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marks.h"

struct SubjectMarks {
    int ISA1;
    int ISA2;
    int ESA;
    char subject[MAX_NAME_LENGTH];
};

void grades(const struct Student* students, int numStudents) {
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

            
            int total_marks = total_ISA1 + total_ISA2 + total_ESA;
            float weight_total = (total_ISA1 * 0.25) + (total_ISA2 * 0.25) + (total_ESA * 0.50);
            float CGPA = weight_total / (MAX_SUBJECTS*10);

            printf("\nExam marks for Roll Number %d:\n", roll);
            printf("Subject  \t\tISA1\tISA2\tESA\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%s\t\t%d\t%d\t%d\n", marksArray[j].subject, marksArray[j].ISA1, marksArray[j].ISA2, marksArray[j].ESA);
            }
            printf("Total Marks:\t\t%d\n", total_marks);
            printf("CGPA:\t\t\t%.2f\n", CGPA);
            break;
        }
    }

    free(marksArray); 
}

#endif
