#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head;

void createDll()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    struct node* ptr;
    if(head==NULL)
    {
        head=ptr=temp;
    }
    else
    {
        ptr->next=temp;
        temp->prev=ptr;
        ptr=temp;
    }
}

//O(n2) solution
// void find_pairs_sum(int x)
// {
//     struct node* ptr1,*ptr2;
//     ptr1 = head;
//     while(ptr1!=NULL)
//     {
//         int c = ptr1->data;
//         int diff = x - c;
//         ptr2 = head;
//         while(ptr2!=NULL)
//         {
//             if(ptr2->data == diff)
//             {
//                 cout<<c<<" "<<ptr2->data<<" "<<endl;
//             }
//             ptr2=ptr2->next;
//         }
//         ptr1=ptr1->next;
//     }
// }


//o(n) solution
void find_pairs_sum(int x)
{
    struct node *first = head;  
    struct node *second = head;  
    while(second->next != NULL)  
        second = second->next; 
    bool found = false;
    while(first!=second && second->next!=first)
    {
        if((first->data + second->data) == x)
        {
            found = true;
            cout<<first->data<<" "<<second->data<<" "<<endl;
            first = first -> next;
            second = second -> prev;
        }
        else
        {
            if((first->data + second->data) < x)
            {
                first = first -> next;
            }
        
            second = second -> prev;
        } 
    }
    if (found == false)  
        cout << "No pair found"; 
}


void display()
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        createDll();
    }
    // display();
    find_pairs_sum(7);
    return 0;
}