#include <bits/stdc++.h>
using namespace std;
/*
총 이동가능한 칸 : 8칸


*/
int dx[8] = {-2, -1, 1, 2, -2, -1, 2, 1};
int dy[8] = {-1, -2, -2, -1, 1, 2, 1, 2};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testNum;
    cin >> testNum;
    
    for(int i = 0; i<testNum; i++)
    {
        int row, col;
        cin >> row;
        col = row;
        
        vector<vector<int>> board(row, vector<int>(col));
        pair<int, int> posNow;
        pair<int, int> posDestination;
        
        
        cin >> posNow.first >> posNow.second;
        cin >> posDestination.first >> posDestination.second;
        
        
        int result = 1;
        bool isArrived = false;
        
        //출발지와 목적지가 같은 경우
        if(posNow.first == posDestination.first && posNow.second == posDestination.second)
            isArrived = true;
        
        //isVisit 사용하지 않기 위해서 출발점의 board 값을 1로 설정
        queue <pair<int, int>> q;
        q.push(posNow);
        board[posNow.first][posNow.second] = 1;
        
        
        while(!q.empty() && !isArrived)
        {
            pair<int, int> cur = q.front();
            q.pop();
            
            for(int j = 0; j<8; j++)
            {
                int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];
                
                //벡터 범위밖을 넘어갔을 경우
                if(nx < 0 || nx >= row || ny < 0 || ny >= col)
                    continue;
                    
                //이미 방문한 곳일 경우
                if(board[nx][ny] != 0) continue;
                
                q.push({nx, ny});
                board[nx][ny] = board[cur.first][cur.second] + 1;
                
                //목적지 도착
                if(nx == posDestination.first && ny == posDestination.second)
                {
                    isArrived = true;
                    result = board[nx][ny];
                    break;
                }
            }
            
            
        }
        
        cout << --result << "\n";
    }
}
