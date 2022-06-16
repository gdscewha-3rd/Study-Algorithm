#include <bits/stdc++.h>
using namespace std;

char board[100][100];
bool isVisit[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct block
{
    int x;
    int y;
    int dis;
    
}block;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row, col;
    cin >> row >> col;
    
    
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            cin >> board[i][j];
        }
    }
    
    queue<block> q;
    q.push({0,0,1});
    isVisit[0][0] = true;
    int result = 100000;
    while(!q.empty())
    {
        block cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int ndis = cur.dis + 1;
            
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(board[nx][ny] == '0' || isVisit[nx][ny]) continue;
            q.push({nx, ny, ndis});
            isVisit[nx][ny] = true; 
            if(nx == row-1 && ny == col-1 && result > ndis)
                result = ndis;
        }
    }
    
    cout << result;
    
}
