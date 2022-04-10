import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1002 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int r1 = Integer.parseInt(st.nextToken());

            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());

            sb.append(point_of_tangency(x1, y1, r1, x2, y2, r2)).append('\n');
        }
        System.out.println(sb);
    }

    // 접점의 개수를 구하는 함수
    private static int point_of_tangency(int x1, int y1, int r1, int x2, int y2, int r2) {

        int distance = (int)(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2)); // 두 원의 중점 간의 거리 제곱

        // case 1 : 중점이 같고, 반지름도 같은 경우 -> 접점 무한개
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            return -1;
        }

        // case 2 : 내접 -> 접점 1개
        else if (distance == Math.pow(r2 - r1, 2)) {
            return 1;
        }

        // case 3 : 외접 -> 접점 1개
       else if (distance == Math.pow(r2 + r1, 2)) {
            return 1;
        }

        //case 4 : 한 원이 다른 원 안에 속해있으나 접하지 않는 경우 -> 접점 0개
        else if (distance < Math.pow(r2 - r1, 2)) {
            return 0;
        }

        //case 5 : 두 원이 아예 닿지 않는 경우 -> 접점 0개
        else if (distance > Math.pow(r2 + r1, 2)) {
            return 0;
        }

        //case 6 : 위의 경우를 모두 제외한 경우 -> 접점 2개
        else {
            return 2;
        }

    }

}
