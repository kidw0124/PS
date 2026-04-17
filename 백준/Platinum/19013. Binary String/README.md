# [Platinum I] Binary String - 19013 

[문제 링크](https://www.acmicpc.net/problem/19013) 

### 성능 요약

메모리: 34108 KB, 시간: 1112 ms

### 분류

무작위화

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>This is an interactive problem.</p>

<p>The jury has a secret string which consists of exactly $1000$ binary digits. In each test for this problem, the string is fixed in advance and does not change. You have to find this string using queries.</p>

<p>In each query, you choose a segment $[a, b]$ ($1 \leq a \leq b \leq 1000$) to ask about. Then the jury flips a coin, and gives you one of the two values, each with probability of 50%:</p>

<ol>
	<li>The number of $1$s in the segment $[a, b]$; </li>
	<li>A value from $0$ to $b - a + 1$ which is <strong>not equal</strong> to the number of ones on this segment, chosen uniformly at random.</li>
</ol>

<p>You are <strong>not allowed</strong> to use the same query twice. All random values used in this problem are uniform and independent.</p>

### 입력 

 Empty

### 출력 

 Empty

