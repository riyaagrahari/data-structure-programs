#include<iostream>
#include<cstdlib>
using namespace std;
template <class t>
class node
 {
   public:
   t info;
   node <t> * link;
};
template <class t>
class linklist
{
node <t> *first;
public:
linklist()
{
 first=NULL;
}
void create(t x)
{
 node <t> *temp=new node <t>;
 temp->info=x;
 temp->link=NULL;
 if(first==NULL)
 {
   first=temp;
   first->link=NULL;
 }
 else
 {
  temp->link=first;
  first=temp;
 }
}
void display()
{
  int i=1;
  node <t> *temp=new node <t>;
  temp=first;
  while(temp!=NULL)
  {
   cout<<"\nInfo at Node"<<i<<":"<<temp->info;
   temp=temp->link;
    i++;
  }
}
void insert(t x)
{
 node <t> *newnode=new node <t>;
 node <t> *temp;
 temp=first;
 newnode->info=x;
 while((temp->info)!=35)
 {
   temp=temp->link;
 }
  newnode->link=temp->link;
  temp->link=newnode;
 }
 void del(t x)
 {
   node <t> *temp;
 temp=first;
 while((temp->link->info)!=x)
    {
      temp=temp->link;
     }
  temp->link=temp->link->link;
temp=temp->link;
  free(temp); 
 }
};


int main()
{
  linklist<float>l1;
  l1.create(15);
  l1.create(25);
  l1.create(35);
  l1.create(45);
  l1.display();
  l1.insert(30);
  cout<<"\nNode after insertion:\n";
  l1.display();
  l1.del(25);
  cout<<"\nNode after deleton:\n";
  l1.display();
return 0;
}
