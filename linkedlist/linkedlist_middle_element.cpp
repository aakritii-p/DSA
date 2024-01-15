#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int data;
    struct ListNode* next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};
ListNode* head;

void insert()
{
    ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    int x;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head = temp;
        return;
    }
    else
    {
        ListNode* ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
    
}

void display()
{
    ListNode* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

// ListNode* middleNode() {
//     int count = 0;
//     ListNode* ptr = head;
//     while(ptr!=NULL)
//     {
//         count++;
//         ptr=ptr->next;
//     }
//     ptr=head;
//     int mid = (count/2);
//     while(mid)
//     {
//         ptr=ptr->next;
//         mid--;
//     } 
//     return ptr; 
// }

ListNode* middleNode() {
    ListNode* slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



int main()
{
    int n;
    cout<<"Enter the number of nodes you want to insert: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insert();
    }
    display();
    ListNode* mid = middleNode();
    cout<<"Mid element is: "<< mid->data << " ";
    return 0;
}


















