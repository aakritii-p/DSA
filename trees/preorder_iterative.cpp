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

void preorder(node* root)
{
    if(!root) return;
    stack<node*> s;
    s.push(root);
    while(!s.empty())
    {
        node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }

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
 
    preorder(root);
 
    return 0;
}