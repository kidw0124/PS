# [Platinum III] Moortal Cowmbat - 18264 

[문제 링크](https://www.acmicpc.net/problem/18264) 

### 성능 요약

메모리: 44272 KB, 시간: 116 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 누적 합, 최단 경로, 플로이드–워셜

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Bessie has been playing the popular fighting game Moortal Cowmbat for a long time now. However, the game developers have recently rolled out an update that is forcing Bessie to change her play style.</p>

<p>The game uses $M$ buttons labeled by the first $M$ lowercase letters ($1 \leq M \leq 26$). Bessie's favorite combo of moves in the game is a length-$N$ string $S$ of button presses ($1 \leq N \leq 10^5$). However, due to the most recent update, every combo must now be made from a series of "streaks", where a streak is defined as a series of the same button pressed at least $K$ times in a row ($1 \leq K \leq N$). Bessie wants to modify her favorite combo to produce a new combo of the same length $N$, but made from streaks of button presses to satisfy the change in rules.</p>

<p>It takes $a_{ij}$ days for Bessie to train herself to press button $j$ instead of button $i$ at any specific location in her combo (i.e. it costs $a_{ij}$ to change a single specific letter in $S$ from $i$ to $j$). Note that it might take less time to switch from using button $i$ to an intermediate button $k$ and then from button $k$ to button $j$ rather than from $i$ to $j$ directly (or more generally, there may be a path of changes starting with $i$ and ending with $j$ that gives the best overall cost for switching from button $i$ ultimately to button $j$).</p>

<p>Help Bessie determine the smallest possible number of days she needs to create a combo that supports the new requirements.</p>

### 입력 

 <p>The first line of input contains $N$, $M$, and $K$. The second line contains $S$, and the final $M$ lines contain an $M\times M$ matrix of values $a_{ij}$, where $a_{ij}$ is an integer in the range $0 \ldots 1000$ and $a_{ii} = 0$ for all $i$.</p>

### 출력 

 <p>Output a single number, representing the minimum number of days Bessie needs to change her combo into one that satisfies the new requirements.</p>

