//stl stack 이용
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfCommand;
    cin >> numOfCommand;
    
    stack<int> s;
    
    for(int i =0; i<numOfCommand; i++)
    {
        int target;
        string command;
        cin >> command;
        
        if(command == "push")
        {
            cin >> target;
            s.push(target);
        }
        else if(command == "pop")
        {
            if(s.empty()) cout << "-1\n";
            else 
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(command == "size")
        {
            cout << s.size() << "\n";
        }
        else if(command == "empty")
        {
            if(s.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else//command == top
        {
            if(s.empty()) cout << "-1\n";
            else cout << s.top() << "\n";
        } 
        
    }
}
/*
//직접 배열로 구현한 스택 이용
#include <bits/stdc++.h>
using namespace std;

const int MX = 10000;
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
    pos--;
    return;
}
int size()
{
    return pos;
}
int top()
{
    return dat[pos-1];
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfCommand;
    cin >> numOfCommand;
    
    for(int i =0; i<numOfCommand; i++)
    {
        int target;
        string command;
        cin >> command;
        
        if(command == "push")
        {
            cin >> target;
            push(target);
        }
        else if(command == "pop")
        {
            if(isEmpty()) cout << "-1\n";
            else 
            {
                cout << top() << "\n";
                pop();
            }
        }
        else if(command == "size")
        {
            cout << size() << "\n";
        }
        else if(command == "empty")
        {
            if(isEmpty()) cout << "1\n";
            else cout << "0\n";
        }
        else//command == top
        {
            if(isEmpty()) cout << "-1\n";
            else cout << top() << "\n";
        } 
        
    }
}
*/
