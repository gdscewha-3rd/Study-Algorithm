//220329
//프로그래머스 [level2] 큰 수 만들기 문제
//https://programmers.co.kr/learn/courses/30/lessons/42883

//최종!
import Foundation

func solution(_ number:String, _ k:Int) -> String {
    let nArr = number.map{String($0)}
    var answer = [String]() //stack
    var erase = 0
    var i = 0
    while(k>erase){ 
        if i == nArr.count{
            answer.removeLast()
            erase += 1
        }else if answer.count == 0 || answer.last! >= nArr[i]{
            answer += [nArr[i]]
            i += 1
        } else if answer.last! < nArr[i]{
            answer.removeLast()
            erase += 1
        }
    }
    answer += Array(nArr[i...])
    return answer.joined(separator:"")
}


/*
func solution(_ number:String, _ k:Int) -> String {
    var nArr = number.map{String($0)}
    var erase = 0
    var i = 0
    while(k>erase){
        if i == nArr.count-1 {
            nArr.removeLast()
            erase += 1
        }else if nArr[i] < nArr[i+1] {
            nArr.remove(at:i)
            erase += 1
            i = 0
        } else{
            i += 1
        }
    }
    return nArr.joined(separator:"")
}*/
//654321 k=1 65432
//654321 k=5 6
//11111117 k=5

/*다른 사람 풀이
import Foundation

func solution(_ number:String, _ k:Int) -> String {
    let numbers = number.compactMap{ Int(String($0))}

    var sub: [Int] = []

    var k = k

    for (i,e) in numbers.enumerated() {
        while k>0, sub.isEmpty == false, sub.last! < e {
            k-=1
            sub.removeLast()
        }

        if k == 0 {
            sub.append(contentsOf: numbers[i...])
            break
        } else {
            sub.append(e)
        }
    }

    return sub[..<(sub.count-k)].map {String($0)}.joined()
}
*/