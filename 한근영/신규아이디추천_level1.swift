//220322
//프로그래머스 [level1] 신규 아이디 추천 문제
//https://programmers.co.kr/learn/courses/30/lessons/72410

//최종 - 정규식, replacingOccurrences 중요!
import Foundation

func solution(_ new_id:String) -> String {
    //1step
    var answer = new_id.lowercased()

    //2step
    answer = answer.replacingOccurrences(of:"[^0-9a-z._-]",with:"", options: .regularExpression)

    //3step
    answer = answer.replacingOccurrences(of:"([.])+",with:".", options: .regularExpression)

    //4step
    answer = answer.trimmingCharacters(in: ["."])

    //5step
    if answer.count==0{
        answer = "a"
    }

    //6step
    if answer.count>15{
        answer = String(answer[..<answer.index(answer.startIndex,offsetBy:15)])
    }
    answer = answer.trimmingCharacters(in: ["."])

    //7step
    if answer.count<3{
        let last = String(answer[answer.index(before:answer.endIndex)])
        while answer.count<3{
            answer += last
        }
    }
    return answer
}

/* 또다른 정규식 표현 확인
do{
        let regex = try NSRegularExpression(pattern:"[0-9a-z._-]", options:[])
        let nsString = NSString(string: answer)
        var results = regex.matches(in:answer, options:[],range:NSRange.init(location:0, length:nsString.length))
        let a = results.map{nsString.substring(with: $0.range)}
        answer = a.joined(separator:"")
    }catch let error{
        print("\(error.localizedDescription)")
    }
*/