#include <stdio.h>
#include <string.h>

void characterCount(char data[]) {
    printf("Character Count: %lu%s\n",
           (unsigned long)strlen(data) + 1, data);
}

void characterStuffing(char data[]) {
    int i;

    printf("Character Stuffing: F");

    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == 'F' || data[i] == 'E')
            printf("E");

        printf("%c", data[i]);
    }

    printf("F\n");
}

void bitStuffing(char data[]) {
    int i, count = 0;

    printf("Bit Stuffing: ");

    for (i = 0; data[i] != '\0'; i++) {
        printf("%c", data[i]);

        if (data[i] == '1') {
            count++;

            if (count == 5) {
                printf("0");
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    printf("\n");
}

int main() {
    char data[100];
    int choice;

    printf("Enter data: ");
    scanf("%99s", data);

    printf("1. Character Count\n");
    printf("2. Character Stuffing\n");
    printf("3. Bit Stuffing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            characterCount(data);
            break;
        case 2:
            characterStuffing(data);
            break;
        case 3:
            bitStuffing(data);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}