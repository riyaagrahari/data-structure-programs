#include<iostream>
using namespace std;
 
class queue
{
public:
int data;
class  queue *next;
class queue *prev;
};
 
class dqueue: public queue
{
  queue *head,*tail;
  int top1,top2;
  public:
   dqueue()
   {
   top1=0;
   top2=0;
   head=NULL;
   tail=NULL;
   }
  void push(int x){
	queue *temp;
	int ch;
	if(top1+top2 >=5)
	{
	  cout <<"dqueue overflow";
	  return ;
	}
	if( top1+top2 == 0)
	  {
	    head = new queue;
	    head->data=x;
	    head->next=NULL;
	    head->prev=NULL;
	    tail=head;
	    top1++;
	  }
	 else
	 {
	   cout <<" Add element 1.FIRST 2.LAST\n enter ur choice:";
	   cin >> ch;
 
 
	   if(ch==1)
	   {
	     top1++;
	     temp=new queue;
	     temp->data=x;
	     temp->next=head; 
	     temp->prev=NULL;
	     head->prev=temp;
	     head=temp;
	   }
	   else
	   {
	     top2++;
	     temp=new queue;
	     temp->data=x;
	     temp->next=NULL;
	     temp->prev=tail;
	     tail->next=temp;
	     tail=temp;
	   }
 
	 }
  }
  void pop()
  {
   int ch;
   cout <<"Delete 1.First node 2.Last Node\n Enter ur choice:";
   cin >>ch;
   if(top1 + top2 <=0)
   {
     cout <<"\nDqueue under flow";
     return;
   }
   if(ch==1)
   {
     head=head->next;
     head->prev=NULL;
     top1--;
   }
   else
   {
     top2--;
     tail=tail->prev;
     tail->next=NULL;
   }
  }
 
  void display()
  {
   int ch;
   queue *temp;
   cout <<"display from 1.Staring 2.Ending\n Enter ur choice";
   cin >>ch;
   if(top1+top2 <=0)
   {
     cout <<"under flow";
     return ;
   }
   if (ch==1)
   {
    temp=head;
    while(temp!=NULL)
    {
      cout << temp->data <<" ";
      temp=temp->next;
    }
   }
   else
   {
    temp=tail;
    while( temp!=NULL) 
    {
      cout <<temp->data << " ";
      temp=temp->prev;
    }
   }
    }
  };
 
  main()
  {
    dqueue d1;
    int ch;
    while (1){
	cout <<"1.INSERT  2.DELETE  3.DISPLAY  4.EXIT\n Enter ur choice:";
    cin >>ch; 
    switch(ch)
    {
    case 1:     cout <<"enter element";
		cin >> ch;
		d1.push(ch); break;
    case 2: d1.pop(); break;
    case 3: d1.display(); break;
    case 4: exit(1);
    }
  }}
