#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

int LOC1=1,LOC2=2;

void FIND(int DATA[],int N)
{
    int FIRST,SECOND;
    FIRST=DATA[1];
    SECOND=DATA[2];
    if(FIRST<SECOND)
    {
        swap(FIRST,SECOND);
        swap(LOC1,LOC2);
    }
    for(int K=3;K<=N;K++)
    {
        if(FIRST<DATA[K])
        {
            SECOND=FIRST;
            FIRST=DATA[K];
            LOC2=LOC1;
            LOC1=K;
        }
        else if(SECOND<DATA[K])
        {
            SECOND=DATA[K];
            LOC2=K;
        }
    }
    return;
}

int main()
{
    int N;
    //vector<int>DATA(N);
    /*int x=15;
    //int y=x/4;
    //cout<<y<<endl;
    cout<<ceil(x/4)<<endl;*/

    int DATA[100000];
    cin>>N;
    //N=100000;
    time_t start,end;

    start=clock();

    for(int i=1;i<=N;i++)
    {
        //DATA[i]=rand();
        cin>>DATA[i];
    }
    FIND(DATA,N);

    end=clock();

    double time=((double)end-start)/CLOCKS_PER_SEC;

    cout<<"LOC1 = "<<LOC1<<"\tDATA = "<<DATA[LOC1]<<endl;
    cout<<"LOC2 = "<<LOC2<<"\tDATA = "<<DATA[LOC2]<<endl;

    cout<<"start = "<<start<<endl;
    cout<<"end = "<<end<<endl;

    cout<<"time = "<<time<<endl;

    cout<<"sizeof time_t = "<<sizeof(time_t)<<endl;

    return 0;
}
