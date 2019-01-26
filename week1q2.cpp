#include<bits/stdc++.h>
using namespace std;
///Getting kth largest and smallest element in a BST
///using inorder traversal for kth smallest
///reverse inorder traversal for kth largest
///solution in O(n)
int r1=0;
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
struct node* create_bst(struct node*root,int d)
{
   //base case
    if(root==NULL){
        return create_node(d);
    }
    if(d<=root->data){
        root->left=create_bst(root->left,d);
    }
    else{
        root->right=create_bst(root->right,d);
    }

return root;
}

struct node* build()
{
    int d;
    cin>>d;
    struct node*root=NULL;
    while(d!=-1)
    {
        root=create_bst(root,d);
        cin>>d;
    }
    return root;
}

void findkthsmallest(struct node*root,int k){
    static int r=k;
    ///base case
    if(root==NULL){
        return;
    }
    findkthsmallest(root->left,r);
    r--;
    if(r==0){
        cout<<root->data;
    }
    findkthsmallest(root->right,r);
}
void findkthlargest(struct node*root,int k){
    static int r=k;
    ///base case
    if(root==NULL){
        return;
    }
    findkthlargest(root->right,r);
    r--;
    if(r==0){
        cout<<root->data;
    }
    findkthlargest(root->left,r);
}
int main()
{
    int n,k;
    cout<<"enter elements in bst--terminate by -1"<<endl;
    struct node*temp=build();
    cout<<"enter value of k to find kth smallest element"<<endl;
    cin>>n;
    cout<<"kth smallest element is:"<<endl;
    findkthsmallest(temp,n);

    cout<<"enter value of k to find kth largest element"<<endl;
    cin>>k;
    cout<<"kth largest element is:"<<endl;
    findkthlargest(temp,k);

}
