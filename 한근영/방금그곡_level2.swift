//20220515
//프로그래머스 level2 방금그곡 문제
//https://programmers.co.kr/learn/courses/30/lessons/17683

import Foundation

func solution(_ m:String, _ musicinfos:[String]) -> String {
    var answer = [String]()
    let dict = ["C#":"c", "D#":"d", "F#":"f", "G#":"g", "A#":"a"]
    var ss: String {
        return dict.reduce(m){
                $0.replacingOccurrences(of:$1.key, with:$1.value)}} 
    print(ss)
    for i in musicinfos{
        let arr = i.components(separatedBy:",")
        let str = arr[3]
        var sss: String {
        return dict.reduce(str){
                $0.replacingOccurrences(of:$1.key, with:$1.value)}} 
        let musicLength = sss.count //음악 길이
        var realmusic = "" //실제 재생된 음악 악보
        
        let start = arr[0].components(separatedBy:":")
        let startInt = start.map{Int($0)!}
        let finish = arr[1].components(separatedBy:":")
        let finishInt = finish.map{Int($0)!}
        let radioLength = (finishInt[0]*60+finishInt[1]) - (startInt[0]*60+startInt[1]) //재생된 시간
        let music = Array(sss)
        var ii = 0
        while(realmusic.count<radioLength){
            realmusic += String(music[ii%musicLength])
            ii += 1
        }
        
        if realmusic.contains(ss){
            answer.append(arr[2])
            answer.append(String(radioLength))
        }

    }
    if answer.count == 2 {
        return answer[0]
    }else if answer.count > 2 {
        var times = [Int]()
        for (i,time) in answer.enumerated(){
            if i%2 == 1 {
                times += [Int(time)!]
            }
        }
        return answer[answer.firstIndex(of:String(times.max()!))!-1]
    }else{
        return "(None)"
    }
}