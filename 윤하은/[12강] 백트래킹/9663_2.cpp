#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;
bool board[20][20];
//board[x][y] == true //x행 y열에 퀸 말을 배치함
bool isUsedY[20];
bool isUsedXY[40];
bool isUsedX_Y[40];

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
    if(isUsedY[y]) return false;
    if(isUsedXY[x+y]) return false;
    if(isUsedX_Y[x-y+n-1]) return false;

    return true;
}
void putQueen(int x, int y)
{
    board[x][y] = true;
    isUsedY[y] = true;
    isUsedXY[x+y] = true;
    isUsedX_Y[x-y+n-1] = true;
    return;

}
void removeQueen(int x, int y)
{
    board[x][y] = false;
    isUsedY[y] = false;
    isUsedXY[x+y] = false;
    isUsedX_Y[x-y+n-1] = false;
    return;
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
                putQueen(cur, i);
                func(cur+1);
                removeQueen(cur, i);
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