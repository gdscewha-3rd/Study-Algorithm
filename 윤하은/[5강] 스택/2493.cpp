#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int towerHeight;
    int idx;
}tower;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int towerNum;
    cin >> towerNum;
    stack<tower> towers;
    
    for(int i =0; i<towerNum; i++)
    {
        tower t;
        cin >> t.towerHeight;
        t.idx = i+1;
        if(towers.empty()) cout << "0 ";
        else
        {
            while(!towers.empty() && towers.top().towerHeight < t.towerHeight) 
                towers.pop();
            
            if(towers.empty()) cout << "0 ";
            else cout << towers.top().idx << " ";
        }
        towers.push(t);
    }
}
