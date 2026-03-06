#include <stdio.h>
int main()
{
    struct Process{
    int pid;
    int arrival;
    int burst;
    int tat;
    int waiting;
    int completion;
    int response;
    };
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

    int time=0;
    for(int i = 0; i < n; i++) {
        if(time < p[i].arrival)
            time = p[i].arrival;
        time+=p[i].burst;
        p[i].completion=time;
        p[i].tat=p[i].completion - p[i].arrival;
        p[i].waiting=p[i].tat-p[i].burst;
        p[i].response=time-p[i].arrival;

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

}
