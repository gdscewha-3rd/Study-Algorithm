# 03강 배열

### 배열의 정의와 성질

- 배열 : 메모리 상에 원소를 연속하게 배치한 자료 구조
- O(1)에 k번째 원소를 확인, 변경 가능
- 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
- cache hit rate가 높음
- 메모리 상에 연속한 구간을 잡아야해서 할당에 제약이 걸림

### 배열의 기능과 구현

- 임의의 원소를 확인, 변경 : O(1)
- 원소를 끝에 추가, 삭제 : O(1)
- 임의의 위치에 원소를 추가/제거 : O(N)
    - k번째에 원소를 추가한다 ⇒ k부터 n-1번째까지 원소 이동시킨 후에 삽입해야함 ⇒ n-k 번 이동 연산 (평균적으로 n/2번 연산해야함) ⇒ O(N)

- [insert 함수, erase 함수 구현해보기](arr_implementation.cpp)
    
   
    

- 전체를 특정값으로 초기화시키기
    - for문으로 값 하나하나 바꾸기
    - **fill 함수** (`algorithm` 헤더 內)
        - fill(시작 주소, 끝나는 주소(포함 x), 바꿀 값)
        - [시작주소, 끝나는 주소) 범위의 원소값을 바꿔줌
        - `fill(arr, arr+9, 10);` // `arr[0]`부터 `arr[8]`까지의 원소를 10으로 변경
    
    ---
    
    - ~~memset 함수(`cstring` 헤더 內) 활용~~ (비추)
        - ‼️주의‼️ 0이나 -1이 아닌 다른 값을 넣으면 오동작함, 2차원 이상의 배열 사용시 잘못되는 경우 ⇒ 비추
    

### STL vector

- `v.insert(삽입할 주소, num)`
    - 시간복잡도 : O(N)
- `v.erase(삭제할 주소)`
    - 시간복잡도 : O(N)
- `push_back(num)`, `pop_back()`
    - 시간 복잡도 : O(1)
- `push_front(num)`, `pop_front()`
    - 시간 복잡도 : O(N)

```cpp
vector<int> v(3, 5);//{5, 5, 5}
v.insert(v.begin()+1, 10);//{5, 10, 5, 5}
v.erase(v.begin()+1);//{5, 5, 5}
```

- vector 복사
    - deep copy (데이터 자체를 복사, 복사본과 원본이 독립적임)
    - `v1 = v2;`
- range-based for loop로 벡터 원소 방문
    
    ```cpp
    	for(int &e: v) { ... }
    //vector<int> 일 경우
    ```
    
- **v.size()-1 주의**
    
    v.size() 는 unsigned int 이기 때문에 v.size() == 0 일때 -1을 하면 unsigned int와 int의 연산이므로 그 결과가 unsigned int가 되므로 overflow가 발생함
