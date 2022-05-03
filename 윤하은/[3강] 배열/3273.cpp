#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int numOfElements=0;
    scanf("%d", &numOfElements);
    
    vector<bool> numComposition(1000001, false);
    vector<int> seq(numOfElements);
    
    for(int i =0; i<numOfElements; i++)
        scanf("%d", &seq[i]);
        
    int target = 0;
    scanf("%d", &target);
    int result = 0;
    
    for(int i =0; i<numOfElements; i++)
    {
        int remain = target-seq[i];
        if(remain < 1 || remain > 1000000) continue;
        if(numComposition[remain]) result++;
        numComposition[seq[i]] = true;
    }
    
    printf("%d", result);
}