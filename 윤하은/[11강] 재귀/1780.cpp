#include <bits/stdc++.h>
using namespace std;
int paper[37][37];
int paperNum[3];
//papaerNum[x+1] = x로만 채워진 종이의 갯수
bool isSame(int rStart, int rEnd, int cStart, int cEnd)
{
    int num = paper[rStart][cStart];
    for(int i = rStart; i<=rEnd; i++)
    {
        for(int j = cStart; j<=cEnd; j++)
        {
            if(num != paper[i][j]) return false;
        }
    }
    
    return true;
    
}
void cutPaper(int rStart, int rEnd, int cStart, int cEnd)
{
    //종이의 숫자가 같을 때
    if(isSame(rStart, rEnd, cStart, cEnd))
    {
        papaerNum[paper[rStart][cStart]+1]++;
        return;
    }
    else
    {
        int tmp = (rEnd-rStart+1)/3;
        for(int i = 0; i<tmp; i++)
            cutPaper(rStart+i*tmp, rStart+i*tmp+tmp-1, cStart+i*tmp, cStart+i*tmp+tmp-1);
    }
}
int main(void)
{
    ios:sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cin >> paper[i][j];
    }
    
    cutPaper(0, n-1, 0, n-1);
    
    for(int i = 0; i<3; i++)
        cout << papaerNum[i] << "\n";
    
    
}
