# [Gold II] Colliding Traffic - 4185 

[문제 링크](https://www.acmicpc.net/problem/4185) 

### 성능 요약

메모리: 2184 KB, 시간: 28 ms

### 분류

브루트포스 알고리즘, 기하학, 수학, 물리학

### 제출 일자

2026년 04월 18일 01:08:27

### 문제 설명

<p>For a boat on a small, constrained body of water, other traffic can be a major hazard. The more traffic there is in the same area, the higher the risk of a collision.</p>

<p>Your job is to monitor traffic and help detect likely collisions before they occur. You have sensors to detect the position, direction, and speed of each boat. Assuming the direction and speed remain constant, your task is to determine whether any of the boats will collide. Two boats are considered to collide if they come within a given distance of each other.</p>

### 입력 

 <p>The first line of input contains a single integer <i>c</i>, the number of test cases to follow. Each test case starts with a line containing two numbers, <i>n</i>, the number of boats, and <i>r</i>, the collision distance. Two boats are considered to collide if they come within <i>r</i> metres of each other. There will be no more than 1000 boats. Each boat is identified by a line containing four numbers <i>x</i>, <i>y</i>, <i>d</i>, <i>s</i>. The numbers <i>x</i> and <i>y</i> give the current position of the boat as a distance east and north, respectively, from a common origin, and will be between -1000 and 1000, inclusive. The lake is small enough that we can model it as a flat surface. The number <i>d</i> gives the direction in which the boat is heading in degrees clockwise from north (so east is 90 degrees). The number <i>s</i> gives the speed of the boat in metres per second, and will be between 0.001 and 1000. Note that <i>r</i>, <i>x</i>, <i>y</i>, <i>d</i>, and <i>s</i> are not necessarily integers. The input data will be such that the answer will not change if any of the numbers <i>x</i>, <i>y</i>, <i>d</i> and <i>s</i> are changed by 10<sup>-6</sup> or less.</p>

### 출력 

 <p>For each test case, output a line containing a single integer, the number of seconds, rounded to the nearest second, before any of the boats come within <i>r</i> metres of each other. If none of the boats ever collide, output the line:</p>

<pre>No collision.
</pre>

