#include<iostream>
#include<fstream>
using namespace std;

//structure declaration for avl node
struct nodeoftree_avl
{
    int data;
    int count;
    struct nodeoftree_avl *left;
    struct nodeoftree_avl *right;
}*root;
//class declaration for avl tree
class Avl_TREE
{
    public:
        int height(nodeoftree_avl *);
        int diff(nodeoftree_avl *);
        nodeoftree_avl *rightallrotate(nodeoftree_avl *);
        nodeoftree_avl *leftallrotate(nodeoftree_avl *);
        nodeoftree_avl *leftrightrotate(nodeoftree_avl *);
        nodeoftree_avl *rightleftrotate(nodeoftree_avl *);
        nodeoftree_avl* tree_Balancing(nodeoftree_avl *);
        nodeoftree_avl* insertintree(nodeoftree_avl *, int );
        nodeoftree_avl* deletefromtree(nodeoftree_avl *root, int value);
        void display(nodeoftree_avl *, int);
        nodeoftree_avl* findpredecessor(nodeoftree_avl *root);
        nodeoftree_avl *min(nodeoftree_avl *root);
        nodeoftree_avl *max1(nodeoftree_avl *root);
        void inorder(nodeoftree_avl *);
        int range(nodeoftree_avl *root,int low , int high);
        Avl_TREE()
        {
            root = NULL;
        }
};


nodeoftree_avl *nearestelempointer;
int diff1=100000;

