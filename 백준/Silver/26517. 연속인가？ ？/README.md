# [Silver V] 연속인가? ? - 26517 

[문제 링크](https://www.acmicpc.net/problem/26517) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 미적분학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>실수 $t$에 대하여, 함수 $f(x)$가 $x=t$에서 정의되어 있고, $\lim_{x \rightarrow t} f(x) = f(t)$인 경우 "$f(x)$는 $x=t$에서 연속이다"라고 한다. </p>

<p>함수 $f(x) = \begin{cases}ax+b & (x \leq k)\\ cx+d & (x > k)\end{cases}$가 주어질 때, 이 함수가 $x=k$에서 연속인지 판별하자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $k$가 주어진다. $(-10^7 \leq k \leq 10^7)$</p>

<p>두 번째 줄에 정수 $a$, $b$, $c$, $d$가 공백으로 구분되어 주어진다. $(-10^7 \leq a, b, c, d \leq 10^7;$ $a, c \neq 0)$</p>

### 출력 

 <p>$f(x)$가 $x=k$에서 연속이라면, <span style="color:#e74c3c;">Yes</span>와 $f(k)$를 공백으로 구분하여 출력하고, 아니라면 <span style="color:#e74c3c;">No</span>를 출력한다.</p>

