// Created by Emily Cho on 2022/05/14.
// 백준 2302 극장 좌석 (실버 1)
// https://www.acmicpc.net/problem/2302

#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 1;
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1);
    vector<int> vip;
    dp[0] = dp[1] = 1; // 피보나치 수열 초기값
    // vip 입력받기
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        vip.push_back(tmp);
    }
    // n까지 피보나치 구하기
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int l = 0;
    for (int r : vip) {
        ans *= dp[r - l - 1];
        l = r;
    }
    ans *= dp[n - l];

    cout << ans;

}

