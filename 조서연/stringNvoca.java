// 220505
// 프로그래머스 숫자 문자열과 영단어
// https://programmers.co.kr/learn/courses/30/lessons/81301?language=java

package com.company;

import java.util.*;
class Solution {
    public int solution(String s) {
        String answer = "";

        HashMap<String, String> hmap = new HashMap<String, String>();
        hmap.put("zero","0");
        hmap.put("one","1");
        hmap.put("two","2");
        hmap.put("three","3");
        hmap.put("four","4");
        hmap.put("five","5");
        hmap.put("six","6");
        hmap.put("seven","7");
        hmap.put("eight","8");
        hmap.put("nine","9");

        String tmpStr = "";
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch>='0'&&ch<='9'){
                // 숫자
                answer+=ch;
            }else{
                tmpStr+=ch;
                if(hmap.containsKey(tmpStr)){
                    answer+=hmap.get(tmpStr);
                    tmpStr = "";
                }
            }
        }
        int intAns = 0;
        for(int i=0;i<answer.length();i++){
            intAns*=10;
            intAns+=answer.charAt(i)-'0';
        }

        return intAns;
    }
}
