#include <bits/stdc++.h>
using namespace std;
int isBracket(char& ch)
{
    int result;
    switch(ch)
    {
        case '(':
            result = 1;
            break;
        case ')':
            result = 4;
            break;
        case '[':
            result = 3;
            break;
        case ']':
            result = 2;
            break;
        default:
            result = 0;
        
    }
    return result;
}
bool isBalanced(string& str)
{
    stack<int> openBrackets;
    bool check = true;
    for(int i = 0; i<str.length(); i++)
    {
        int bracketNum = isBracket(str[i]);
        //방문한 문자가 괄호일 경우
        if(bracketNum > 0)
        {
            //여는 괄호일 경우
            if(bracketNum%2 == 1)
                openBrackets.push(bracketNum);
            //닫는 괄호일 경우
            else
            {
                //스택이 비어있을 때
                if(openBrackets.empty()) check = false;
                else
                {
                    int top = openBrackets.top();
                    if((top + bracketNum) == 5)
                        openBrackets.pop();
                    //짝이 안맞는 괄호일 경우
                    else check = false;
                }
            }
        }
    }
    if(openBrackets.empty() && check)
        return true;
    else return false;
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    bool result;
    while(1)
    {
        getline(cin, str);
        if(str == ".")
            break;
        else
        {
            result = isBalanced(str);
            if(result)
                cout << "yes\n";
            else cout << "no\n";
        }
    }
}
