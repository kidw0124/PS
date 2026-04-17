# [Platinum III] Personality Test - 31599 

[문제 링크](https://www.acmicpc.net/problem/31599) 

### 성능 요약

메모리: 33260 KB, 시간: 404 ms

### 분류

브루트포스 알고리즘, 비둘기집 원리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>There are $n$ students taking a personality test consisting of $m$ questions. The students are numbered from $1$ to $n$ and the questions are numbered from $1$ to $m$. For each question, each student can either answer it with a single uppercase Latin character (<code>A</code>–<code>Z</code>) or not answer it. Let $S_i$ be a string of $m$ characters representing the answers of student $i$, where the $j$-th character of $S_i$ is an uppercase Latin character if they answered question $j$, or a period (<code>.</code>) if they did not.</p>

<p>Two students are considered <em>similar</em> if there is a set of at least $k$ questions where both students answered all questions in the set, and for each question in the set, they answered it with the same answer.</p>

<p>For example, let $n = 3$, $m = 3$, $k = 2$, $S_1 =$ <code>BBC</code>, $S_2 =$ <code>..C,</code> and $S_3 =$ <code>.BC</code>. In this example, students $1$ and $3$ are similar since they answered questions $2$ and $3$ with the same answer, while students $2$ and $3$ are not similar since they answered only question $3$ with the same answer.</p>

<p>You want to find a pair of integers $(a, b)$ such that $a < b$ and students $a$ and $b$ are similar, or determine if there is no such pair. If there is more than one pair, find the one with the <strong>smallest</strong> $b$. If there is still more than one pair, find the one with the <strong>largest</strong> $a$.</p>

### 입력 

 <p>The first line of input contains three integers $n$, $m$, and $k$ ($2 ≤ n ≤ 5000$; $1 ≤ m ≤ 3000$; $1 ≤ k ≤ 5$). Each of the next $n$ lines contains a string of $m$ characters. The $i$-th line contains the string $S_i$.</p>

### 출력 

 <p>Output one line containing the integers $a$ and $b$ representing the pair of similar students as mentioned in the problem statement, or just the integer <code>-1</code> if there is no such pair.</p>

