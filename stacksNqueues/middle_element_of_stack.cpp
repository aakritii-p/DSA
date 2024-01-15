#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *prev,*next;
    node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

struct node* dummy = new node(-1);
struct node *head=dummy;
struct node *mid=dummy;
int stacksize=0;

void push(int x){
    struct node* temp = new node(x);
    head->prev = temp;
    temp->next = head;
    head = temp;
    stacksize++;
    if(stacksize==1){
        mid = temp;
    }
    else if(stacksize%2==0){ //if stack size is even we will have to shift mid forward    
        mid = mid->prev ; //as its stack we are maintaining list like 3=prev<-2->next=1
    }
}

int pop(){
    if(stacksize==0){  
        cout<<"stack is empty."<<endl;
        return 0;
    }
    struct node* temp = head;
    int x = head->data;
    head = head -> next;
    if(head!=NULL) head->prev=NULL;
    stacksize--;
    if(stacksize%2 != 0) {
        mid = mid->next;
    }
    free(temp);
    return x;
}

int middle(){
    if(stacksize==0){
        cout<<"stack is empty."<<endl;
        return 0;
    }
    return mid->data;
}

void display(){
    struct node* ptr1 = head;
    while(ptr1->next!=NULL){
        cout<<ptr1->data<<" ";
        ptr1=ptr1->next;
    }
    cout<<endl;
}

void deletemid(){
    if(stacksize!=0){
        struct node* temp = mid;
        if(stacksize==1){
            head=NULL;
            mid=NULL;
        }
        else if(stacksize==2){
            head=head->next;
            mid=mid->next;
            head->prev=NULL;
        }
        else{
            mid->prev->next=mid->next;
            mid->next->prev=mid->prev;
            if(stacksize%2==0) mid = mid->next; //if current size is even
            else mid = mid->prev; //if current size is odd
        }
        free(temp);
        stacksize--;
    }
    else{
        cout<<"Stack is empty. Cant delete."<<endl;
        return;
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    cout<<"popped element is: "<<pop()<<endl;
    cout<<"middle element is: "<<middle()<<endl;
    deletemid();
    display();
    cout<<"middle element is: "<<middle()<<endl;
    display();
    deletemid();
    cout<<"middle element is: "<<middle()<<endl;
    display();
    return 0;
}