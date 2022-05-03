#include <bits/stdc++.h>
using namespace std;
void calculateComposition(vector<int>& v, int num)
{
    while(num > 0)
    {
        v[num%10]++;
        num/=10;
    }
    return;
}
void calculateCompositionS(vector<int>& v, int num)
{
    string str = to_string(num);
    
    for(char c : str)
        v[c-'0']++;
    return;
}
void printVector(vector<int>& v)
{
    for(int num : v)
        printf("%d\n", num);
}
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    vector<int> v(10, 0);
    calculateComposition(v, a*b*c);
    
    printVector(v);
    
}