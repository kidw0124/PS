# [Silver I] Finding Privacy - 33140 

[문제 링크](https://www.acmicpc.net/problem/33140) 

### 성능 요약

메모리: 5088 KB, 시간: 16 ms

### 분류

수학, 해 구성하기, 많은 조건 분기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You surely agree that the best place to use a restroom is at home. However, sometimes people have no choice but to use a public restroom, where toilets are often arranged side by side in a single row. Aiming for some privacy, each person who enters such restroom will choose an unoccupied toilet that has no occupied toilets on its sides.</p>

<p>Suppose that $K$ people arrive at a public restroom with $N$ initially unoccupied toilets arranged in a row. Determine if it’s possible that each of the $K$ people chooses a toilet with no occupied toilets on its sides, and an additional person would not be able to find an unoccupied toilet meeting this privacy condition. People choose toilets one by one, and each chosen toilet is immediately occupied before the next person is allowed to choose.</p>

### 입력 

 <p>The input consists of a single line that contains two integers $K$ and $N$ ($1 ≤ K ≤ N ≤ 10^6$), indicating respectively the number of people and the number of toilets.</p>

### 출력 

 <p>Output a single line with a string of length $N$ if the $K$ people can choose toilets in a way that prevents an additional person from finding an available toilet with the required privacy. In this case the $i$-th character of the string must be the uppercase letter “<code>X</code>” if the $i$-th toilet is chosen, and the character “<code>-</code>” (hyphen) otherwise. Toilets are chosen as it is described in the statement. If there are multiple solutions, output any of them.</p>

<p>If toilets cannot be chosen as requested, output a line with the character “<code>*</code>” (asterisk) instead.</p>

