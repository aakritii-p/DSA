#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class twoStacks{

    int * arr;
    int top1,top2,size;

    public: 

    twoStacks(int n=100){  arr=new int[n]; size = n; top1 = -1; top2 = size; }

    void push1(int x){
        top1++;
        arr[top1]=x;
    }

    void push2(int x){
        top2--;
        arr[top2]=x;
    }

    int pop1(){
        if(top1==-1) return -1;
        else return arr[top1--];

    }

    int pop2(){
        if(top2==size) return -1;
        else return arr[top2++];
    }

};

int main(){
    twoStacks *sq = new twoStacks(); //o
    sq->push1(10);
    cout<<sq->pop1()<<endl;
    sq->push2(20);
    cout<<sq->pop2()<<endl;
    return 0;
}