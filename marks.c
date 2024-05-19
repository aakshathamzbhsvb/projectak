#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_ISA 3

typedef struct {
    char srn[10];
    char name[50];
    char class[5];
    int semester;
    int marks[MAX_ISA][MAX_SUBJECTS];
} Student;

void readCSV(const char *filename, Student students[], int *studentCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(1);
    }

    char line[MAX_LINE];
    *studentCount = 0;
    while (fgets(line, MAX_LINE, file) && *studentCount < MAX_STUDENTS) {
        if (*studentCount == 0) {
            // Skip the header line
            (*studentCount)++;
            continue;
        }

        // Parse the line
        char *token = strtok(line, ",");
        strcpy(students[*studentCount - 1].srn, token);

        token = strtok(NULL, ",");
        strcpy(students[*studentCount - 1].name, token);

        token = strtok(NULL, ",");
        strcpy(students[*studentCount - 1].class, token);

        token = strtok(NULL, ",");
        students[*studentCount - 1].semester = atoi(token);

        for (int i = 0; i < MAX_ISA; i++) {
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                token = strtok(NULL, ",");
                if (token != NULL) {
                    students[*studentCount - 1].marks[i][j] = atoi(token);
                }
            }
        }

        (*studentCount)++;
    }
    fclose(file);
}

void findStudentBySRN(Student students[], int studentCount, const char *srn) {
    for (int i = 0; i < studentCount - 1; i++) {
        if (strcmp(students[i].srn, srn) == 0) {
            printf("SRN: %s\nName: %s\nClass: %s\nSemester: %d\n",
                   students[i].srn, students[i].name, students[i].class, students[i].semester);

            // Print marks in the specified format
            printf("\tISA1\tISA2\tISA3\n");
            const char* subjects[] = {"MATH", "ENGLISH", "HINDI", "BIOLOGY", "HISTORY"};
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%s\t", subjects[j]);
                for (int k = 0; k < MAX_ISA; k++) {
                    printf("%d\t", students[i].marks[k][j]);
                }
                printf("\n");
            }
            return;
        }
    }
    printf("Student with SRN %s not found.\n", srn);
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount;

    readCSV("markscard.csv", students, &studentCount);

    char srn[10];
    printf("Enter SRN: ");
    scanf("%s", srn);

    findStudentBySRN(students, studentCount, srn);

    return 0;
}
