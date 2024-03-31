#include<stdio.h>

#ifndef MARKS_H
#define MARKS_H

void marks(int rollno[]) {
    int ISA1[6];
    int ISA2[6];
    int ESA[6];
    char sub[6][20] = {"Physics  ", "Maths    ", "Chemistry", "English  ", "Hindi    ", "Computer "};
    
    printf("\nEnter the rollno to get the information of the student: ");
    int roll;
    scanf("%d", &roll);
    
    for (int i = 0; i < 10; i++) {
        if (rollno[i] == roll) {
            printf("\nEnter the marks for the subjects:\n");
            for (int j = 0; j < 6; j++) {
                printf("%d. %s: ", j + 1, sub[j]);
                scanf("%d %d %d", &ISA1[j], &ISA2[j], &ESA[j]);
            }
            
            printf("\nMarks for Roll Number %d:\n", roll);
            printf("Subject  \t\tISA1\tISA2\tESA\n");
            for (int j = 0; j < 6; j++) {
                printf("%s\t\t%d\t%d\t%d\n", sub[j], ISA1[j], ISA2[j], ESA[j]);
            }
            break; 
        }
    }
}

#endif
