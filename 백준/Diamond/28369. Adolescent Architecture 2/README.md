# [Diamond III] Adolescent Architecture 2 - 28369 

[문제 링크](https://www.acmicpc.net/problem/28369) 

### 성능 요약

메모리: 2176 KB, 시간: 0 ms

### 분류

기하학, 매개 변수 탐색, 게임 이론, 스프라그–그런디 정리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Three years ago, you helped little Peter stack his toy blocks into a tower. Since then, he has extended his collection of toy blocks, which now features the following base shapes:</p>

<ul>
	<li><code>circle</code> $a$ -- a circle of radius $a$;</li>
	<li><code>square</code> $a$ -- a square with side length $a$;</li>
	<li><code>triangle</code> $a$ -- an equilateral triangle with side length $a$.</li>
</ul>

<p>Here, $a$ may be any positive integer. The top shapes of each block are the same as their bottom shapes, so the blocks are cuboids, cylinders, and triangular prisms, respectively. Peter has an infinite supply of blocks of each shape and size.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 503px; height: 100px;"></p>

<p style="text-align: center;">Figure A.1: A game in progress.</p>

<p>Peter and his friend Amy are playing a two-player game, where the blocks need to be stacked on top of each other. Initially, some blocks are already placed on the floor. In each move, the current player must take a toy block from the infinite supply and put it on top of one of the existing stacks of blocks. The block may be rotated around its vertical axis before placing it. The outline of the new block must be strictly within the outline of the old block; the outlines are not allowed to touch. The first player who is unable to make a move loses the game.</p>

<p>Given the initial configuration, determine the number of winning moves for the first player.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \le n \le 1000$), the number of initial stacks.</li>
	<li>$n$ lines, each with a string $s$ ($s$ is one of "<code>circle</code>", "<code>square</code>" or "<code>triangle</code>") and an integer $a$ ($1 \le a \le 10^9$), giving the topmost blocks of the initial stacks as described above.</li>
</ul>

### 출력 

 <p>Output the number of winning moves for the first player.</p>

