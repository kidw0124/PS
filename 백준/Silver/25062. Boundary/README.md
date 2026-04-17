# [Silver I] Boundary - 25062 

[문제 링크](https://www.acmicpc.net/problem/25062) 

### 성능 요약

메모리: 2160 KB, 시간: 28 ms

### 분류

수학, 정수론, 많은 조건 분기, 유클리드 호제법

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Bethany would like to tile her bathroom. The bathroom has width $w$ centimeters and length $l$ centimeters. If Bethany simply used the basic tiles of size $1 × 1$ centimeters, she would use $w · l$ of them.</p>

<p>However, she has something different in mind.</p>

<ul>
	<li>On the interior of the floor she wants to use the $1 × 1$ tiles. She needs exactly $(w - 2) · (l - 2)$ of these.</li>
	<li>On the floor boundary she wants to use tiles of size $1 × a$ for some positive integer $a$. The tiles can also be rotated by $90$ degrees.</li>
</ul>

<p>For which values of $a$ can Bethany tile the bathroom floor as described? Note that $a$ can also be $1$.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 100$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>Each test case consist of a single line, which contains two integers $w$, $l$ ($3 ≤ w, l ≤ 10^9$) — the dimensions of the bathroom.</p>

### 출력 

 <p>For each test case, print an integer $k$ ($0 ≤ k$) — the number of valid values of $a$ for the given test case — followed by $k$ integers $a_1$, $a_2$, $\dots$, $a_k$ ($1 ≤ a_i$) — the valid values of $a$. The values $a_1$, $a_2$, $\dots$, $a_k$ have to be sorted from smallest to largest.</p>

<p>It is guaranteed that under the problem constraints, the output contains at most $200\,000$ integers.</p>

