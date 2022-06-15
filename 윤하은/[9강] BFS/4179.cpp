#include <bits/stdc++.h>
using namespace std;
char board[1000][1000];
bool fire[1000][1000];
int dist[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int row, col;
typedef struct
{
    int x;
    int y;
    char blockType;
    
}block;
bool isEdge(int x, int y)
{
    if(x == 0 || x == row-1 || y == 0 || y == col-1)
     return true;
    else return false;
}
void printBoard()
{
    for(int i = 0 ;i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(fire[i][j]) cout << "F";
            else if(board[i][j] == '#') cout << 'x';
            else cout << dist[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> row >> col;
    
    queue<block> q;
    int jx, jy;
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'F')
            {
                fire[i][j] = true;
                q.push({i, j, board[i][j]});
                //cout << "push Fire " << i << ", " << j << "\n";
            }
            else if(board[i][j] == 'J')
            {
                jx = i;
                jy = j;
            }
        }
    }
    
    bool escapeSuccess = false;
    int result = 1;
    
    if(isEdge(jx, jy)) escapeSuccess = true;
    dist[jx][jy] = 1;
    q.push({jx, jy, board[jx][jy]});
    
    
    while(!q.empty() && !escapeSuccess)
    {
        
        block cur = q.front();
        q.pop();
        
        //printBoard(row, col);
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            //cout << nx <<", "<< ny << "\n";
        
            if(board[nx][ny] == '#') continue;
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) 
                continue;
                
            //불길일 경우
            if(cur.blockType == 'F')
            {
                //이미 불길이 번진 칸일 경우
                if(fire[nx][ny]) continue;
                fire[nx][ny] = true;
                q.push({nx, ny, 'F'});
            }
            //지훈이가 갈 수 있는 길일 경우
            else
            {
                if(dist[nx][ny] != 0 || fire[nx][ny]) continue;
                dist[nx][ny] = dist[cur.x][cur.y]+1;
                //가장자리에 도달
                if(isEdge(nx, ny))
                {    
                    escapeSuccess = true;
                    result = dist[nx][ny];
                    break;
                }
                q.push({nx, ny, 'J'});
            }
            
        }
    }
    
    if(escapeSuccess) cout << result;
    else cout << "IMPOSSIBLE";
    
    
    
}
