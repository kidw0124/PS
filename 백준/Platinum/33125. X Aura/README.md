# [Platinum III] X Aura - 33125 

[문제 링크](https://www.acmicpc.net/problem/33125) 

### 성능 요약

메모리: 11024 KB, 시간: 60 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Mount ICPC can be represented as a grid of $R$ rows (numbered from $1$ to $R$) and $C$ columns (numbered from $1$ to $C$). The cell located at row $r$ and column $c$ is denoted as $(r, c)$ and has a height of $H_{r,c}$. Two cells are adjacent to each other if they share a side. Formally, $(r, c)$ is adjacent to $(r - 1, c)$, $(r + 1, c)$, $(r, c - 1)$, and $(r, c + 1)$, if any exists.</p>

<p>You can move only between adjacent cells, and each move comes with a penalty. With an aura of an <strong>odd positive integer</strong> $X$, moving from a cell with height $h_1$ to a cell with height $h_2$ gives you a penalty of $(h_1-h_2)^X$. Note that the penalty can be negative.</p>

<p>You want to answer $Q$ independent scenarios. In each scenario, you start at the starting cell $(R_s, C_s)$ and you want to go to the destination cell $(R_f , C_f )$ with minimum total penalty. In some scenarios, the total penalty might become arbitrarily small; such a scenario is called <em>invalid</em>. Find the minimum total penalty to move from the starting cell to the destination cell, or determine if the scenario is invalid.</p>

### 입력 

 <p>The first line consists of three integers $R$ $C$ $X$ ($1 ≤ R, C ≤ 1000$; $1 ≤ X ≤ 9$; $X$ is an odd integer).</p>

<p>Each of the next $R$ lines consists of a string $H_r$ of length $C$. Each character in $H_r$ is a number from $0$ to $9$. The $c$<sup>th</sup> character of $H_r$ represents the height of cell $(r, c)$, or $H_{r,c}$.</p>

<p>The next line consists of an integer $Q$ ($1 ≤ Q ≤ 100\, 000$).</p>

<p>Each of the next $Q$ lines consists of four integers $R_s$ $C_s$ $R_f$ $C_f$ ($1 ≤ R_s, R_f ≤ R$; $1 ≤ C_s, C_f ≤ C$).</p>

### 출력 

 <p>For each scenario, output the following in a single line. If the scenario is invalid, output <code>INVALID</code>. Otherwise, output a single integer representing the minimum total penalty to move from the starting cell to the destination cell.</p>

