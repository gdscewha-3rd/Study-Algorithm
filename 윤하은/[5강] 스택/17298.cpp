#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int seqSize;
    cin >> seqSize;
    vector<int> tmp(seqSize);
    
    for(int i =0; i<seqSize; i++)
        cin >> tmp[i];
        
    stack<int> s;
    stack<int> result;
    
    for(int i = seqSize-1; i>=0; i--)
    {
        int num = tmp[i];
        if(s.empty()) result.push(-1);
        else
        {
            while(!s.empty() && s.top() <= num)
                s.pop();
            if(s.empty()) result.push(-1);
            else result.push(s.top());
        }
        s.push(num);
    }
    
    while(!result.empty())
    {    
        cout << result.top() << " ";
        result.pop();
    }
    
    
}
