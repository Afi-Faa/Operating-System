#include <bits/stdc++.h>
using namespace std;
int main()
{
    int pid[15];
    int bt[15];
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter process id of all the processes: ";
    for(int i=0;i<n;i++)
    {
        cin>>pid[i];
    }
  cout<<"Enter burst time of all the processes: ";
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    int i, wt[n];
    wt[0]=0;
    //for calculating waiting time of each process
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
    cout<<"Process ID     Burst Time     Waiting Time     TurnAround Time\n";
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        cout<<pid[i]<<"\t\t";
        cout<<bt[i]<<"\t\t";
       cout<<wt[i]<<"\t\t";
        //calculating and printing turnaround time of each process
        cout<<bt[i]+wt[i]<<"\t\t";
        cout<<"\n";
        //for calculating total waiting time
        twt += wt[i];
        //for calculating total turnaround time
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
    //for calculating average waiting time
    awt = twt/n;
    //for calculating average turnaround time
    att = tat/n;
    cout<<"Avg. waiting time= "<<awt<<"\n";
    cout<<"Avg. turnaround time="<< att;
}
