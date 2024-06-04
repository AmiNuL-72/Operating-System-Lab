#include<stdio.h>

#define mx 30

int main(){
    // Initialization part
    int i, n, QuaTime, cnt = 0, tmp, sq = 0, rem_bt[mx], BurstTime[mx], WaitingTime[mx], TurnAroundTime[mx];
    float AvgWaitTime = 0, AvgTurnArTime = 0;

    // Input part
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of the processes: ");
    for(i = 0; i < n; i++){
        scanf("%d", &BurstTime[i]);
        rem_bt[i] = BurstTime[i];
    }
    printf("Enter the Quantum Time: ");
    scanf("%d", &QuaTime);

    // Processing part
    while(1){
        int done = 1;  
        for(i = 0; i < n; i++){
            if(rem_bt[i] > 0) {
                done = 0;  // There is a pending process

                if(rem_bt[i] > QuaTime){
                    rem_bt[i] -= QuaTime;
                    sq += QuaTime;
                }
                else {
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                    TurnAroundTime[i] = sq;
                }
            }
        }
        if(done == 1) // If all processes are done
            break;
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        WaitingTime[i] = TurnAroundTime[i] - BurstTime[i];
        AvgWaitTime += WaitingTime[i];
        AvgTurnArTime += TurnAroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, BurstTime[i], WaitingTime[i], TurnAroundTime[i]);
    }

    AvgWaitTime /= n;
    AvgTurnArTime /= n;
    printf("Average waiting time: %f\n", AvgWaitTime);
    printf("Average turnaround time: %f\n", AvgTurnArTime);

    return 0;
}
