package baekjoon.baekjoon_5430;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class bj_5430 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine()); // test case
        while (T-- > 0) { // T번 반복
            String[] func_arr = br.readLine().split(""); // function array
            int N = Integer.parseInt(br.readLine());
            String st = br.readLine();
            LinkedList<String> deque = new LinkedList<String>();

            if (st.length() > 2) {
                String[] str = st.substring(1, st.length() - 1).split(",");
                for (int i = 0; i < N; i++) { // deque 초기화
                    deque.offerLast(str[i]);
                }
            }

            boolean isError = false; // error 발생시 true
            boolean isStartFirst = true; // 순서가 앞에서부터 시작하면 true
            for (int i = 0; (i < func_arr.length) && !isError; i++) {
                switch (func_arr[i]) {
                    case "R" :
                        isStartFirst = !isStartFirst; // 앞 <-> 뒤 switch
                        break;

                    case "D" :
                        if (deque.isEmpty()) {
                            sb.append("error").append('\n');
                            isError = true; // for문 탈출
                            break;
                        }
                        if (isStartFirst) {
                            deque.pollFirst();
                            break;
                        }
                        else {
                            deque.pollLast();
                            break;
                        }
                }
            }

            if (!isError) { // error가 없으면 deque 내용 출력
                int size = deque.size();
                sb.append('[');
                if (isStartFirst) {
                    for (int i = 0; i < size - 1; i++) {
                        sb.append(deque.pollFirst()).append(',');
                    }
                    sb.append(deque.pollFirst()).append(']').append('\n');
                }
                else {
                    for (int i = 0; i < size - 1; i++) {
                        sb.append(deque.pollLast()).append(',');
                    }
                    sb.append(deque.pollLast()).append(']').append('\n');
                }
            }

        }

        System.out.println(sb);
    }
}
