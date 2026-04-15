# [Bronze I] Triple Fairness - 34872 

[문제 링크](https://www.acmicpc.net/problem/34872) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

해 구성하기

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p><strong>This problem adopts exactly the same definition of <em>Fair Problemset</em> as Problem H, “Fair Problemset”.</strong></p>

<p>ICPC is a team competition. Each team has three members. At the beginning of a contest, most teams divide the $3n$ problem evenly. They use one of two common methods to distribute problems:</p>

<ol>
<li><strong>Sequential Distribution</strong>: Each member takes a contiguous block of $n$ problems from the set of $3n$ problems. Specifically, the first member takes problems $1, \cdots , n$, the second member takes problems $n + 1, \cdots , 2n$, and the third member takes problems $2n + 1, \cdots , 3n$.</li>
<li><strong>Jump Distribution</strong>: Each member takes problems with indices that have the same remainder when divided by $3$ from the set of $3n$ problems. Specifically, the first member takes problems $1, 4, 7, \cdots , 3n − 2$, the second member takes problems $2, 5, 8, \cdots , 3n − 1$, and the third member takes problems $3, 6, 9, \cdots , 3n$.</li>
</ol>

<p>The ICPC Seoul Regional Contest Scientific Committee must prepare a problemset consisting of $3n$ problems. The difficulty of each problem is represented by an integer from $1$ to $n$, inclusive. For each difficulty, there are exactly three problems with that difficulty. Thus, the arrangement of difficulties in the problemset can be viewed as a <em>difficulty sequence</em> of length $3n$ containing three problems of each of the $n$ difficulty levels.</p>

<p>To prevent any advantage or disadvantage for a team based on their chosen problem distribution method, the ICPC Seoul Regional Contest Scientific Committee has defined a standard called a <em>Fair Problemset</em>. A difficulty sequence of length $3n$ is called a Fair Problemset if it satisfies both of the following conditions:</p>

<ol>
<li><strong>Sequential Distribution Fairness</strong>: When using Sequential Distribution, for every difficulty level $i$ ($1 ≤ i ≤ n$), each of the three members receives exactly one problem with difficulty $i$.</li>
<li><strong>Jump Distribution Fairness</strong>: When using Jump Distribution, for every difficulty level $i$ ($1 ≤ i ≤ n$), each of the three members receives exactly one problem with difficulty $i$.</li>
</ol>

<p>In other words, regardless of which of the two methods is chosen, each team member must be assigned exactly one problem for each difficulty level from $1$ to $n$, inclusive.</p>

<p>Given a positive integer $n$, write a program to find <strong>any</strong> Fair Problemset sequence of length $3n$.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of exactly one line. The line contains an integer $n$ ($1 ≤ n ≤ 200$; $n$ is <strong>not</strong> divisible by $3$). It can be shown that for every valid input, there exists at least one Fair Problemset sequence of length $3n$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line consisting of $3n$ space-separated positive integers, representing a Fair Problemset sequence of length $3n$. Any valid Fair Problemset sequence of length $3n$ will be accepted.</p>

