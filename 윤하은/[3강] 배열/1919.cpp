//220330
//백준 1919번 애너그램만들기 문제 (브론즈 2)
//boj.kr/1919

#include <bits/stdc++.h>
using namespace std;
const int NUM_OF_ALPHABETS(26);
vector<int> charCompositionStr1;
vector<int> charCompositionStr2;

void InitailizeVector(vector<int> &target)
{
    const int NUM_OF_ALPHABETS = 26;
    target = vector<int>(NUM_OF_ALPHABETS);
    
    return;
}
void assignCharComposition(vector<int> &v, string& target)
{
    for(int i =0; i<target.length(); i++)
        v[target[i]-97]++;
    
    return;
}
void InputString(string &str1, string &str2)
{
    cin >> str1 >> str2;
    return;
}
int checkDifferentChar(string &str1, string& str2)
{
    int dif =0; 
    for(int i =0; i<NUM_OF_ALPHABETS; i++)
        dif += abs(charCompositionStr1[i] - charCompositionStr2[i]);
        
    return dif;
}
int makeAnagram(string& str1, string& str2)
{
    InitailizeVector(charCompositionStr1);
    InitailizeVector(charCompositionStr2);
    
    assignCharComposition(charCompositionStr1, str1);
    assignCharComposition(charCompositionStr2, str2);
    
    return checkDifferentChar(str1, str2);
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str1;
    string str2;
    
    InputString(str1, str2);
    cout << makeAnagram(str1, str2);
    
}
