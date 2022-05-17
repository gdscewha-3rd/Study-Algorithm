#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<int> q;
    
    int commandNum;
    cin >> commandNum;
    
    for(int i =0; i<commandNum; i++)
    {
        string command;
        int target;
        cin >> command;
        
        bool isEmpty = q.empty();
        
        if(command == "push")
        {
            cin >> target;
            q.push(target);
            
        }
        else if(command == "pop")
        {
            if(isEmpty) cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(command == "size")
        {
            cout << q.size() << "\n";
        }
        else if(command == "empty")
        {
            if(isEmpty) cout << "1\n";
            else cout << "0\n";
        }
        else if(command == "front")
        {
            if(isEmpty) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else//command == "back"
        {
            if(isEmpty) cout << "-1\n";
            else cout << q.back() << "\n";
        }
        
    }
    
    
    
}
