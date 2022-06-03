#include <bits/stdc++.h>
using namespace std;
void printStack(stack<char> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int result = 0;
    stack<char> sticks;

    for (int i = 0; i < str.length(); i++)
    {
        //레이저일 경우
        if (i < str.length() - 1 && str[i] == '(' && str[i + 1] == ')')
        {
            i++;
            result += sticks.size();
        }
        else if (str[i] == ')')
        {
            result++;
            sticks.pop();
        }

        else
            sticks.push(str[i]);
        //printStack(sticks);
    }
    cout << result;
}
