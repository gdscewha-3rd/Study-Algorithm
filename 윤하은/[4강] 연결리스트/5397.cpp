//220409
//백준 5397번 키로거 (실버 3)
//bojkr/5397

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string inputString;
    list<char> keyLogger;
    list<char>::iterator cursor;

    int testNum = 0;
    cin >> testNum;

    for (int i = 0; i < testNum; i++)
    {
        cin >> inputString;
        cursor = keyLogger.begin();

        for (int i = 0; i < inputString.length(); i++)
        {
            char target = inputString[i];
            switch (target)
            {
            case '<':
                if (cursor != keyLogger.begin()) cursor--;
                break;
            case '>':
                if (cursor != keyLogger.end()) cursor++;
                break;
            case '-':
                if (cursor != keyLogger.begin()) cursor = keyLogger.erase(--cursor);
                break;
            default://알파벳 혹은 숫자
                keyLogger.insert(cursor, target);
            }
            
        }
        for (auto ch : keyLogger) cout << ch;
        cout << "\n";
        keyLogger.clear();
    }

}
