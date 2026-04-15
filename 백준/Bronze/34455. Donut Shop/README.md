# [Bronze IV] Donut Shop - 34455 

[문제 링크](https://www.acmicpc.net/problem/34455) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 구현, 사칙연산, 시뮬레이션

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>The owner of a donut shop spends the day baking and selling donuts.</p>

<p>Given the events that happen over the course of the day, your job is to determine the number of donuts remaining when the shop closes.</p>

### 입력 

 <p>The first line of input contains a non-negative integer, $D$, representing the number of donuts available when the shop first opens.</p>

<p>The second line contains a positive integer, $E$, representing the number of events that happen over the course of the day. The next $E$ pairs of input lines describe these events.</p>

<p>The first line in the pair contains either the <code>+</code> (plus) symbol, indicating that donuts have been baked, or the <code>-</code> (minus) symbol, indicating that donuts have been sold. The second line in the pair contains a positive integer, $Q$, representing the quantity of donuts associated with the event.</p>

<p>For each sale of donuts, the value of $Q$ will be less than or equal to the number of donuts available at that time.</p>

### 출력 

 <p>Output the non-negative integer, $R$, which is the number of donuts remaining when the shop closes.</p>

