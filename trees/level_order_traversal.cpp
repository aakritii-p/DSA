#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node( int value)
    {
        data=value;
        right=NULL;
        left=NULL;
    }
};

void level_order(node* root)
{
    if(!root) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* t = q.front();
        cout<<t->data<<" ";
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
        q.pop();
    }
}

int main()
{
    int n;
    struct node* root = new node(10);
    root->left= new node(20);
    root->right= new node(30);
    root->left->left= new node(40);
    root->left->right= new node(50);
    level_order(root);
    return 0;
}