#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
    const int SUM_TARGET = 100;
    int numsComposition[101] = {0,};
    
    for(int i = 0; i<N; i++)
    {    
        int remain = SUM_TARGET-arr[i];
        if(numsComposition[remain] == 1) return true;
        numsComposition[arr[i]] = 1;
    }
    
    return 0;
    
}

int main(void)
{
    int arr[] = {50, 50, 48};
    int N = sizeof(arr)/sizeof(arr[0]);
    printf("%d", func2(arr, N));
}