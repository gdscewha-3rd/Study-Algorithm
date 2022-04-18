# 05강 스택
### 스택이란?

한쪽 끝에서만 데이터의 삽입, 삭제가 가능한 자료구조, FILO (first in last on), 특정 위치에서만 원소를 넣고 뺄 수 있는 자료구조인 스택, 큐, 덱을 묶어서 restiricted structure라고 함.

### 성질

- 원소의 추가 : O(1)
- 원소의 제거 : O(1)
- 제일 상단의 원소 확인 : O(1)
- 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능 = 스택 자료구조에서 제공하는 기능이 아님

### 구현

- [배열로 구현](stack_implementation_arr.cpp)
    - 연결리스트로 구현하는 것보다 쉬움)
    - pos 변수 : 새로운 원소를 추가할 위치, 스택의 원소의 갯수
    
    
- [연결 리스트로 구현](stack_implementation_list.cpp)

### STL stack

- push
- pop : **`stack.empty() == true` 일때 호출하면 런타임 에러 주의**
- empty
- top : **`stack.empty() == true` 일때 호출하면 런타임 에러 주의**

### 연습문제 : BOJ 10828

- [STL stack 이용](10828.cpp)
- [직접 구현한 stack 배열 이용](10828.cpp)
    - 10828.cpp 파일에 주석처리 되어있음
    

+) **BOJ 10773 은 풀어보고 나머지 문제집 문제들 너무 어려우면 bfs/dfs 후에 풀어보기**
