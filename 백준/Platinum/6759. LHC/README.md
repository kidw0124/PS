# [Platinum IV] LHC - 6759 

[문제 링크](https://www.acmicpc.net/problem/6759) 

### 성능 요약

메모리: 67644 KB, 시간: 464 ms

### 분류

수학, 그래프 이론, 그래프 탐색, 트리, 조합론, 깊이 우선 탐색, 트리의 지름

### 제출 일자

2025년 12월 15일 00:56:27

### 문제 설명

<p>For your latest top-secret experiment, you will need a large quantity of Higgs bosons. To obtain these elusive particles, you will need to build a large hadron collider, a long circular tunnel that you can use to accelerate particles and smash them into each other.</p>

<p>You already have access to an extensive network of tunnels, which is guaranteed to be connected and free of cyclic paths. In other words, the existing tunnels form a tree structure. This system can be represented by N junctions, labelled 1 through N, connected by N − 1 tunnels, each of which connects two junctions. Tunnels can be traversed in either direction (i.e., if there is a junction from a to b, that junction also goes from b to a).</p>

<p>By adding exactly one tunnel to the network, you can create a cyclic path, which you will use to build your large hadron collider. You wish to form the longest possible collider in this way, where we define length as the number of tunnels in a cycle. Also, you would like to compute the number of ways to do this– that is, the number of distinct pairs of junctions such that adding a tunnel between them forms a cycle of maximum length.</p>

<p>For example, in the following network, we can form a collider of length 4 by building a tunnel between junctions 1 and 5, or between 2 and 5:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e66006bb-1b72-4217-a27d-49d72d1a5643/-/preview/" style="width: 179px; height: 161px;"></p>

### 입력 

 <p>The first line of each test case will contain N (3 ≤ N ≤ 400 000), the number of junctions. The next N − 1 lines will each contain two space-separated integers i and j, indicating that there is a tunnel between junctions i and j (1 ≤ i, j ≤ N).</p>

### 출력 

 <p>The output should consist of a single line with two space-separated integers: the length of the longest possible collider, and the number of ways to achieve that length. Note that you may need a 64-bit integer to store the answer.</p>

