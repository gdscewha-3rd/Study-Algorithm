import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class boj_18870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        int[] input = new int[N]; // 입력받은 원본 배열
        int[] sorted = new int[N]; // 정렬한 배열
        HashMap<Integer, Integer> rankMap = new HashMap<>(); // <원소, 랭킹> 저장

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for(int i = 0; i < N; i++) {
            input[i] = sorted[i] = Integer.parseInt(st.nextToken());
        }

        // 정렬
        Arrays.sort(sorted);

        // 원소의 랭킹 Map에 추가
        int rank = 0;
        for (int i : sorted) {
            if (!rankMap.containsKey(i)) { // Map에 동일한 키가 없을 경우에만 put
                rankMap.put(i, rank);
                rank++;
            }
        }

        // 원소의 랭킹 찾아서 출력
        for(int k : input) {
            int value = rankMap.get(k);
            sb.append(value).append(' ');
        }

        System.out.println(sb);

    }
}
