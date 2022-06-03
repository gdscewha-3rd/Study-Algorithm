#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int height;
    int canSeeMe;
}building;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int buildingNum;
    cin >> buildingNum;
    stack<building> buildings;
    
    int result = 0;
    for(int i =0; i<buildingNum; i++)
    {
        int h;
        cin >> h;
        building tmp;
        tmp.height = h;
        tmp.canSeeMe = 0;
        while(!buildings.empty() && buildings.top().height <= h)
            buildings.pop();
        
        if(buildings.empty())
            buildings.push(tmp);
            
        else//나보다 큰 빌딩이 있어서 pop을 그만둔 경우
        {
            tmp.canSeeMe = buildings.top().canSeeMe + 1;
            result += tmp.canSeeMe;
            buildings.push(tmp);
        }
    }
    cout << result;
}