nodeoftree_avl *Avl_TREE::leftallrotate(nodeoftree_avl *parent)
{
    nodeoftree_avl *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
int Avl_TREE::height(nodeoftree_avl *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 

int Avl_TREE::diff(nodeoftree_avl *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 

nodeoftree_avl *Avl_TREE::rightallrotate(nodeoftree_avl *parent)
{
    nodeoftree_avl *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}


 

nodeoftree_avl *Avl_TREE::leftrightrotate(nodeoftree_avl *parent)
{
    nodeoftree_avl *temp;
    temp = parent->left;
    parent->left = rightallrotate (temp);
    return leftallrotate (parent);
}
 

nodeoftree_avl *Avl_TREE::rightleftrotate(nodeoftree_avl *parent)
{
    nodeoftree_avl *temp;
    temp = parent->right;
    parent->right = leftallrotate (temp);
    return rightallrotate (parent);
}

nodeoftree_avl *Avl_TREE::tree_Balancing(nodeoftree_avl *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = leftallrotate (temp);
        else
            temp = leftrightrotate (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rightleftrotate (temp);
        else
            temp = rightallrotate (temp);
    }
    return temp;
}
 


nodeoftree_avl *Avl_TREE::deletefromtree(nodeoftree_avl *root, int value)
{
if(root==NULL)
    {cout<<"the nearest element is "<<nearestelempointer->data<<endl;
       return root;
}
else if(value<root->data)
    {  if((value-root->data<0)&&(value-root->data>-diff1))
        {diff1=root->data-value;
         nearestelempointer=root;}
         else if ((value-root->data>0)&&(value-root->data<diff1))
         { diff1=value-root->data;
         nearestelempointer=root;  }
       root->left=deletefromtree(root->left,value);
      root=tree_Balancing(root);}
else if(value>root->data)
    {  if((value-root->data<0)&&(value-root->data>-diff1))
        {diff1=root->data-value;
         nearestelempointer=root;}
         else if ((value-root->data>0)&&(value-root->data<diff1))
         { diff1=value-root->data;
         nearestelempointer=root;  }
        root->right=deletefromtree(root->right,value);
        root=tree_Balancing(root);}

else if(value==root->data){
    if((root->left==NULL)&&(root->right==NULL))
    { nodeoftree_avl *p;
        p=root;
      if(p->count==1)  
     { delete(p);
      root=NULL;}
      else{
        p->count--;
      }
    }
    else if((root->left==NULL)&&(root->right!=NULL))
     {  

        nodeoftree_avl *p;
        root->data=root->right->data;
        root->count=root->right->count;
        p=root->right;
        if(p->count==1)
       { delete(p);
        root->right=NULL;}
        else{
            p->count--;
        }
     }
         else if((root->left!=NULL)&&(root->right==NULL))
     {  

        nodeoftree_avl *p;
        root->data=root->left->data;
        root->count=root->left->count;
        p=root->left;
        if(p->count==1){
        delete(p);
        root->left=NULL;}
        else{
            p->count--;
        }
     }   
     else {if(root->count==1){
       nodeoftree_avl *temp=findpredecessor(root->left);
       root->data=temp->data;
       root->count=temp->count;
       root->left=deletefromtree(root->left,temp->data);
       root=tree_Balancing(root);}
       else{
        root->count--;
       }
     }
}
}
nodeoftree_avl *Avl_TREE::findpredecessor(nodeoftree_avl *root){
    nodeoftree_avl *temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp;
}
nodeoftree_avl *Avl_TREE::insertintree(nodeoftree_avl *root, int value)
{
    if (root == NULL)
    {
        root = new nodeoftree_avl;
        root->data = value;
        root->count=1;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(value==root->data){
        root->count++;
    }
    else if (value < root->data)
    {
        root->left = insertintree(root->left, value);
        root = tree_Balancing (root);
    }
    else if (value > root->data)
    {
        root->right = insertintree(root->right, value);
        root = tree_Balancing (root);
    }
    return root;
}

int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fstream ifile;
    char fname[30];int s;
    Avl_TREE avl;
    ifile.open("test.txt");
    while(!ifile.eof()){
     ifile>>s;
     root = avl.insertintree(root, s);
     }
     avl.display(root,1);
     ifile.close();
    int choice;
    char ch;
do{ cout<<"\n1.add salar in the tree.\n";
    cout<<"\t2.delete salary from the tree.\n";
    cout<<"\t3.find maximum in the tree\n";
    cout<<"\t4.find minimum in the tree\n";
    cout<<"\t5.find employee in the range\n";
    cin>>choice;
    
        if(choice==1){       int salary;
                    cout<<"\n ENTER SALARY";
                    cin>>salary;
                    root=avl.insertintree(root,salary);
                    cout<<"\n SALARY ADDED";
                    avl.display(root,1);
                    
                }
       else if(choice==2) {   int removesalary;
                    cout<<"\nWHICH SALARY DO YOU WANT TO remove";
                    cin>>removesalary;
                    root=avl.deletefromtree(root,removesalary);
                    
                }
        else if(choice==3) {   
                    root=avl.max1(root);
                     
                }        
        else if(choice==4) {  
                    root=avl.min(root);
                    
                } 
        else if(choice==5) {  int low,high,r;
                   cout<<"\n ENTER THE SALARY RANGE";
                   cin>>low>>high;
                   r=avl.range(root,low,high);
                   cout<<r;
                   
                }             
        else{cout<<"\n!!ENTERED WRONG CHOICE";}        
    cout<<"\n DO YOU WANT TO DO MORE OPERATIONS(y/n)";
    cin>>ch;
}while((ch=='y')||(ch=='Y'));
       return 0;
}

void Avl_TREE::display(nodeoftree_avl *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data<<" "<<ptr->count;
        display(ptr->left, level + 1);
    }
}

nodeoftree_avl *Avl_TREE::max1(nodeoftree_avl *root)
{
    if(root->right==NULL)
       { cout<<"\n MAXIMUM SALARY IS :"<<root->data;
        return root;}
    else{
        root=root->right;
        root=max1(root);
    }
}

nodeoftree_avl *Avl_TREE::min(nodeoftree_avl *root)
{
    if(root->left==NULL)
       { cout<<"\n MINIMUM SALARY IS :"<<root->data;
        return root;}
    else{
        root=root->left;
        root=min(root);
    }
}
int sum=0;
int Avl_TREE::range(nodeoftree_avl *root,int low , int high)
{
    if(root==NULL)
    { 
        return sum;
    }
    sum=range(root->left,low,high) ;
        if((root->data>=low)&&(root->data<=high))
        sum+=root->count;
    sum=range(root->right,low,high);
}