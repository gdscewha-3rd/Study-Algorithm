#include <bits/stdc++.h>
using namespace std;
int board[100][100];
bool isVisit[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, squareNum;
    cin >> y >> x >> squareNum;
    cout << x << ", " << y;
/*
    //직사각형 입력
    for(int i = 0; i<squareNum; i++)
    {
        pair<int, int> leftDown, rightUp;
        cin >> leftDown.first >> leftDown.second;
        cin >> rightUp.first >> rightUp.second;
        rightUp.first--;
        rightUp.second--;

        for(int j = rightUp.first; j>= leftDown.first; j--)
        {
            for(int k = rightUp.second; k>= leftDown.second; k--)
            {
                //if(board[j][k] != 0) continue;
                board[j][k] = 1;
                cout << "squre : {" << j << ", "<< k << "}\n";
            }
        }

    }

    for(int i = y; i>=0; i--)
    {
        for(int j = 0; j<x; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    int result = 0;
    vector<int> v;
    
    for(int i = 0; i< x; i++)
    {
        for(int j = 0; j<y; j++)
        {
            //이미 방문한 곳이거나 직사각형일 경우 
            if(board[i][j] != 0 || isVisit[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            isVisit[i][j] = true;
            cout << "starting point : {" << i << ", " << j << "\n"; 

            int area = 0;
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                 
                for(int k = 0; k<4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= x || ny <0 || nx >= y) continue;
                    if(board[nx][ny] != 0 || isVisit[nx][ny]) continue;

                    cout << "now checkig'''' : {" << nx << ", " << ny << "\n"; 
                    area++;
                    q.push({nx, ny});
                    isVisit[nx][ny] = true;
                }
            }

            result++;
            v.push_back(area);

        }
    }

    sort(v.begin(), v.end());

    cout << result << "\n";

    for(int i = 0; i<v.size(); i++)
        cout << v[i] << " ";*/


}