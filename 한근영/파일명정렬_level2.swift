//220331
//프로그래머스 [level2] 파일명 정렬 문제
//https://programmers.co.kr/learn/courses/30/lessons/17686

//파일명이 숫자로 끝날경우 number 부분 주의 필요
func solution(_ files:[String]) -> [String] {
    var arr: Array<fileStruct> = []

    for f in files {
        let lowerArray = f.map{$0.lowercased()}
        let nums = lowerArray.filter{Character($0).isNumber == true}
        let numberFirstIndex = lowerArray.firstIndex(of:nums[0])!
        let head = Array(lowerArray[..<numberFirstIndex]).joined(separator:"")
        //print(head)
        let characters = Array(lowerArray[numberFirstIndex..<lowerArray.endIndex]).filter{Character($0).isNumber == false}
        //print(characters)
        var number: Int
        if characters.count == 0 {
            number = Int(Array(lowerArray[numberFirstIndex..<lowerArray.endIndex]).joined(separator:""))!
        } else{
            let numberLastIndex = Array(lowerArray[numberFirstIndex..<lowerArray.endIndex]).firstIndex(of:characters[0])!
        //print(numberLastIndex)
        number = Int(Array(lowerArray[numberFirstIndex..<numberFirstIndex+numberLastIndex]).joined(separator:""))!
        }

        let s = fileStruct(name:f,Head: head ,Number:number)
        arr += [s]
    }

    let newArr = arr.sorted(by:{$0.Number < $1.Number})
    let newArr2 = newArr.sorted(by: {$0.Head < $1.Head})

    let answer = newArr2.map {$0.name}

    return answer
}

struct fileStruct {
    var name: String
    var Head: String
    var Number: Int
}

/*
정렬 부분 참조
https://gonslab.tistory.com/35
*/


/*
다른 사람 풀이

extension String{
    var numeric: ClosedRange<Character> { return "0"..."9" }
    var head: String{
        return self.prefix { numeric.contains($0) == false }.uppercased()
    }
    var number: Int {
        return Int( self.drop   { numeric.contains($0) == false}
                        .prefix { numeric.contains($0) == true })!
    }
}

func solution(_ files:[String]) -> [String] {

    return files.enumerated().sorted { (lhs, rhs) in
        let l = lhs.element
        let r = rhs.element
        if l.head != r.head { return l.head < r.head}
        if l.number != r.number { return l.number < r.number}
        return lhs.offset < rhs.offset

    }.map{ $0.element }
}
*/