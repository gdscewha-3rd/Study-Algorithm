//220328
//프로그래머스 [level2] 프렌즈4블록 문제
//https://programmers.co.kr/learn/courses/30/lessons/17679

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var pre_answer = 0
    var answer = 0
    var answerArr = [[Int]]()
    var arr = Array(repeating:Array(repeating:"0",count:n),count:m)
    for (i,b) in board.enumerated(){
        arr[i] = b.map{String($0)}
    }

    repeat{
        pre_answer = answer
        //행,열 탐색해서 같은 거 있으면 answerArr에 좌표 넣기
        for i in stride(from:0,to:m-1,by:1){ //행
            for j in stride(from:0,to:n-1,by:1){ //열
                if arr[i][j] == "0" {continue}
                if arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j+1]{
                    answerArr = answerArr + [[i,j]]+[[i+1,j]]+[[i,j+1]]+[[i+1,j+1]]
                }
            }
        }

        //answerArr 중복 없애기
        answerArr = Array(Set(answerArr))

        //answerArr에 있는 좌표 모두 0 만들기
        answer += answerArr.count
        for i in answerArr{
            arr[i[0]][i[1]] = "0"
        }

        //arr 배열 재배치
        for j in stride(from:0,to:n,by:1){ //열
            var first = 0 //블록이 내려와야할 행 위치
            if arr[m-1][j] == "0" {first = m-1}
            for i in stride(from:m-2,through:0,by:-1){ //행
                if arr[i][j] == "0"{
                    if i>first {first = i }
                }
                else if arr[i+1][j] == "0"{
                    arr[first][j] = arr[i][j]
                    arr[i][j] = "0"
                    first -= 1
                }
            }
        }
        //answerArr 다시 빈 배열 만들기
        answerArr = [[Int]]()
    } while(pre_answer<answer)
    return answer
}