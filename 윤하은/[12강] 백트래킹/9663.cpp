#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;
int board[20][20];
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
void cannotExist(int targetX, int targetY)
{
    for(int i = 0; i<n; i++)
    {
        board[targetX][i] = 1;
        board[i][targetY] = 1;
    }
    int x = targetX;
    int y = targetY;
    
    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x++][y++] = 1;
    }

    x = targetX;
    y = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x--][y--] = 1;
    }

    x = targetX;
    y = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x++][y--] = 1;
    }

    x = targetX;
    x = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x--][y++] = 1;
    }

    return;
}
void canExist(int targetX, int targetY)
{
    for(int i = 0; i<n; i++)
    {
        board[targetX][i] = 0;
        board[i][targetY] = 0;
    }
    int x = targetX;
    int y = targetY;
    
    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x++][y++] = 0;
    }

    x = targetX;
    y = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x--][y--] = 0;
    }

    x = targetX;
    y = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x++][y--] = 0;
    }

    x = targetX;
    x = targetY;

    while(x >= 0 && x < n && y >= 0 && y < n)
    {
        board[x--][y++] = 0;
    }

    return;
}
//cur 번째 행에 퀸 말 배치
void func(int cur)
{
    if(cur == n)
    {
        if(cnt > 10)
            exit(0);
        cnt++;
        cout << "cnt" << cnt << "\n"; 
        printBoard();
        return;
    }
    else
    {
        
        for(int i = 0; i<n; i++)
        {
            if(board[cur][i] == 0)
            {
                cannotExist(cur, i);
                board[cur][i] = 2;
                cout << "***now board***\n";
                printBoard();
                func(cur+1);
                canExist(cur, i);
                board[cur][i] = 0;
                cout << "***now board***\n";
                printBoard();
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