
//TO BE DRYRUN AND REQUIRED CHANGES TO BE MADE

#include<stdio.h>

int main()
{
	int n,i,arrival_time[10], burst_time[10], tat[10], waiting_time[0], flag=0,quanta, rem_time[10];
	int process[n],proc; //Keeps track of no. of processes that are stll left to be executed
	int totalRunTime=0;
	printf("Enter no. of processes:");
	scanf("%d",&n);
	proc=n;
	printf("Enter time quantum:");
	scanf("%d", &quanta);
	printf("\nEnter arrival time and burst time for the processes:\n");
	for(i=0;i<n;i++)
	{
		printf("Process, P[%d]:\n\tArrival Time:",(i+1));
		scanf("%d",&arrival_time[n]);
		printf("\n\tCPU Burst Time:");
		scanf("%d", &burst_time[n]);
		waiting_time[i]=0;
		tat[i]=0;
		rem_time[i]=burst_time[n];
	}

	for(int i=0;proc!=0; i++)
	{	
		if(arrival_time[i]>totalRunTime)
		{
			continue;
			totalRunTime++;
		}
		if(arrival_time[i]<=totalRunTime && process[i]==1)
		{
			
			tat[i]=totalRunTime ; //Gets overwritten for every process, with the current CPU runttime
			if(rem_time[i]<=quanta)
			{
				proc--;
				process[i]=0;//Denotes, that the process will no longer be executed
				totalRunTime+=rem_time[i];
				rem_time[i]=0;
				waiting_time[i]=totalRunTime-burst_time[i];
				tat[i]=totalRunTime;	
			}
			 else if(rem_time[i]>quanta)
			{
				totalRunTime+=quanta;
				rem_time[i]-=quanta;
			}

			
		}

		if(i==n-1)//Setting i back to 0th process
			i=-1;
	}
	 return 0;
}

		
	

