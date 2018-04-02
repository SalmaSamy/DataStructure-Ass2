#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
    stack<T> st1 , st2 ;

public:

    Queue<T>() {}

    void Enqueue( T value )
    {
        if( st1.empty() )
        {
            st1.push(value);
            return ;
        }

        for(int i=0 ; i<st1.size() ; i++)
        {
            T x = st1.top() ;
            st2.push( x );
            st1.pop();
            i--;
        }

        st1.push(value);

        for(int i=0 ; i<st2.size() ; i++)
        {
            T x = st2.top() ;
            st1.push( x );
            st2.pop();
            i--;
        }

    }

    void Dequeue()
    {
        st1.pop();
    }
    bool isEmpty()
    {
        return st1.empty();
    }
    int Size()
    {
        return st1.size();
    }
    void Clear()
    {
        for(int i=0 ; i<st1.size() ; i++)
        {
            st1.pop();
        }
    }
    T First()
    {
        return st1.top();
    }

};

int main()
{
    Queue<int> Q;

    for(int i=1; i<=10 ; i++)
        Q.Enqueue(i);


    Q.Dequeue();
    cout << Q.Size() << endl;

    for(int i=0 ; i<Q.Size()-1 ; i++)
    {
        cout << Q.First() << " " ;
        Q.Dequeue();
        i--;
    }

    cout << endl << Q.Size() << endl;

    Q.Clear();
    cout << Q.isEmpty() ;
}
