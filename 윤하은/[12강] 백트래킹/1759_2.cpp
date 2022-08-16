//next_permutation 사용
#include <bits/stdc++.h>
using namespace std;

void printPW(vector<char>& pw)
{
    for(int i = 0; i< pw.size(); i++)
        cout << pw[i];
    cout << "\n";
}
bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[20];
    
    int pwLength, charNum;
    cin >> pwLength >> charNum;

    char chars[20];
    for(int i = 0; i<charNum; i++)
        cin >> chars[i];

    for(int i = 0; i<pwLength; i++)
        arr[i] = 0;
    for(int i = pwLength; i<charNum; i++)
        arr[i] = 1;

    //사전순 출력을 위한 정렬
    sort(chars, chars+charNum);
    
    do{
        vector<char> pw;
        int vowelNum = 0;
        int consonantNum = 0;
        for(int i = 0; i<charNum; i++)
        {
            //chars[i]가 뽑힘
            if(arr[i] == 0)
            {    
                pw.push_back(chars[i]);
                if(isVowel(chars[i])) vowelNum++;
                else consonantNum++;
            }
        }
        if(vowelNum >= 1 && consonantNum >= 2)
        {
            //오름차순이라는 조건이 있으니까
            //정해진 문자 조합으로 가능한 pw는 단 하나임
            sort(pw.begin(), pw.end());
            printPW(pw);

        }

    }while(next_permutation(arr, arr+charNum));
}