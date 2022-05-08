#include <bits/stdc++.h>
using namespace std;

const int MX= 1000005;
int dat[MX];
int pos =0;

bool isEmpty()
{
    if(pos > 0) return false;
    else return true;
    
}
void push(int num)
{
    dat[pos++] = num;
    return;
}
void pop()
{
    if(isEmpty()) return;
    else 
    {
        pos--;
        return;
    }
}
int top()
{
    if(isEmpty()) return 0;
    else return dat[pos-1];
}
void printStack()
{
    for(int i=pos-1; i>= 0; i--)
        cout << dat[i] << " ";
    cout << "\n";
}
int main(void)
{
    push(13);
    push(15);
    push(3);
    push(41);
    push(-7);
    push(16);
    
    printStack();
    
    pop();
    printStack();
    
    cout << top() << "\n";
    
    printStack();
}
/*
실행 결과 
16 -7 41 3 15 13
-7 41 3 15 13
-7
-7 41 3 15 13
*/
