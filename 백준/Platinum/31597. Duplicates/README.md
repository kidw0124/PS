# [Platinum V] Duplicates - 31597 

[문제 링크](https://www.acmicpc.net/problem/31597) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

구현, 애드 혹, 해 구성하기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>We say that a number sequence <em>contains duplicates</em> if there is an element that appears more than once in the sequence. Formally, a sequence $(a_1, \dots , a_n)$ contains duplicates if there exist two indices $i$ and $j$ such that $i \ne j$ and $a_i = a_j$.</p>

<p>You are given an $n \times n$ matrix $X$. Each entry in $X$ is an integer between $1$ and $n$, inclusive. You can modify zero or more entries in $X$ to arbitrary integers between $1$ and $n$, inclusive. Different entries can be modified to different integers.</p>

<p>Your task is to make modifications to entries of $X$ such that all of the following hold:</p>

<ul>
	<li>For each row $i$, the sequence $(X_{i1}, X_{i2}, \dots , X_{in})$ contains duplicates.</li>
	<li>For each column $j$, the sequence $(X_{1j }, X_{2j}, \dots , X_{nj})$ contains duplicates.</li>
</ul>

<p>Compute the minimum number of entries that need to be modified to achieve this. Also, find one possible set of modifications to do it. For each modification, you have to specify which entry will be modified and to what value. Note that the minimum number of entries to be modified can be zero when the given matrix $X$ already satisfies the conditions above.</p>

### 입력 

 <p>The first line of input contains one integer $t$ ($1 ≤ t ≤ 1000$) representing the number of test cases. After that, $t$ test cases follow. Each of them is presented as follows.</p>

<p>The first line of a test case contains one integer $n$ ($3 ≤ n ≤ 100$). Each of the next $n$ lines contains $n$ integers. The $j$-th integer in the $i$-th line denotes $X_{ij}$ ($1 ≤ X_{ij} ≤ n$).</p>

<p>The sum of $n^2$ across all test cases in one input file does not exceed $10\, 000$.</p>

### 출력 

 <p>For each test case, output a set of modifications in the following format.</p>

<p>On the first line, output an integer $m$ representing the minimum number of entries that need to be modified. On each of the next $m$ lines, output three integers $i$, $j$, and $v$. This represents a single modification where the entry $X_{ij}$ will be modified to $v$. All of the three integers must be between $1$ and $n$, inclusive.</p>

<p>If there are multiple solutions, you can output any of them.</p>

