#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int arr[MAX];
int top=-1; 

bool push(int x){
    if(top==(MAX-1)){
        cout<<"Stack is full."<<endl;
        return false;
    }
    else{
        top++;
        arr[top]=x;
        cout<<"element pushed into stack successfully."<<endl;
        return true;
    }
} 

int pop(){
    if(top<0){
        cout<<"Stack is empty!"<<endl;
        return 0;
    }
    else{
        int x = arr[top--];
        return x;
    }
}

void topele(){
    if(top<0){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        cout<<arr[top]<<endl;
    }
}


int main(){
    push(10);
    push(20);
    push(30);
    cout<<pop()<<endl;
    topele();
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    topele();
    return 0;
}