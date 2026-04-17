# [Diamond I] Graph Counting - 18453 

[문제 링크](https://www.acmicpc.net/problem/18453) 

### 성능 요약

메모리: 6080 KB, 시간: 2508 ms

### 분류

수학, 다이나믹 프로그래밍, 그래프 이론, 조합론, 생성 함수

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Consider undirected graphs on 2n vertices with no loops and no multiple edges. We will say that a graph G is <strong>good</strong> if there is no perfect matching in G, but for any edge not in G, if we add it to G, the resulting graph will have a perfect matching.</p>

<p>Your goal is to calculate the number of different good graphs on 2n vertices modulo 998 244 353.</p>

<p>Two graphs are different if they are non-isomorphic, meaning that one graph can not be transformed into another by relabeling the vertices.</p>

### 입력 

 <p>The first line of the input contains one integer n (1 ≤ n ≤ 500 000). Recall that 2n is the number of vertices in graph.</p>

### 출력 

 <p>Print one integer: the number of different good graphs on 2n vertices modulo 998 244 353.</p>

