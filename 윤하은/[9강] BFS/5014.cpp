#include <bits/stdc++.h>
using namespace std;
/*
f층으로 이루어짐
g층에 사무실
현재 위치 s층
u버튼 -> u층으로 이동
d버튼 -> d층으로 이동
(이동불가라면 아예 이동 x)

*/
int elevator[1000001];
bool isVisit[1000001];
int result[1000001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int totalFloor, destination, posNow, buttonU, buttonD;
    cin >> totalFloor >> posNow >> destination >> buttonU >> buttonD;

    if(destination == posNow)
    {
        cout << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(posNow);
    isVisit[posNow] = true;
    //result[posNow] = 0;

    int dx[2] = {buttonU, -buttonD};
    

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0; i<2; i++)
        {
            int nx = cur + dx[i];
            //cout << "now checking... " << nx << "\n";

            if(nx <= 0 || nx > totalFloor) continue;
            if(isVisit[nx]) continue;
            
            
            //cout << "push " << nx << "to queue... \n";
            result[nx] = result[cur]+1;
            q.push(nx);
            isVisit[nx] = true;

            if(nx == destination)
            {
                cout << result[nx];
                return 0;
            }
        }

    }

    cout << "use the stairs";


}