# [Gold II] Kingdom’s Development Plan - 32459 

[문제 링크](https://www.acmicpc.net/problem/32459) 

### 성능 요약

메모리: 32080 KB, 시간: 248 ms

### 분류

자료 구조, 그래프 이론, 우선순위 큐, 방향 비순환 그래프, 위상 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The Kingdom of Topcaria is planning a series of developmental projects to enhance its infrastructure. Each project has specific prerequisites that must be completed before the project can start. The Ministry of Development has asked you to help determine a feasible order in which all the projects can be completed.</p>

<p>You are given:</p>

<ul>
	<li>$n$, the number of projects numbered from $1$ to $n$.</li>
	<li>$m$, the number of prerequisite relationships between these projects.</li>
	<li>A list of $m$ pairs, where each pair $(a, b)$ indicates that project $a$ must be completed before project $b$ can start.</li>
</ul>

<p>Your task is to determine an order in which all the projects can be completed. If it is impossible to complete all projects due to a cyclic dependency, output “<code>IMPOSSIBLE</code>”. If there are multiple valid orders, please output any the lexicographically smallest one.</p>

### 입력 

 <p>The first line contains two integers $n$ and $m$ — the number of projects and the number of prerequisite relationships. The next $m$ lines each contain two integers $a$ and $b$ — a prerequisite pair indicating that project $a$ must be completed before project $b$.</p>

### 출력 

 <p>If it is not possible, output “<code>IMPOSSIBLE</code>”. If it is possible to complete all projects, output a single line with $n$ integers — a valid order of project completions. If there are multiple possible orders, output the lexicographically smallest one. An order is lexicographically smaller than another order if at the first position where they differ, the project number on the first order is smaller than the number on the second order.</p>

