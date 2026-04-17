# [Diamond I] Friendship Circles - 21065 

[문제 링크](https://www.acmicpc.net/problem/21065) 

### 성능 요약

메모리: 77272 KB, 시간: 688 ms

### 분류

기하학, 반평면 교집합, 델로네 삼각분할

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Let $p_0, p_1, \dots, p_{n-1}$ be $n$ points in the plane. We say that two points are <em>friends</em> if one can draw a circle that contains both points in its interior and all the other $n-2$ points in its exterior. Print the indices of the points that are friends with $p_0$.</p>

<p>It is guaranteed that there is no circumference containing $p_0$ and three or more other points. It is also guaranteed that there is no line containing $p_0$ and two or more other points.</p>

### 입력 

 <p>The first line contains an integer $t$, the number of test cases ($1 \leq t \leq 10^4$).</p>

<p>Each test case starts with a line containing an integer $n$ ($2 \leq n \leq 10^5$), the number of points. It is followed by $n$ lines, each one containing two integers $x_i$ and $y_i$ ($-10^{9} \leq x_i, y_i \leq 10^{9}$): the coordinates of the $i$-th point.</p>

<p>The tests are not explicitly targeting precision issues. In particular, it is guaranteed that, if we moved $p_0$ by a distance of at most $10^{-6}$ units in any direction, the answer would remain the same.</p>

<p>The total number of points in all test cases does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, print a line containing one integer $m$, the number of friends of $p_0$, followed by $m$ integers: the indices of the friends of $p_0$ in lexicographical order.</p>

