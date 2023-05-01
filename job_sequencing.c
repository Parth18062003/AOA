#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

void printJobSequence(int jobs[], int deadlines[], int profits[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }
    int jobSequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        jobSequence[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int deadline = deadlines[i];
        while (deadline > 0 && jobSequence[deadline - 1] != -1) {
            deadline--;
        }
        if (deadline > 0) {
            jobSequence[deadline - 1] = jobs[i];
        }
    }
    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (jobSequence[i] != -1) {
            printf("%c ", jobSequence[i]);
        }
    }
    int totalProfit = 0;
    for (int i = 0; i < maxDeadline; i++) {
        if (jobSequence[i] != -1) {
            for (int j = 0; j < n; j++) {
                if (jobs[j] == jobSequence[i]) {
                    totalProfit += profits[j];
                    break;
                }
            }
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    int jobs[MAX_JOBS], deadlines[MAX_JOBS], profits[MAX_JOBS], n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    printf("Enter the details of each job (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &jobs[i], &deadlines[i], &profits[i]);
    }
    printJobSequence(jobs, deadlines, profits, n);
    return 0;
}
