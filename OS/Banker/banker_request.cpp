#include <bits/stdc++.h>
using namespace std;

int maxi[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();

void show();

void cal();

void request();

int main()
{
    int i, j,f;
    cout<<"********** Banker's Algo ************"<<endl;
    input();
    cal();
    show();
    request();


    return 0;
}

void input()
{
    int i, j;
    cout<<"Enter the no of Processes: ";
    cin >> n;
    cout<<"Enter the no of resources instances: ";
    cin >> r;
    cout<<"Enter the Max Matrix:"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> maxi[i][j];
        }
    }
    cout<<"Enter the Allocation Matrix"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }
    cout<<"Enter the available Resources: "<<endl;
    for (j = 0; j < r; j++)
    {
        cin >> avail[j];
    }
}

void show()
{
    int i, j;
    cout<<"Process\t Alloca\t Max\t Need\t Available"<<endl;
    for (i = 0; i < n; i++)
    {
        cout<<"\nP"<<i<<"\t";
        for (j = 0; j < r; j++)
        {
            cout<<alloc[i][j]<<" ";
        }
        cout<<"\t";
        for (j = 0; j < r; j++)
        {
            cout<<maxi[i][j]<<" ";
        }
        cout<<"\t";
        for (j = 0; j < r; j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<"\t";
        if (i == 0)
        {
            for (j = 0; j < r; j++)
            cout<<avail[j]<<" ";
        }
    }
}

void cal()
{
    int finish[100], flag = 1, k, c1 = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = maxi[i][j] - alloc[i][j];
        }
    }
    cout<<"\n";
    while (flag)
    {

        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        cout<<"P"<<i<<"->";
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            cout<<"P"<<i<<"->";
        }
    }
    if (c1 == n)
    {
        cout<<"\n The system is in safe state\n";
    }
    else
    {
        cout<<"\n Process are in dead lock\n";
        cout<<"\n System is in unsafe state\n";
    }
}

void request()
{
    int c, pid, request[100][100], i;
    cout<<"\n Do you want make an additional request for any of the process ? (1=Yes|0=No)";
    cin>>c;
    if (c == 1)
    {
        cout<<"\n Enter process number : ";
        cin>>pid;
        cout<<"\n Enter additional request : \n";
        for (i = 0; i < r; i++)
        {
            cout<<" Request for resource "<<i+1<<": ";
            cin>>request[0][i];
        }
        if (request[0][i] <= need[pid][i])
        {
            if (request[0][i] <= avail[i])
            {
                for (i = 0; i < r; i++)
                {
                    avail[i] -= request[0][i];
                    alloc[pid][i] += request[0][i];
                    need[pid][i] -= request[0][i];
                }
                cal();
                show();
            }
            else
            {
                cout << "Resource not avaiable" << endl;
                exit(0);
            }
        }

        else
        {
            cout<<"\nError encountered\n";
            exit(0);
        }
    }
    else
    {
        exit(0);
    }
}
