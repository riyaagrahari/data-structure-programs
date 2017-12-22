#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class linked
{
struct node
{
    T info;
    struct node *link;
};
struct node *first;
public:
linked()
{
	first=NULL;
}
void insert(T n);
void delete1(int a);
void traverse();
};
template<class T>
void linked<T>::insert(T n){
	
	 node *ptr,*cpt,*tpt;
    int i,m;
    ptr = (struct node*) malloc(sizeof(struct node));
   
    cout<<"Enter the position of term "<<endl;
    cin>>m;
    cpt=first;
    if ( m == 0 )
    {
        ptr->info=n;
        ptr->link=first;
        first = ptr;
    }
    else
    {
        for(i=1;i<m-1;i++)
        {
            cpt=cpt->link;
        }
        ptr->info = n;
        ptr->link = cpt->link;
        cpt->link = ptr;
    }
	
}

void linked<T>::traverse()
{
    struct node *ptr;
    ptr = first;
    cout<<"Traversing of list is "<<endl;
    while (ptr->link != NULL )
    {
        cout<<ptr->info<<endl;
        ptr = ptr->link;
    }
     cout<<ptr->info<<endl;
}


void  linked<T>::delete1(int a)
{
    struct node *cpt,*tpt;
    int i;
    
    
    cpt=first;
    if ( a ==0 )
    {
        first = cpt->link;
        free(cpt);
    }
    else
    {
        for(i=1;i<a-1;i++)
        {
            cpt=cpt->link;
        }
        tpt=cpt->link;
        cpt->link=cpt->link->link;
        free(tpt);
    }
}

int main()
{
    int n,i;
    
         linked<int>T;
        T.insert(2);
        T.insert(3);
        T.insert(14);
        T.insert(10);
        T.traverse();
        T.delete1(0);//position of element is passed 
        T.delete1(1);//position of element is passed
        T.traverse();
       return 0;
}





