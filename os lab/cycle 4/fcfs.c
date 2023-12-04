#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int pid[10], at[10], bt[10], n, ct[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process id: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter arrival time of processes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst time of processes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(&at[j], &at[j + 1]);
                swap(&pid[j], &pid[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
            else if (at[j] == at[j + 1]) {
                if (pid[j] > pid[j + 1]) {
                    swap(&at[j], &at[j + 1]);
                    swap(&pid[j], &pid[j + 1]);
                    swap(&bt[j], &bt[j + 1]);
                }
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    printf("\nPID  AT  BT  CT  TAT  WT\n");
    float tat = 0, wt = 0;
    for (int i = 0; i < n; i++) {
        printf(" P%d  %d   %d   %d   %d   %d\n", pid[i], at[i], bt[i], ct[i], (ct[i] - at[i]), (ct[i] - at[i] - bt[i]));
        tat += ct[i] - at[i];
        wt += ct[i] - at[i] - bt[i];
    }

    float tat_avg = tat / n;
    float wt_avg = wt / n;
    printf("\nAverage Turnaround Time is %f.\n", tat_avg);
    printf("\nAverage Waiting Time is %f.\n", wt_avg);

    return 0;
}