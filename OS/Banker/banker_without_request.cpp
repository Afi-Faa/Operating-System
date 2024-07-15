#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, r, i, j, k,flag=0;
    n = 5; // Indicates the Number of processes
    r = 3; // Indicates the Number of resources
    int alloc[5][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int avail[3] = {2, 3, 2}; // These are Available/work Resources

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][r];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                flag=0;

                for (j = 0; j < r; j++)
                {
                    if (need[i][j] <= avail[j])
                    {
                        ans[ind]=i;
                        ind++;
                        for (y = 0; y < r; y++)
                        {
                            avail[y] += alloc[i][y];
                        }
                        f[i]=1;
                        
                    }
                    else
                    {
                        flag=1;
                        break;

                    }
                }

            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=1;

        }
    }
    if(flag==1)
    {
        cout<<"safe"<<endl;
    }
    else
    {
        cout<<"unsafe"<<endl;
    }

    printf("Th SAFE Sequence is as follows\n");
    for (i = 0; i < n ; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}