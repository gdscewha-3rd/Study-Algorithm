#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;
void push(int target)
{
    dat[tail++] = target;
    return;
}
void pop()
{
    head++;
    return;
}
int rear()
{
    return dat[tail-1];
}
int front()
{
    return dat[head];
}
void printQ()
{
    for(int i = head; i<tail; i++)
        cout << dat[i] << " ";
    cout << "\n";
    return;
}
int main(void)
{
    push(3);
    push(5);
    push(1);
    push(-13);
    push(17);
    
    printQ();
    
    cout << front() << "\n";
    cout << rear() << "\n";
    
    pop();
    
    printQ();
    
    pop();
    pop();
    
    printQ();
}
