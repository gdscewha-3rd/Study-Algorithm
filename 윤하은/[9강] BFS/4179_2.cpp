#include <bits/stdc++.h>
using namespace std;
int fire[1000][1000];
int dist[1000][1000];
char maze[1000][1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int row, col;

void printMaze()
{
    for(int i = 0 ;i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool escapeSuccess = false;
    queue<pair<int, int>> fireQ;
    queue<pair<int, int>> jihoonQ;
    cin >> row >> col;
    
    
    for(int i =0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'F')
            {
                fireQ.push({i, j});
                fire[i][j] = 1;
            }
            else if(maze[i][j] == 'J')
            {
                //처음부터 지훈이의 위치가 가장자리일 경우
                if(i == 0 || j == 0 ||i == row-1 || j == col-1) escapeSuccess = true;
                jihoonQ.push({i, j});
                dist[i][j] = 1;
            }
        }
    }
    
    while(!fireQ.empty() && !escapeSuccess)
    {
        pair<int, int> cur = fireQ.front();
        fireQ.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            //벽이거나 이미 불길이 번진 곳일 경우
            if(maze[nx][ny] == '#' || fire[nx][ny] != 0) continue;
            
            //OutofMaze 
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            fireQ.push({nx, ny});
    
        }
    }
    
    
    int result = 1;
    
    while(!jihoonQ.empty() && !escapeSuccess)
    {
        pair<int, int> cur = jihoonQ.front();
        jihoonQ.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            //벽이거나 이미 지훈이가 지나간 곳일 경우
            if(maze[nx][ny] == '#' || dist[nx][ny] != 0) continue;
        
            //OutofMaze 
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            
            int nDist = dist[cur.first][cur.second] + 1;
            
            //이미 불길이 번진 곳일 경우 지훈이 이동 불가
            if(fire[nx][ny] != 0 && nDist >= fire[nx][ny]) continue;
            if(nx == 0 || ny == 0 || nx == row-1 || ny == col-1)
            {
                escapeSuccess = true;
                result = nDist;
                //printMaze();
                break;
            }
            dist[nx][ny] = nDist;
            jihoonQ.push({nx, ny});
    
        }
    }
    
    if(escapeSuccess) cout << result;
    else cout << "IMPOSSIBLE";
    
    
}
