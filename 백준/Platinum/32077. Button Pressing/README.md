# [Platinum I] Button Pressing - 32077 

[문제 링크](https://www.acmicpc.net/problem/32077) 

### 성능 요약

메모리: 5732 KB, 시간: 4 ms

### 분류

애드 혹, 누적 합, 불변량 찾기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given $N$ buttons (numbered from $1$ to $N$) and $N$ lamps (numbered from $1$ to $N$). Each lamp can either be on or off. Initially, lamp $i$ is on if $A_i = 1$, and off if $A_i = 0$.</p>

<p>Button $i$ is connected to lamp $i - 1$ (if $i > 1$) and lamp $i + 1$ (if $i < N$). In one move, you can press a button <strong>$i$ only if lamp $i$ is on</strong>. When a button is pressed, the state of the lamps connected to this button is toggled. Formally, the lamps will be on if it was off previously, and the lamps will be off if it was on previously. Note that lamp i is not connected to button $i$, thus, the state of lamp $i$ does not change if button $i$ is pressed.</p>

<p>After zero or more moves, you want lamp $i$ to be on if $B_i = 1$, and off if $B_i = 0$. Determine if it is possible to achieve this task.</p>

### 입력 

 <p>This problem has multiple test cases. The first line consists of an integer $T$ ($1 ≤ T ≤ 1000$), which represents the number of test cases. Each test case consists of three lines.</p>

<p>The first line of each test case consists of an integer $N$ ($3 ≤ N ≤ 200\, 000$). The sum of $N$ over all test cases does not exceed $200\, 000$.</p>

<p>The second line of each test case consists of a string $A$ of length $N$. Each character of $A$ can either be $0$ or $1$. The $i$<sup>th</sup> character represents the initial state of lamp $i$.</p>

<p>The third line of each test case consists of a string $A$ of length $N$. Each character of $B$ can either be $0$ or $1$. The $i$<sup>th</sup> character represents the desired final state of lamp $i$.</p>

### 출력 

 <p>For each test case, output <code>YES</code> in a single line if the final state of all lamps can be reached after zero or more moves, or <code>NO</code> otherwise.</p>

