# [Gold III] Journey to Jupiter - 18713 

[문제 링크](https://www.acmicpc.net/problem/18713) 

### 성능 요약

메모리: 2036 KB, 시간: 380 ms

### 분류

기하학, 3차원 기하학

### 제출 일자

2024년 7월 29일 21:57:40

### 문제 설명

<p>It’s the year 10, 007 AD, and all the delicious food in the Arab region has gone extinct. Luckily for you, you made once a time travel in the past and you could taste how delicious this food was. An alien rumor has come to you saying that there’s still remaining Arab food in Jupiter. Since the Alien rumors, unlike humans’, are usually true, you decided to build your own spacecraft to go to Jupiter. In order to test the control system you embedded in your spacecraft, you want to build a flight simulator, which is a device that artificially re-creates spacecraft flight and the environment in which it flies, for astronaut training and other purposes.</p>

<p>In this problem, a flight simulator consists of a 2-dimensional equilateral triangle of side length L, with three actuators (mechanical devices, that can be treated as line segments of modifiable lengths) attached to the vertices A, B, C of the triangle, respectively. The other ends of the actuators are all attached to a static base point located at (0, 0, −H). The midpoint of the triangle (located at (0, 0, 0)) is attached to the same base using a spherical connection, which means that the triangle can rotate in any direction but its midpoint cannot move.</p>

<p>The yoke (a device used to control the rotations of the triangle) has the direction vector along N = (N<sub>x</sub>, N<sub>y</sub>, N<sub>z</sub>) which is always normal on the plane of the triangle. By changing the direction of the yoke, the length of each actuator changes and the triangle rotates (the yoke will remain normal on the triangle), while the midpoint remains at (0, 0, 0). Initially, all the actuators have the same length, the triangle lies horizontally in the XY plane (i.e. z = 0) and the yoke is pointing along the positive Z-axis (i.e. initially N = (0, 0, 1)). The point A is initially located on the negative X-axis (z<sub>A</sub> = y<sub>A</sub> = 0, x<sub>A</sub> < 0) and the vertices A, B, C are in an anticlockwise order relative to the yoke direction.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/595a3767-d7d8-4a0f-958d-fdba2791c65c/-/preview/" style="width: 493px; height: 254px;"></p>

<p>We want you to write a program that makes the simulator rotate given a new yoke direction. Formally, given both of a yoke direction and the location of the point A after rotation, we need you to calculate the corresponding lengths of the actuators L<sub>1</sub>, L<sub>2</sub>, L<sub>3</sub>, which are attached to the vertices A, B, C respectively, so that the yoke direction is still normal on the triangle.</p>

### 입력 

 <p>The first line of the input contains a single integer T specifying the number of test cases.</p>

<p>Each test case consists of a single line containing eight integers N<sub>x</sub>, N<sub>y</sub>, N<sub>z</sub>, A<sub>x</sub>, A<sub>y</sub>, A<sub>z</sub>, L, and H (−500 ≤ A<sub>x</sub>, A<sub>y</sub>, A<sub>z</sub>, N<sub>x</sub>, N<sub>y</sub> ≤ 500, 1 ≤ N<sub>z</sub>, H, L ≤ 500), in which N<sub>x</sub>, N<sub>y</sub>, and N<sub>z</sub> is the yoke direction after rotation, A<sub>x</sub>, A<sub>y</sub>, and A<sub>z</sub> is the position of the point A after rotation, L is the side length of the triangle, and H is the point in the base where actuators are attached</p>

<p>It is guaranteed that the following constraints hold for all test cases:</p>

<ul>
	<li>A<sub>x</sub>, A<sub>y</sub>, A<sub>z</sub> ≠ 0</li>
	<li>A<sub>x</sub>N<sub>x</sub> + A<sub>y</sub>N<sub>y</sub> + A<sub>z</sub>N<sub>z</sub> = 0</li>
	<li>A<sub>x</sub><sup>2</sup> + A<sub>y</sub><sup>2</sup> + A<sub>z</sub><sup>2</sup> = L<sup>2</sup>/3.</li>
</ul>

### 출력 

 <p>For each test case, print a single line containing three space-separated decimal numbers (rounded to exactly 6 decimal places), the lengths L1, L2, L3 of the actuators connected to the vertices A, B, C corresponding to the given query.</p>

<p>The given input will guarantee that there is exactly one solution.</p>

