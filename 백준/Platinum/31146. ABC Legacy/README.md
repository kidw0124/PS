# [Platinum V] ABC Legacy - 31146 

[문제 링크](https://www.acmicpc.net/problem/31146) 

### 성능 요약

메모리: 16916 KB, 시간: 68 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given a string $S$ of length $2n$, consisting of the characters <code>A</code>, <code>B</code> and <code>C</code>. Determine if $S$ can be split into $n$ non-intersecting subsequences, each of which forms one of the strings "<code>AB</code>", "<code>AC</code>", "<code>BC</code>". If it is possible, find such a splitting.</p>

### 입력 

 <p>The first line of input contains one integer $n$ ($1 \le n \le 10^5$).</p>

<p>The second line of input contains a string $S$ of length $2n$, consisting of the characters <code>A</code>, <code>B</code> and <code>C</code>.</p>

### 출력 

 <p>If the splitting is not possible, print "<code>NO</code>" (without quotes).</p>

<p>If the splitting is possible, print "<code>YES</code>" (without quotes), followed by $n$ lines, each describing two indices for the $i$-th subsequence ($1 \le l_i < r_i \le 2n$).</p>

