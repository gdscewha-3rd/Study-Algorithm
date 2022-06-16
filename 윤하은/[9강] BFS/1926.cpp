#include <bits/stdc++.h>
using namespace std;
#define x first;
#define y second;
int board[500][500];
bool isVisit[500][500];
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
        for(int j = 0; j<col; j++)
            cin >> board[i][j];
    }
    
    int picNum = 0;
    int maxArea = 0;
    
    for(int i = 0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            if(board[i][j] == 1 && !isVisit[i][j])
            {
                queue<pair<int, int>> q;
                //cout << "now start : " << i<< " " << j <<"\n";
                int area = 1;
                isVisit[i][j] = true;
                q.push({i, j});
                //cout << q.front().first << " " << q.front().second <<"\n";
                
                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    
                    for(int k = 0; k<4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        //cout << "1. "<<nx <<" " << ny <<"\n";
                        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                        if(isVisit[nx][ny] || board[nx][ny] == 0) continue;
                        //cout <<"2. " << nx <<" " << ny <<"\n";
                        q.push({nx, ny});
                        area++;
                        isVisit[nx][ny] = true;
                    }
                }
                if(area > maxArea) maxArea = area;
                picNum++;
            }
        }
    }
    cout << picNum << "\n" << maxArea;
    
}
