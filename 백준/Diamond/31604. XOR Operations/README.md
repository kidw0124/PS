# [Diamond III] XOR Operations - 31604 

[문제 링크](https://www.acmicpc.net/problem/31604) 

### 성능 요약

메모리: 2804 KB, 시간: 48 ms

### 분류

수학, 선형대수학, 가우스 소거법, 배타적 논리합 기저 (gf(2))

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given $n$ integers $a_1, a_2, \dots , a_n$. You have a sequence of $n$ integers $B = (b_1, b_2, \dots , b_n)$ which initially are all zeroes.</p>

<p>In one operation, you choose two different indices $i$ and $j$, then simultaneously</p>

<ul>
	<li>replace $b_i$ with $b_i \oplus a_i \oplus a_j$, and</li>
	<li>replace $b_j$ with $b_j \oplus a_i \oplus a_j$.</li>
</ul>

<p>Note that $\oplus$ represents the bitwise XOR operation, which returns an integer whose binary representation has a $1$ in each bit position for which the corresponding bits of either but not both operands are $1$. For example, $3 \oplus 10 = 9$ because $(0011)_2 \oplus (1010)_2 = (1001)_2$.</p>

<p>You want to compute the number of different possible sequences $B$ you can obtain after performing zero or more operations. Since this number might be huge, calculate this number modulo $998\, 244\, 353$.</p>

<p>Two sequences of length $n$ are considered different if and only if there exists an index $i$ ($1 ≤ i ≤ n$) such that the $i$-th element of one sequence differs from the $i$-th element of the other sequence.</p>

### 입력 

 <p>The first line of input contains one integer $n$ ($2 ≤ n ≤ 200\, 000$). The second line contains $n$ integers $a_1, a_2, \dots , a_n$ ($0 ≤ a_i < 2^{30}$ for all $i$).</p>

### 출력 

 <p>Output an integer representing the number of different possible sequences $B$ you can obtain after performing zero or more operations modulo $998\, 244\, 353$.</p>

