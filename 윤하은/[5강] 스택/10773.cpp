#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    cin >> k;
    
    stack<int> accountBook;
    int sum =0;
    for(int i =0; i<k; i++)
    {
        int num;
        cin >> num;
        if(num == 0) 
        {
            sum -= accountBook.top();
            accountBook.pop();
        }
        else
        {
            sum += num;
            accountBook.push(num);
        }
    }
    
    cout << sum;
    
}
