#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<vector>
#include <stdio.h>

using namespace std;
int table_size=107;
int cnv=0;
int i1=0;

 struct structure{
  int q;
  char e[31];
};
void mergesort(structure *a,int i1,int j1,int i2,int j2)
{   structure temp[j2+1-i1];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    while((i<=j1)&&(j<=j2))
    {
        if(a[i].q>a[j].q)
        temp[k++]=a[i++];
        else
          temp[k++]=a[j++];
    }
    while(i<=j1)
    temp[k++]=a[i++];
    while(j<=j2)
    temp[k++]=a[j++];
    for(int i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];

}
void merge(structure *a,int beg,int end)
{   int mid,i;
    if(beg<end)
    {mid=(beg+end)/2;
    merge(a,beg,mid);
    merge(a,mid+1,end);
    mergesort(a,beg,mid,mid+1,end);}
}
class hashnode
{ public:
	char s[20];
	int count;
	int key;
	hashnode *next;
	hashnode(int k,char t[]){
	strcpy(s,t);
	key=k;
	count=0;
	next=NULL;
	}
};

class hashtable
{
	hashnode** htable;
	  public:
	  	hashtable()
	  	{
	  		htable=new hashnode*[table_size];
	  		for(int i=0;i<table_size;i++){
   				htable[i]=NULL;
	  		     }
	  	}
      ~hashtable()
	  	{
            for (int i = 0; i < table_size; ++i)
	    {
                hashnode* entry = htable[i];
                while (entry != NULL)
	        {
                    hashnode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] htable;
        }
        int hashfunction(int key)
        {
        	return (key%table_size);
        }

        void Insert(int key, char value[])
        {
            int hash_val = hashfunction(key);
            hashnode* prev = NULL;
            hashnode* entry = htable[hash_val];
            while (entry != NULL)
            {    if(strcmp(entry->s,value)==0){
                                                break;
                                               }
               else{ prev = entry;
                entry = entry->next;}
            }
            if (entry == NULL)
            {cnv++;
                entry = new hashnode(key,value);
                if (prev == NULL)
	            {
                    htable[hash_val] = entry;
                    htable[hash_val]->count++;
                }
	        else
	            {
                    prev->next = entry;
                    entry->count++;
                }
            }
            else
            {  if(strcmp(entry->s,value)==0){
               strcpy(entry->s,value);
               entry->count++;}
            }
        }

             int display(int key,structure srt[],int threshold)
        {
            int hash_val = hashfunction(key);
            hashnode* entry = htable[hash_val];
            while (entry != NULL)
	        {
	            {
                    srt[i1].q=entry->count;
                    strcpy(srt[i1].e,entry->s);i1++;
                }
                entry = entry->next;
            }
                return -1;
        }

};

int main()
{
    
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //freopen("output.txt", "w", stdout);
#endif

    char s[31],fname[50];int thold;
    cout<<"enter file\n";
    cin>>fname;
     cout<<"enter the threshold value\n";
   cin>>thold;
   FILE* filePtr = fopen(fname, "r+");
   char c;
   while((c = fgetc(filePtr)) != EOF)
   {
       if(c==';'||c==','||c=='.'||c=='['||c==']'||c=='{'||c=='}'||c=='('||c==')'||c=='>'||c=='<'||c==':'||c=='/'||c=='"'||c=='?'||c=='|'||c=='='||c=='-')
       {
           fseek(filePtr, -1, SEEK_CUR);
           fputc(' ', filePtr);
       }
   }
   fclose(filePtr);
    hashtable h;
  vector<int>v;
   fstream ifile;
   ifile.open(fname);
   if(!ifile) {
    cout<<"FILE DOESNOT EXIST\n";
   }
   else{
    while(!ifile.eof()){
        ifile>>s;int sum=0;
            for(int i=0;s[i]!='\0';i++){
              s[i]=tolower(s[i]);
              sum+=((31)^i)*s[i];
        }
        h.Insert(sum,s);
        int x=1;
        for(int j=0;j<v.size();j++)
        {if(sum%table_size==v[j])
             x=0;
          }
        if(x==1)
          {v.push_back(sum%table_size);}
         }
   }
    struct structure b[cnv];
int q;
for(int i=0;i<v.size();i++)
 { q=h.display(v[i],b,thold);}
 
 for(int i3=0;i3<cnv;i3++)
 { if(strcmp(b[i3].e,s)==0)
    {b[i3].q--;}}

//int m1=strcmp(b[17].e,"m");
 merge(b,0,cnv-1);
//cout<<m1<<endl;
//cout<<s<<endl;
 for(int i=0;i<cnv;i++)
 {

 if(b[i].q>thold)
  cout<<b[i].e<<":"<<b[i].q<<endl;
 }
      ifile.close();
    return 0;
}


