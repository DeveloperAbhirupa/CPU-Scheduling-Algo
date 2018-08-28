#include<stdio.h>

struct process
{
      char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
}p_q[10];

int limit;

void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(p_q[i].arrival_time > p_q[j].arrival_time)
                  {
                        temp = p_q[i];
                        p_q[i] = p_q[j];
                        p_q[j] = temp;
                  }
            }
      }
}

void main()
{
      int i, time = 0, burst_time = 0, largest;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            p_q[i].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", p_q[i].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &p_q[i].arrival_time );
            printf("Enter Burst Time:\t");
            scanf("%d", &p_q[i].burst_time);
            printf("Enter Priority:\t");
            scanf("%d", &p_q[i].priority);
            p_q[i].status = 0;
            burst_time = burst_time + p_q[i].burst_time;
      }
      Arrival_Time_Sorting();
      p_q[9].priority = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time = p_q[0].arrival_time; time < burst_time;)
      {
            largest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(p_q[i].arrival_time <= time && p_q[i].status != 1 && p_q[i].priority > p_q[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + p_q[largest].burst_time;
            p_q[largest].ct = time;
            p_q[largest].waiting_time = p_q[largest].ct - p_q[largest].arrival_time - p_q[largest].burst_time;
            p_q[largest].turnaround_time = p_q[largest].ct - p_q[largest].arrival_time;
            p_q[largest].status = 1;
            wait_time = wait_time + p_q[largest].waiting_time;
            turnaround_time = turnaround_time + p_q[largest].turnaround_time;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", p_q[largest].process_name, p_q[largest].arrival_time, p_q[largest].burst_time, p_q[largest].priority, p_q[largest].waiting_time);
      }
      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}

