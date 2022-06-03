//220601 시간초과
#include <bits/stdc++.h>
using namespace std;

//뒤집기 함수 
void reverseDeque(deque<int>& dq)
{
    int size = dq.size();
    vector<int> tmp(size);
    
    if(size > 0)
    {
        for(int i = 0; i<size; i++)
        {
            tmp[i] = dq.back();
            dq.pop_back();
        }
        
        for(int i = 0; i<size; i++)
            dq.push_back(tmp[i]);
        
    }
}
void printDeque(deque<int>& dq)
{
    if(dq.empty()) cout << "[]\n";
    else
    {
        cout << "[";
        for(int i  =0; i<dq.size()-1; i++)
            cout << dq[i] << ",";
    
        cout << dq[dq.size()-1] << "]\n";
        
    }
}
void initDeque(deque<int>& dq, int size)
{
    char tmp;
    cin >> tmp;
    for(int i = 0; i<size; i++)
    {
        int num;
        char ch;
        cin >> num >> ch;
        dq.push_back(num);
    }
    if(size == 0)
        cin >> tmp;
    
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testNum;
    cin >> testNum;
    
    for(int i = 0; i<testNum; i++)
    {
        deque<int> dq;
        string funcOperator;
        cin >> funcOperator;
        bool error = false;
        
        int size;
        cin >> size;
        
        initDeque(dq, size);
        //printDeque(dq);
        
        for(int j = 0; j<funcOperator.size(); j++)
        {
            if(funcOperator[j] == 'R')//순서뒤집기 함수
                reverseDeque(dq);
            
            else//funcOperator[j] == 'D'//맨 앞 원소 삭제 함수
            {
                if(dq.empty())
                {
                    error = true;
                    break;
                }
                else
                    dq.pop_front();
            }
            
        }
        
        if(error)
            cout << "error\n";
        else
            printDeque(dq);
        
        
    }
}
