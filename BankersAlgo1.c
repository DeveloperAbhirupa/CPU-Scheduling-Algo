//Implement safety algorithm using Banker's algorithm


#include<stdio.h>

int m=5;
int n=3;

int NeedMatrix( int N[m][n], int A[m][n], int M[m][n])
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			N[i][j]=M[i][j]-A[i][j];
		}
	}
}//NeedMatrix generated

void checkSafe(int Av[n], int A[][n], int M[][n]){
	int N[m][n];
	NeedMatrix( N, A, M);

	//To store the safe sequence
	int S[n];
	int work[n];
	int i,j;
	int status[m]; //Stores the status of m processes
	for(i=0;i<m;i++)
		status[i]=0;
	int count=0;

	//Create a separate work,[] and copy Av[] to work
	for(i=0;i<n;i++)
	{
		work[i]=Av[j];
	}

	while(count<m)
	{
		int found=-1;
		for(i=0;i<m;i++)
		{

			if (status[i] == 0) //If the process execution has not finished CONDITION1
			{
				for(j=0;j<n;j++) //CONDITION2
					if(N[i][j]<work[j])
						break;
				if(j==n) //All conditions satisfied
				{
					for(j=0;j<n;j++)	
						work[j]+=A[i][j];

					S[count++]=i;//Stored the safe sequence
					status[i] =1;

					found=1;
				
				}

			}
		}
		if(found==-1)
		{
			printf("System is not in safe state!");
			return;
		}
	}

	printf("System is in safe state! Safe sequence:\n");
	for(j=0;j<m;j++)
		printf("%d  ",  S[j]);
	return;
}


int main()
{
	m=5;
	n=3;
	int Av[3] = {3, 3, 2};
	int demo[2][2]={{2,3},{3,0}};
	int M[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int A[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	checkSafe(Av,A, M);
	return 0;

}





