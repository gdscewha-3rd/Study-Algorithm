//20220416
//프로그래머스 level2 문자열 압축 문제
//https://programmers.co.kr/learn/courses/30/lessons/60057


//s의 길이는 최대 1000 이므로 시간 계산 복잡도는 O(n^2) 즉 최악의 경우에 1000000
//보통 1억이 1초이므로 효율적이지는 않아도 시간 제한에 걸리지는 않겠다고 판단
//반복되는 문자의 숫자가 일의 자리를 넘어서는 경우, 특히 10인 경우 고려 필요

import Foundation

func solution(_ s:String) -> Int {
    var length = s.count
    for i in stride(from:1,to:s.count/2+1,by:1){
        var arr = "" //stack
        var str = s
        var count = [Int](repeating:1,count:s.count)
        var total = 0
        while str.count > 0 {
            //print(arr)
            if arr.count == 0{
                arr.append(String(str.prefix(i)))
                str = String(str.dropFirst(i))
            } else if String(str.prefix(i)) == String(arr.suffix(i)){
                str = String(str.dropFirst(i))
                count[arr.count] += 1
            } else {
                arr.append(String(str.prefix(i)))
                str = String(str.dropFirst(i))
            }
            if str.count < i {
                arr.append(str)
                break
            }
        }
        let new_count = count.filter{$0 > 1}
        let str_count = new_count.map{String($0)}
        //print(str_count)
        total = arr.count + str_count.joined(separator:"").count
        //print(total)
        if length > total {
            length = total
        }
    }
    return length
}