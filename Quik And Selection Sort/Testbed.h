#ifndef TESTBED_H
#define TESTBED_H
#include "QuickSort.h"
#include "SelectionSorter.h"
#include <bits/stdc++.h>

using namespace std ;
class Testbed
{
    public:
        Testbed();
        virtual ~Testbed();
        int* GenerateRandomList(int Min,int Max,int Size);
        int* GenerateReverseOrderedList(int Min, int Max, int Size);
        double RunOnce(Sorter*,int* data, int Size);
        double RunAndAverage(Sorter*,int type,int Min,int Max,int Size,int  sets_num);
        void RunExperient (Sorter* , int type,int Min,int Max,int min_val,int max_val,int sets_num,int step);

    protected:

    private:
        QuickSort so;
        int *arr;
};

#endif // TESTBED_H
