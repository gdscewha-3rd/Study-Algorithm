#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;
bool board[20][20];
//board[x][y] == true //x행 y열에 퀸 말을 배치함

void printBoard()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
bool canPutQueen(int x, int y)
{
    //같은 열, 행에 퀸이 존재하는지 확인
    for(int i = 0; i<n; i++)
    {
        if(board[x][i]) return false;
        if(board[i][y]) return false;
    }

    //대각선 확인 순서 : 왼쪽위, 오른쪽위, 왼쪽아래, 오른쪽아래
    int dx[4] = {-1, 1, -1, 1};
    int dy[4] = {-1, -1, 1, 1};

    for(int i = 0; i<4; i++)
    {
        int targetX = x + dx[i];
        int targetY = y + dy[i];

        while(targetX >= 0 && targetX < n && targetY >=0 && targetY < n)
        {
            if(board[targetX][targetY]) return false;
            targetX += dx[i];
            targetY += dy[i];
        }
    }

    return true;
}
//cur 번째 행에 퀸 말 배치
void func(int cur)
{
    if(cur == n)
    {
        cnt++;
        return;
    }
    else
    {
        
        for(int i = 0; i<n; i++)
        {
            if(!board[cur][i] && canPutQueen(cur, i))
            {
                board[cur][i] = true;
                func(cur+1);
                board[cur][i] = false;
            }
        }
        

    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    func(0);

    cout << cnt;
}