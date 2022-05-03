//220412
//백준 1874번 스택 수열 문제 (실버 3)
//boj.kr/1874

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string result = "";
    vector<int> seq(n + 1);

    for (int i = 1; i <= n; i++) cin >> seq[i];

    int maxInStack = 0;
    stack<int> s;

    for (int i = 1; i <= n; i++)
    {
        int target = seq[i];
        if (!s.empty() && s.top() == target)
        {
            s.pop();
            result += "-";
        }
        else if (!s.empty() &&s.top() != target && maxInStack >= target)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            for (int j = maxInStack + 1; j <= target; j++)
            {
                s.push(j);
                result += "+";
                maxInStack = j;
            }
            s.pop();
            result += "-";
        }

    }
    if (result.length() == n*2 && s.empty() && maxInStack == n) for (char ch : result) cout << ch << "\n";
    else cout << "NO";
    return 0;

}
