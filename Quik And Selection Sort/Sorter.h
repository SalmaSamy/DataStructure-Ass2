#ifndef SORTER_H
#define SORTER_H
#include <bits/stdc++.h>

using namespace std ;

class Sorter
{
    public:
        Sorter();
        virtual ~Sorter();
        virtual int * Sort(int arr[], int Size)=0;
        virtual int *ReverseSort(int arr[], int Size)=0;

    protected:

    private:
};

#endif // SORTER_H
