// 20220430
// 백준 14888 연산자 끼워넣기 (실버1)
// https://www.acmicpc.net/problem/14888

package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class boj14888 {

    static int n;
    static int[] num;
    static int[] op;
    static int mmin = 1000000001;
    static int mmax = -1000000001;

    static void calc(int res, int idx) {
        if (idx == n) {
            mmax = Math.max(mmax, res);
            mmin = Math.min(mmin, res);
        }
        // op 배열은 순서대로 + - * / 연산
        for (int i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--; // 연산자 사용
                if (i == 0)
                    calc(res + num[idx], idx + 1);
                else if (i == 1)
                    calc(res - num[idx], idx + 1);
                else if (i == 2)
                    calc(res * num[idx], idx + 1);
                else
                    calc(res / num[idx], idx + 1);
                op[i]++; // 백트래킹을 위해 연산자 되돌리기
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(bf.readLine());
        num = new int[n];
        op = new int[4];

        String str = bf.readLine();
        StringTokenizer st = new StringTokenizer(str);
        // 연산할 숫자 입력받기
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        str = bf.readLine();
        st = new StringTokenizer(str);
        // 연산자 개수 입력받기 + - * /
        for (int i = 0; i < 4; i++) {
            op[i] = Integer.parseInt(st.nextToken());
        }

        calc(num[0], 1);

        System.out.println(mmax);
        System.out.println(mmin);
    }
}
