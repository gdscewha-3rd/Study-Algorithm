// Created by Emily Cho on 2022/05/21.
// 백준 16568 엔비스카의 영혼 (실버 1)
// https://www.acmicpc.net/problem/16568

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    // 1초에 맨 앞 한 명이 가고 a 또는 b칸 새치기 하므로 1씩 더함
    a++;
    b++;

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        // 그냥 1초 기다리는 경우, 1초 지나고 a칸 새치기, 1초 지나고 b칸 새치기 중 min값 dp[i]에 담기
        dp[i] = dp[i - 1] + 1;
        if (i - a >= 0) {
            dp[i] = min(dp[i], dp[i - a] + 1);
        }
        if (i - b >= 0) {
            dp[i] = min(dp[i], dp[i - b] + 1);
        }
    }
    cout << dp[n];
}

