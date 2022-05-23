//220515
//백준 2847번 게임을 만든 동준이 (실버 4)
//https://www.acmicpc.net/problem/2847


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int score[100];
    int count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    for (int i = N - 1; i > 0; i--) {
        while (score[i] <= score[i - 1]) {
            score[i - 1]--;
            count++;
        }
    }

    cout << count;

    return 0;
}