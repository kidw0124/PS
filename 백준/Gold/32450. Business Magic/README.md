# [Gold III] Business Magic - 32450 

[문제 링크](https://www.acmicpc.net/problem/32450) 

### 성능 요약

메모리: 4364 KB, 시간: 44 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>There are $n$ stores located along a street, numbered from $1$ to $n$ from nearest to farthest. Last month, the store $k$ had a net profit of $r_k$. If $r_k$ is positive, it represents a proft of $r_k$ dollars; if $r_k$ is negative, it represents a loss of $-r_k$ dollars.</p>

<p>As a master of business magic, you have two types of spells at your disposal that you can use to alter the net profts of these stores for the next month:</p>

<ol>
	<li><strong>Blue Magic</strong>: You can choose a single continuous interval $[L, R]$. The effect of this spell will be to double the net profit of every store from store $L$ to store $R$ (inclusive) for the next month. That is, if $k \in [L, R]$, then store $k$ will have net profit $2r_k$ next month.</li>
	<li><strong>Green Magic</strong>: You can choose any store and cast the green magic on it. The effect of the green magic is to change the next month’s net profit of that store to the negative of its last month’s net profit.</li>
</ol>

<p>Any store that has not been affected by either spell will have the same net profit next month as it did last month.</p>

<p>However, there are some restrictions when casting spells. You can only cast the blue magic once and it must be used before the green magic. Additionally, the green magic cannot be cast on any store that has already been affected by the blue magic. Your task is to determine the <em>maximum possible sum of the net profits</em> for all stores for the next month after casting your spells optimally.</p>

### 입력 

 <p>The first line contains an integer $n$, the number of stores. The second line contains $n$ space-separated integers $r_1, r_2, \dots ,r_n$, where $r_k$ is the net profit of store $k$ last month.</p>

### 출력 

 <p>Output a single integer, the maximum possible total net profit of all stores for the next month after casting the spells optimally.</p>

