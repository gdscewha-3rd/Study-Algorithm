#include <bits/stdc++.h>
using namespace std;
void printD(deque<int>& x)
{
    for(int i = 0; i<x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}
void leftMove(deque<int>& x)
{
    int tmp = x[0];
    for(int i = 0; i<x.size()-1; i++)
        x[i] = x[i+1];
    
    x[x.size()-1] = tmp;
    //printD(x);
}
void rightMove(deque<int>& x)
{
    int tmp = x[x.size()-1];
    
    for(int i = x.size()-1;i>0;i--)
        x[i] = x[i-1];
        
    x[0] = tmp;
    //printD(x);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    deque<int> dq;
    
    int result =0;
    for(int i = 1; i<=n; i++)
        dq.push_back(i);
    //1 2 3 4 5 6 7 8 9 10
    for(int i =0; i<m; i++)
    {
        int target;
        cin >> target;
        int moveNum;
        bool direction;
        
        
        if(dq.front() == target)
        {
            dq.pop_front();
            continue;
        }
        
        else
        {
            int targetIdx = find(dq.begin(), dq.end(), target)-dq.begin();
            //cout << "targetIdx : " << targetIdx;
            
            //왼쪽으로 이동시키는게 이득
            if(targetIdx <= dq.size()/2)
            {
                
                result += targetIdx;
                for(int j = 0; j<targetIdx; j++)
                    leftMove(dq);
                dq.pop_front();
            }
            
            //오른쪽으로 이동시키는게 이득
            else
            {
                targetIdx = dq.size()-targetIdx;
                result += targetIdx;
                for(int j = 0; j<targetIdx; j++)
                    rightMove(dq);
                dq.pop_front();
            }
            
        }
        
    }
    
    cout << result;
}
