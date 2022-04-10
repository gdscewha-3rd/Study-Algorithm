//220331
//프로그래머스 [level2] 2개 이하로 다른 비트 문제
//https://programmers.co.kr/learn/courses/30/lessons/77885

import Foundation

func solution(_ numbers:[Int64]) -> [Int64] {
    var answer = [Int64]()
    for n in numbers {
        var bit = String(Int(n),radix:2).map{String($0)}
        if bit.last! == "0" {
            bit[bit.count-1] = "1"
        } else if let zeroIndex = bit.lastIndex(of:"0"){
            bit[zeroIndex] = "1"
            bit[zeroIndex+1] = "0"
        } else {
            bit.insert("1",at:0)
            bit[1] = "0"
        }
        answer += [Int64(bit.joined(separator:""),radix:2)!]
    }
    return answer
}

/*
다른 사람 풀이(이렇게 비트 연산 이용해서)

func solution(_ numbers: [Int64]) -> [Int64] {
    return numbers.map(f)
}

func f(_ number: Int64) -> Int64 {
    return (number | ~number & (number + 1)) & ~((~number & (number + 1)) >> 1)
}
*/