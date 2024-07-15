#include <bits/stdc++.h>
using namespace std;
int findLRU(int t[], int n2);
int i, j, n, a[50], q[50], l[50], lm = 0, frame[10], index, maxi, temp[10], s = 0, no, k, avail, cont = 0, cont2 = 0, t[10], flag1, flag2, flag3 = 0, flag4 = 0, flag5, pos, faults = 0, f = 0, found;
int fifo()
{
    for (i = 0; i < no; i++)
    {
        frame[i] = -1;
    }

    j = 0;
    cout << "\tstring\t page frames" << endl;

    for (i = 1; i <= n; i++)
    {
        cout << "\t\t" << a[i];
        avail = 0;
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                avail = 1;
            }
        }
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            cont++;
            for (k = 0; k < no; k++)
                cout << "\t" << frame[k];
        }
        cout << "\n";
    }
}

int findLRU(int t[], int n)
{
    int i, minimum = t[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (t[i] < minimum)
        {
            minimum = t[i];
            pos = i;
        }
    }

    return pos;
}

int lru()
{
    for (i = 0; i < no; ++i)
    {
        frame[i] = -1;
    }

    cout << "\t page frames" << endl;

    for (i = 0; i < n; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no; ++j)
        {
            if (frame[j] == q[i])
            {
                cont2++;
                t[j] = cont2;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no; ++j)
            {
                if (frame[j] == -1)
                {
                    cont2++;
                    faults++;
                    frame[j] = q[i];
                    t[j] = cont2;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            pos = findLRU(t, no);
            cont2++;
            faults++;
            frame[pos] = q[i];
            t[pos] = cont2;
        }

        cout << endl;

        for (j = 0; j < no; ++j)
        {
            cout << "\t" << frame[j];
        }
    }
    cout << "\n";
}

int opt()
{
    for (i = 0; i < no; i++)
    {
        frame[i] = -1;
    }
    cout << "\t page frames" << endl;

    for (i = 0; i < n; ++i)
    {
        flag3 = flag4 = 0;

        for (j = 0; j < no; ++j)
        {
            if (frame[j] == l[i])
            {
                flag3 = flag4 = 1;
                break;
            }
        }

        if (flag3 == 0)
        {
            for (j = 0; j < no; ++j)
            {
                if (frame[j] == -1)
                {
                    f++;
                    frame[j] = l[i];
                    flag4 = 1;
                    break;
                }
            }
        }

        if (flag4 == 0)
        {
            flag5 = 0;

            for (j = 0; j < no; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no; ++k)
                {
                    if (frame[j] == l[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag5 = 1;
                    break;
                }
            }

            if (flag5 == 0)
            {
                maxi = temp[0];
                pos = 0;

                for (j = 1; j < no; ++j)
                {
                    if (temp[j] > maxi)
                    {
                        maxi = temp[j];
                        pos = j;
                    }
                }
            }
            frame[pos] = l[i];
            f++;
        }

        cout<<"\n";

        for (j = 0; j < no; ++j)
        {
            cout<<"\t"<<frame[j];
        }
    }
    cout << "\n";
}

int main()
{
    cout << "ENTER THE NUMBER OF PAGES: ";
    cin >> n;
    cout << "ENTER THE PAGE NUMBER : ";

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++)
    {
        q[s] = a[i];
        s++;
    }
    for (i = 1; i <= n; i++)
    {
        l[lm] = a[i];
        lm++;
    }

    cout << "ENTER THE NUMBER OF FRAMES : ";
    cin >> no;
    fifo();
    cout << "Page Fault in FIFO is " << cont << endl;

    lru();
    cout << "Page Fault in LRU is " << faults << endl;

    opt();
    cout << "Page Fault in OPTIMAL is " << f << endl;

    return 0;
}
