#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addTask(char task, char *array) {
    char *allocate = (char *)malloc(10 * sizeof(char));
    if (allocate == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    char *result = strcpy(allocate, &task);
    if (result != NULL) {
        printf("Task added successfully\n");
    } else {
        printf("Failed to add task\n");
    }
    free(allocate);
}

int main() {
    int choice;
    char taskArray[10], task;

    while (1) {
        printf("Enter your choice: \n");
        printf("1. Add a task\n");
        printf("2. Show the tasks\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add a task
                printf("Add your task here: ");
                scanf(" %c", &task);
                addTask(task, taskArray);
                break;

            case 2:
                printf("Tasks:\n");
                for (int i = 0; i < 10; i++) {
                    if (taskArray[i] != '\0') {
                        printf("%c\n", taskArray[i]);
                    } else {
                        break;
                    }
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
