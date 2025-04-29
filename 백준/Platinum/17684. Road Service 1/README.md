# [Platinum V] Road Service 1 - 17684 

[문제 링크](https://www.acmicpc.net/problem/17684) 

### 성능 요약

메모리: 4528 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 브루트포스 알고리즘, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 30일 03:33:27

### 문제 설명

<p>There are N cities in IOI kingdom, numbered from 1 to N. There are also N − 1 bidirectional roads, numbered from 1 to N − 1. The i-th road connects the A<sub>i</sub>-th city and the B<sub>i</sub>-th city. There exists a path between any pair of vertices.</p>

<p>The distance between two cities are defined as the smallest number of roads which connect the two cities. The total distance of IOI kingdom is defined as the sum of the distances between all pair of different cities.</p>

<p>The king of IOI kingdom plans to construct K additional roads in order to reduce the total distance and improve convenience.</p>

<p>You, as an assistant of the king, help the king by finding a good plan.</p>

<p>Given the information of existing roads in IOI kingdom and the number of roads to construct, output a plan for constructing K roads. The less the total distance is, the more points you gain.</p>

### 입력 

 <p>There are 6 inputs for this task. Read the following data from each input.</p>

<ul>
	<li>The first line of input contains three space separated integers N, K and W<sub>0</sub>. These mean that IOI kingdom has N cities and that the king plans to construct K roads. W<sub>0</sub> is a parameter for scoring.</li>
	<li>The i-th (1 ≦ i ≦ N − 1) line of the following N − 1 lines contains integers A<sub>i</sub> and B<sub>i</sub>, the cities which the i-th road connects.</li>
</ul>

### 출력 

 <p>Write K lines on your submission file. The j-th line of the output contains two integers X<sub>j</sub>, Y<sub>j</sub> (1 ≦ X<sub>j</sub> ≦ N, 1 ≦ Y<sub>j</sub> ≦ N), representing the cities connected by a road to construct.</p>

