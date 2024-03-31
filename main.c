#include<stdio.h>
#include<stdlib.h>
#include"marks.h"
#include"grades.h"
#include"marks_card.h"
int main(){
    char names[10][50];//enter 10 names with atleat each name having 50 characters in it !!
    int rollno[10];
    int sem[10];
    char class[10][10];
    printf("Enter the names, rollnumbers, semesters and class of 10 studentslie this pattern(Akshatha 1110 2 B): \n");
    
    for(int i=0;i<10;i++){
        printf("%d. ",i+1);
        scanf("%s %d %d %s", names[i], &rollno[i], &sem[i], class[i]); 
    }
    printf("\nThe information of 10 students: \n");
    for(int i=0;i<10;i++){
        printf("%d. %s \t\t%d\t\t%d\t\t%s\n", i+1, names[i], rollno[i], sem[i], class[i]);
    }
    int choice;
    printf("\nRead the options below and make a choice: \n");
    printf("1.Enter '1' to obtain the student's information entered: \n");
    printf("2.Enter '2' to obtain the student's exam marks entered: \n");
    printf("3.Enter '3' to obtain the student's grade calculation: \n");
    printf("4.Enter '4' to obtain the student's marks card: \n");
    printf("Please Enter your choice (1,2,3 or 4): \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter the rollno to get the information of the student: \n");
            int roll;
            scanf("%d",&roll);
            for(int i=0;i<10;i++){
                if(rollno[i]==roll){
                    printf("Name: %s\n", names[i]);
                    printf("Rollno: %d\n", rollno[i]);
                    printf("Sem: %d\n", sem[i]);                
                    printf("Class: %s\n", class[i]);
            
                }
            }
            break;
        case 2:
            marks(rollno);
            break;
        case 3:
            grades(rollno);
            break;
        case 4:
            printMarksCard(names, rollno, sem, class);
            break;   
        default:
            printf("Invalid choice.");
            break;
    }
    return 0;
}