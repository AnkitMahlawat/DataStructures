#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
float clk=0;
float avgtime=0;
struct node1{
	int noc;
	float toq;
	int qno;
};
struct node2{
    float at;
    float dt;
    int qno;
};
class heap{
	node1 *heap1;
	node2 *heap2;
	int curr_size;
	int maxsize;
	public:
		heap(int n,int k){
           heap1=new node1[k];
           heap2=new node2[n];
           curr_size=0;
           maxsize=k;
           for(int i=0;i<k;i++){
           	heap1[i].qno=i;
           	heap1[i].noc=0;
           	heap1[i].toq=0;
           }
		}
		int parent(int x){
			return (x-1)/2;
		}
		int left(int x){
			return 2*x+1;
		}
		int right(int x){
			return 2*x+2;
		}
		void update(float time){
			for(int i=0;i<maxsize;i++){
				heap1[i].toq=heap1[i].toq-time;
				if(heap1[i].toq<=0){
					heap1[i].toq=0;
				} 
			}
		}
		
		void insert2(int counterno,float arrivaltime,float departuretime){
			curr_size++;
			int i=curr_size-1;
			heap2[i].at=arrivaltime;
			heap2[i].dt=departuretime;
			heap2[i].qno=counterno;
			while ((i != 0 )&& (heap2[parent(i)].dt > heap2[i].dt))
           {
               swap2(&heap2[i], &heap2[parent(i)]);
               i = parent(i);
           }
		}  
		void swap2(node2 *x, node2 *y)
        {
           node2 temp = *x;
            *x = *y;
            *y = temp;
         }
		void insert1(float arrivaltime,float servicetime){
			float diff=arrivaltime-clk;
			update(diff);
			clk=arrivaltime;			
			heap1[0].noc++;
			avgtime+=heap1[0].toq;
                        heap1[0].toq+=servicetime;	
		    insert2(heap1[0].qno,arrivaltime,arrivaltime+heap1[0].toq);
		    int i=0; 		
	        while((i<maxsize)&&(((heap1[left(i)].noc<=heap1[i].noc)&&(2*i+1<maxsize))||((heap1[right(i)].noc<=heap1[i].noc)&&(2*i+2<maxsize)))){
	        	if(heap1[right(i)].noc<heap1[left(i)].noc){
	        		swap1(&heap1[right(i)],&heap1[i]);
	        		i=right(i);
	        	}
	        	else{
	        		swap1(&heap1[left(i)],&heap1[i]);
	        		i=left(i);
	        	}
	        }
	    }
	    void swap1(node1 *x,node1 *y){
	    	node1 temp = *x;
            *x = *y;
            *y = temp;
	    }

	    void hdelete2(){
	    	int x=heap2[0].qno;
	    	float diff1=heap2[0].dt;
	    	swap2(&heap2[0],&heap2[curr_size-1]);
	    	curr_size--;
	    	float diff=diff1-clk;
	    	 clk=diff1;
	    	 update(diff);
	    	 hdelete1(x);
	    }
	    void hdelete1(int x){
	    	for(int i=0;i<maxsize;i++){
	    		if(x==heap1[i].qno){
	    			heap1[i].noc--;	    			
	    		}
	    	}
	    }
	    float dpt(){
	    	if(curr_size>0)
	    	return heap2[0].dt;
	       else
	       	return -1;
	    }
};



int main()
{    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     float m,v,n,R;
     int noofcust,k;
     cin>>R>>m>>v>>k>>noofcust;
     heap h(noofcust,k);
    float a;
    float srvtime[noofcust];
    float arrtime[noofcust];
    srand(time(0));
    for(int i=0;i<noofcust;i++)
    {a=rand()%512;
    n=a/511;
    srvtime[i]=((n*2*v)+(m-v));
    cout<<srvtime[i]<<" ";
    //unit of srvtimme is as per unit of m and v
    }
    for(int i=0;i<noofcust;i++)
    {a=rand()%512;
    	n=a/511;
    arrtime[i]=i/R+n/R;
    cout<<n/R<<" ";
    //units of arrival time is as per R(arrival rate).
    //units oof 1/R and m,v should be same.
}
int a1=0;
int flag=0;
while(flag==0)
{  if((arrtime[a1]>h.dpt())&&(h.dpt()>=0))
     {h.hdelete2();}
    else
    {h.insert1(arrtime[a1],srvtime[a1]);
     a1++;
     }
    if (a1==noofcust)
     {
     flag=1;
     }
}
cout<<endl<<avgtime/noofcust;


return 0;

}
