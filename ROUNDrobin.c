
#include<stdio.h>

int main()
{

  int c,j,n,time,remn,flag=0,quanta;
  int wait_time=0,turnaround_time=0,at[10],bt[10],run_time[10];
  printf("Enter number of Process:\t ");
  scanf("%d",&n);
  remn=n;
  for(c=0;c<n;c++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1);
    scanf("%d",&at[c]);
    scanf("%d",&bt[c]);
    run_time[c]=bt[c];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&quanta);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,c=0;remn!=0;)
  {
    if(run_time[c]<=quanta && run_time[c]>0)
    {
      time+=run_time[c];
      run_time[c]=0;
      flag=1;
    }
    else if(run_time[c]>0)
    {
      run_time[c]-=quanta;
      time+=quanta;
    }
    if(run_time[c]==0 && flag==1)
    {
      remn--;
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,time-at[c],time-at[c]-bt[c]);
      wait_time+=time-at[c]-bt[c];
      turnaround_time+=time-at[c];
      flag=0;
    }
    if(c==n-1)
      c=0;
    else if(at[c+1]<=time)
      c++;
    else
      c=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
