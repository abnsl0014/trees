#include<bits/stdc++.h>
using namespace std;

/*class node(){
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};
*/
///OR
///node defination
struct node
{
    int data;
    struct node *left, *right;

};
///new node creation
struct node* new_node(int d){
    struct node* temp=new node;
    temp->data=d;
    temp->right=temp->left=NULL;
    return temp;
}
///building my tree as preorder input
node* buildtree(){
    int d;cin>>d;
    //base case
    if(d==-1){
        return NULL;
    }
    node* root=new_node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;

}
///display my tree
void displaytree(node* root){
    ///base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    displaytree(root->left);
    displaytree(root->right);

}



int main()
{
    struct node* root=buildtree();
    displaytree(root);
}
