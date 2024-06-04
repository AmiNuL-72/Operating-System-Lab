#include<stdio.h>
#include<conio.h>
#define mx 30

int main(){
    //initialization part
    int i,j,n,t,Process[mx],BurstTime[mx],WaitingTime[mx],TurnAroundTime[mx];
    float AvgWaitTime=0, AvgTurnArTime=0;
    
    //input part here
    printf("Enter the no of process: ");
    scanf("%d",&n);
    printf("Enter the process number: ");
    for(i=0; i<n; i++){
        scanf("%d",&Process[i]);
    }
    printf("Enter the burst time of the process: ");
    for(i=0; i<n; i++){
        scanf("%d",&BurstTime[i]);
    }
    // sort according to burst time
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(BurstTime[j]>BurstTime[j+1]){
                t=BurstTime[j];
                BurstTime[j]=BurstTime[j+1];
                BurstTime[j+1]=t;

                t=Process[j];
                Process[j]=Process[j+1];
                Process[j+1]=t;
            }
        }
    }
    printf("process\t burst time\t waiting time\t turn around time\n");
    //Logic implementation part here
    for(i=0; i<n; i++){
        WaitingTime[i]=0;
        TurnAroundTime[i]=0;

        for(j=0; j<i; j++){
            WaitingTime[i]=WaitingTime[i]+BurstTime[j];
        }
        TurnAroundTime[i]=WaitingTime[i]+BurstTime[i];
        AvgWaitTime=AvgWaitTime+WaitingTime[i];
        AvgTurnArTime=AvgTurnArTime+TurnAroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\n",Process[i],BurstTime[i],WaitingTime[i],TurnAroundTime[i]);
    }
    AvgWaitTime=AvgWaitTime/n;
    AvgTurnArTime=AvgTurnArTime/n;
    printf("Average waiting time %f\n",AvgWaitTime);
    printf("Average turn around time %f\n",AvgTurnArTime);
    
}
