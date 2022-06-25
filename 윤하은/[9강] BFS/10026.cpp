#include <bits/stdc++.h>
using namespace std;
char colors[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
int bfsColors(char color, char color2)
{
    vector<vector<bool>> isVisit(n, vector<bool>(n));
    int result = 0;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if((colors[i][j] == color || colors[i][j] == color2) && !isVisit[i][j])
            {
                queue<pair<int, int>> q;
                
                q.push({i, j});
                isVisit[i][j] = true;
                
                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    
                    for(int k = 0; k<4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(isVisit[nx][ny] || !(colors[nx][ny] == color || colors[nx][ny] == color2)) 
                            continue;
                        q.push({nx, ny});
                        isVisit[nx][ny] = true;
                    }
                }
                result++;
            }
        }
    }
    return result;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            cin >> colors[i][j];
        }
    }
    
    int redNum = bfsColors('R', 'R');
    int greenNum = bfsColors('G', 'G');
    int blueNum = bfsColors('B', 'B');
    
    int redGreenNum = bfsColors('R', 'G');
    
    cout << redNum+greenNum+blueNum << " ";
    cout << redGreenNum + blueNum;
    
}
