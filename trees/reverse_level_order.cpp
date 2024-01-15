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

void reverse_level_order(node* root)
{
    if(!root) return;
    queue<node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty())
    {
        node* t = q.front();
        s.push(t->data);
        if(t->right) q.push(t->right);
        if(t->left) q.push(t->left);
        q.pop();
    }
    while(!s.empty())
    {
        int top = s.top();
        cout<<top<<" ";
        s.pop();
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
    reverse_level_order(root);
    return 0;
}