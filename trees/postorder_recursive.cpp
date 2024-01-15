#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

void postorder(node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    /* 
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);
 
    postorder(root);
 
    return 0;
}