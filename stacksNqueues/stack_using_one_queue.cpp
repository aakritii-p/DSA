//While implementing stack using one queue:
//For push operation:
//1. insert the element
//2. find (size of q1 - 1)
//3. pop all the elements till size-1 and push them to the back of the queue
// For pop: simply pop from q1


#include<bits/stdc++.h>

using namespace std;


queue<int> q1;

void push(int x){
    q1.push(x);
    int sz = q1.size()-1;
    while(sz--)
    {
        q1.push(q1.front());
        q1.pop();
    }
}

int pop(){
    int ans;
    if(q1.empty()){
        ans = -1;
    }else{
        ans = q1.front();
        q1.pop();
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