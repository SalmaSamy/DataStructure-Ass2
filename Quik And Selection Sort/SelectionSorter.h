#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H
#include "Sorter.h"


class SelectionSorter:public Sorter
{
    public:
        SelectionSorter();
        virtual ~SelectionSorter();
        int *Sort(int arr[], int Size)override;
        int *ReverseSort(int arr[], int Size);


    protected:

    private:
};

#endif // SELECTIONSORTER_H
