#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int NUM_OF_ALPHABETS = 26;
    
    vector<int> charComposition(NUM_OF_ALPHABETS, 0);
    
    string str;
    cin >> str;
    
    for(char c : str)
        charComposition[c-'a']++;
        
    for(int num : charComposition)
        cout << num << " ";
}