#include <iostream>
#include"Testbed.h"

using namespace std;

int main()
{
    Sorter *e;
    e= new SelectionSorter();
    Testbed test;
    int Min, Max, Size,sets_num,min_value,max_value,step ;

    int PairSize = ((max_value-min_value)/step)+1;
    pair <int,int> data[PairSize];

    cout <<"Enter Max Value in array and Min and Array Size  and number of arrays in arrange : "<<endl;
    cin>>Max>>Min>>Size>>sets_num>>min_value>>max_value>>step;

    //int *arr;
    //arr=new int [Size];
    //arr = test.GenerateRandomList(Min, Max, Size);

    // for(int i=0 ; i<Size ; i++)cout<<arr[i]<<" ";
    // cout <<endl;

    //arr=test.GenerateReverseOrderedList(Min , Max , Size);

    //test.RunOnce( e , arr , Size);
    //test.RunAndAverage(e,0,Min,Max,Size,sets_num);
    test.RunExperient(e,1,Min,Max,min_value,max_value,sets_num,step);

    return 0;
}
