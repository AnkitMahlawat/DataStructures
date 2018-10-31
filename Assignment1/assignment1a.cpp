////////////////////////////////////////////////////////////
//   IMPLEMENTATION OF QUEUE USING TEMPLATE               //
////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class T>      
class queue {
		 int front,n,rear;         // HIDDEN DATA MEMBERS  
		 T *a;
	int full()                         //HIDDEN MEMBER FUNCTION BEING CALLED FROM ENQUEUE
	{ if(rear==n-1)
	  return 1;
	  else
	  return 0;
	}

	int empty()                        //HIDDEN MEMBER FUNCTION BEING CALLED FROM DEQUEUE
	{if(front==rear)
	  return 1;
	else 
	  return 0;
	}

	public:

	queue(int z)                        //PARAMETERISED CONSTRUCTOR PROVIDING INITIAL VALUES TO OBJECT OF QUEUE TYPE
	{front=-1;
	rear=-1;
	n=z;
	a=new T[z];
	}

	void enqueue(T x)                   //THIS FUNCTION INSERTS ELEMENT INTO QUEUE
	{ if(full()==0)
	  { rear++;
	    a[rear]=x;
	  }
	  else
	  cout<<"OVERFLOW!!! QUEUE IS FULL\n";
	}

	void dequeue()                     //THIS FUNCTION DELETES ELEMENT FROM QUEUE
	{ if(empty()==0)
	  {front++;
	   a[front]=0;
	 }
	 else
	  cout<<"UNDERFLOW!!! QUEUE IS EMPTY\n";
	}

	void output()                       // THIS FUNCTION SHOWS THE ELEMENT IN THE QUEUE
	{int i;
	for(i=front+1;i<=rear;i++)
		{cout<<a[i]<<" ";}
		cout<<"\n";
	}

};

int main()
{ int ch,n,x;
  char k,m;
 do{ cout<<"ENTER YOUR CHOICE OF DATA TYPE\n";
  cout<<"\t PRESS 1 FOR INT DATA TYPE\n";
  cout<<"\t PRESS 2 FOR FLOAT DATA TYPE\n";
  cout<<"\t PRESS 3 FOR CHAR DATA TYPE\n";
  cin>>ch;
  cout<<"ENTER THE SIZE OF QUEUE\n";
  cin>>n;

  switch(ch)
  { case 1: {queue <int>q1(n);                                   //QUEUE HAVING INT AS DATA TYPE
             do{ 
                cout<<"ENTER YOUR CHOICE:\n1.ENQUEUE\n2.DEQUEUE\n3.OUTPUT\n";
                cin>>x;
                switch(x)
                {  case 1: { int e;
                            cout<<"ENTER THE ELEMENTS\n";
                            cin>>e;
                            q1.enqueue(e);
                            break;}
                  case 2:{ q1.dequeue();
                          break;
                         }
                  case 3:{ q1.output();
                           break;}
                  default : {cout<<"YOU HAVE ENTERED WRONG CHOICE\n";
                            break;}
                }
               cout<<"DO YOU WANT TO IMPLEMENT QUEUE AGAIN WITH SAME DATA TYPE(y/n)";
               cin>>k;
              }while((k=='Y')||(k=='y'));
              break;
             }
    case 2: {queue <float>q2(n);                                    //QUEUE HAVING FLOAT AS DATA TYPE
            do{ 
                cout<<"ENTER YOUR CHOICE:\n1.ENQUEUE\n2.DEQUEUE\n3.OUTPUT\n";
                cin>>x;
                switch(x)
                {  case 1: { float e;
                            cout<<"ENTER THE ELEMENTS\n";
                            cin>>e;
                            q2.enqueue(e);
                            break;}
                  case 2:{ q2.dequeue();
                          break;
                         }
                  case 3:{ q2.output();
                           break;}
                  default : {cout<<"YOU HAVE ENTERED WRONG CHOICE\n";
                            break;}
                }
               cout<<"DO YOU WANT TO IMPLEMENT QUEUE AGAIN WITH SAME DATA TYPE(y\n)";
               cin>>k;
              }while((k=='Y')||(k=='y'));
              break;
             }

    case 3: {queue <char>q3(n);                                       // QUEUE HAVING CHAR AS DATA TYPE
            do{ 
                cout<<"ENTER YOUR CHOICE:\n1.ENQUEUE\n2.DEQUEUE\n3.OUTPUT\n";
                cin>>x;
                switch(x)
                {  case 1: { char e;
                            cout<<"ENTER THE ELEMENTS\n";
                            cin>>e;
                            q3.enqueue(e);
                            break;}
                  case 2:{ q3.dequeue();
                          break;
                         }
                  case 3:{ q3.output();
                           break;}
                  default : {cout<<"YOU HAVE ENTERED WRONG CHOICE\n";
                            break;}
                }
               cout<<"DO YOU WANT TO IMPLEMENT QUEUE AGAIN WITH SAME DATA TYPE(y\n)";
               cin>>k;
              }while((k=='Y')||(k=='y'));
              break;
             }

    default : {cout<<"YOU HAVE ENTERED A WRONG CHOICE\n"; return 0; }
  }
 cout<<"DO YOU WANT TO IMPLEMENT QUEUE WITH ANOTHER DATA TYPE(y/n)\n";
 cin>>m;
}while((m=='y')||(m=='Y'));
return 0;
}




