#include <stdio.h>
void calcWaitTime( int burst[] , int wait[] , int n ){
    wait[0]=0;
    for (int  i = 1; i < n ; i++ )  
        wait[i] =  burst[i-1] + wait[i-1];
}

void calcTurnAroundTime( int burst[] , int wait[], int n , int turn[]){
    for (int  i = 0; i < n ; i++)  
        turn[i] = burst[i] + wait[i];
}

void main(){
    int burst[10];
    int n,i;
    int totalWait=0;
    int totalTurn=0;
    printf( "\nHow many processes?(max 10)" );
    scanf("%d",&n);
    printf( "\nEnter their respective burst times: \n" );
    for( i = 0 ; i < n ; i++ ){
            scanf( "%d" , &burst[i] );
    }
    int wait[n];
    int turn[n];
    calcWaitTime( burst , wait , n );
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