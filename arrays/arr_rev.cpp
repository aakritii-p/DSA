#include <iostream>

using namespace std;

string reverse(string str){
    int start = 0, end = str.length()-1;
    char temp;
    while(end>start){
        temp = str[start];
        str[start]=str[end];
        str[end] = temp;
        end--;
        start++;
    }
    return str;
}

int main()
{
   string str = "hello";
   cout<<reverse(str);
   return 0;
}