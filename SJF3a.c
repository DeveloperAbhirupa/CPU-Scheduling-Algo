#include <stdio.h>

int main()
{
	int n,j,temp,min, burst_time[10], waiting_time[10], turn_time[10], i, P[10];
	int avgtat, avgwt, tat, wt;
	printf("Enter the no. of processes:");
	scanf("%d",&n);

	printf("\nEnter burst time for the processes:\n");
        for(i=0;i<n;i++)
        {
                printf("Process, P[%d]:",(i+1));
                scanf("%d", &burst_time[i]);
		P[i]=i+1;
		waiting_time[i]=0;
        }

	//Selection Sorting
	for(i=0; i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			min=i;
			if(burst_time[j]<burst_time[i])
			{
				min=j;
				 //swapping
				// printf ("Swapping %d with %d\n",burst_time[i],burst_time[j]);
                        	temp=P[i];
				P[i]=P[min];
        	                P[min]=temp;
	
        	                temp=burst_time[i];
                	        burst_time[i]=burst_time[min];
                        	burst_time[min]=temp;

			}
		}
	}
	printf("Swapping done");
	//Calculating waiting time
	waiting_time[0]=0;
	turn_time[0]=burst_time[0];
	for(i=1;i<n;i++)
	{
		waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
		turn_time[i]=waiting_time[i]+burst_time[i];
	}
	//Displaying table
	printf("\nPROCESS\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	for(i=0;i<n;i++)
	{

		printf("\nP[%d]:\t\t%d\t\t\t%d",P[i],waiting_time[i],turn_time[i]);
	}
	printf("\n");
	return 0;



}
