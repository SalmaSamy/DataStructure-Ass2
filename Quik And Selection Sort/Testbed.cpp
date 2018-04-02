#include "Testbed.h"
#include <bits/stdc++.h>
#include "QuickSort.h"
#include "SelectionSorter.h"

using namespace std ;

Testbed::Testbed()
{

}

Testbed::~Testbed()
{

}

int *Testbed::GenerateRandomList(int Min,int Max,int Size)
{
    arr=new int [Size];
    int range = Max-Min + 1;
    srand(time(0));
    for(int i =0 ; i<Size ; i++)
    {
        arr[i]=rand()%range+Min;

    }

    /*cout<<"GenerateRandomList"<<endl;
    for(int i =0 ; i<Size ; i++)
    {
        cout<<arr[i]<<" " ;

    }
    cout<<endl;*/
    return arr;

}

int *Testbed::GenerateReverseOrderedList(int Min, int Max, int Size)
{
    arr=new int [Size];
    int range = Max-Min + 1;
    srand(time(0));
    for(int i =0 ; i<Size ; i++)
    {
        arr[i]=rand()%range +Min;

    }
    /*for(int i =0 ; i<Size ; i++)
    {
        cout<<arr[i]<<" " ;

    }
    cout<<endl;*/
    QuickSort sortred;

    arr = sortred.ReverseSort(arr, Size);

   /* cout<<"GenerateReverseOrderedList"<<endl;
    for(int i =0 ; i<Size ; i++)
    {
        cout<<arr[i]<<" " ;

    }
    cout<<endl;
    */return arr;
}


double Testbed::RunOnce(Sorter* e, int * data, int Size)
{
    time_t start,End;
    start=NULL;
    start = clock();
   // cout<<"Time before sorting "<<endl;
    //cout <<start<<endl;
    data= e->Sort(data, Size);
    //cout<<"Time after sorting "<<endl;
    End=NULL;
    End = clock();
   // cout<<End<<endl;
    //cout<<"Different Time before and after PER_MISEC"<<endl;
    //cout <<(double(End-start)/CLOCKS_PER_SEC)<<endl;
    cout<<fixed<<setprecision(5);

    double value = (double((End-start))) ;

return value;
}

double Testbed::RunAndAverage(Sorter* e,int type,int Min,int Max,int Size,int sets_num)
{
    double timee,sorttime,sum=0.0;
    arr = new int [Size];
    time_t start, End ;

    while(sets_num !=0)
    {
        if( !type )
            arr = GenerateRandomList(Min,Max,Size);
        else
            arr = GenerateReverseOrderedList(Min,Max,Size);

        sum+= RunOnce(e , arr ,Size);
        sets_num--;
    }
    cout<<fixed<<setprecision(5);
   // cout<<"\navarage sum :"<<sum<<endl;

return sum ;
}

void Testbed::RunExperient (Sorter* e, int type,int Min,int Max,int min_val,int max_val,int sets_num,int step)
{
    double sum=0.0;
    clock_t start, End ;
    int Size =min_val, counter=sets_num ,pair_counter=0;
    int PairSize = ((max_val-min_val)/step)+1;
    pair <double,double >data[PairSize];

    while(1)
    {
        sum=RunAndAverage( e,type, Min,Max,Size,sets_num);
        sum/=sets_num;
        sum/=1000;
        data[pair_counter].first=Size;
        data[pair_counter].second=sum;
        pair_counter++;

        Size+=step;
        if(Size>max_val)
            break;
    }

    for(int i=0 ;i<PairSize ;i++){
            cout<<fixed<<setprecision(5);
        cout<<data[i].first<< " "<< data[i].second <<endl;
    }

}
