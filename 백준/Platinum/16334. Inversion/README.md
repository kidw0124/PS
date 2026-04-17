# [Platinum III] Inversion - 16334 

[문제 링크](https://www.acmicpc.net/problem/16334) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

수학, 다이나믹 프로그래밍, 그래프 이론, 조합론, 위상 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A sequence p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub> is called a permutation of n numbers 1, 2, . . . , n if any number in the range [1, n] occurs exactly once in it. The pair (i, j) of integers in the range 1 to n is called an inversion if i < j and p<sub>i</sub> > p<sub>j</sub>.</p>

<p>Let’s call an inversion graph a graph which has exactly n vertices and there is and an edge between the pair (i, j) if and only if this pair is an inversion.</p>

<p>A set s of vertices of a graph is called independent if no two vertices from this set have an edge between them. A set t of vertices of a graph is called dominant if every vertice which does not belong to the set has an edge between at least one vertice which belongs to it. A set g of vertices of a graph is called independent-dominant if it is both dominant and independent.</p>

<p>You have an inversion graph of a particular permutation 1, 2, . . . n which is defined with pairs of vertices (a<sub>i</sub>, b<sub>i</sub>) which have an edge between them. Find the number of independent-dominant sets of the graph.</p>

<p>It is guaranteed that the answer does not exceed 10<sup>18</sup>.</p>

### 입력 

 <p>The first line contains two integers n and m (1 ≤ n ≤ 100, 0 ≤ m ≤ n×(n−1)/2) — the number of vertices of the graph and the number of edges in the graph.</p>

<p>Each of the next m lines contains two integers u<sub>i</sub> and v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ n), which means that there is an edge between u<sub>i</sub> and v<sub>i</sub>.</p>

<p>It is guaranteed that there exists a permutation that gives this graph.</p>

### 출력 

 <p>Print out the number of independent-dominant sets of vertices of the graph.</p>

<p>It is guaranteed that the answer does not exceed 10<sup>18</sup>.</p>

