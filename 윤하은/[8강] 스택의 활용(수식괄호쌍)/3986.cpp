#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    int wordNum;
    cin >> wordNum;
    int result = 0;
    
    for(int i = 0; i<wordNum; i++)
    {
        cin >> str;
        stack<char> letters;
        
        for(int i  = 0; i< str.length(); i++)
        {
            char ch = str[i];
            if(!letters.empty() && letters.top() == ch)
                letters.pop();
                
            else
                letters.push(ch);
        }
        
        if(letters.empty()) result++;
        
    }
    
    cout << result;
    
}
