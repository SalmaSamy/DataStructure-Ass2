#include <bits/stdc++.h>

using namespace std;

template <typename ValueType>
class Set
{

    int siz;
    int *mySet;

    public :

        Set() : siz(0) , mySet( new ValueType[0] ){}
        ~Set() { delete[] mySet ; siz = 0 ; }

        int size() const
        {
            return siz;
        }
        bool isEmpty() const
        {
            return (siz == 0) ;
        }
        void clear()
        {
            delete[] mySet , siz = 0 ;
        }

        ////////////////////

        void insert(const ValueType& value)
        {
            for( int i=0,j=0 ; i<siz ; i++)
            {
                if( mySet[i] == value ) return ;
            }

            ValueType *tmp = new ValueType[siz];

            for(int i=0 ; i<siz ; i++) tmp[i] = mySet[i];
            delete[] mySet ;

            mySet = new ValueType[++siz];

            for(int i=0 ; i<siz-1 ; i++) mySet[i] = tmp[i];
            delete[] tmp ;

            mySet[siz-1] = value;

            sort( mySet , mySet+siz);
        }

        void remove(const ValueType& value)
        {
            ValueType *tmp = new ValueType[--siz];

            for( int i=0,j=0 ; i<siz+1 ; i++)
            {
                if( mySet[i] != value ) tmp[j++] = mySet[i];
            }
            delete[] mySet ;

            mySet = new ValueType[siz];

            for(int i=0 ; i<siz ; i++) mySet[i] = tmp[i];
            delete[] tmp ;

        }

        bool contains (const ValueType& value) const
        {
            ValueType x = value ;

            for( int i=0 ; i<siz ; i++)
            {
                if( mySet[i] == x ) return 1;
            }
            return 0 ;
        }

        bool isSubsetOf( const Set& set2) const
        {
            for(int i=0,j=0 ; i<set2.size() ; i++)
            {
                if( set2.mySet[i] == mySet[j] )
                {
                    j++;
                    if( j == siz ) return 1;
                }
            }
            return 0 ;
        }

        bool operator== (const Set& set2) const
        {
            if( siz != set2.siz ) return 0 ;

            for(int i=0 ; i<siz ; i++)
            {
                if( mySet[i] != set2.mySet[i])
                    return 0;
            }

            return 1 ;
        }

        bool operator!= (const Set& set2) const
        {
            if( siz != set2.siz ) return 1 ;

            for(int i=0 ; i<siz ; i++)
            {
                if( mySet[i] != set2.mySet[i])
                    return 1;
            }

            return 0 ;
        }

        //////////////////////

        Set operator+ (const Set& set2) const ///Union
        {
            Set <ValueType> unionSet ;

            for( int i=0 ; i<siz ; i++)
            {
                unionSet.insert(mySet[i]) ;
            }
            for( int i=0 ; i<set2.siz ; i++)
            {
                unionSet.insert(set2.mySet[i]) ;
            }

            return unionSet ;

        }

        Set operator-(const Set& set2) const ///subtraction
        {
            Set <int> subtractedSet ;

            for( int i=0 ; i<siz ; i++)
            {
                int ch = 0 ;
                for(int j=0 ; j<set2.siz ; j++)
                {
                     if( set2.mySet[j] == mySet[i] )
                     {
                         ch++;
                         break;
                     }
                }
                if( !ch ) subtractedSet.insert(mySet[i]) ;
            }

            return subtractedSet;
        }

        Set operator* (const Set& set2) const ///Intersection
        {
             Set <int> intersectionSet ;

            for( int i=0 ; i<siz ; i++)
            {
                for(int j=0 ; j<set2.siz ; j++)
                {
                     if( set2.mySet[j] == mySet[i] )
                     {
                         intersectionSet.insert(mySet[i]) ;
                         break;
                     }
                }
            }

            return intersectionSet;
        }

        Set operator= (const Set& set2) const
        {
             Set <int> newSet ;

            for( int i=0 ; i<set2.siz ; i++)
            {
                newSet.insert( set2.mySet[i]) ;
            }

            return newSet;
        }

        //////////////////////

        friend ostream &operator<<(ostream &out, const Set& set2)
        {
            for(int i=0 ; i<set2.siz ; i++)
            {
                out << set2.mySet[i] << " ";
            }

            return out;
        }


};


int main()
{
    Set<int> set1;
    for(int i=0 ; i<10 ; i++) set1.insert(i);

    Set<int> set2;
    for(int i= 8 ; i<15 ; i++) set2.insert(i);

    Set<int> set3;
    set3.insert(11);
    set3.insert(14);

    ////////////////////

    cout << (set1.contains(6) ? "Yes\n" : "No\n" ); /// yes
    cout << (set1.contains(100) ? "Yes\n" : "No\n" ); /// no

    cout << ( set1 == set2 ? "Yes\n" : "No\n" ); /// no
    cout << ( set1 != set2 ? "Yes\n" : "No\n" ); /// yes
    cout << ( set3.isSubsetOf( set2) ? "Yes\n" : "No\n" ) ; /// yes

    ////////////////////

    cout << "\n\n/////////////////\nSet1 Before Removing: ";
    cout << set1;

    set1.remove(2);
    set1.remove(5);

    cout << "\n\nSet1 After Removing(2,5): ";
    cout << set1;

    ////////////////////

    Set<int>set4 = set1+set2 ;
    Set<int>set5 = set1*set2 ;
    Set<int>set6 = set1-set2 ;

    cout << "\n\n/////////////////\n\nSet1: ";
    cout << set1;
    cout << "\n\nSet2: ";
    cout << set2;

    cout << "\n\nSet4 (Union): ";
    cout << set4;
    cout << "\n\nSet5 (intersection): ";
    cout << set5;
    cout << "\n\nSet6 (subtraction): ";
    cout << set6;

    ///////////////////

    cout << endl << endl;
    cout << (set1.isEmpty() ? "Yes\n" : "No\n" ); /// no
    set1.clear();
    cout << (set1.isEmpty() ? "Yes\n" : "No\n" ); /// yes


}
