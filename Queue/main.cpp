#include <bits/stdc++.h>

using namespace std ;

template<class T >
struct Node
{
    T data ;
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

        void push( T data )
        {
            Node<T>* newNode = new Node<T> ;
            newNode->data = data ;
            newNode->next = NULL ;

            Node<T> *current = head ;

            siz++;
            if( head == NULL )
            {
                head = newNode ;

                return ;
            }

            while( current->next != NULL)
            {
                current = current->next ;
            }

            current->next = newNode ;
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

        void print()
        {

            Node<T> *current = head ;

            while( current != NULL )
            {
                cout << current->data << " " ;
                current = current->next ;
            }

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
    Queue<char> myQueue;

    string s = "[[[<Sd/*[*/[][]]}" ;

    for(int i=0 ; i<s.size() ; i++)
    {
        if( s[i] == '[' )
            myQueue.push(s[i]) ;


        if( s[i] == ']' )
        {
            if( !myQueue.isEmpty() )
                myQueue.pop();
        }
    }


    cout << myQueue.Size() << endl;

    myQueue.print() ;


}
