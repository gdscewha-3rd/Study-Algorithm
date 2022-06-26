#include <bits/stdc++.h>
using namespace std;

int ground[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row;
    col = row;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cin >> ground[i][j];
        }
    }
    //왜 역참조가 안되지????
    //cout << "maxElement" << *max_element(ground, ground+(101*101)) << "\n"; 
    int maxHeight = 0;
    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(maxHeight < ground[i][j])
                maxHeight = ground[i][j];
        }
    }

    int maxResult = 0;
    for(int i = 1; i<=maxHeight; i++)
    {
        //i이하의 높이의 땅은 물에 잠김 -> 안전한 영역의 수를 구해야함
        //안전한 영역에 대해 bfs 돌리기 => i이하면 continue
        cout << "i : " << i <<"\n";
        int result = 0;

        //i높이를 기준으로 전체 bfs를 돌리는 거니까 여기 위치가 맞는듯..??
        bool isVisit[101][101];
        for(int j = 0; j<row; j++)
        {
            for(int k = 0; k<col; k++)
            {

                //isVisit 재설정 위치 헷갈림...
                
                if(ground[j][k] <= i) 
                {
                    cout << j<<", " << k<<" stopped : the ground is so low\n";
                    continue;
                }
                if(isVisit[j][k]) 
                {
                    cout << j<<", " << k <<" stopped : already visited\n";
                    continue;
                }
                queue<pair<int, int>> q;
                q.push({j, k});
                isVisit[j][k] = true;
                cout << "starting point : " << j << ", " << k << "\n";

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for(int l = 0; l<4; l++)
                    {
                        int nx = cur.first + dx[l];
                        int ny = cur.second + dy[l];

                        if(nx < 0 || nx >= row || ny < 0 || ny >= col)
                            continue;

                        if(isVisit[nx][ny]) continue;
                        if(ground[nx][ny] <= i) continue;

                        cout << "new element! pushed : " << nx << ", " << ny << "\n"; 
                        q.push({nx, ny});
                        isVisit[nx][ny] = true;

                    }


                }
                result++;
                cout << "now checking... : " << j <<", " << k << "\n";
                cout << "numOfSafezone for "<< i << " : "<< result << "\n"; 

                
            }

        }

        if(result > maxResult)
            maxResult = result;


    }

    cout << maxResult;
}