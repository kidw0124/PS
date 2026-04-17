# [Gold V] Pho Restaurant - 31600 

[문제 링크](https://www.acmicpc.net/problem/31600) 

### 성능 요약

메모리: 3408 KB, 시간: 16 ms

### 분류

그리디 알고리즘, 많은 조건 분기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>As you may know, pho is one of the most common dishes in Hanoi. It contains a special kind of flour noodles, meat (usually beef or chicken), and green onions dipped in a tasty broth. Vietnamese people enjoy pho for breakfast, lunch, dinner, and even light meals. For tourists, trying pho is a must, especially in the cold of Hanoi.</p>

<p>You own a <em>phở bò</em> (beef pho) restaurant in Vietnam with $n$ tables, numbered $1$ to $n$. The 2024 ICPC Asia Pacific Championship contestants are currently in your restaurant. Each contestant is initially seated at one of the tables and there is at least one contestant initially seated at each table.</p>

<p>Each contestant would like to order one of the two most well-known kinds of pho: <em>phở tái</em> (pho with medium-rare beef) or <em>phở chín</em> (pho with well-done beef). The initial state of table $i$ is represented by the binary string $S_i$. The length of $S_$i is the number of contestants initially seated at table $i$. The $j$-th character of $S_i$ is $0$ if the $j$-th contestant initially seated at the table would like to order a <em>phở tái</em>, and $1$ if the contestant would like to order a <em>phở chín</em>.</p>

<p>To make it easier to track the orders, the restaurant wants the contestants seated at the same table to have the same order. That is, for each table, at least one of the following must be true:</p>

<ul>
	<li>All of the contestants seated at that table would like to order a <em>phở tái</em>.</li>
	<li>All of the contestants seated at that table would like to order a <em>phở chín</em>.</li>
</ul>

<p>To satisfy this requirement and the contestants’ orders, you want to move zero or more contestants to a different table. The destination table must be one of the $n$ tables. In other words, you must not add new tables. There is no limit to the number of contestants that can be seated at the same table. After moving the contestants, the following condition should be satisfied by each table: either there is no contestant seated at that table or all contestants seated at that table would like to order the same dish.</p>

<p>Since moving contestants takes some time, you would like to compute the minimum number of contestants you need to move.</p>

### 입력 

 <p>The first line of input contains one integer $n$ ($2 ≤ n ≤ 100\, 000$). Each of the next $n$ lines contains a binary string. The $i$-th line contains $S_i$ ($1 ≤ |S_i | ≤ 200\, 000$). The sum of $|S_i |$ across all $i$ does not exceed $500\, 000$.</p>

### 출력 

 <p>Output an integer representing the minimum number of contestants you need to move.</p>

