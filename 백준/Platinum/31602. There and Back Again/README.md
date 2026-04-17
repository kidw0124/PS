# [Platinum IV] There and Back Again - 31602 

[문제 링크](https://www.acmicpc.net/problem/31602) 

### 성능 요약

메모리: 31032 KB, 시간: 288 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라, 역추적

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>There are $n$ cities in Asia-Pacific, numbered from $1$ to $n$. The 2024 ICPC Asia Pacific Championship is held in Hanoi, which is city $n$.</p>

<p>There are $m$ bidirectional roads, numbered from $1$ to $m$, connecting some pairs of cities. Road $i$ connects cities $u_i$ and $v_i$ and takes $t_i$ units of time to travel in either direction. Each road connects different cities and different roads connect different pairs of cities.</p>

<p>You live in city $1$. You would like to travel to city $n$ to attend the contest through a sequence of roads, and then travel back to city $1$ through a sequence of roads. Traveling through the same route is boring, so you would like the routes in both traversals to be different. Two routes are considered different if the <strong>set of distinct</strong> roads traversed through one route is different from the <strong>set of distinct</strong> roads traversed through the other route.</p>

<p>In each traversal, it is possible to pass through the same city or road multiple times. It is also possible to continue traversing after reaching the destination city (i.e., city $1$ or city $n$). The <em>traversal time</em> is the sum of the travel times of the roads passed through in the traversal. If a road is passed through multiple times in the traversal, then the travel time of the road is also counted multiple times accordingly.</p>

<p>Determine the minimum total traversal time to do both traversals satisfying the requirements above, or indicate if the requirements cannot be satisfied.</p>

### 입력 

 <p>The first line of input contains two integers $n$ and $m$ ($2 ≤ n ≤ 100\, 000$; $1 ≤ m ≤ \min(\frac{n(n-1)}{2}, 300\, 000)$). Each of the next m lines contains three integers. The $i$-th line contains $u_i$, $v_i$, and $t_i$ ($1 ≤ u_i < v_i ≤ n$; $1 ≤ t_i ≤ 1000$). Different roads connect different pairs of cities.</p>

### 출력 

 <p>Output an integer representing the minimum total traversal time to do both traversals satisfying the requirements above, or <code>-1</code> if the requirements cannot be satisfied.</p>

