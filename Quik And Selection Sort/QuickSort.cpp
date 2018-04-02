#include "QuickSort.h"
#include <bits/stdc++.h>

using namespace std ;

QuickSort::QuickSort()
{

}

QuickSort::~QuickSort()
{

}

int *QuickSort:: Sort(int arr[],int Size)
{   // time_t start;
    //start = time(&start);
    //cout<<"Time before sorting1 "<<endl;
    // cout <<start<<endl;
    int *arr1;
    arr1 = new int[Size];
    arr1= QSort( arr, 0, Size);
    //cout<<"Time after sorting1 "<<endl;
    //start = time(&start) - start;
    //cout <<start<<endl;
    return arr1 ;
}

int *QuickSort:: ReverseSort(int arr[],int Size)
{
    int *arr1;
    arr1 = new int[Size];
    arr1= QSortRverse( arr, 0, Size);
    return arr1 ;
}

int * QuickSort:: QSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap (arr[j], arr[i]);
            i++;
            j--;
        }
    }
    if (left < j)
        QSort(arr, left, j);
    if (i < right)
        QSort(arr, i, right);

    return arr;
}

int * QuickSort:: QSortRverse(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;
        if (i <= j)
        {
            swap (arr[j], arr[i]);
            i++;
            j--;
        }
    }
    if (left < j)
        QSortRverse(arr, left, j);
    if (i < right)
        QSortRverse(arr, i, right);

    return arr;

}
