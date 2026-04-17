# [Gold V] Closest Pair - 14746 

[문제 링크](https://www.acmicpc.net/problem/14746) 

### 성능 요약

메모리: 26688 KB, 시간: 248 ms

### 분류

정렬, 이분 탐색, 두 포인터

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Given two sets P and Q of finitely many points in the plane, a closest pair of P and Q is a pair (p, q) of points p ∈ P and q ∈ Q such that the distance between p and q is the minimum among all pairs (p′, q′) with p′ ∈ P and q′ ∈ Q.</p>

<p>Specifically, in this problem, by the <em>distance</em> between two points a and b in the plane, we mean:</p>

<p style="text-align: center;">d(a, b) = |x<sub>a</sub> - x<sub>b</sub>| + |y<sub>a</sub> - y<sub>b</sub>|</p>

<p>where x<sub>a</sub> and y<sub>a</sub> denote the x- and y-coordinates of point a, and x<sub>b</sub> and y<sub>b</sub> denote the x- and y-coordinates of point b. Then, a pair (p, q) with p ∈ P and q ∈ Q is a closest pair of P and Q if and only if the following holds:</p>

<p style="text-align: center;">d(p, q) = min{ d(p′, q′) | p′ ∈ P and q′ ∈ Q}</p>

<p>Given two sets P and Q, write a program that computes the distance between a closest pair of P and Q and the number of distinct closest pairs of P and Q.</p>

<p>Note that you can assume the following on the input points in P and Q:</p>

<ol>
	<li>All the points in P lie on the horizontal line y = c<sub>1</sub> while all the points in Q lie on the horizontal line y = c<sub>2</sub> for some integers c<sub>1</sub> and c<sub>2</sub>.</li>
	<li>No two input points in P have the same coordinates; no two input points in Q have the same coordinates.</li>
</ol>

### 입력 

 <p>Your program is to read from standard input. The input consists of four lines. The first line contains two integers, n (1 ≤ n ≤ 500,000) and m (1 ≤ m ≤ 500,000), where n is the number of points in set P and m is the number of points in set Q. In the second line, two integers c<sub>1</sub> and c<sub>2</sub> (-10<sup>8</sup> ≤ c<sub>1</sub>, c<sub>2</sub> ≤ 10<sup>8</sup>) are given in order, separated by a single space. In the third line, n distinct integers between -10<sup>8</sup> and 10<sup>8</sup>, inclusively, are given, separated by a single space, that are the x-coordinates of the points in set P, while their y- coordinates are all the same as c<sub>1</sub>. In the fourth line, m distinct integers between -10<sup>8</sup> and 10<sup>8</sup>, inclusively, are given, separated by a single space, that are the x-coordinates of the points in set Q, while their y- coordinates are all the same as c<sub>2</sub>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for the input. The line should contain two integers, separated by a single space, that represent the distance between a closest pair of P and Q and the number of closest pairs of P and Q in this order.</p>

