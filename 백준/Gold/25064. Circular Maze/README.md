# [Gold II] Circular Maze - 25064 

[문제 링크](https://www.acmicpc.net/problem/25064) 

### 성능 요약

메모리: 2288 KB, 시간: 24 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given a circular maze such as the ones shown in the figures.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 352px; height: 166px;"></p>

<p>Determine if it can be solved, i.e., if there is a path which goes from the center to the outside of the maze which does not touch any wall. The maze is described by $n$ walls. Each wall can be either circular or straight.</p>

<ul>
	<li>Circular walls are described by a radius $r$, the distance from the center, and two angles $θ_1$, $θ_2$ describing the beginning and the end of the wall in the clockwise direction. Notice that swapping the two angles changes the wall.</li>
	<li>Straight walls are described by an angle $θ$, the direction of the wall, and two radii $r_1 < r_2$ describing the beginning and the end of the wall.</li>
</ul>

<p>Angles are measured in degrees; the angle $0$ corresponds to the upward pointing direction; and angles increase clockwise (hence the east direction corresponds to the angle $90$).</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 20$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains an integer $n$ ($1 ≤ n ≤ 5000$) — the number of walls.</p>

<p>Each of the following $n$ lines each contains a character (<code>C</code> for circular, and <code>S</code> for straight) and three integers:</p>

<ul>
	<li>either $r$, $θ_1$, $θ_2$ ($1 ≤ r ≤ 20$ and $0 ≤ θ_1, θ_2 < 360$ with $θ_1 \ne θ_2$) if the wall is circular,</li>
	<li>or $r_1$, $r_2$ and $θ$ ($1 ≤ r_1 < r_2 ≤ 20$ and $0 ≤ θ < 360$) if the wall is straight.</li>
</ul>

<p>It is guaranteed that circular walls do not overlap (but two circular walls may intersect at one or two points), and that straight walls do not overlap (but two straight walls may intersect at one point). However, circular and straight walls can intersect arbitrarily</p>

### 출력 

 <p>For each test case, print <code>YES</code> if the maze can be solved and <code>NO</code> otherwise.</p>

