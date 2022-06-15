#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int dx[2] = {-1, 1};
bool bfs(queue<int>& q, int nx, int cur, int sis)
{
    //배열 범위 밖일 경우
    if(nx < 0 || nx > 100000) return false;
            
    //이미 방문한 곳일 경우
    if(dist[nx] != 0) return false;
            
    dist[nx] = dist[cur] + 1;
    q.push(nx);
            
    //동생찾기 성공
    if(nx == sis)
    {
        cout << dist[nx]-1;
        return true;
    }
    
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int soobinLocation, sisterLocation;
    cin >> soobinLocation >> sisterLocation;
    
    if(soobinLocation == sisterLocation)
    {    
        cout << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(soobinLocation);
    
    //visit 배열을 따로 두지 않기 위해 초기값 1로 설정
    //result 출력시 -1 해줘야함
    dist[soobinLocation] = 1;
    
    
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i<2; i++)
        {
            if(bfs(q, cur+dx[i], cur, sisterLocation))
                return 0;
        }
        
        if(bfs(q, cur * 2, cur, sisterLocation))
            return 0;
       
    }
    
    
}
