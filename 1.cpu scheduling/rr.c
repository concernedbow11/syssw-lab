#include<stdio.h>

void calcWaitTime( int burst[] , int wait[] , int n , int timeQuant){
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = burst[i];
    int t = 0; // Current time
    
    while (1) {
        int flag = 1;
 
        for (int i = 0 ; i < n; i++) {

            if (rem_bt[i] > 0) {
                flag = 0; 
                if (rem_bt[i] > timeQuant) {

                t += timeQuant;

                rem_bt[i] -= timeQuant;
                }

                else {

                t = t + rem_bt[i];

                wait[i] = t - burst[i];

                rem_bt[i] = 0;
                }
            }
      }

      if ( flag == 1 )
         break;
   }
}

void calcTurnAroundTime( int burst[] , int wait[], int n , int turn[]){
    for (int  i = 0; i < n ; i++)  
        turn[i] = burst[i] + wait[i];
}

void main(){
    int burst[10];
    int n,i,timeQuant;
    int totalWait=0;
    int totalTurn=0;
    printf( "\nHow many processes?(max 10)" );
    scanf("%d",&n);
    printf( "\nEnter their respective burst times: \n" );
    for( i = 0 ; i < n ; i++ ){
            scanf( "%d" , &burst[i] );
    }
    printf( "\nEnter the time quantum: " );
    scanf("%d",&timeQuant);
    int wait[n];
    int turn[n];
    calcWaitTime( burst , wait , n, timeQuant );
    calcTurnAroundTime( burst , wait , n , turn);
    for( i = 0 ; i < n ; i++){
        totalTurn += turn[i];
        totalWait += wait[i];
    }
    totalTurn = (float) totalTurn/(float) n;
    totalWait = (float) totalWait/(float) n;
    printf("Average waiting time = %d", totalWait); 
    printf("\n"); 
    printf("Average turn around time = %d ", totalTurn); 
}
    