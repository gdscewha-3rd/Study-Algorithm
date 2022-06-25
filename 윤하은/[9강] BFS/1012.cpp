#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testNum;
    cin >> testNum;
    
    for(int i = 0; i<testNum; i++)
    {
        int field[50][50];
        bool isVisit[50][50];
        pair<int, int> pos[2500];
        
        int row, col, numOfCabbage;
        int result = 0;
        cin >> col >> row >> numOfCabbage;
        
        //배추 위치 입력
        for(int j = 0; j<numOfCabbage; j++)
        {
            int x, y;
            cin >> y >> x;
            
            field[x][y] = 1;ㅋ
            pos[j] = {x, y};
        }
        
        for(int j = 0; j<numOfCabbage; j++)
        {
            pair<int, int> bfsStart = pos[j];
            if(isVisit[bfsStart.first][bfsStart.second]) continue;
            cout << "bfsStart : " << bfsStart.first <<", "<< bfsStart.second << "\n";
            result++;
            
            queue<pair<int, int>> q;
        
            q.push(bfsStart);
            isVisit[bfsStart.first][bfsStart.second] = true;
            
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                
                for(int k = 0; k<4; k++)
                {
                    
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    cout << "checking : " << nx << ", " <<ny << "\n";
                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if(isVisit[nx][ny] || field[nx][ny] == 0) continue;
                    
                    isVisit[nx][ny] = true;
                    q.push({nx, ny});
                    cout << "okay : " << nx << ", " <<ny << "\n";
                }
                
                
            }
        }
        
        cout << result << "\n";
    }
    
    
    
    
    
}
