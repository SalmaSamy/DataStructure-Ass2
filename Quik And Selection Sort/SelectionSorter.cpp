#include "SelectionSorter.h"
#include <bits/stdc++.h>

using namespace std ;
SelectionSorter::SelectionSorter()
{
}

SelectionSorter::~SelectionSorter()
{
}


int *SelectionSorter::Sort(int arr[], int Size)
{
    for(int i =0 ; i <Size ; i++)
    {
        int smallestnumber=arr[i];
        int smallestnumberindex=i;

        for(int j=i+1 ; j<Size ; j++)
        {
            if(arr[i]>arr[j])
            {
                smallestnumber=arr[j];
                smallestnumberindex=j;
                swap(arr[i],arr[smallestnumberindex]);
            }
        }


    }

    return arr;
}


int *SelectionSorter::ReverseSort(int arr[], int Size)
{
    for(int i =0 ; i <Size ; i++)
    {
        int graestnumber=arr[i];
        int gretnumberindex=i;

        for(int j=i+1 ; j<Size ; j++)
        {
            if(arr[i]<arr[j])
            {
                graestnumber=arr[j];
                gretnumberindex=j;
                swap(arr[i],arr[gretnumberindex]);
            }
        }


    }

    return arr;
}
