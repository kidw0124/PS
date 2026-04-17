# [Gold V] Double Rainbow - 23567 

[문제 링크](https://www.acmicpc.net/problem/23567) 

### 성능 요약

메모리: 2332 KB, 시간: 188 ms

### 분류

두 포인터

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Let $P$ be a set of $n$ points on the $x$-axis and each of the points is colored with one of the colors $1, 2, \dots , k$. For each color 𝑖 of the 𝑘 colors, there is at least one point in $P$ which is colored with $i$. For a set $P'$ of consecutive points from $P$, if both $P'$ and $P \backslash P'$ contain at least one point of each color, then we say that $P'$ makes a <em>double rainbow</em>. See the below figure as an example. The set 𝑃 consists of ten points and each of the points is colored by one of the colors $1$, $2$, $3$, and $4$. The set $P'$ of the five consecutive points contained in the rectangle makes a double rainbow.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 336px; height: 76px;"></p>

<p>Given a set $P$ of points and the number $k$ of colors as input, write a program that computes and prints out the minimum size of $P'$ that makes a double rainbow.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers $n$ and $k$ ($1 ≤ k ≤ n ≤ 10,000$), where $n$ is the number of the points in $P$ and $k$ is the number of the colors. Each of the following $n$ lines consists of an integer from $1$ to $k$, inclusively, and the $i$-th line corresponds to the color of the $i$-th point of $P$ from the left.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the minimum size of $P'$ that makes a double rainbow. If there is no such $P'$, print <code>0</code>.</p>

