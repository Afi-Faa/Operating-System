#include<bits/stdc++.h>
using namespace std;
int buffer[5],in=0,out=0,n,item,con;
void output();
void produce();
void consumer();

void produce()
{
    while(true)
    {
        if(((in+1)%5)==out)
        {
            cout<<"Buffer is full"<<endl;
            output();
            break;
        }
        cout<<"Enter number: ";
        cin>>item;
        buffer[in]=item;
        in=(in+1)%5;
        output();

    }
}
void consumer()
{
    while(true)
    {
        if(in==out)
        {
            cout<<"Buffer is empty"<<endl;
            output();
            break;
        }
        con=buffer[out];
        cout<<"Consume number is "<<con<<endl;
        out=(out+1)%5;
        output();

    }
}
void output()
{
    cout<<"1.Producer  2.Consumer  3.Exit"<<endl;
    cin>>n;
    if(n==1)
    {
        produce();
    }
    if(n==2)
    {
        consumer();
    }
}
int main()
{
    output();
}