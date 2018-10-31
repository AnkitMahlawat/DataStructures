//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//             STACK PERMUTATION              //
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
#include<iostream>
using namespace std;

// CLASS QUEUE 
class queue{
	int front,rear,n,*b;    /*HIDDEN DATA MEMBERS */
	public:

	queue(int z)            /* PARAMETERISED CONSTRUCTOR WHERE Z IS SIZE OF ARRAY *b */
	{	front=-1;
		 rear=-1;
		 n=z;
 		b=new int[n];   
	}

	void enqueue(int x)     /* ENQUEUE MEMBER FUNCTION OF QUEUE CLASS, INSERTING ELEMENT INTO QUEUE */ 
	{if(rear!=n)
 	  {
           rear++; 
           b[rear]=x;
          }
	}

	int dequeue()           /* DEQUEUE MEMBER FUNCTION OF QUEUE CLASS DELETING ELEMENT FROM QUEUE AND RETURNING THE DELETED ELEMENT */
        {
	if(front!=rear)
	{
          front++;
 	  int k;
          k=front;
          return b[k];          
        }
        }
    };

//CLASS STACK 
class stack{                    		         
	int top,n,*c;             /* HIDDEN DATA MEMBERS */
	public:

	stack(int z)               /* PARAMETERISED CONSTRUCTOR WHERE Z IS SIZE OF ARRAY *C */
	{
          top=-1;
	  n=z;
	  c=new int[n];
	}

	void push(int x)           /* PUSH MEMBER FUNCTION OF STACK CLASS, INSERTING ELEMENT INTO STACK */
	{ if(top!=n)
	  {top++;
	   c[top]=x;
	  }
	}

	int pop()                  /* POP MEMBER FUNCTION OF STACK CLASS, DELETES ELEMENT FROM STACK AND RETURN TO OUTPUT QUEUE */
	{ top--;
	  int k;
	  k=top+1;
	  return c[k];
	}
       int empty()
       {if(top==-1)
         return 1;
        else
          return 0;
        }
        
        int t()
      { return c[top];
      }
     };

int main()
{	int n;
	cout<<"ENTER THE SIZE OF QUEUE\n";
	cin>>n;
	int x,p,a[n];               /* HERE a[n] IS THE INPUT ARRAY PERMUTATION WHICH USER WANTS TO CHECK WITH THE OUTPUT QUEUE q2*/
	queue q1(n),q2(n);          /* HERE q1 IS THE INPUT QUEUE AND q2 IS THE OUTPUT QUEUE */
	stack s(n);                 /* STACK s CONTAINS THE ELEMENT WHICH ARE POPED FROM q1 AND WE DON'T THAT ELEMENT IN q2 AT ith ITERATION */

	cout<<"ENTER THE ELEMENTS\n";
	for(int i=0;i<n;i++)
	{ cin>>x;
	  q1.enqueue(x);
	}

	cout<<"ENTER THE PERMUTATION\n";
	for(int i=0;i<n;i++)
	{cin>>a[i];
	}

	int i=0,g=0,u;

	 for(int t=0;t<n;t++)                                              
	  {	p=q1.dequeue(); 
	  	if(p==a[i])
	   	{
		 q2.enqueue(p);i++;  /* DEQUEUED ELEMENT FROM q1 IS BEING ENQUEUED IN OUTPUT QUEUE q2 */  
         	 cout<<p<<" ELEMENT IS ENQUEUED INTO Q2 FROM Q1\n";
	   	}
               else {if(s.empty()==0) 
                     {u=s.t(); 
                  if(u==a[i])
                 { u=s.pop();n++;
                   q2.enqueue(u);g--;i++;
                 }                
                 
          
 		else   		
		{ s.push(p);g++;      /* DEQUEUED ELEMENT FROM q1 IS BEING PUSHED IN THE STACK FOR THE TIME BEING */
	  	 cout<<p<<" ELEMENT IS ENQUEUED INTO STACK FROM Q1\n";
		}
                 }
               else
                { s.push(p);g++;      /* DEQUEUED ELEMENT FROM q1 IS BEING PUSHED IN THE STACK FOR THE TIME BEING */
                 cout<<p<<" ELEMENT IS ENQUEUED INTO STACK FROM Q1\n";
                }

   	 }}

	  while(g!=0)
	  {
		p=s.pop();           /* REST ALL ELEMENTS OF STACK IS BEING PUSHED TO OUTPUT QUEUE q2 AFTER INPUT QUEUE q1 IS EMPTY */
		if(p==a[i])
		{
		q2.enqueue(p);i++;g--;
                cout<<p<<" ELEMENT IS PUSHED FROM STACK TO Q2\n";
   		}
               else {
          cout<<"IT IS NOT A STACK PERMUTATION\nTHIS IS DUE TO BECAUSE AT "<<i+1<<" LOCATION OUTPUT QUEUE HAS "<<p<<" INSTEAD OF "<<a[i]<<"\n";
   cout<<"THEREFORE WE ARE STOPPING OUR PERMUTATION AT "<<i+1<<" ITERATION \n";
          break;                     
                    }
         }  

       if(g==0)
       cout<<"YES THE GIVEN PERMUTATION IS A STACK PERMUTATION\n";
       return 0;
}
