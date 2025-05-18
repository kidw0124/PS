# [Gold III] gcd와 set - 33837 

[문제 링크](https://www.acmicpc.net/problem/33837) 

### 성능 요약

메모리: 5996 KB, 시간: 536 ms

### 분류

수학, 브루트포스 알고리즘, 애드 혹, 정수론, 유클리드 호제법

### 제출 일자

2025년 5월 19일 00:46:26

### 문제 설명

<p>길이가 $N$인 정수 배열 $A$가 주어진다. 집합 $S = \{1, 2, \dots, N\}$를 정의하자. 집합 $S$의 부분집합 $S'$에 대해, 다음 값의 최댓값을 구하여라.<sup><a href="#seminus" id="r-setminus">[1]</a></sup></p>

<p>$$ \text{gcd}_A(S') + \text{gcd}_A(S \setminus S') $$</p>

<p>집합 $P = \{p_1, p_2, \dots, p_k\}$일 때, $\text{gcd}_A(P)$는 $A_{p_1}, A_{p_2}, \dots, A_{p_k}$의 최대공약수로 정의한다. 만약 집합 $P$가 <strong>공집합</strong>일 경우에는 $\text{gcd}_A(\varnothing) = 0$으로 정의한다.</p>

### 입력 

 <p>첫 번째 줄에 정수 $N$이 주어진다. $(1 \leq N \leq 10^6)$</p>

<p>두 번째 줄에 $N$개의 정수 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다. $(1 \leq A_i \leq 5\ 000)$</p>

### 출력 

 <p>첫 번째 줄에 $\text{gcd}_A(S') + \text{gcd}_A(S \setminus S')$의 최댓값을 출력한다.</p>

