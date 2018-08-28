#include<stdio.h>
//#include<conio.h>
#include<string.h>


void main()
{
    int expected_time[20],arrival_time[10],n,i,j,temp,start_time[10],final_time[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float avg_wt,ata;
    char proc_name[10][10],t[10];
    //clrscr();
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name, arrival time& execution time:");
        //flushall();
        scanf("%s%d%d",proc_name[i],&arrival_time[i],&expected_time[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(expected_time[i]<expected_time[j])
            {
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;
                temp=expected_time[i];
                expected_time[i]=expected_time[j];
                expected_time[j]=temp;
                strcpy(t,proc_name[i]);
                strcpy(proc_name[i],proc_name[j]);
                strcpy(proc_name[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            start_time[i]=arrival_time[i];
        else
            start_time[i]=final_time[i-1];
        wt[i]=start_time[i]-arrival_time[i];
        final_time[i]=start_time[i]+expected_time[i];
        ta[i]=final_time[i]-arrival_time[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    avg_wt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",proc_name[i],arrival_time[i],expected_time[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",avg_wt);
    printf("\nAverage turnaroundtime is:%f",ata);

}
