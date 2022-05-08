//220508
//프로그래머스 [level2] 짝지어 제거하기 문제
//https://programmers.co.kr/learn/courses/30/lessons/12973

import Foundation

func solution(_ s:String) -> Int{
    var answer:Int = 0
    var str = s.map{String($0)}
    var new_str = [String]() //스택 사용 -> O(n)
    if s.count % 2 == 1 { return answer }
    for s in str {
        if new_str.count == 0 {
            new_str.append(s)
        } else if new_str.last! == s {
            new_str.remove(at:new_str.count - 1)
        } else {
            new_str.append(s)
        }
    }

    if new_str.count == 0 { answer = 1 }

    return answer
}


/* 시간초과
replacingOccurrences(of:String,with:String) -> String
새로운 문자열을 리턴해주는 메서드
원소의 개수 n만큼 돌면서 target 스트링을 교체 -> 이 함수 자체 시간복잡도가 O(n)
그런데 이 함수를 while문 안에 넣었으니 최악의 경우에는 O(n^2)만큼의 시간복잡도가 나올 수 있으므로
시간 초과 실패가 나온 것

import Foundation

func solution(_ s:String) -> Int{
    var answer:Int = 0
    var str = s
    var new_str = s
    if s.count % 2 == 1 { return answer }
    while true {
        str = new_str
        new_str = str.replacingOccurrences(of:"(.)\\1",with:"",options:.regularExpression)
         //print(str,new_str)
         if new_str == str { break }
    }

    if new_str == "" { answer = 1 }

    return answer
}
*/