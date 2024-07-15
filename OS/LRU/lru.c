#include <stdio.h>
#include <conio.h>
int fsize;
int frm[15];
void display();
void main()
{
    int pg[100], change[15], nPage, i, j, k, l, index, pf = 0, temp, flag = 0, flag1 = 0, found, max;
    printf("\n Enter frame size:");
    scanf("%d", &fsize);
    printf("\n Enter number of pages:");
    scanf("%d", &nPage);

    for (i = 0; i < nPage; i++)
    {
        printf("\n Enter page[%d]:", i + 1);
        scanf("%d", &pg[i]);
    }
    for (i = 0; i < fsize; i++)
        frm[i] = -1;

    printf("\n page | \t Frame content ");
    printf("\n--------------------------------------");
    for (j = 0; j < nPage; j++)
    {
        flag = 0;
        flag1 = 0;
        for (i = 0; i < fsize; i++)
        {
            if (frm[i] == pg[j])
            {
                flag = 1;
                flag1 = 1;
                break;
            }
        }
        if (flag == 0)
        {

            for (i = 0; i < fsize; i++)
            {
                if (frm[i] == -1)
                {
                    frm[i] = pg[j];
                    pf++;
                    flag1 = 1;
                    break;
                }
            }
        }

        if (flag1 == 0)
        {
            for (i = 0; i < fsize; i++)
                change[i] = 0;

            for (i = 0; i < fsize; i++)
            {
                for (k = j + 1; k <= nPage; k++)
                {
                    if (frm[i] == pg[k])
                    {
                        change[i] = k - j;// j sobr age excute hoice
                        break;
                    }
                }
            }
            found = 0;

            for (i = 0; i < fsize; i++)
            {
                if (change[i] == 0)
                {
                    index = i;
                    found = 0;
                    break;
                }
            }
            if (found == 0)
            {
                max = change[0];
                index = 0;

                for (i = 1; i < fsize; i++)
                {
                    if (max < change[i])
                    {
                        max = change[i];
                        index = i;
                    }
                }
            }
            frm[index] = pg[j];
            pf++;
        }
        printf("\n %d    |", pg[j]);
        display();
    }
    printf("\n--------------------------------------");
    printf("\n total page fault:%d", pf);
    getch();
}
void display()
{
    int i;
    for (i = 0; i < fsize; i++)
        printf("\t %d", frm[i]);
}
