# [Platinum IV] Reverse Game - 21906 

[문제 링크](https://www.acmicpc.net/problem/21906) 

### 성능 요약

메모리: 3680 KB, 시간: 12 ms

### 분류

애드 혹, 게임 이론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Alice and Bob are playing a turn-based game. The rules of the game are as follows:</p>

<ol>
	<li>At the beginning of the game some binary string $s$ is chosen.</li>
	<li>On his turn player has to choose some substring $t$ of $s$, equal to one of <code>10</code>, <code>110</code>, <code>100</code>, <code>1010</code>. Then the player has to reverse $t$. For example, if $s = $<code>010101</code>, the player can select substring $t = $<code>1010</code> and reverse it, obtaining $s = $<code>001011</code></li>
	<li>he player who can’t make a move (who can’t choose an appropriate substring $t$) loses.</li>
	<li>The players cannot skip a turn.</li>
</ol>

<p>Which player has the winning strategy, if Alice moves first?</p>

<p>A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.</p>

### 입력 

 <p>The only line of the input contains a binary string $s$ ($1 \le |s| \le 10^6$) — the string with which Alice and Bob play.</p>

### 출력 

 <p>If Alice wins, output <code>Alice</code>. Otherwise, output <code>Bob</code>.</p>

