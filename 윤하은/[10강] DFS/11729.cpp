#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int result;
void hanoi(int n, int start, int destination)
{
    if(n == 1) {
        v.push_back(to_string(start)+" "+to_string(destination));
        result++;
    }
    else 
    {
        hanoi(n-1, start, 6-start-destination);
        v.push_back(to_string(start)+" "+to_string(destination));
        result++;
        hanoi(n-1, 6-start-destination, destination);
        
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int diskNum;
    cin >> diskNum;
    hanoi(diskNum, 1, 3);
    cout << result << "\n";
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    
    
}
