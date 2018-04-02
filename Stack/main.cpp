#include <iostream>

using namespace std;

template < class t >
struct Node
{
    t data ;
    Node * prev;
};

template < class t >
class Stack
{
    private :
        Node<t> *head ;
        int Size =0;
    public :
        Stack()
        {
            head=NULL;
        }
        void pushs(t value)
        {
            Node<t>* current = head ;
            Node<t>* NewNode = new Node <t> ;
            NewNode->data = value ;
            NewNode->prev =current;
            head = NewNode;
            Size++;
        }

        t Front()
        {
            return head->data ;
        }

        void pops()
        {
            Node<t>* NewNode = new Node <t> ;
            NewNode=head;
            head = head -> prev ;
            Size-- ;
            delete NewNode;
        }

        void print ()
        {
            Node<t>* current = head;
            while (current != NULL)
            {
                cout<<current->data <<" " ;
                current =current->prev ;
            }

        }

        bool isempty()
        {
            if (head == NULL)
                return 1;

            else
                return 0 ;
        }

        int getSize()
        {
            return Size ;
        }
};

int main()
{
    Stack<char> y ;
    string s ;
    string pu ="{";
    string po ="}";
    cin>>s ;
    char ch ;

    for(int i =0 ; i< s.size() ; i++)
    {

        if(s[i]== '{')
            y.pushs(s[i]);

        else if (s[i]=='}')
        {
            if( y.isempty())
                cout<<"invalid"<<endl;

            else
                y.pops();
        }


    }

    y.print();
    cout<< y.getSize();
    return 0;
}




