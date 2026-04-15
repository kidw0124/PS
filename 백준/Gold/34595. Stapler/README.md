# [Gold I] Stapler - 34595 

[문제 링크](https://www.acmicpc.net/problem/34595) 

### 성능 요약

메모리: 2084 KB, 시간: 4 ms

### 분류

기하학, 많은 조건 분기, 선분 교차 판정

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Alice is selling a new model of game console in the toy store. When selling a new console, Alice uses a stapler to attach the receipt to the box.</p>

<p>However, the stapler pierces the box at two points, causing damage along the entire line segment between those two points. If any part of this segment (including its endpoints) overlaps with the console’s screen (including its boundary), it will be damaged and Alice must compensate for the console.</p>

<p>Fortunately, a laser reveals the exact position of the screen inside the box. The game console’s screen is a rectangle with sides parallel to the coordinate axes. Its bottom-left corner is at $(x_l , y_l)$ and its top-right corner is at $(x_r, y_r)$.</p>

<p>Alice plans to staple the box at the points $(x_1, y_1)$ and $(x_2, y_2)$. Please help her determine whether the stapler will damage the screen. If it will, stop her immediately.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$. The description of the test cases follows.</p>

<p>The first line of each test case contains four integers $x_l$, $y_l$, $x_r$, $y_r$, representing the coordinates of the bottom-left and top-right corners of the screen.</p>

<p>The second line of each test case contains four integers $x_1$, $y_1$, $x_2$, $y_2$, representing the coordinates of the expected stapler penetration positions.</p>

### 출력 

 <p>For each test case, print <code>STOP</code> on a line if Alice will damage the screen, and print <code>OK</code> otherwise.</p>

