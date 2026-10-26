#include <stdio.h>
#include <string.h>

void calculateCRC(char data[], char generator[]) {
    char temp[300];
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    int i, j;

    strcpy(temp, data);

    for (i = 0; i < genLen - 1; i++)
        temp[dataLen + i] = '0';

    temp[dataLen + genLen - 1] = '\0';

    for (i = 0; i < dataLen; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < genLen; j++) {
                temp[i + j] =
                    (temp[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    printf("CRC Remainder: ");

    for (i = dataLen; i < dataLen + genLen - 1; i++)
        printf("%c", temp[i]);

    printf("\n");
}

int main() {
    char data[200];
    int choice;

    printf("Enter binary data: ");
    scanf("%199s", data);

    printf("1. CRC-12\n");
    printf("2. CRC-16\n");
    printf("3. CRC-CCITT\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            calculateCRC(data, "1100000001111");
            break;
        case 2:
            calculateCRC(data, "11000000000000101");
            break;
        case 3:
            calculateCRC(data, "10001000000100001");
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}