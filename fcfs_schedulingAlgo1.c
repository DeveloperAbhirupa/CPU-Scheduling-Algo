#include<stdio.h>

int main()
{
	int n, bt[20], i,j,wt[20], tat[20], avtat=0, avwt=0;
	printf( "Enter total no. of processes(max 20):");
	scanf("%d\n ",&n);

	printf("Enter process burst time for each process:\n");
	for(i=0;i<n;i++)
	{
		printf("P[%d]:",i);
		scanf("%d", &bt[i]);
	}

	wt[0]=0; //Waiting time for the first process is 0

	//Calculating waiting time for each process
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
	}

	printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time");

	//Calculating turnaround time
	
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i]; //Calculating total waiting time
		avtat+=tat[i]; //Calculating total turn around time

		//Printing 
		printf("\nP[%d]\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
	}
//	printf("2 values are: %d %d", avwt, avtat);

	avwt/=n;
	avtat/=n;
	printf("\nAverage waiting time: %d", avwt);
	printf("\nAverage turnaround time: %d/n",avtat);

	return 0;
}
		




