# [Diamond V] Factorization - 17603 

[문제 링크](https://www.acmicpc.net/problem/17603) 

### 성능 요약

메모리: 2056 KB, 시간: 0 ms

### 분류

수학, 정수론, 이산 제곱근

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Integer factorization serves an important role in many cryptography systems. It is about finding two positive integers p and q for a given positive composite number n such that n = pq and 1 < p ≤ q < n. However, it is a well-known NP-intermediate candidate. We still don’t have any algorithm to solve it in polynomial time.</p>

<p>Taylor, a number theorist, created another factorization problem as follows.</p>

<p>Given a prime number p and two integers a<sub>0</sub>, a<sub>1</sub> ∈ {0, 1, . . . p − 1}. Find two integers b<sub>0</sub>, b<sub>1</sub> ∈ {0, 1, . . . p − 1} such that a<sub>0</sub> ≡ b<sub>0</sub> · b<sub>1</sub> (mod p) and a<sub>1</sub> ≡ b<sub>0</sub> + b<sub>1</sub> (mod p).</p>

<p>“This factoring is way much cooler, in the sense that it can be computed efficiently,” said Taylor. Now, he invites you to enjoy this new variant of factorization.</p>

### 입력 

 <p>The first line contains an integer 1 ≤ T ≤ 100 indicating the number of test cases. For each test case, there is a line containing three non-negative integers p, a0, a1 separated by a single blank.</p>

### 출력 

 <p>For each test case, output a line containing b<sub>0</sub> and b<sub>1</sub> in ascending order separated by a single blank if b<sub>0</sub> and b<sub>1</sub> satisfy the equations. If there are multiple solutions, you may output any of them. If there is no solution, output −1.</p>

