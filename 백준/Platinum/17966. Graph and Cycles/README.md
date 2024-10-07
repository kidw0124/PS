# [Platinum IV] Graph and Cycles - 17966 

[문제 링크](https://www.acmicpc.net/problem/17966) 

### 성능 요약

메모리: 27484 KB, 시간: 268 ms

### 분류

그래프 이론, 그리디 알고리즘, 정렬

### 제출 일자

2024년 10월 7일 18:21:16

### 문제 설명

<p>There is an undirected weighted complete graph of n vertices where n is odd.</p>

<p>Let’s define a <em>cycle-array</em> of size k as an array of edges [e<sub>1</sub>, e<sub>2</sub>, . . . , e<sub>k</sub>] that has the following properties:</p>

<ul>
	<li>k is greater than 1.</li>
	<li>For any i from 1 to k, an edge e<sub>i</sub> has exactly one common vertex with edge e<sub>i−1</sub> and exactly one common vertex with edge e<sub>i+1</sub> and these vertices are distinct (consider e<sub>0</sub> = e<sub>k</sub>, e<sub>k+1</sub> = e<sub>1</sub>).</li>
</ul>

<p>It is obvious that edges in a cycle-array form a cycle.</p>

<p>Let’s define f(e<sub>1</sub>, e<sub>2</sub>) as a function that takes edges e<sub>1</sub> and e<sub>2</sub> as parameters and returns the maximum between the weights of e<sub>1</sub> and e<sub>2</sub>.</p>

<p>Let’s say that we have a cycle-array C = [e<sub>1</sub>, e<sub>2</sub>, . . . , e<sub>k</sub>]. Let’s define the <em>price of a cycle-array</em> as the sum of f(e<sub>i</sub>, e<sub>i+1</sub>) for all i from 1 to k (consider e<sub>k+1</sub> = e<sub>1</sub>).</p>

<p>Let’s define a <em>cycle-split</em> of a graph as a set of non-intersecting cycle-arrays, such that the union of them contains all of the edges of the graph. Let’s define the <em>price of a cycle-split</em> as the sum of prices of the arrays that belong to it.</p>

<p>There might be many possible cycle-splits of a graph. Given a graph, your task is to find the cycle-split with the minimum price and print the price of it.</p>

### 입력 

 <p>The first line contains one integer n (3 ≤ n ≤ 999, n is odd) — the number of nodes in the graph.</p>

<p>Each of the following n·(n−1)/2 lines contain three space-separated integers u, v and w (1 ≤ u, v ≤ n, u ≠ v, 1 ≤ w ≤ 10<sup>9</sup>), meaning that there is an edge between the nodes u and v that has weight w.</p>

### 출력 

 <p>Print one integer — the minimum possible price of a cycle-split of the graph.</p>

