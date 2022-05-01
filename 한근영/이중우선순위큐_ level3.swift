//20220423
//프로그래머스 level3 이중우선순위큐 문제
//https://programmers.co.kr/learn/courses/30/lessons/42628

import Foundation

func solution(_ operations:[String]) -> [Int] {
    var answer = [0,0]
    var queue = [Int]()
    for o in operations {
        let split = o.components(separatedBy:" ")
        if split[0] == "D" && queue.count>0{
            if split[1] == "1" {
            queue.remove(at:queue.firstIndex(of:queue.max()!)!)
            } else {
                queue.remove(at:queue.firstIndex(of:queue.min()!)!)
            }
        } else if split[0] == "I"{
            queue.append(Int(split[1])!)
        }
    }
    if queue.count > 0 {
        answer = [Int(queue.max()!),Int(queue.min()!)]
    }
    return answer
}