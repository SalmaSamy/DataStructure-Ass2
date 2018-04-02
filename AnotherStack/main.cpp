#include <bits/stdc++.h>

using namespace std;

template < class t >
struct Node
{
    t data ;
    Node * prev;
    Node * next;
};

template < class t >
class Stack
{
    private :

        Node<t> *head ;
        int Size = 0;

    public :

        Stack()
        {
            head = NULL;
        }

        void push(t data)
        {
            Node<t>* newNode = new Node<t> ;
            newNode->data = data ;
            newNode->next = NULL ;

            Node<t> *current = head ;

            Size++;
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
            newNode->prev = current ;
        }

        t top()
        {
            Node<t>* current = new Node <t> ;
            current = head;

            while( current->next != NULL)
            {
                current = current->next ;
            }

            return current->data ;
        }

        void pop()
        {
            Node<t>* current = new Node <t> ;
            current = head;

            if( head == NULL ) return ;

            while( current->next != NULL)
            {
                current = current->next ;
            }

            current->prev->next = NULL ;
            Size-- ;

            delete current;
        }

        bool isEmpty()
        {
            return head == NULL ;
        }

        int getSize()
        {
            return Size ;
        }

        void Clear()
        {
            head = NULL ;
        }
};

int main()
{
    Stack<int>s;
    s.push(4);
    s.push(5);
    s.push(7);

    s.Clear();
    cout << s.isEmpty() ;

}




