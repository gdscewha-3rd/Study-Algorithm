#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int commandNum; 
    cin >> commandNum;
    deque<int> d;
    
    string command;
    int target;
    
    for(int i = 0; i<commandNum; i++)
    {
        cin >> command;
        bool isEmpty = d.empty();
        
        if(command == "push_back")
        {
            cin >> target;
            d.push_back(target);
        }
        else if(command =="push_front")
        {
            cin >> target;
            d.push_front(target);
        }
        else if(command =="pop_front")
        {
            if(isEmpty)
            {
                cout << "-1\n";
            }
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
            
        }
        else if(command == "pop_back")
        {
            if(isEmpty)
            {
                cout << "-1\n";
            }
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
            
        }
        else if(command == "size")
        {
            cout << d.size() << "\n";
        }
        else if(command == "empty")
        {
            cout << isEmpty << "\n";
        }
        else if(command == "front")
        {
            if(isEmpty)
            {
                cout << "-1\n";
            }
            else
            {
                cout << d.front() << "\n";
               
            }
            
        }
        else//command == "back"
        {
           if(isEmpty)
            {
                cout << "-1\n";
            }
            else
            {
                cout << d.back() << "\n";
            }
            
            
        }
    }
}
