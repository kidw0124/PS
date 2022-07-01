# [Diamond III] Planinarenje - 15371 

[문제 링크](https://www.acmicpc.net/problem/15371) 

### 성능 요약

메모리: 2728 KB, 시간: 48 ms

### 분류

이분 매칭(bipartite_matching), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Mirko and Slavko like to hike together. Mirko likes mountain peaks, and Slavko likes valleys. Because of this, every time they climb to a peak, Slavko decides which valley they are going to descend to, given that a trail exists to it. Similarly, in each valley, Mirko decides which peak they are going to climb up to. It will never be possible to directly climb from one peak to another, or to get from one valley to another valley. In order to make the hiking as fun as possible, they never visit the same spot twice (whether it’s a peak or a valley). Once they reach a spot that only leads to spots they’ve visited before, they call the mountain rangers to pick them up. If the final spot is a peak, Mirko wins, and if it is a valley, Slavko wins.</p>

<p>Naturally, you must already know what your task is: If we assume that both of them play optimally, who wins? Answer this question for all initial peaks.</p>

### 입력 

 <p>The first line contains two positive integers, N and M (1 ≤ N ≤ 5000, 1 ≤ M ≤ min(5000, N·N)). Here N denotes the number of peaks and valleys (therefore, there are N peaks and N valleys), and M denotes the number of hiking trails.</p>

<p>Each of the following M lines contains two positive integers: v<sub>i</sub> and d<sub>i</sub> (1 ≤ v<sub>i</sub>, d<sub>i</sub> ≤ N) that denote there is a trail between peak v<sub>i</sub> and valley d<sub>i</sub>.</p>

<p>Between each peak and valley, there will exist at most one trail.</p>

### 출력 

 <p>You must output N lines. The i th line denotes the winner if the starting point is peak i.</p>

