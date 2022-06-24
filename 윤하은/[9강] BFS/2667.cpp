#include <bits/stdc++.h>
using namespace std;

char apart[25][25];
bool isVisit[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> result;
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> apart[i][j];
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(apart[i][j] == '0') continue;
            if(isVisit[i][j]) continue;
            
            queue<pair<int, int>> q;
            
            q.push({i, j});
            int apartNum = 1;
            isVisit[i][j] = true;
            
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if(isVisit[nx][ny]) continue;
                    if(apart[nx][ny] == '0') continue;
                    
                    q.push({nx, ny});
                    isVisit[nx][ny] = true;
                    apartNum++;
                }
            }
            
            result.push_back(apartNum);
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    
    for(int i = 0; i< result.size(); i++)
        cout << result[i] << "\n";
        
    
    
}
