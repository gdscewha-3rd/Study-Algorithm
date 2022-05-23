#include <bits/stdc++.h>
using namespace std;

void printV(vector<vector<int>>& v, int& n)
{
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, target;
    cin >> n >> target;
    int n2 = n*n;
    
    vector<vector<int>> snail(n, vector<int>(n));
    
    //row가 증감하는 방향으로 idx가 바뀌는지
    bool isRow = true;
    
    bool isAscendingR = true;
    bool isAscendingC = true;
    int row = 0, col = 0;
    int posR, posC;
    while(n2 >= 1)
    {
        if(n2 == target)
        {
            posR = row;
            posC = col;
        }
        //row의 idx가 변화중일 때
        if(isRow)
        {
            if(isAscendingR)
            {
                snail[row++][col] = n2--;
                if(row == n)
                {    
                    isRow = false;
                    row = n-1;
                    col++;
                    isAscendingR = !isAscendingR;
                }
                else if(snail[row][col] != 0)
                {
                    isRow = false;
                    row--;
                    col++;
                    isAscendingR = !isAscendingR;
                }
            }
            else//row가 감소
            {
                snail[row--][col] = n2--;
                if(row == -1)
                {
                    isRow = false;
                    row = 0;
                    col--;
                    isAscendingR = !isAscendingR;
                }
                else if(snail[row][col] != 0)
                {
                    isRow = false;
                    row++;
                    col--;
                    isAscendingR = !isAscendingR;
                }
                
            }
        }
        
        //col의 idx가 변화중일 때
        else
        {
            if(isAscendingC)
            {
                snail[row][col++] = n2--;
                if(col == n)
                {    
                    isRow = true;
                    col = n-1;
                    row--;
                    isAscendingC = !isAscendingC;
                }
                else if(snail[row][col] != 0)
                {
                    isRow = true;
                    col--;
                    row--;
                    isAscendingC = !isAscendingC;
                }
            }
            else//col이 감소
            {
                snail[row][col--] = n2--;
                if(col == -1)
                {
                    isRow = true;
                    col = 0;
                    row++;
                    isAscendingC = !isAscendingC;
                }
                else if(snail[row][col] != 0)
                {
                    isRow = true;
                    col++;
                    row++;
                    isAscendingC = !isAscendingC;
                }
                
            }
            
        }
        
    }
    
    printV(snail, n);
    cout << posR+1 << " " << posC+1;
    

}
