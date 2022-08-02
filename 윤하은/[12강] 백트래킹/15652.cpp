#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isUsed[10];
int arr[10];

void func(int k)
{
    if(k == m+1)
    {
        for(int i = 1; i <= m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        for(int i = 1; i<= n; i++)
        {
            if(arr[k-1] <= i)
            {
                arr[k] = i;
                func(k+1);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    func(1);
    
}
