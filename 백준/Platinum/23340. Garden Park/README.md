# [Platinum IV] Garden Park - 23340 

[문제 링크](https://www.acmicpc.net/problem/23340) 

### 성능 요약

메모리: 108800 KB, 시간: 288 ms

### 분류

다이나믹 프로그래밍, 정렬, 트리, 트리에서의 다이나믹 프로그래밍

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>In the Garden park, there are n places of interest (numbered from 1 to n) and n − 1 trails (numbered from 1 to n − 1) connecting the places of interest. For every i ∈ {1, 2, ..., n − 1}, trail i has two ends at place a<sub>i</sub> and place b<sub>i</sub>, and the trail does not pass any place of interest except its ends. Moreover, the trails do not have any intersection except the ends.</p>

<p>To protect the garden, visitors may only walk along the trails (in any direction) and inside the places of interest. For any pair of places of interest (x, y) where x ≠ y, there exists a sequence of trails s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub> satisfying the following conditions.</p>

<ul>
	<li>Place x is an end of trail s<sub>1</sub>.</li>
	<li>Place y is an end of trail s<sub>k</sub>.</li>
	<li>For 1 ≤ i < k, trail s<sub>i</sub> and trail s<sub>i+1</sub> have a common end.</li>
	<li>If place z is the common end of trails s<sub>i</sub> and s<sub>i+1</sub> for some i ∈ {1, ..., k − 1}, then z cannot be a common end of any other pairs of trails in s<sub>1</sub>, ..., s<sub>k</sub>.</li>
</ul>

<p>In other words, a visitor move from x to y by walking along the trails s<sub>1</sub>, ..., s<sub>k</sub> without visiting a place of interest twice. Such a sequence is called a simple path from x to y. The administration division of the park plans to host an event in the park. It puts labels on the trails. For trail t, the label on t is an integer ℓ(t), and a visitor can learn ℓ(t) by walking through trail t. A simple path s<sub>1</sub>, ..., s<sub>k</sub> from x to y is with strictly increasing labels if ℓ(s<sub>1</sub>) < ℓ(s<sub>2</sub>) < ··· < ℓ(s<sub>k</sub>). By reporting m distinct simple paths with strictly increasing labels to the administration division, a visitor may win m free tickets for future visits.</p>

<p>Your friend George just visited the park, and learned all labels on the trails. He wants to win free tickets for future visits with you. Please write a program to compute the number of distinct simple paths with strictly increasing labels in the garden park.</p>

### 입력 

 <p>The first line contains one integers n. The (i + 1)-th line contains three integers a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>. Trail i connects place a<sub>i</sub> and b<sub>i</sub>, and the label ℓ(i) on trail i is c<sub>i</sub>.</p>

### 출력 

 <p>Output the number of distinct simple paths with strictly increasing labels in the garden park.</p>

