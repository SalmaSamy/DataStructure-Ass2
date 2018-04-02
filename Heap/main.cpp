#include <bits/stdc++.h>

using namespace std;

class Heap
{
    int *h ;
    int siz ;

    int rightCh( int x )
    {
        return x*2+1 ;
    }
    int leftCh( int x )
    {
        return x*2+2;
    }
    int parent( int x )
    {
        return x/2 ;
    }

    void heapUp()
    {
        int x = siz-1 ;
        while( x > 0 )
        {
            if( h[x] < h[parent(x)] )
            {
                swap( h[x] , h[parent(x)] );
            }
            x = parent(x);
        }
    }
    void heapDown()
    {
        int x = 0 ;
        while( rightCh(x) < siz && leftCh(x) < siz )
        {
            if( h[rightCh(x)] < h[x] && h[rightCh(x)] < h[leftCh(x)] )
            {
                swap( h[x] , h[rightCh(x)] );
                x = rightCh(x);
            }
            else if( h[leftCh(x)] < h[x] && h[leftCh(x)] < h[rightCh(x)] )
            {
                swap( h[x] , h[leftCh(x)] );
                x = leftCh(x);
            }
        }
    }

    public:

    Heap()
    {
        siz = 0 ;
        h = new int ;
    }

    int top()
    {
       if( siz > 0 )
        return h[0];
       else
        cout << "Heap is empty";
    }

    void push(int x)
    {
        int *tmp = new int[siz];

        for(int i=0 ; i<siz ; i++)
            tmp[i] = h[i];

        delete h ;

        h = new int[siz+1];

        for(int i=0 ; i<siz ; i++)
            h[i] = tmp[i];

        delete tmp ;

        h[siz++] = x ;

        heapUp();
    }

    void pop()
    {
        swap( h[0] , h[siz-1] ) ;

        int *tmp = new int[siz];

        for(int i=0 ; i<siz ; i++)
            tmp[i] = h[i];

        delete h ;

        h = new int[--siz];

        for(int i=0 ; i<siz ; i++)
            h[i] = tmp[i];

        delete tmp ;

        heapDown();

    }

    int size()
    {
        return siz ;
    }

    void print()
    {
       for( int i=0 ; i<siz ; i++ )
        cout << h[i] << " ";
       cout << endl;
    }

    void heapSort()
    {
        int *tmp = new int[ siz ];

        int index = 0 ;
        while (siz)
        {
            tmp[ index++ ] = h[0] ;
            pop();
        }
        for (int i=0 ; i<index ; i++)
        {
            push(tmp[i]);
        }

        delete tmp ;
    }
    ~Heap()
    {
        delete h ;
    }

};

int main()
{
    Heap h;
    h.push(3);
    h.push(5);
    h.push(2);
    h.push(10);
    h.push(0);
    h.push(1);
    h.push(11);
    h.push(20);
    h.push(12);
    h.push(0);

    h.print();

    h.pop();
    h.pop();
    h.print();

    h.heapSort();
    h.print();


}
