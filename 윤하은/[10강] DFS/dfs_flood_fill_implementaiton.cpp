#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool isVisit[502][502];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
    
    int result = 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(isVisit[i][j]) continue;
            if(board[i][j] == uncolored) continue;
            
            stack<pair<int, int>> s;
            s.push({i, j});
            isVisit[i][j] = true;
            
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
                    
                }
            }
            result++;
        }
    }
    
    cout << result;
    
    
}
