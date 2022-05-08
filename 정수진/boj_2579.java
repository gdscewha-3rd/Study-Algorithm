import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_2579 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int result;
        int[] score = new int[301]; // 각 계단까지의 최대 점수
        for(int i = 1; i <= n; i++)
            score[i] = Integer.parseInt(br.readLine());

        result = dp(n, score);
        System.out.println(result);
    }

    public static int dp(int n, int[] score) {
        int result = 0;
        int[] dp = new int[301];
        Arrays.fill(dp, 0);

        dp[1] = score[1];
        dp[2] = score[1] + score[2];

        for(int i = 3; i <= n; i++) {
            // 1칸 전에서 온 경우, 2칸 전에서 온 경우 중 최댓값과 현재 점수를 더한다.
            dp[i] = Math.max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];
        }

        result = dp[n];
        return result;
    }
}
