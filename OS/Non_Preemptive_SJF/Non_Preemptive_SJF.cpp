#include<bits/stdc++.h>
using namespace std;
int main()
{
    int burst_time[20],p[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_waiting_time,avg_tat;
    cout<<"please enter number of process: ";
    cin>>n;
    cout<<"\nenter the Burst Time:\n";
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<":";
        cin>>burst_time[i];
        p[i]=i+1;
    }
    // from here, burst times sorted
    for(i=0; i<n; i++)
    {
        pos=i;
        for(j=i+1; j<n; j++)
        {
            if(burst_time[j]<burst_time[pos])
            {
                pos=j;
            }
        }
        swap(burst_time[i],burst_time[pos] );
        swap(p[i],p[pos] );
    }

    waiting_time[0]=0;
    //for calculating waiting time of each process
    for(i=1; i<n; i++)
    {
        waiting_time[i]= burst_time[i-1]+ waiting_time[i-1];
        total+=waiting_time[i];
    }
    avg_waiting_time=(float)total/n;
    total=0;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0; i<n; i++)
    {
        tat[i]=burst_time[i]+waiting_time[i];
        total+=tat[i];
        cout<<"\np"<<p[i]<<":\t\t  "<<burst_time[i]<<"\t\t    "<<waiting_time[i]<<"\t\t\t"<<tat[i];
    }
    avg_tat=(float)total/n;
    cout<<"\n\nthe average Waiting Time="<<avg_waiting_time<<endl;
    cout<<"\nthe average Turnaround Time="<<avg_tat<<endl;
}


