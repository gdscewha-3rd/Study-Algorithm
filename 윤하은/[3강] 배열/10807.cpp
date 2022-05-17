#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> numComposition(201, 0);
    
    int numOfNum = 0;
    scanf("%d", &numOfNum);
    
    for(int i =0; i<numOfNum; i++)
    {
        int num =0;
        scanf("%d", &num);
        numComposition[num+100]++;
    }
    
    int target =0;
    scanf("%d", &target);
    
    printf("%d",numComposition[target+100]);
    
}