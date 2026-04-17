# [Platinum III] Derangement Rotations - 21179 

[문제 링크](https://www.acmicpc.net/problem/21179) 

### 성능 요약

메모리: 17900 KB, 시간: 64 ms

### 분류

수학, 애드 혹, 정수론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A <em>Derangement</em> is a permutation $p$ of $1, 2, \dots , n$ where $p_i \ne i$ for all $i$ from $1$ to $n$.</p>

<p>A <em>rotation</em> of a sequence $a_1, a_2, \dots , a_n$ with offset $k$ ($1 \le k \le n$) is equal to the sequence $a_k, a_{k+1}, \dots, a_n, a_1, a_2, \dots, a_{k-1}$. A sequence of length $n$ has at most $n$ distinct rotations.</p>

<p>Given a derangement $D$, let $f(D)$ denote the number of distinct rotations of $D$ that are also derangements. For example, $f([2, 1]) = 1$, $f([3, 1, 2]) = 2$.</p>

<p>Given $n$ and a prime number $p$, count the number of derangements $D$ of $1, 2, \dots , n$ such that $f(D) = n - 2$, modulo $p$.</p>

### 입력 

 <p>The single line of input contains two integers $n$ ($3 \le n \le 10^6$) and $p$ ($10^8 \le p \le 10^9 + 7$), where $n$ is a permutation size, and $p$ is a prime number.</p>

### 출력 

 <p>Output a single integer, which is the number of derangements $D$ of size $n$ with $f(D) = n - 2$, modulo $p$.</p>

