#include <bits/stdc++.h>
using namespace std;

class flight{
	int Atime,Dtime,price,to,from;
	string plane;
public:
	flight(){}

	flight(const flight& a){
		Atime=a.Atime;
		Dtime=a.Dtime;
		to=a.to;
		from=a.from;
		price=a.price;
		plane=a.plane;
	}
	
	flight(int from,int to,int Dtime,int Atime ,string plane,int price){
		this->Atime=Atime;
		this->Dtime=Dtime;
		this->price=price;
		this->to=to;
		this->from=from;
		this->plane=plane;
	}
	
	bool compare(flight a){
			return this->Dtime>a.Dtime;
	}

	void printFlight(){
		cout<<from<<" "<<to<<" "<<Dtime<<" "<<Atime<<" "<<plane<<" "<<price<<endl;
	}
};


class heap{
	int CAPACITY;
	int size;
	flight* list;
	
	int parent(int i){
		return (i-1)/2;
	}

	int firstChild(int i){
		return 2*i+1;
	}

	int secondChild(int i){
		return 2*i+2;
	}

	void heapifyUP(){
		int i=size-1;
		int parent=this->parent(i);
		while(i!=0){
			if (list[parent].compare(list[i])){
				flight temp = list[i];
				list[i]=list[parent];
				list[parent]=temp;
				i=parent;
				parent=this->parent(i);
			}else break;	
		}
	}

	int minChild(int i){
		int firstChild=this->firstChild(i);
		int minChild=firstChild;
		int secondChild=this->secondChild(i);
		if (secondChild<size){
			if (list[firstChild].compare(list[secondChild])){
				minChild=secondChild;
			}
		}
		return minChild;
	}

	void heapifyD(int i=0){
		int firstChild=this->firstChild(i);
		int secondChild=this->secondChild(i);
		int minChild=this->minChild(i);
		while(firstChild<size){
			if (list[i].compare(list[minChild])){
				flight temp=list[i];
				list[i]=list[minChild];
				list[minChild]=temp;
				i=minChild;
				firstChild=this->firstChild(i);
				secondChild=this->secondChild(i);
				minChild=this->minChild(i);
			}else break;
		}
	}

	void heapify(){
		int lastMember=size-1;
		int parent=this->parent(lastMember);
		for (int i =parent ; i >=0 ; --i){
			heapifyD(i);
		}
	}
public:
	heap(int capacity){
		CAPACITY=capacity;
		flight temp[CAPACITY];
		list=temp;
		size=0;
	}

	heap(const heap& a){
		CAPACITY=a.CAPACITY;
		size=a.size;
        
		flight temp[CAPACITY];
		for (int i = 0; i < size; ++i){
			flight f(a.list[i]);
			a.list[i].printFlight();
			temp[i]=f;
		}
		list=temp;
	}

	bool isEmpty(){
		return size==0;
	}

	void resize(){
		CAPACITY=2*CAPACITY;
		flight temp[CAPACITY];
		for (int i = 0; i < size; ++i){
			temp[i]=list[i];
		}
		list=temp;
		free(temp);
	}

	void insert(flight l[],int size,int capacity){
		CAPACITY=capacity;
	    this->size=size;
		list=l;
		heapify();
	}

	void insert(flight f){
		if (size==CAPACITY)
			resize();
		list[size]=f;
		size++;
		heapifyUP();
	}

	flight deleteMin(){
		if (isEmpty()){
			flight temp;
			return temp;
		}
		flight temp=list[0];
		list[0]=list[size-1];
		size--;
		heapifyD();
		return temp;
	}

	void printHeap(){
		for (int i = 0; i < size; ++i){
			printf("%d: ",i);
			list[i].printFlight();	
		}
	}
	
};

int main(int argc, char const *argv[]){
	if (argc!=2){
		printf("usage:%s filename\n",argv[0] );
		exit(0);
	}

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen(argv[1], "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int Ncities,Nplanes;
    scanf("%d %d",&Ncities,&Nplanes);
    
    flight list[Nplanes]; 
    heap H(Nplanes);

    for (int i = 0; i <Nplanes; ++i){
    	int from,to,Dep,Arrv,price;
    	string plane;
    	cin>>from>>to>>Dep>>Arrv>>plane>>price;
    	flight temp(from,to,Dep,Arrv,plane,price);
    	list[i]=temp;
    }
    
    H.insert(list,Nplanes,Nplanes);
    
    int Queries;
    cin>>Queries;

    for (int i = 0; i < Queries; ++i){

    	heap temp(H);
    	temp.printHeap();
    	int start_city,end_city,Dep_time,Arr_time;
    	cin>>start_city>>end_city>>Dep_time>>Arr_time;

    }

	return 0;
}
