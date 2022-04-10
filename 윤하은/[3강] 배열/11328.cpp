//220329
//백준 11328번 Strfry 문제(브론즈 2)
//boj.kr/11328
#include <bits/stdc++.h>
using namespace std;

//str1에 strfry를 적용해서 str2를 만들 수 있는지 판단하는 함수
//정렬 후 str1과 str2가 같으면 true 반환
bool IsPossible(string& str1, string& str2)
{
    int length1 = str1.length();
    int length2 = str2.length();
    
    //두 문자열의 길이가 다른 경우
    if(length1 != length2) return false;
    
    //두 문자열의 길이가 같은 경우
    else
    {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        //cout << str1 << "\t" << str2 << "\n";
        
        //compare 함수 사용 가능
        //str1.compare(str2)
        
        /*for(int i =0; i<length1; i++)
            if(str1[i] != str2[i]) return false;*/
            
        if(str1 == str2) return true;
        else return false;
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCaseNum =0;
    string str1, str2;
    cin >> testCaseNum;
    
    for(int i =0; i<testCaseNum; i++)
    {
        cin >> str1 >> str2;
        
        if(IsPossible(str1, str2))
            cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";
    }
    
    
    
    
}
