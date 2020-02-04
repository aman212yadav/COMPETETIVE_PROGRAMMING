#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
      node(int data){
          this->data = data;
          left=NULL;
          right=NULL;
      }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void printTreePre(node*root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    printTreePre(root->left);
    printTreePre(root->right);
}
int main(){
    node* root = buildTree();
    printTreePre(root);
    return 0;

}
