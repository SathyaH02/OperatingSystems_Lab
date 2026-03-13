#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Process {
    int pid;
    int priority;
    int arrival;
    int burst;
    int tat;
    int waiting;
    int completion;
    int response;
    int remaining;
    int completed;
};

void prioNonPreemptive(struct Process p[], int n);
void prioPreemptive(struct Process p[], int n);

int main() {
    int n;
    printf("Enter the no.of processes: ");
    scanf("%d",&n);
    struct Process p[n];

    for (int i=0;i<n;i++) {
        printf("Process %d arrival time: ",i+1);
        scanf("%d",&p[i].arrival);

        printf("Process %d burst time: ",i+1);
        scanf("%d",&p[i].burst);

        printf("Process %d priority: ",i+1);
        scanf("%d",&p[i].priority);

        p[i].pid=i+1;
        p[i].completed = 0;
        p[i].remaining = p[i].burst;
        p[i].response = -1; // not yet started
    }

    int choice;
    printf("Non-preemptive or Preemptive Priority? 1/2: ");
    scanf("%d",&choice);
    switch(choice) {
    case 1:
        prioNonPreemptive(p,n);
        break;
    case 2:
        prioPreemptive(p,n);
        break;
    default:
        printf("Invalid choice");
    }

    int tatSum=0, wtSum=0, rtSum=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < n; i++) {
        tatSum+=p[i].tat;
        wtSum+=p[i].waiting;
        rtSum+=p[i].response;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].tat,  p[i].waiting, p[i].response);
    }

    printf("\nAverage Turn Around Time: %f",(float)tatSum/n);
    printf("\nAverage Waiting Time: %f",(float)wtSum/n);
    printf("\nAverage Response Time: %f",(float)rtSum/n);

    return 0;
}

void prioNonPreemptive(struct Process p[], int n) {
    int time = 0, completed = 0;

    while(completed < n) {
        int idx = -1;
        int bestPriority = INT_MAX;

        for(int i=0;i<n;i++) {
            if(p[i].arrival <= time && p[i].completed==0) {
                if(p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            if(p[idx].response == -1) p[idx].response = time - p[idx].arrival;

            time += p[idx].burst;
            p[idx].completion = time;
            p[idx].tat = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].tat - p[idx].burst;

            p[idx].completed = 1;
            completed++;
        } else {
            time++;
        }
    }
}

void prioPreemptive(struct Process p[], int n) {
    int time = 0, completed = 0;

    while(completed < n) {
        int idx = -1;
        int bestPriority = INT_MAX;

        for(int i=0;i<n;i++) {
            if(p[i].arrival <= time && p[i].completed==0) {
                if(p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            if(p[idx].response == -1) p[idx].response = time - p[idx].arrival;

            p[idx].remaining--;
            time++;

            if(p[idx].remaining == 0) {
                p[idx].completion = time;
                p[idx].tat = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].tat - p[idx].burst;
                p[idx].completed = 1;
                completed++;
            }
        } else {
            time++;
        }
    }
}
