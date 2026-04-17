# [Gold II] Construct a Coin Set - 32462 

[문제 링크](https://www.acmicpc.net/problem/32462) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The change-making problem is the problem of finding the minimum number of coins that add up to the change to be returned after purchasing items at a shop. A coin set refers to a collection of coin values available for making the change. The greedy algorithm for the change-making problem repeatedly selects the largest coin value among the coin set that does not exceed the remaining amount of change. This process continues until the total amount of change is made.</p>

<p>An optimal solution refers to a solution that uses the fewest number of coins. However, the greedy algorithm does not always guarantee an optimal solution. Under certain conditions, the greedy algorithm may give a non-optimal solution.</p>

<p>Given a positive integer $N$, your task is to find a coin set for which the greedy algorithm returns an optimal solution for all amounts from $1$ won to $(N-1)$ won, but not for $N$ won. Notice that the coin whose value is $1$ is always in the coin set.</p>

### 입력 

 <p>The first line of input contains the number of test cases $T$. Each of the next $T$ lines of input contains a single integer $N$.</p>

### 출력 

 <p>For each test case,</p>

<p>If it is impossible to construct a coin set satisfying the conditions given in the problem, print $-1$.</p>

<p>If it is possible to construct a coin set, print the size of the coin set $K$ in the first line. In the next line, print the coin values $a_{1},a_{2},\ldots ,a_{K}$, separated by spaces in increasing order. The size of the coin set does not have to be a minimum.</p>

