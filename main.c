#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marks.h"
#include "grades.h"
#include "marks_card.h"


void getStudentInfo(struct Student* student) {
    printf("Enter name, roll number, semester, and class (e.g., Akshatha 1110 2 B): ");
    scanf("%s %d %d %s", student->name, &student->rollno, &student->sem, student->class);
}

int main() {
    /*const char names[MAX_SUBJECTS][MAX_NAME_LENGTH];
    const int rollno[10]; 
    const int sem[2];
    const char class[MAX_SUBJECTS][MAX_CLASS_LENGTH];*/

    struct Student* students = malloc(NUM_STUDENTS * sizeof(struct Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter details for student %d:\n", i + 1);
        getStudentInfo(&students[i]);
    }

    printf("\nThe information of 10 students:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%d. ", i + 1);
        printStudentInfo(&students[i]);
    }

    int choice;
    printf("\nRead the options below and make a choice:\n");
    printf("1. Enter '1' to obtain a student's information.\n");
    printf("2. Enter '2' to obtain a student's exam marks.\n");
    printf("3. Enter '3' to obtain a student's grade calculation.\n");
    printf("4. Enter '4' to obtain a student's marks card.\n");
    printf("Please Enter your choice (1, 2, 3, or 4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int roll;
            printf("\nEnter the roll number to get the information of the student: ");
            scanf("%d", &roll);
            for (int i = 0; i < NUM_STUDENTS; i++) {
                if (students[i].rollno == roll) {
                    printStudentInfo(&students[i]);
                    break;
                }
            }
            break;
        }
        case 2:
            marks(students, NUM_STUDENTS);
            break;
        case 3:
            grades(students,NUM_STUDENTS);
            break;
        case 4:
             printMarksCard(students, NUM_STUDENTS);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    free(students); 
    return 0;
}
