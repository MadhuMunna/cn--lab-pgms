#include <stdio.h>

int main() {
    int n, window, lost;
    int i, end, j;

    printf("Enter total number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter lost frame number (0 for no loss): ");
    scanf("%d", &lost);

    if (n <= 0 || window <= 0 || window > n ||
        lost < 0 || lost > n) {
        printf("Invalid input\n");
        return 1;
    }

    i = 1;

    while (i <= n) {
        end = i + window - 1;

        if (end > n)
            end = n;

        printf("\nSending frames %d to %d\n", i, end);

        if (lost >= i && lost <= end) {
            printf("Frame %d lost!\n", lost);
            printf("Retransmitting from frame %d\n", lost);

            for (j = lost; j <= end; j++)
                printf("Retransmitting frame %d\n", j);

            lost = 0;
        }

        printf("Acknowledgement received for frames %d to %d\n",
               i, end);

        i = end + 1;
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}