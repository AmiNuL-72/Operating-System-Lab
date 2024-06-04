
#include<stdio.h>
#include<conio.h>
#define mx 30

int main(){
    //initialization part
    int i,j,n,BurstTime[mx],ArrivalTime[mx],WaitingTime[mx],TurnAroundTime[mx],tmp[mx];
    float AvgWaitTime=0, AvgTurnArTime=0;
    
    //input part here
    printf("Enter the no of process: ");
    scanf("%d",&n);
    printf("Enter the burst time of the process: ");
    for(i=0; i<n; i++){
        scanf("%d",&BurstTime[i]);
    }
    printf("Enter the arrival time of the process: ");
    for(i=0; i<n; i++){
        scanf("%d",&ArrivalTime[i]);
    }
    tmp[0]=0;
    printf("process\t burst time\t arrival time\t waiting time\t turn around time\n");
    //Logic implementation part here
    for(i=0; i<n; i++){
        WaitingTime[i]=0;
        TurnAroundTime[i]=0;
        tmp[i+1]=tmp[i]+BurstTime[i];
        WaitingTime[i]=tmp[i]-ArrivalTime[i];
        TurnAroundTime[i]=WaitingTime[i]+BurstTime[i];
        AvgWaitTime=AvgWaitTime+WaitingTime[i];
        AvgTurnArTime=AvgTurnArTime+TurnAroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,BurstTime[i],ArrivalTime[i],WaitingTime[i],TurnAroundTime[i]);
    }
    AvgWaitTime=AvgWaitTime/n;
    AvgTurnArTime=AvgTurnArTime/n;
    printf("Average waiting time %f\n",AvgWaitTime);
    printf("Average turn around time %f\n",AvgTurnArTime);
    
}
