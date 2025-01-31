#include <stdio.h>

int main() {
    int num, count = 0;
    
    printf("Enter a number (between 2 and 7 digits): ");
    scanf("%d", &num);

    
    if (num < 10 || num > 9999999) {
        printf("Invalid input! Please enter a number with 2 to 7 digits.\n");
        return 1;
    }

    int temp = num;
    while (temp > 0) {
        temp /= 10;
        count++;
    }

    printf("The number %d has %d digits.\n", num, count);
    printf("The number of digits is %s.\n", (count % 2 == 0) ? "even" : "odd");

    return 0;
}
