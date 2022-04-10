//220403
//LeetCode 345. Reverse Vowels of a String (Easy)
//https://leetcode.com/problems/reverse-vowels-of-a-string/


#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowel;

        for (int i = 0; i < s.size(); i++) { // 문자열 크기만큼 문자 하나씩 스캔
            // 만약 i번째 문자가 모음이면
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowel.push(s[i]); // 스택에 push
                s[i] = '$'; // 그 자리에 표시
            };
        };
        for (int i = 0; i < s.size(); i++) { // 다시 문자열 크기만큼 문자 하나씩 스캔
            if (s[i] == '$') { // 만약 i번째 문자가 표시된 문자이면 (모음 자리이면)
                s[i] = vowel.top(); // 스택 최상위 요소를 i번째 자리에
                vowel.pop();
            };
        };
        return s;
    };

    int main() {
        string s;
        cin >> s;
        s = reverseVowels(s);
        cout << s;
        return 0;
    };
};
