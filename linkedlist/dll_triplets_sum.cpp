#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head;

void insert()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int x;
    cout<<"Enter data: "<<endl;
    cin>>x;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
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

//O(n3)
// int tripletSum(int x)
// {
//     int count = 0;
//     struct node* ptr1, *ptr2, *ptr3;
//     for(ptr1 = head; ptr1!=NULL ; ptr1=ptr1->next)
//     {
//         for(ptr2 = ptr1->next; ptr2!=NULL ; ptr2=ptr2->next)
//         {
//             for(ptr3 = ptr2->next; ptr3!=NULL; ptr3=ptr3->next)
//             {
//                 if((ptr1->data+ptr2->data+ptr3->data)==x)
//                     count++;
//             }
//         }
//     }
//     return count;
// }

//O(n2) hashing 
// int tripletSum(int x)
// {
//     int count = 0;
//     struct node* ptr, *ptr1, *ptr2;
//     map<int, node*> m;
//     for(ptr=head;ptr!=NULL;ptr=ptr->next)
//     {
//         m[ptr->data]=ptr;
//     }
//     for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next){
//         for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
 
//             int sum = ptr1->data + ptr2->data;

//             if(m.find(x - sum) != m.end() && m[x - sum] != ptr1
//                 && m[x - sum] != ptr2)
//                 count++;
//         }
//     }
//     return (count/3);
// }

//O(n2) O(1)memory

int countTriplets(struct node* first, struct node* second, int value)
{
    int count = 0;
    while(first!=NULL && second!=NULL && first!=second && second->next!=first)
    {
        if((first->data+second->data)==value)
        {
            count++;
            first=first->next;
            second=second->prev;
        }
        else{
            if((first->data+second->data)<value)
            {
                first=first->next;
            }
            else
            {
                second=second->prev;
            }
        }
    }
    return count;

}



int tripletSum(int x)
{
    int count = 0;
    struct node* current, *first, *last;
    last = head;
    while (last->next != NULL)
        last = last->next;
    for(current=head;current!=NULL;current=current->next)
    {
        first=current->next;
        count += countTriplets(first,last,x - current->data);
    }
    return count;

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
    cout<<"Enter the number of nodes to be inserted: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insert();
    }
    display();
    cout<<"Counting triplets that sum up to x: "<<endl;
    int x = 17;
    int res = tripletSum(x);
    cout<<"Count is: "<<res<<endl;
    return 0;
}