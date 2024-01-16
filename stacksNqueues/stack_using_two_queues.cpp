
// While using two queues, there are 3 steps involved for push operation: 
// 1. insert the element
// 2. push all the remaining elements in q2(if any) to q1
// 3. swap(q1,q2) (function exists for std library queue - to swap the contents of two queues)

// For pop: simply pop the contents of q2


#include<bits/stdc++.h>

using namespace std;


queue<int> q1;
queue<int> q2;


void push(int x){
    q1.push(x);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1,q2);
}

int pop(){
    int ans;
    if(q2.empty()){
        ans = -1;
    }else{
        ans = q2.front();
        q2.pop();
    }
    return ans;
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);

    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;

    return 0;

}