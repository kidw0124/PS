# [Diamond IV] NP-Hard? NP-Complete? - 34170 

[문제 링크](https://www.acmicpc.net/problem/34170) 

### 성능 요약

메모리: 2352 KB, 시간: 184 ms

### 분류

수학, 다이나믹 프로그래밍, 정수론, 조합론

### 제출 일자

2025년 9월 4일 05:01:37

### 문제 설명

<p>NP-Hard와 NP-Complete가 무엇인지 아는가?</p>

<p>익명을 요구한 MatKor 출제/검수진 누군가는 다음과 같이 대답했다.</p>

<p style="text-align: center;"><img alt="" src="" style="width:600px;max-width:100%;"></p>

<p>양의 정수 $N$과 소수 $P$가 주어질 때, $\binom{N}{i}\equiv 0\pmod P$를 만족하는 $0$ 이상 $N$ 이하의 정수 $i$의 개수를 구하는 문제는 너무 쉽게 풀리므로, NP-Complete이다. 이제 음이 아닌 정수 $K$를 하나 더 입력으로 주어, $\binom{N}{i}\equiv 0\pmod{P^K}$를 만족하는 $0$이상 $N$이하의 정수 $i$의 개수를 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 $T(1\le T\le 1\, 000)$이 주어진다.</p>

<p>두 번째 줄부터 $T$ 줄에 걸쳐 양의 정수 $N(1\le N\le 10^{18})$과 소수 $P(2\le P\le 10^{18})$, 정수 $K(0\le K\le 10^{18})$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫 번째 줄부터 $T$ 줄에 걸쳐 각 테스트 케이스 별로 문제의 정답을 한 줄에 한 개씩 출력한다.</p>

