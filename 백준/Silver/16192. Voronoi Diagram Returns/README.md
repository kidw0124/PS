# [Silver I] Voronoi Diagram Returns - 16192 

[문제 링크](https://www.acmicpc.net/problem/16192) 

### 성능 요약

메모리: 2184 KB, 시간: 1764 ms

### 분류

브루트포스 알고리즘, 기하학, 보로노이 다이어그램

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="height: 70%; width: 70%;"></p>

<p style="text-align: center;"><em><strong>Figure</strong>: Voronoi Diagram of size 4.</em></p>

<p>In the 2-dimensional Cartesian coordinate system, we define the <strong>Voronoi Diagram</strong> of a non-empty set of points $S$, as a diagram that divides the plane by the criteria "which point in the set $S$ is closest in this location?". More precisely, the Voronoi diagram of a given non-empty point set $\{P_1,\ P_2,\ \cdots,\ P_n\}$ is a collection of <strong>regions</strong>: A point $K$ is included in region $i$ if and only if $d(P_i,\ K) \le d(P_j,\ K)$ holds for all $1 \le j \le n$, where $d(X,\ Y)$ denotes the Euclidean distance between point $X$ and $Y$.</p>

<p>For example, in the picture above, every location over the plane is colored by the closest point with such location. The points which belongs to a single region is colored by a light color indicating a region, and the points which belongs to more than one region forms lines and points colored black.</p>

<p>There is an algorithm which computes the Voronoi Diagram in $\mathcal{O}(n \log(n))$, but it is infamous to be very complicated and hard. In fact, we are lenient problem setters, so we set $n \leq 2000$, which means you can solve this task with slower Voronoi Diagram algorithms!</p>

<p>In this task, you should solve the <strong>point query problem</strong> in Voronoi diagram: in the Voronoi diagram constructed with the set of points $\{P_1,\ P_2,\ \cdots,\ P_n\}$, you should determine which region(s) the point belongs to. More precisely, you will be given $q$ queries of points. For each query point, you should determine the following:</p>

<ul>
	<li>If it's not included in any region, output <code>NONE</code>.</li>
	<li>If it's included in exactly one region, output <code>REGION X</code>, where <code>X</code> is the index of such region.</li>
	<li>If it's included in exactly two regions, output <code>LINE X Y</code>, where <code>X</code> and <code>Y</code> (<code>X</code> < <code>Y</code>) are the indices of such two regions.</li>
	<li>If it's included in three or more regions, output <code>POINT</code>.</li>
</ul>

### 입력 

 <p>In the first line, the number of points consisting Voronoi diagram $n$, and the number of queries $q$ are given. ($3 \le n \le 2, 000,\ 1 \le q \le 250, 000$)</p>

<p>In the $i$th line of next $n$ lines, two integers indicating $x$ and $y$ co-ordinate of $P_i$ are given. These are the points consisting the Voronoi diagram. All $n$ points are distinct. ($|x|,\ |y| \le 10,000$)</p>

<p>In the $j$th line of next $q$ lines, two integers indicating $x$ and $y$ co-ordinate of $Q_j$ are given. For each point $Q_j$, you should determine in which region(s) the given point belongs to. ($|x|,\ |y| \le 10,000$)</p>

### 출력 

 <p>Output consists of $q$ lines. In the $j$th line, you should print one of following:</p>

<ul>
	<li>If $Q_j$ is not included in any region, output <code>NONE</code>.</li>
	<li>If $Q_j$ is included in exactly one region, output <code>REGION X</code>, where <code>X</code> is the index of such region.</li>
	<li>If $Q_j$ is included in exactly two regions, output <code>LINE X Y</code>, where <code>X</code> and <code>Y</code> (<code>X</code> < <code>Y</code>) are the indices of such two regions.</li>
	<li>If $Q_j$ is included in three or more regions, output <code>POINT</code>.</li>
</ul>

