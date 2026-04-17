# [Platinum I] Greek Casino - 31757 

[문제 링크](https://www.acmicpc.net/problem/31757) 

### 성능 요약

메모리: 22340 KB, 시간: 780 ms

### 분류

수학, 다이나믹 프로그래밍, 정수론, 확률론, 조화수

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Since the early civilizations, humankind has enjoyed games of chance. Even the ingenious Greeks, known for their groundbreaking concept of the least common multiple (LCM), couldn’t resist a good gamble.</p>

<p>Inspired by this mathematical marvel, folks in Athens devised a unique betting system: after purchasing a ticket, a participant would receive a random number of coins. To determine this number, there are $N ≥ 3$ ordered slots numbered from $1$ to $N$. A token is initially placed at slot $1$, and the following steps are repeated:</p>

<ul>
	<li>Let $xv be the number of the slot where the token is currently located.</li>
	<li>Generate a random integer $y$ between $1$ and $N$, and compute $z$ the LCM of $x$ and $y$.</li>
	<li>If $z > N$, the procedure ends.</li>
	<li>Otherwise, the token is moved to slot $z$, and the participant receives one coin.</li>
</ul>

<p>As it is well known, the house always wins: the casino employs a particular probability distribution for generating random integers, so as to ensure a profitable outcome.</p>

<p>The casino owner is constantly seeking to optimize the betting system’s profitability. You, an AI designed to aid in such tasks, are given $N$ and the probability distribution. Determine the expected total number of coins awarded to a participant.</p>

### 입력 

 <p>The first line contains an integer $N$ ($3 ≤ N ≤ 10^5$) indicating the number of slots.</p>

<p>The second line contains $N$ integers $W_1, W_2, \dots , W_N$ ($1 ≤ W_i ≤ 1000$ for $i = 1, 2, \dots , N$), representing that the probability of generating $i$ is $W_i/ \left( \sum_j{W_j} \right)$, that is, the probability of generating $i$ is the relative weight of $W_i$ with respect to the sum of the whole list $W_1, W_2, \dots , W_N$.</p>

### 출력 

 <p>Output a single line with the expected total number of coins awarded to a participant. The output must have an absolute or relative error of at most $10^{-9}$. It can be proven that the procedure described in the statement ends within a finite number of iterations with probability $1$, and that the expected total number of coins is indeed finite.</p>

