

#include <iostream>

using namespace std;

struct Node
{
    int data ;
    Node *right;
    Node *left;
    Node *parent;

};


class BinarySearchTree
{
public :

    Node *root ;
    int Size = 0 ;

    BinarySearchTree()
    {
        root = NULL ;
    }

    Node* Search( Node *node , int value )
    {

        if( (node->right != NULL && value > node->data) )
        {
            node = Search ( node->right , value );
        }

        if( (node->left != NULL && value < node->data) )
        {
            node = Search ( node->left , value );
        }


        return node;
    }

    void add( int data )
    {
        Node *newN = new Node ;
        newN->data = data ;
        newN->left = newN->right = newN->parent = NULL ;
        Insert( root , newN ) ;
    }


    void Insert( Node *node , Node *newNode )
    {
        Size++;

        if( root == NULL )
        {
            root = newNode ;
        }
        else if( newNode->data  > node->data  )
        {
            if (node->right != NULL)
                Insert( node->right , newNode );
            else
            {
                node->right = newNode;
                newNode->parent = node;
            }
        }
        else
        {
            if (node->left != NULL)
                Insert( node->left , newNode );
            else
            {
                node->left = newNode;
                newNode->parent = node;
            }
        }

    }

    void left_right( Node *node )
    {
        Node* curr = node->left ;

        while( curr->right != NULL ) /// get last right
            curr = curr->right ;

        swap( node->data , curr->data ) ;

        if( curr->parent->left != NULL && curr->parent->left->data == curr->data ) /// if there was no right
        {
            if( curr->left != NULL )
            {
                curr->parent->left = curr->left ;
                curr->left->parent = curr->parent ;
            }
            else
                curr->parent->left = NULL ;
        }
        else /// if last right
        {
            if( curr->left != NULL ) /// if there is left tree to the last right
            {
                curr->data = curr->left->data ;
                curr = curr->left ;
                curr->parent->left = NULL ;
            }
            else
                curr->parent->right = NULL ;
        }

        delete curr ;
    }

    void right_left( Node *node )
    {
        Node* curr = node->right ;

        while( curr->left != NULL ) /// get last left
        {
            curr = curr->left ;
        }

        swap( node->data , curr->data ) ;

        if( curr->parent->right != NULL && curr->parent->right->data == curr->data ) /// if there was no left
        {
            if( curr->right != NULL )
            {
                curr->parent->right = curr->right ;
                curr->right->parent = curr->parent ;
            }
            else
                curr->parent->right = NULL ;
        }
        else /// if last left
        {
            if( curr->right != NULL ) /// if there is right tree to the last left
            {
                curr->data = curr->right->data ;
                curr = curr->right ;
                curr->parent->right = NULL ;
            }
            else
                curr->parent->left = NULL ;
        }

        delete curr ;

    }

    void Delete( Node *node )
    {
        Node *P = node->parent ;

        if( node->right != NULL ) /// right then last left
        {
            right_left( node );
        }

        else if( node->left != NULL ) /// left then last right
        {
            left_right( node );
        }
        else /// if it was a leaf
        {
            if( P == NULL )
                root = NULL;
            else if( P->right != NULL && P->right->data == node->data )
                P->right = NULL ;
            else
                P->left = NULL ;

            delete node ;
        }

    }

    void Print( Node *node ) /// in order
    {
        if( node->left != NULL )
            Print( node->left );

        cout << node->data << endl;

        if( node->right != NULL )
            Print( node->right );
    }

};

int main()
{
    BinarySearchTree Tree ;
    int arr[7] = { 5 , 3 ,7 ,2 ,9 ,1 ,10 };

    for(int i=0 ; i<7 ; i++ )
    {
        Tree.add( arr[i] );
    }

    Tree.Print( Tree.root );


}
