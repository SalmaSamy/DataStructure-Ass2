#include <bits/stdc++.h>

using namespace std ;

template<class T >
struct Node
{
    T data ;
    int priority ;
    Node *next ;

};

template<class T >
class Queue
{
    private :
        Node<T> *head ;
        int siz = 0 ;

    public:

        Queue()
        {
            head = NULL;
        }

        void push( T value , int pr )
        {
            Node<T>* newNode = new Node<T> ;
            newNode->data = value ;
            newNode->priority = pr ;

            siz++;
            if( head == NULL )
            {
                head = newNode ;
                return ;
            }

            Node<T> *current = head ;

            while( current->next != NULL && current->next->priority > pr )
            {
                current = current->next ;
            }

            if( current->priority < pr )
            {
                newNode->next = head ;
                head = newNode ;
            }
            else
            {
                newNode->next = current->next;
                current->next = newNode ;
            }
        }

        T top()
        {
            return head->data ;
        }

        void pop()
        {
            head = head->next ;
            siz-- ;
        }

        bool isEmpty()
        {
            return head == NULL ;
        }

        int Size()
        {
            return siz ;
        }

};

int main()
{
    Queue<int> pQueue;

    for(int i=1 ; i<=5 ; i++)
    {
        pQueue.push(i,i);
    }

    cout << pQueue.Size() << endl;

    for(int i=0 ; i<pQueue.Size() ; i++)
    {
        cout << pQueue.top() << " " ;
        pQueue.pop() ;
        i--;
    }

    cout << endl << pQueue.isEmpty() ;

}

