#include <bits/stdc++.h>
using namespace std;
int visitNum;

pair<int, int> visitV(pair<int, int> target, vector<vector<int>>& v)
{
    int dx[4] = {0, 0, 1, 1};
    int dy[4] = {0, 1, 0, 1};
    
    int nx, ny;
    
    for(int i = 0; i<4; i++)
    {
        nx = target.first + dx[i];
        ny = target.second + dy[i];
        
        v[nx][ny] = visitNum++;
    }
    
    pair<int, int> p = make_pair(nx, ny);
    return p;
    
}
void printV(int n, vector<vector<int>>& v)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, targetRow, targetCol;
    cin >> n >> targetRow >> targetCol;
    
    int size = pow(2, n);
    vector<vector<int>> v(size, vector<int>(size));
    
    pair<int, int> now = make_pair(0, 0);
    
    while(now.first >= 0 && now.first < size && now.second >= 0 && now.second < size)
    {
        //cout <<"while start\n";
        //printV(size, v);
        now = visitV(now, v);
        if(now.second == size-1)
        {
            now.first = now.first + 1;
            now.second = 0;
        }
        else
        {
            now.first = now.first - 1;
            now.second = now.second + 1;
        }
        
    }
    cout << v[targetRow][targetCol];
    
}
