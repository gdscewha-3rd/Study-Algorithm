#include <bits/stdc++.h>
using namespace std;

int box[1000][1000];
int days[1000][1000];
bool isVisit[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    queue<pair<int, int>> q;
    
    int row, col;
    cin >> col >> row;
    
    for(int i =0; i<row; i++)
    {
        for(int j =0; j<col; j++)
            cin >> box[i][j];
    }
    
    //(익은 토마토 == 시작점들)을 찾아서 큐에 넣기 
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(box[i][j] == 1)
            {
                isVisit[i][j] = true;
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    }
    
    int result = 0;
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) 
                continue;
            if(isVisit[nx][ny] || box[nx][ny] == -1) 
                continue;
                
            //cout << "now visit {" << nx <<", "<< ny << "}\n";
            isVisit[nx][ny] = true;
            q.push({nx, ny});
            days[nx][ny] = days[cur.first][cur.second] + 1;
            result = days[nx][ny];
        }
    }
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(isVisit[i][j] == false && box[i][j] == 0)
                result = -1;
        }
    }
    cout << result;
    
    
    
}
