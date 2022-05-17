// 20220507
// 프로그래머스 신고 결과 받기
// https://programmers.co.kr/learn/courses/30/lessons/92334

package com.company;
import java.io.IOException;
import java.util.*;
public class reportResult {

    static class Pair{
        String x;
        String y;
        public Pair(String x, String y){
            this.x = x;
            this.y = y;
        }
        public String first(){
            return x;
        }
        public String second(){
            return y;
        }
    }

    public static int[] solution(String[] id_list, String[] report, int k) {
        int n = id_list.length;
        int[] answer = new int[n];

        HashSet<String> exist = new HashSet<>();
        List<Pair> reportList = new ArrayList<>();
        for (String s : report) {
            StringTokenizer st = new StringTokenizer(s);
            String a = st.nextToken();
            String b = st.nextToken();
            Pair newP = new Pair(a, b);
            if (!exist.contains(s)) {
                reportList.add(newP);
                exist.add(s);
            }
        }
        HashMap<String, Integer> reportCnt = new HashMap<>();
        HashMap<String, Integer> ansCnt = new HashMap<>();
        for (String s : id_list) {
            reportCnt.put(s, 0);
            ansCnt.put(s, 0);
        }
        for (Pair p : reportList) {
            String reported = p.second();
            reportCnt.put(reported, reportCnt.get(reported) + 1);
        }

        for (String id : id_list) {
            Iterator<Pair> iter = reportList.iterator();
            if (reportCnt.get(id) >= k) {
                while (iter.hasNext()) {
                    Pair p = iter.next();
                    if (p.second().equals(id)) {
                        ansCnt.put(p.first(), ansCnt.get(p.first()) + 1);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            answer[i] = ansCnt.get(id_list[i]);
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        String[] id_list = {"con", "ryan"};
        String[] report = {"ryan con", "ryan con", "ryan con", "ryan con"};
        int[] ans = solution(id_list, report, 3);
    }
}

