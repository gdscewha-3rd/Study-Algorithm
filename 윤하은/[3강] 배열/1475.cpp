#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    vector<int> numComposition(10, 0);
    
    for(char c:str)
        numComposition[c-'0']++;
    
    int sumOf69 = numComposition[6]+numComposition[9];
    numComposition[6] = sumOf69/2;
    numComposition[9] = sumOf69-numComposition[6];
    
    cout << *max_element(numComposition.begin(), numComposition.end());
    
}