import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int count, N;
    public static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        count = 0;
        N = Integer.parseInt(st.nextToken());
        arr = new int[N]; // index가 column, value가 row

        dfs(0);
        System.out.println(count);
    }

    // 퀸을 둘 수 있는 경우의 수를 구하는 함수
    private static void dfs(int depth) {
        if (depth == N) {
            count++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (possible(depth, i)) {
                arr[depth] = i;
                dfs(depth + 1);
            }
        }
    }

    // 그 자리에 퀸을 두어도 되는지 알려주는 함수
    private static boolean possible(int depth, int i) {
        for (int j = 0; j < depth; j++) { // 다른 행에 있어야한다.
            if (arr[j] == i) {
                return false;
            }

            if (Math.abs(j - depth) == Math.abs(arr[j] - i)) { // 서로 대각선에 위치하지 않아야한다.
                return false;
            }
        }
        return true;
    }
}
