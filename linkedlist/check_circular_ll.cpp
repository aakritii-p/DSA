#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};
node* head;

void insert(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    cout<<"Enter data to be inserted:"<<endl;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        struct node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}

void display(){
    struct node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
}

bool isCircular()
{
    if(head==NULL)
    {
        return true;
    }
 
    struct node* ptr = head->next;

    while(ptr!=NULL && ptr!=head)
        ptr=ptr->next;

    return(head==ptr);

}


int main(){
    int n;
    cout<<"Enter the number of nodes you want to insert:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    cout<<isCircular()<<endl;    
    return 0;
}