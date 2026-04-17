# [Gold III] Make RUN Great Again - 32467 

[문제 링크](https://www.acmicpc.net/problem/32467) 

### 성능 요약

메모리: 5756 KB, 시간: 304 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>KAIST Clubs Union is a student agency that delegates the university’s club funding based on the club’s activity records. Taein is a member of RUN — the <em>marathon</em> club of KAIST — and has joined the KAIST Clubs Union to make it richer.</p>

<p>There are $N+1$ clubs at KAIST numbered from $1$ to $N+1$. RUN has a number $N+1$. KAIST Clubs Union will assign the <strong>scores</strong> to each club, which is a non-negative integer. A club’s rank is then defined as $(\text{Number of clubs with a higher score than itself}) +1$. Note that there can be multiple clubs with the same rank. The funding opportunities for the club will be better if a club’s rank is lower.</p>

<p>Taein wishes to fabricate the scores in favor of RUN. Currently, every club <strong>except the RUN</strong> has their scores determined — for each $1\le i\le N$, club $i$ has a score of $a_i$. Taein can change each club’s score under the following conditions:</p>

<ul>
	<li>Each club’s score should not increase after Taein’s change.</li>
	<li>Each club’s score must be a non-negative integer after Taein’s change.</li>
	<li>If Taein reduces the club $i$’s score by $T$, the KAIST Clubs Union’s <strong>skepticism factor</strong> will increase by $T\times b_i$, where $b_i$ is an integer decided for each club based on their influence and information gathering skills.</li>
	<li>The total <strong>skepticism factor</strong> should be <strong>less than</strong> $K$. If it is at least $K$, it will trigger an internal investigation, which might cause trouble for Taein.</li>
</ul>

<p>After the fabrication, Taein will fill in the score for RUN, which will finish the funding delegation process.</p>

<p>To avoid suspicion, Taein wishes to keep the score for RUN as low as possible while keeping the rank small enough for all needed funds. You should find the lowest possible initial score for RUN, such that the final rank of RUN is at most $X$, and there exists a fabrication scheme that raises the skepticism factor by <strong>less than</strong> $K$. Since RUN is a club as well, this score has to be a non-negative integer as well.</p>

### 입력 

 <p>The first line contains $N,K,X$, separated by spaces.</p>

<p>The $i$-th of the next $N$ lines contains $a_i$ and $b_i$, separated by a space.</p>

### 출력 

 <p>Print the lowest possible initial score for RUN, such that the final rank of RUN is at most $X$, and there exists a fabrication scheme that raises the skepticism factor by <strong>less than</strong> $K$. Since RUN is a club as well, this score has to be a non-negative integer as well.</p>

