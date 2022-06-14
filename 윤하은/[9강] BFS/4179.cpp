#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int dist[1000][1000];

//상하좌우 순으로 접근
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row, col;
    cin >> row >> col;
    
    queue<pair<int, int>> q;
    
    //dist 배열에서 불길은 -1로 표현
    //거리는 1부터 표현 (결과 낼 때 -1해주기)
    //방문안한 부분 -> 0인 것 주의
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'J')
            {
                dist[i][j] = 1;
                q.push({i, j});
                //cout << "push Jihoon " << i << ", " << j << "\n";
            }
            else if(board[i][j] == 'F')
            {
                dist[i][j] = -1;
                q.push({i, j});
                //cout << "push Fire " << i << ", " << j << "\n";
            }
        }
    }
    
    bool escapeSuccess = false;
    int result = 0;
    
    while(!q.empty())
    {
        
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //cout << nx <<", "<< ny << "\n";
            if(board[nx][ny] == '#' || dist[nx][ny] != 0) {
                //cout << "check1\n"; 
                continue;
                
            }
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) 
            {
                //cout << "check2\n"; 
                continue;
            }
            int curState = dist[cur.first][cur.second];
            //불길일 경우
            if(curState == -1)
            {
                dist[nx][ny] = -1;
                q.push({nx, ny});
            }
            else
            {
                dist[nx][ny] = curState+1;
                q.push({nx, ny});
                //가장 자리에 도달
                if(nx == 0 || nx == row-1 || ny == 0 || ny == col-1)
                {
                    result = dist[nx][ny];
                    escapeSuccess = true;
                    break;
                }
                
            }
            //cout << dist[nx][ny] << " : " << nx <<", "<< ny << "\n";
            
        }
    }
    
    if(escapeSuccess) cout << result;
    else cout << "IMPOSSIBLE";
    
    
}
