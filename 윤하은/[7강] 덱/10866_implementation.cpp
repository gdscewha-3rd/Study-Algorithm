#include <bits/stdc++.h>
using namespace std;
const int MX = 10000;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int target)
{
    dat[head--] = target;
    return;
   
}
int dequeSize()
{
    return tail-head;
}
bool isEmpty()
{
    if(tail == head)
        return true;
    else return false;
}
void push_back(int target)
{
     dat[++tail] = target;
     return;
}
void pop_front()
{
    if(isEmpty()) return;
    else
    {    
        head++;
        return;
    }
    
}
void pop_back()
{
    if(isEmpty()) return;
    else 
    {
         tail--;
        return;
    }
   
}
int front()
{
    if(isEmpty()) return -1;
    else return dat[head+1];
}
int back()
{
    if(isEmpty()) return -1;
    return dat[tail];
}
void printDeque()
{
    for(int i = head+1; i<=tail; i++)
        cout << dat[i] << " ";
        
    cout << "\n";
}
void test()
{
    push_back(3);
    printDeque();
    push_front(5);
    
    printDeque();
    
    push_back(17);
    push_front(9);
    
    printDeque();
    
    pop_back();
    pop_front();
    
    printDeque();
    
    cout << "front() : " << front() << "\n";
    cout << "back() : " << back() << "\n";
    
    printDeque();
    
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int commandNum; 
    cin >> commandNum;
    
    string command;
    int target;
    
    for(int i = 0; i<commandNum; i++)
    {
        cin >> command;
        bool empty = isEmpty();
        
        if(command == "push_back")
        {
            cin >> target;
            push_back(target);
        }
        else if(command =="push_front")
        {
            cin >> target;
            push_front(target);
        }
        else if(command =="pop_front")
        {
            cout << front() << "\n";
            pop_front();
            
        }
        else if(command == "pop_back")
        {
            cout << back() << "\n";
            pop_back();
            
        }
        else if(command == "size")
        {
            cout << dequeSize() << "\n";
        }
        else if(command == "empty")
        {
            if(empty) cout << "1";
            else cout << "0";
            cout << "\n";
        }
        else if(command == "front")
        {
            cout << front() << "\n";
        }
        else//command == "back"
        {
            cout << back() << "\n";
            
        }
    }
}
