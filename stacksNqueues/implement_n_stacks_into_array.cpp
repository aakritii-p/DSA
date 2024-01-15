#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define size 6

#define n 2 //3 stacks

int arr[size];
int top[n];
int nextt[size];
int freee = 0;

bool isFull(){
    if(freee==-1) return true;
    else return false;
}

bool isEmpty(int sn){
    if(top[sn]==-1) return true;
    else return false;
}

void push(int item, int sn){
    if(isFull()){
        cout<<"Stack is full!"<<endl;
        return;
    }
    int i = freee;
    freee = nextt[i];
    nextt[i] = top[sn];
    top[sn] = i;
    arr[i] = item; 
}

int pop(int sn){
    if(isEmpty(sn)){
        cout<<"Stack is empty!"<<endl;
        return -1;
    }

    int i = top[sn];
    int ele = arr[i];
    top[sn] = nextt[i];
    nextt[i] = freee;
    freee = i;
    return ele;
}


int main(){

    for(int i=0;i<n;i++){
        top[i]=-1;
    }

    for(int i=0;i<size;i++){
        nextt[i]=(i+1);
    }

    nextt[size-1]=-1;

    push(1,0);
    push(2,0);
    push(3,1);
    push(4,0);
    push(5,1);
    
    cout<<"popped: "<<pop(0)<<endl;
    cout<<"popped: "<<pop(0)<<endl;
    cout<<"popped: "<<pop(0)<<endl;
    cout<<"popped: "<<pop(1)<<endl;
    cout<<"popped: "<<pop(1)<<endl;


    return 0;
    
}