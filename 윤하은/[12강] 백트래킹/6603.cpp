#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    
    while(1)
    {
        cin >> k;
        if(k==0) break;
        
        int arr[20];
        for(int i = 0; i<k; i++)
            cin >> arr[i];
            
        int tmp[20];
        for(int i = 0; i<6; i++)
            tmp[i] = 0;
        for(int i = 6; i<k; i++)
            tmp[i] = 1;
            
        do
        {
            for(int i = 0; i<k; i++)
            {
                if(tmp[i] == 0)
                    cout << arr[i] << " ";
            }
            cout << "\n";
            
        }while(next_permutation(tmp, tmp+k));
        
        cout << "\n";
        
        
    }
    
    
}
