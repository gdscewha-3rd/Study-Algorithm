#include <bits/stdc++.h>
using namespace std;
int box[101][101][101];
int dist[101][101][101];

//확인 순서 : 상하좌우(2차원기준)위층아래층
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row, col, h;
    cin >> col >> row >> h;
    
    queue<tuple<int, int, int>> q;
    
    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<row; j++)
        {
            for(int k = 0; k<col; k++)
            {
                cin >> box[i][j][k];
                
                //익은 토마토일 경우
                if(box[i][j][k] == 1)
                {
                    q.push({i, j, k});
                    //방문여부 확인을 위해 1부터 시작 -> 결과 출력할때 1빼고 출력
                    dist[i][j][k] = 1;
                }
            }
        }
    }
    
    
    //처음부터 모두 익은 토마토인지 확인해주기
    bool isAlreadyRipen = true;
    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<row; j++)
        {
            for(int k =0; k<col; k++)
            {
                if(box[i][j][k] == 0)
                    isAlreadyRipen = false;
            }
        }
    }
    
    if(isAlreadyRipen)
    {
        cout << "0";
        return 0;
    }
    
    while(!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i<6; i++)
        {
            int nz = get<0>(cur) + dz[i];
            int nx = get<1>(cur) + dx[i];
            int ny = get<2>(cur) + dy[i];
            
            //outofindex
            if(nz < 0 || nz >= h || nx <0 || nx >= row || ny < 0 || ny >= col)
                continue;
            
            //토마토가 들어있지 않은 칸일 경우
            if(box[nz][nx][ny] == -1)
                continue;
            
            //이미 방문한 칸일 경우
            if(dist[nz][nx][ny] != 0)
                continue;
                
        
            q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
        
        /*for(int i = 0; i<h; i++)
        {
            printf("%dth floor\n", i);
            for(int j = 0; j<row; j++)
            {
                for(int k = 0; k<col; k++)
                {
                    if(box[i][j][k] == -1) printf("x "); 
                    else printf("%d ", dist[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }*/
    }
    
    //토마토가 모두 익지 못하는 경우 체크 -> dist사용
    int result = 0;
    
    for(int i =0; i<h; i++)
    {
        for(int j = 0; j<row; j++)
        {
            for(int k =0; k<col; k++)
            {
                //토마토가 있는 칸인데 방문하지 못했다면
                if(box[i][j][k] != -1 && dist[i][j][k] < 1)
                {
                    cout << "-1";
                    return 0;
                }
                //result = max(dist);
                if(dist[i][j][k] > result)
                    result = dist[i][j][k];
            }
        }
    }
    cout << result-1;
}
