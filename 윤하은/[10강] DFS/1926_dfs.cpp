#include <bits/stdc++.h>
using namespace std;

int board[501][501];
bool isVisit[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int uncolored = 0;
    int row, col;
    cin >> row >> col;
    
    bool noPic = true;
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1) noPic = false;
        }
    }
    
    if(noPic)
    {
        cout << 0 << "\n" << 0;
        return 0;
    }
    
    
    
    int result = 0;
    int picNum = 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(isVisit[i][j]) continue;
            if(board[i][j] == uncolored) continue;
            
            stack<pair<int, int>> s;
            s.push({i, j});
            isVisit[i][j] = true;
            int picArea = 1;
            
            while(!s.empty())
            {
                pair<int, int> cur = s.top();
                s.pop();
                
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    if(nx <0 || nx >= row || ny <0 || ny >= col)
                        continue;
                        
                    if(isVisit[nx][ny] || board[nx][ny] == uncolored)
                        continue;
                        
                    s.push({nx, ny});
                    isVisit[nx][ny] = true;
                    picArea++;
                    
                }
            }
            
            picNum++;
            if(picArea > result)
                result = picArea;
        }
    }
    
    cout << picNum << "\n" << result;
    
    
}
