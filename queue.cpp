 #include<iostream>
 #include<conio.h>
 using namespace std;
 #define MAX 10
 template <class T>
 class queue
 {
  T Q[MAX];
  int front,rear;
  public:
  void def()
  {
  front=rear=-1;
  }
  void insert(T ch);
  T delete1();
 };
 
 template <class T>void queue<T>::insert(T item)
 {
  if (rear>=MAX)
  {
  cout << "Queue is full\n";
  return;
  }
  if(front==-1)
   front++;
  Q[++rear] = item;//inserting the item in the Que
 }

 template <class T>T queue<T>::delete1()
 {
  T val;
  if((front==-1)||(front>rear))
  {
  cout << "Queue is empty\n";
  return 0; // return null on empty stack
  }
  val= Q[front];//item to be deleted
  front++;
  return val;
 }

 int main()
 {
  queue <char> ob1;
  queue <int> ob2;
  int i;  
  ob1.def();
  ob2.def();
  ob1.insert('p');
  ob1.insert('q');
  ob1.insert('r');
  ob2.insert(10);
  ob2.insert(20);
  ob2.insert(30);
  cout << "Delete from Queue of characters: "<<endl;
  for (i=0; i<3; i++)
   cout<<"  "<<ob1.delete1() << "\n";
  cout << "Delete from Queue of integers: "<<endl;
  for (i=0; i<3; i++)
   cout<<"  "<<ob2.delete1() << "\n";

  queue <double> ob3;
  ob3.def();
  ob3.insert(1.1);
  ob3.insert(1.2);
  cout << "Delete from Queue of doubles: "<<endl;
  for (i=0; i<2; i++)
  cout<<"  "<<ob3.delete1() << "\n";
  getch();
  return 0;
 }
