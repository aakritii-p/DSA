// long long multiplyTwoLists (Node* l1, Node* l2)
// {
//     long long N = 100000007;
//     long long num1= 0, num2=0;

//     while(l1||l2)
//     {
//         if(l1)
//         {
//             num1=((num1*10)%N)+l1->data;
//             l1=l1->next;
//         }
//         if(l2)
//         {
//             num2=((num2*10)%N)+l2->data;
//             l2=l2->next;
//         }
//     }

//     return ((num1%N)*(num2%N))%N;

//}