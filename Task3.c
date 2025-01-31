#include <stdio.h>
#include <string.h>

#define NAME_COUNT 20
#define MAX_NAME_LENGTH 50

void bubbleSort(char names[][MAX_NAME_LENGTH], int count, int ascending) {
    char temp[MAX_NAME_LENGTH];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascending && strcmp(names[j], names[j + 1]) > 0) || 
                (!ascending && strcmp(names[j], names[j + 1]) < 0)) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    char names[NAME_COUNT][MAX_NAME_LENGTH] = {
        "Kwizera", "Alice", "Smith", "Johnson", "David ",
        "Sandra", "James Anderson", "Thomas", "Robert", "Olivia",
        "William", "Martin", "Joseph", "Isaac", "Charles",
        "Max", "Daniel", "Michael", "Henry", "Alain"
    };

    char order[10];
    printf("Enter 'asc' for ascending order or 'desc' for descending order: ");
    scanf("%s", order);

    int ascending = (strcmp(order, "asc") == 0) ? 1 : (strcmp(order, "desc") == 0) ? 0 : -1;

    if (ascending == -1) {
        printf("Invalid input! Please enter 'asc' or 'desc'.\n");
        return 1;
    }

    bubbleSort(names, NAME_COUNT, ascending);

    printf("\nSorted Names:\n");
    for (int i = 0; i < NAME_COUNT; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
