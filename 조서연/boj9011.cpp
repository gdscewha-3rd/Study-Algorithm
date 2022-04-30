// Created by Emily Cho on 2022/04/09.
// 백중 9011 순서 (실버 1)
// https://www.acmicpc.net/problem/9011

#include "iostream"
#include "vector"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> R(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> R[i];
        }
        vector<int> score(n); // 각 칸 왼쪽에 숫자가 몇 개 남아있는지 기록.
        vector<int> S;
        bool possible = true; // R에서 S를 찾는 것이 불가능하다면 false
        for (int i = 0; i < n; i++) {
            // 어느 숫자도 사용하지 않은 초기 상태에는 인덱스 i보다 작은 숫자는 i개. ex) 3(i=2)보다 작은 숫자는 2개
            score[i] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            int num = R[i]; // score 배열에서 찾을 숫자. ex) num = 5라면 사용하지 않은 숫자 중 자신보다 작은 숫자가 5개인 숫자 찾기
            bool found = false; // num을 찾았는지 체크
            for (int j = 0; j < n; j++) {
                if (score[j] == num) {
                    found = true; // 찾았다
                    S.push_back(j + 1);
                    score[j] = -1; // 사용한 숫자 표시
                    for (int k = j + 1; k < n; k++) {
                        // 사용한 숫자 num 보다 큰 숫자는 자신보다 작은 숫자가 하나 줄어들었기 때문에 -1
                        score[k]--;
                    }
                    break; // num을 찾았고, S에 푸시했으면 for문을 나가야한다!
                }
            }
            if (!found) { // Impossible. num을 못 찾았다.
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = n - 1; i >= 0; i--) {
                cout << S[i]<<' ';
            }
            cout << "\n";
        }

    }
    return 0;
}
