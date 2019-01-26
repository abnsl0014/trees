#include<bits/stdc++.h>
using namespace std;
///constructing a Binary search Tree from given Postorder Traversal
///solution in O(n)Log(n)

int r;
struct node
{
    int data;
    struct node*left,*right;
};
struct node*create_node(int d)
{
    struct node*temp=new node;
    temp->data=d;
    temp->right=temp->left=NULL;
    return temp;
};

int binarySearchindex(int s,int e,int ele,int arr[])
{
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(ele==arr[mid])
        {
            return mid;
        }
        else if(ele<arr[mid])
        {
            e=mid;
        }
        else
        {
            s=mid+1;
        }
    }
}

void print(struct node*temp)
{
    if(temp==NULL)
    {
        return;
    }
    print(temp->left);
    cout<<temp->data<<" ";
    print(temp->right);
}
void preorder(struct node*temp)
{
    if(temp==NULL)
    {
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}

struct node* create_bst_from_postorder(int s,int e,int *post,int *in,int n)
{
    static int index=n-1;//staic-so that it will not change
    //base case
    if(s>e)
    {
        return NULL;
    }
    struct node*nodee=create_node(post[index]);
    int r=-1;
    r=binarySearchindex(s,e,post[index],in);
    index--;
    nodee->right=create_bst_from_postorder(r+1,e,post,in,n);
    nodee->left=create_bst_from_postorder(s,r-1,post,in,n);

    return nodee;
};

int main()
{
    int n;
    cout<<"enter no. of elements of bst"<<" ";
    cin>>n;
    int post[n];
    int in[n];
    cout<<"enter postorder elements"<<" ";
    for(int i=0; i<n; i++)
    {
        cin>>post[i];
        in[i]=post[i];
    }
    cout<<"inorder is"<<" ";
    sort(in,in+n);
    cout<<endl;
    struct node*root=create_bst_from_postorder(0,n-1,post,in,n);
    print(root);//inorder
    cout<<endl;
    cout<<"preorder"<<endl;
    preorder(root);



}
