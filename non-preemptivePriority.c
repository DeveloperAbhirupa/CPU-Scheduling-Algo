#include<stdio.h>

int main()
{
      int brst_time[20], proc[20], wait_tim[20], turnaround_time[20], priority[20];
      int i, j, limit, sum = 0, position, t;
      float average_wait_time, average_turnaround_time;
      printf("Enter no. of processes:\t");
      scanf("%d", &limit);
      printf("\nEnter Burst time and priority order for each process\n");
      for(i = 0; i < limit; i++)
      {
            printf("\nproc[%d]\n", i + 1);
            printf("Enter Burst Time:");
            scanf("%d", &brst_time[i]);
            printf("Enter Priority:");
            scanf("%d", &priority[i]);
            proc[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            t = priority[i];
            priority[i] = priority[position];
            priority[position] = t;
            t = brst_time[i];
            brst_time[i] = brst_time[position];
            brst_time[position] = t;
            t = proc[i];
            proc[i] = proc[position];
            proc[position] = t;
      }
      wait_tim[0] = 0;
      for(i = 1; i < limit; i++)
      {
            wait_tim[i] = 0;
            for(j = 0; j < i; j++)
            {
                  wait_tim[i] = wait_tim[i] + brst_time[j];
            }
            sum = sum + wait_tim[i];
      }
      average_wait_time = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = brst_time[i] + wait_tim[i];
            sum = sum + turnaround_time[i];
            printf("\nproc[%d]\t\t\t%d\t\t %d\t\t %d\n", proc[i], brst_time[i], wait_tim[i], turnaround_time[i]);
      }
      average_turnaround_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}
