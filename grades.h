#include<stdio.h>

#ifndef GRADES_H
#define GRADES_H
void grades(int rollno[]){
    int ISA1[6];
    int ISA2[6];
    int ESA[6];
    int total_ISA1=0;
    int total_ISA2=0;
    int total_ESA=0;
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
            int total_sub=6;
            for(int i=0;i< total_sub;i++){
                total_ISA1 += ISA1[i];
                total_ISA2 += ISA2[i];
                total_ESA += ESA[i];
            }
            float weight_total = (total_ISA1 * 0.25) + (total_ISA2 * 0.25) + (total_ESA * 0.50);
            float total=weight_total/total_sub;
            float CGPA=total/10;
        
            
            printf("\nMarks for Roll Number %d:\n", roll);
            printf("Subject  \t\tISA1\tISA2\tESA\n");
            for (int j = 0; j < 6; j++) {
                printf("%s\t\t%d\t%d\t%d\n", sub[j], ISA1[j], ISA2[j], ESA[j]);
            }
            printf("Total:\t\t\t%d\t%d\t%d\nCGPA:\t\t\t%f",total_ISA1,total_ISA2,total_ESA,CGPA);

            break; 
        }
    }
}
#endif