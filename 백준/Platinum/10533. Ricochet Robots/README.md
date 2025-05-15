# [Platinum III] Ricochet Robots - 10533 

[문제 링크](https://www.acmicpc.net/problem/10533) 

### 성능 요약

메모리: 26372 KB, 시간: 264 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 5월 16일 03:56:38

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images2/robot1.png" style="float:right; height:273px; width:232px">A team of up-to four robots is going to deliver parts in a factory floor. The floor is organized as a rectangular grid where each robot ocupies a single square cell. Each robot is represented by an integer from 1 to 4 and can move in the four orthogonal directions (left, right, up, down). However, once set in motion, a robot will stop only when it detects a neighbouring obstacle (i.e. walls, the edges of the factory or other stationary robots). Robots do not move simultaneously, i.e. only a single robot moves at each time step.</p>

<p>The goal is to compute an efficient move sequence such that robot 1 reaches a designed target spot; this may require moving other robots out of the way or to use them as obstacles for “ricocheting” moves.</p>

<p>Consider the example given above, on the right, where the gray cells represent walls, X is the target location and 1 , 2 mark the initial positions of two robots. One optimal solution consists of the six moves described below.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/robot2.png" style="height:120px; width:626px"></p>

<p>Note that the move sequence must leave robot 1 at the target location and not simply pass through it (the target does not cause robots to stop — only walls, edges and other robots).</p>

<p>Given the description of the factory floor plan, the initial robot and target positions, compute the minimal total number of moves such that robot 1 reaches the target position.</p>

### 입력 

 <p>The first line contains the number of robots n, the width w and height h of the factory floor in cells, and an upper-bound limit ℓ on the number of moves for searching solutions.</p>

<p>The remaining h lines of text represent rows of the factory floor with exactly w characteres each representing a cell position:</p>

<ul>
	<li>W a cell occupied by a wall;</li>
	<li>X the (single) target cell;</li>
	<li>1,2,3,4 initial position of a robot;</li>
	<li>’.’ an empty cell.</li>
</ul>

### 출력 

 <p>The output should be the minimal number of moves for robot 1 to reach the target location or NO SOLUTION if no solution with less than or equal the given upper-bound number of moves exists.</p>

