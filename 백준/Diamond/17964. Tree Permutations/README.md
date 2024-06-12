# [Diamond I] Tree Permutations - 17964 

[문제 링크](https://www.acmicpc.net/problem/17964) 

### 성능 요약

메모리: 17728 KB, 시간: 200 ms

### 분류

애드 혹, 자료 구조, 해시를 사용한 집합과 맵, 정렬

### 제출 일자

2023년 1월 4일 10:31:12

### 문제 설명

<p>Once upon a time, Mr. Cool created a tree (an undirected graph without cycles) of n vertices, by assigning to each vertex i > 1 two numbers: p<sub>i</sub> < i — the direct ancestor of vertex i and w<sub>i</sub> — the weight of the edge between vertex i and p<sub>i</sub>. Vertex 1 is the root, so it does not have any ancestors.</p>

<p>You wanted to know what tree did Mr. Cool build, but Mr. Cool refused to tell this, but he gave you a tip:</p>

<p>He wrote all these numbers in one line. That’s how he got array b of length 2 · n − 2.</p>

<p style="text-align: center;">b = [p<sub>2</sub>, w<sub>2</sub>, p<sub>3</sub>, w<sub>3</sub>, . . . , p<sub>n−1</sub>, w<sub>n−1</sub>, p<sub>n</sub>, w<sub>n</sub>]</p>

<p>Then he randomly shuffled it. That’s how he got array a, and Mr. Cool presented you with it.</p>

<p>Since it is impossible to restore the tree knowing only values of array a, you decided to solve a different problem.</p>

<p>Let’s call a tree k-long, if there are exactly k edges on the path between vertex 1 and n.</p>

<p>Let’s call a tree k-perfect, if it is k-long and the sum of the weights of the edges on the path between vertex 1 and vertex n is maximal among all possible k-long trees that Mr. Cool could build.</p>

<p>Your task is to print the sum of the weights of the edges on the path between vertex 1 and vertex n for all possible k-perfect trees or print −1 if a certain k-long tree could not be built by Mr. Cool.</p>

### 입력 

 <p>The first line contains one integer n (2 ≤ n ≤ 10<sup>5</sup>) — the number of the vertices in the tree.</p>

<p>The second line contains 2 · n − 2 integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>2n−2</sub> (1 ≤ a<sub>i</sub> ≤ n − 1) — the elements of array a.</p>

### 출력 

 <p>In one line, print n − 1 space-separated integers w<sub>1</sub>, w<sub>2</sub>, w<sub>3</sub>, . . . , w<sub>n−1</sub>, where w<sub>k</sub> — the sum of the weights of the edges on the path between vertex 1 and vertex n in a k-perfect tree. If there is no i-long tree, then wi should be equal to −1.</p>

