#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sorter.h"

class QuickSort:public Sorter
{
    public:
        QuickSort();
        virtual ~QuickSort();
        int* Sort(int arr[],int Size) override;
        int* QSort(int arr[], int left, int right);
        int* ReverseSort(int arr[],int Size);
        int* QSortRverse(int arr[], int left, int right);


    protected:

    private:
};

#endif // QUICKSORT_H
