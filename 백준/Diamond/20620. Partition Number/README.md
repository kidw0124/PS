# [Diamond III] Partition Number - 20620 

[문제 링크](https://www.acmicpc.net/problem/20620) 

### 성능 요약

메모리: 10592 KB, 시간: 2032 ms

### 분류

수학, 다이나믹 프로그래밍, 조합론, 배낭 문제, 포함 배제의 원리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given an integer set $A=\{a_1,a_2,\ldots,a_n\}$. Please calculate the number of solutions for equation $x_1+x_2+\ldots+x_k=m$, where $x_i$ are positive integers, $x_1 \le x_2 \le \ldots \le x_k$ and $x_i \not \in A$.</p>

<p>As the answer may be very large, you are only asked to calculate it modulo $(10^9 + 7)$.</p>

### 입력 

 <p>There are multiple test cases. The first line of the input contains an integer $T$ indicating the number of test cases. For each test case:</p>

<p>The first line contains two integers $n$ and $m$ ($1 \le n \le 500$, $n \le m \le 3 \cdot 10^5$).</p>

<p>The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le m$, $a_i \ne a_j$ for all $i \ne j$).</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $500$.</p>

### 출력 

 <p>For each test cases, output an integer denoting the answer.</p>

