# [Platinum IV] Fractal Area - 32542 

[문제 링크](https://www.acmicpc.net/problem/32542) 

### 성능 요약

메모리: 2116 KB, 시간: 0 ms

### 분류

수학, 기하학, 미적분학

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>The director of the local Mathematical Institute has decided to brighten up the walls by adding some pictures of Bounded Auto-similar Periodic Curves, which are geometric structures usually known as fractals. The director has some great ideas for beautiful fractals, but they are not sure whether these will fit on the walls of the institute.</p>

<p>Since these fractals will be painted all over the walls of the institute, the director has asked you to determine the area of these fractals, so they know exactly how much paint they will need to use for this.</p>

<p>The fractals are constructed from a polyline<sup>1</sup> between $(0,0)$ and $(1,0)$. Starting with an equilateral triangle with side length $1$, each segment of the boundary is recursively replaced by a scaled and rotated version of the original polyline, so that the endpoints and orientation match.</p>

<p>As an example, consider the first sample case, visualized in Figure F.1. The resulting fractal in this case is called the <em>Koch Snowflake</em>.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 500px; height: 215px;"></p>

<p style="text-align: center;">Figure F.1: Visualization of the first sample case, with the given polyline on the left and the resulting fractal on the right.</p>

<hr>
<p><sup>1</sup>A polyline is a shape made by connecting a series of straight line segments at their endpoints.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($2\leq n\leq 1000$), the number of points defining the polyline.</li>
	<li>$n$ lines with two floating point numbers $x$ and $y$ ($0 \leq x \leq 1$, $|y| < 0.5$), the coordinates of a point defining the polyline.</li>
</ul>

<p>All floating point numbers consist of exactly $6$ digits behind the decimal point. It is guaranteed that the first point is $(0,0)$ and the last point is $(1,0)$. The resulting fractal converges and does not overlap with itself.</p>

### 출력 

 <p>Output the area of the resulting fractal.</p>

<p>Your answer should have an absolute or relative error of at most $10^{-6}$.</p>

