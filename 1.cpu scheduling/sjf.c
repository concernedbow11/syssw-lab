#include <stdio.h>

void calcWaitTime( int burst[] , int wait[] , int n ){
    int i,j;
    wait[0]=0;
    //calculate waiting time
    for ( i=1 ; i < n ; i++)
    {
        wait[i]=0;
        for( j=0 ; j < i ; j++ )
            wait[i] += burst[j];
    }
}

void calcTurnAroundTime( int burst[] , int wait[], int n , int turn[]){
    int i;
    for(i=0;i<n;i++)
    {
        turn[i]=burst[i] + wait[i];
    }
}
void main(){
    int process[10];
    int burst[10];
    int n,i,j,pos,temp;
    int totalWait=0;
    int totalTurn=0;
    printf( "\nHow many processes?(max 10)" );
    scanf("%d",&n);
    printf( "\nEnter their respective burst times: \n" );
    for( i = 0 ; i < n ; i++ ){
            process[i]=i;
            scanf( "%d" , &burst[i] );
    }

    for ( i  = 0 ; i < n ; i++ )
    {
        pos=i;
        for ( j = i + 1 ; j < n ; j++ )
        {
            if(burst[j]<burst[pos])
                pos=j;
        }
 
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
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