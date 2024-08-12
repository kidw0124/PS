# [Platinum I] Painting Grid - 28168 

[문제 링크](https://www.acmicpc.net/problem/28168) 

### 성능 요약

메모리: 33588 KB, 시간: 60 ms

### 분류

애드 혹, 비트마스킹, 브루트포스 알고리즘, 많은 조건 분기, 해 구성하기, 해싱, 무작위화

### 제출 일자

2024년 8월 12일 16:48:51

### 문제 설명

<p>Grammy has an $n \times m$ wall covered by squares. Each small square on the wall is of unit size and should be painted into one color completely. She wants to color the wall into black and white. Grammy likes the concept of diversity, so she decided to make each row look different from all previous rows and also make each column look different from all previous columns. As she was about to paint, she found her paint was just enough: half of white paint and half of black paint, both with an amount to paint exactly $\frac{nm}{2}$ unit area. Please help Grammy to satisfy her diversity condition using limited paint.</p>

### 입력 

 <p>The input contains multiple test cases.</p>

<p>The first line contains a single integer $T$ ($1 \leq T \leq 2000$), denoting the number of test cases.</p>

<p>For each test case:</p>

<p>The only line contains two integers $n$ and $m$ ($1 \leq n,m \leq 1000$). It is guaranteed that the sum of $n \cdot m$ does not exceed $10^6$.</p>

### 출력 

 <p>For each test case, if no solution exists, output "<code>NO</code>". Otherwise, output "<code>YES</code>" followed by $n$ lines. Each line should contain $m$ characters. $0$ denotes a white square and $1$ denotes a black square in the solution.</p>

