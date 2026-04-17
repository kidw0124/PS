# [Platinum III] Concurrent Contests - 32597 

[문제 링크](https://www.acmicpc.net/problem/32597) 

### 성능 요약

메모리: 8352 KB, 시간: 88 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Because of some scheduling issues, there are $m$ different programming contests scheduled on the same day, at the same time. There are $n$ people who would like to participate in these contests, but because all contests happen simultaneously, each participant can only compete in one contest. Everyone wants to choose the contest in which to participate such that their expected winnings are maximized.</p>

<p>Every contest has a single cash prize for the winner (no-one else gets a prize). Furthermore, every participant has a skill level, which determines their winning probability. If the sum of skill levels over all participants in a contest is $t$, then the winning probability in this contest of a participant with skill level $s$ is $\frac{s}{t}$.</p>

<p>Find a distribution of the participants over the contests, such that it is impossible for any person to switch to a different contest and increase their expected winnings. It is guaranteed that such a distribution exists.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $m$ ($1\leq n\leq 2\cdot10^5$, $1 \leq m \leq 100$), the number of contestants and the number of contests.</li>
	<li>One line with $n$ integers $s$ ($1\leq s\leq10^9$), the skill levels of the contestants.</li>
	<li>One line with $m$ integers $p$ ($1 \leq p \leq 10^9$), the prizes for the winners of the contests.</li>
</ul>

<p>The sum of all skill levels is at most \(10^9\).</p>

### 출력 

 <p>For each contest, output the number of contestants that should participate in this contest, followed by the $1$-based indices of the contestants that should participate in this contest.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

