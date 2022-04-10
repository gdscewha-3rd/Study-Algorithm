//20220404
//프로그래머스 level2 주차요금계산 문제
//https://programmers.co.kr/learn/courses/30/lessons/92341

import Foundation

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var cars: Array<car> = []
    var record = Array(repeating:Array(repeating:"0",count:records[0].count),count:records.count)
    for (i,r) in records.enumerated(){
        record[i] = r.components(separatedBy:" ")
    }
    for i in record {
        if cars.contains{$0.name == i[1]}{
            cars[cars.index(where:{$0.name == i[1]})!].time += [i[0]]
        } else {
            let c = car(name: i[1], time: [i[0]], totalTime:0,fee:fees[1])
            cars += [c]
        }
    }
    var answer = cars.sorted(by: {$0.name < $1.name})
    for (index,a) in answer.enumerated() {
        if a.time.count%2==1 { //마지막 출차 없을 경우
            answer[index].time += ["23:59"]
        }
        for i in stride(from:0,to:answer[index].time.count-1 ,by:2){
            let start = answer[index].time[i].components(separatedBy:":")
            let startInt = start.map {Int($0)!}
            let finish = answer[index].time[i+1].components(separatedBy:":")
            let finishInt = finish.map {Int($0)!}
            let f = finishInt[0]*60+finishInt[1]
            let s = startInt[0]*60+startInt[1]
            answer[index].totalTime += f-s
        }

        answer[index].fee = fees[1]
        if answer[index].totalTime > fees[0] {
            answer[index].fee += fees[3] * Int(ceil(Double(answer[index].totalTime-fees[0])/Double(fees[2])))
        }
    }
    let answer2 = answer.map{$0.fee}
    return answer2
}

struct car {
    var name: String
    var time: [String]
    var totalTime: Int
    var fee: Int
}