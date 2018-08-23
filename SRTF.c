#include<stdio.h>

int main(){

	int n,j,temp,min, burst_time[10],arrival_time[10], waiting_time[10], turn_time[10], i, P[10];
        int avgtat, avgwt, tat, wt;
        printf("Enter the no. of processes:");
        scanf("%d",&n);

        printf("\nEnter burst time for the processes:\n");
        for(i=0;i<n;i++)
        {
                printf("Process, P[%d]:",(i+1));
                scanf("%d", &burst_time[i]);
		scanf("%d", &arrival_time[i]);
                P[i]=i+1;
                waiting_time[i]=0;
        }

	 //Selection Sorting
        for(i=0; i<n-1;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        min=i;
                        if(arrival_time[j]<arrival_time[i])
                        {
                                min=j;
                                 //swapping
                                // printf ("Swapping %d with %d\n",burst_time[i],burst_time[j]);
                                temp=P[i];
                                P[i]=P[min];
                                P[min]=temp;

                                temp=arrival_time[i];
                                arrival_time[i]=arrival_time[min];
                                arrival_time[min]=temp;

                        }
                }
        }
	
	printf("\nPROCESS\t\tARRIVAL TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
        for(i=0;i<n;i++)
        {

                printf("\nP[%d]:\t\t%d\t\t\t%d\t\t\t\t%d",P[i],arrival_time[i],waiting_time[i],turn_time[i]);
        }
        printf("\n");
        return 0;
}

