#include <bits/stdc++.h>
using namespace std;
int blueNum, whiteNum;
bool paper[128][128];
bool isSame(pair<int, int> start, int n)
{
    bool tmp = paper[start.first][start.second];
    for(int i = start.first; i<n; i++)
    {
        for(int j = start.second; j<n; j++)
        {
            if(tmp != paper[i][j])
                return false;
        }
    }
    
    return true;
}
void cutPaper(pair<int, int> start, int n)
{
    if(isSame(start, n) || n == 1)
    {
        if(paper[start.first][start.second])
            blueNum++;
        else whiteNum++;
        return;
    }
    else
    {
        
       //todo: for문으로 바꾸기
       cutPaper(start, n/2);
       cutPaper(make_pair(start.first, start.second + (n/2)), n/2);
       cutPaper(make_pair(start.first + (n/2), start.second, n/2);
       cutPaper(make_pair(start.first + n/2, start.second+n/2, n/2));
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cutPaper(make_pair(0, 0), n);
}
