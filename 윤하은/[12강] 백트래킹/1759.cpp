#include <bits/stdc++.h>
using namespace std;

int numOfPW;
int charNum;//주어지는 알파벳의 갯수
char pw[20];
char candidateChar[20];
bool isUsed[30];

void printNowPW(int k)
{
    cout << "printNowPW\n";
    for(int i = 1; i<= k; i++)
        cout << pw[i] << " ";
    cout << "\n";

}
bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else return false;
}
void func(int k, int vowelNum, int consonantNum)
{
    if(k == numOfPW+1)
    {
        //모음 최소 한개이상이라는 조건 있음
        if(vowelNum >= 1 && consonantNum >= 2)
        {
            //cout << "*****candidate complete*****\n";
            for(int i = 1; i<= numOfPW; i++)
                cout << pw[i];
            cout << "\n";
            //cout << "*****candidate complete*****\n";
            

        }
        return;
    }

    for(int i = 0; i<charNum; i++)
    {
        char cur = candidateChar[i];
        if(!isUsed[cur] && pw[k-1] < cur)
        {
            isUsed[cur] = true;
            pw[k] = cur;
            //printNowPW(k);
            //cout << "call func(" << k+1 << ")\n";
            if(isVowel(cur)) func(k+1, vowelNum+1, consonantNum);
            else func(k+1, vowelNum, consonantNum+1);
            //cout << "finish func(" << k+1 << ")\n";
            isUsed[cur] = false;
            
        }

    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numOfPW;
    cin >> charNum;

    for(int i = 0; i<charNum; i++)
        cin >> candidateChar[i];

    
    //후보 문자열들을 사전식으로 출력해야해서 미리 정려해줌
    sort(candidateChar, candidateChar+charNum);
    
    //알파벳 오름차순을 확인하려고 func함수에서 k-1 인덱스를 확인해야하는데
    //이 때 outOfIndex 내지 않으려고 index=1부터 사용

    //func 함수에서 index = k-1과 비교하기 위해 a의 아스키코드인 97보다 작은수로
    //초기화 해줌
    pw[0] = 95;
    
    //cout << "call func(1)\n";
    func(1, 0, 0);
}