#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    printf("Select an option:\n");
    printf("1. Details\n");
    printf("2. Marks\n");
    printf("3. Markscard\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("details.exe");
                break;
            case 2:
                system("marks.exe");
                break;
            case 3:
                system("markscard.exe");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
