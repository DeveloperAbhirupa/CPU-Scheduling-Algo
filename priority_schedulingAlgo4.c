#include<stdio.h>

int main()
{
	int n,Pnum[20], P[20], bt[20], wt[20], avgwt=0, tat[20], avgtat=0, i,j, temp, pos=-1;

	printf("Enter no. of processes: (max 20) ");
	scanf("%d ", &n);

	//Enter waiting tme and priority number
	for(i=0;i<n;i++)
	{
		printf("For process %d:\nPriority:",(i+1));
		scanf("%d",&P[i]);
		printf("Waiting time:");
		scanf("%d",&wt[i]);
		Pnum[i]=i+1;
	}

	//Sorting processes according to priority
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(P[j]<P[i])
				pos=j;
		}
		//Swap data
		temp=P[i];
		P[i]=P[pos];
		P[pos]=temp;

		temp=wt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;

		temp=Pnum[i];
		Pnum[i]=Pnum[pos];
		Pnum[pos]=j;
	}
	//Calculating waiting time
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[i];
		avgwt+=wt[i];
	}
	avgwt/=n;
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
        	tat[i]=bt[i]+wt[i];    
	        avgtat+=tat[i];
	        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",Pnum[i],bt[i],wt[i],tat[i]);
	}

	avgtat/=n;     
	printf("\n\nAverage Waiting Time for the processes=%d", avgwt);
	printf("\nAverage Turnaround Time for the processes=%d",avgtat);

	return 0;
}






