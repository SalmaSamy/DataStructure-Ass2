#include <bits/stdc++.h>

using namespace std;


class node
{
    private:
        int data;

    public:

        node* next;

        node() {}
        ~node() {}

        int getData()
        {
            return data;
        }
        void setData( int d )
        {
            data = d;
        }

};

class LinkedList
{
    private:
        node *head;
        int siz = 0 ;

    public:

        LinkedList() { head = NULL; }
        int Length(){ return siz; }
        ~LinkedList() {}


        void InsertForword( int n )
        {
            node *tmp = new node;
            tmp->setData(n);
            tmp->next = head;
            head = tmp;
            siz++;
        }

        void InsertBackword( int n )
        {
            node *tmp = new node;
            tmp->setData(n);
            tmp->next = NULL;

            if( head == NULL ) /// why node head needs exception !?
            {
                head = tmp ;
                siz++;
                return ;
            }

            node *current = head;
            while( current->next != NULL )
            {
                current = current->next;
            }
            current->next = tmp ;

            siz++;

        }

        void Delete( int n )
        {
            if( head == NULL ) return ;

            int ch = 0 ;
            node *current = head ;

            while( current->next != NULL )
            {
                if( current->getData() == n || current->next->getData() == n)
                {
                    ch++ ;
                    break;
                }
                current = current->next ;

            }

            if(ch && current == head ) head = head->next , siz-- ;
            else if(ch) current->next = current->next->next , siz-- ;
        }

        void PrindList()
        {
            node *current = head;
            while( current != NULL )
            {
                cout << current->getData() << " ";
                current = current->next ;
            }
        }


};

int main()
{
    LinkedList L;
    L.InsertBackword(4);
    L.InsertBackword(5);
    L.InsertBackword(6);
    L.InsertForword(3);
    L.InsertForword(2);
    L.InsertForword(1);
    L.Delete(3);
    L.Delete(6);

    L.Delete(3);  /// deleting  no existing element
    L.Delete(1); /// deleting the first element

    cout << L.Length() << endl;
    L.PrindList();

}
