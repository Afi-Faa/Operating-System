// C++ implementation of First - Fit algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the
    // block allocated to a process
    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocation[i] = j;

                // Reduce available memory in this block.
                blockSize[j] -= processSize[i];

                break;
            }
        }
    }
    cout<<"First Fit";
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
//implementation of worst - Fit algorithm
void worstFit(int block[], int k, int process[], int l)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[l];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < l; i++)
    {
        // Find the best fit block for current process
        int wstIdx = -1;
        for (int j = 0; j < k; j++)
        {
            if (block[j] >= process[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (block[wstIdx] < block[j])
                    wstIdx = j;
            }
        }

        // If we could find a block for current process
        if (wstIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = wstIdx;

            // Reduce available memory in this block.
            block[wstIdx] -= process[i];
        }
    }

    cout<<"Worst Fit";
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < l; i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
//implementation of Best - Fit algorithm
void bestFit(int bloSize[], int o, int proSize[], int p)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[p];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < p; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j = 0; j < o; j++)
        {
            if (bloSize[j] >= proSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (bloSize[bestIdx] > bloSize[j])
                    bestIdx = j;
            }
        }

        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            bloSize[bestIdx] -= proSize[i];
        }
    }
    cout<<"Best Fit";
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < p; i++)
    {
        cout << "   " << i + 1 << "\t\t" << proSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);
    cout<<endl;

    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int k = sizeof(block) / sizeof(block[0]);
    int l = sizeof(process) / sizeof(process[0]);

    worstFit(block, k, process, l);
    cout<<endl;

    int bloSize[] = {100, 500, 200, 300, 600};
    int proSize[] = {212, 417, 112, 426};
    int o = sizeof(bloSize) / sizeof(bloSize[0]);
    int p = sizeof(proSize) / sizeof(proSize[0]);

    bestFit(bloSize, o, proSize, p);
    cout<<endl;

    return 0;
}
