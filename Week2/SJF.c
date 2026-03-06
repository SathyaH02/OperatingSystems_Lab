#include <stdio.h>
#include <limits.h>


struct Process{
    int pid;
    int arrival;
    int burst;
    int tat;
    int waiting;
    int completion;
    int response;
    };

void nonPreemptiveSJF(struct Process p[], int n);
void preemptiveSJF(struct Process p[], int n);

int main()
{
    int n;
    printf("Enter the no.of processes: ");
    scanf("%d",&n);
    struct Process p[n];

    for (int i=0;i<n;i++)
    {
        printf("Process %d arrival time: ",i+1);
        scanf("%d",&p[i].arrival);

        printf("Process %d burst time: ",i+1);
        scanf("%d",&p[i].burst);

        p[i].pid=i+1;
    }

    int choice;
    printf("Non-preemptive or Preemptive SJF? 1/2: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        nonPreemptiveSJF(p,n);
        break;
    case 2:
        preemptiveSJF(p,n);
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].tat,  p[i].waiting, p[i].response);
    }

    printf("\nAverage Turn Around Time: %f",(float)tatSum/n);
    printf("\nAverage Waiting Time: %f",(float)wtSum/n);
    printf("\nAverage Response Time: %f",(float)rtSum/n);

    return 0;
}

void nonPreemptiveSJF(struct Process p[], int n) {
    int completed = 0, time = 0;
    int isDone[n];
    for (int i = 0; i < n; i++) isDone[i] = 0;

    while (completed < n) {
        int shortest = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!isDone[i] && p[i].arrival <= time) {
                if (p[i].burst < minBurst) {
                    minBurst = p[i].burst;
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        time += p[shortest].burst;
        p[shortest].completion = time;
        p[shortest].tat = p[shortest].completion - p[shortest].arrival;
        p[shortest].waiting = p[shortest].tat - p[shortest].burst;
        p[shortest].response = p[shortest].waiting;

        isDone[shortest] = 1;
        completed++;
    }
}


void preemptiveSJF(struct Process p[], int n)
{
    int remaining[n];
    for (int i=0;i<n;i++)
    {
        remaining[i]=p[i].burst;
        p[i].response=-1;
    }
    int time=0, completed=0;

    while (completed < n)
    {
        int shortest=-1;
        int min_remaining=INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && remaining[i] > 0) {
                if (remaining[i] < min_remaining) {
                    min_remaining = remaining[i];
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        if (p[shortest].response == -1) {
            p[shortest].response = time - p[shortest].arrival;
        }

        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0) {
            completed++;
            p[shortest].completion = time;
            p[shortest].tat = p[shortest].completion - p[shortest].arrival;
            p[shortest].waiting = p[shortest].tat - p[shortest].burst;
        }

    }
}
