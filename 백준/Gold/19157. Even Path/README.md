# [Gold IV] Even Path - 19157 

[문제 링크](https://www.acmicpc.net/problem/19157) 

### 성능 요약

메모리: 5108 KB, 시간: 80 ms

### 분류

애드 혹, 누적 합

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Pathfinding is a task of finding a route between two points. It often appears in many problems. For example, in a GPS navigation software where a driver can query for a suggested route, or in a robot motion planning where it should find a valid sequence of movements to do some tasks, or in a simple maze solver where it should find a valid path from one point to another point. This problem is related to solving a maze.</p>

<p>The maze considered in this problem is in the form of a matrix of integers A of N × N. The value of each cell is generated from a given array R and C of N integers each. Specifically, the value on the i<sup>th</sup> row and j<sup>th</sup> column, cell (i, j), is equal to R<sub>i</sub> + C<sub>j</sub>. Note that all indexes in this problem are from 1 to N.</p>

<p>A path in this maze is defined as a sequence of cells (r<sub>1</sub>, c<sub>1</sub>),(r<sub>2</sub>, c<sub>2</sub>), . . . ,(r<sub>k</sub>, c<sub>k</sub>) such that |r<sub>i</sub> − r<sub>i+1</sub>| + |c<sub>i</sub> − c<sub>i+1</sub>| = 1 for all 1 ≤ i < k. In other words, each adjacent cell differs only by 1 row or only by 1 column. An even path in this maze is defined as a path in which all the cells in the path contain only even numbers.</p>

<p>Given a tuple <r<sub>a</sub>, c<sub>a</sub>, r<sub>b</sub>, c<sub>b</sub>> as a query, your task is to determine whether there exists an even path from cell (r<sub>a</sub>, c<sub>a</sub>) to cell (r<sub>b</sub>, c<sub>b</sub>). To simplify the problem, it is guaranteed that both cell (r<sub>a</sub>, c<sub>a</sub>) and cell (r<sub>b</sub>, c<sub>b</sub>) contain even numbers. For example, let N = 5, R = {6, 2, 7, 8, 3}, and C = {3, 4, 8, 5, 1}. The following figure depicts the matrix A of 5 × 5 which is generated from the given array R and C.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 177px; height: 176px;"></p>

<p>Let us consider several queries:</p>

<ul>
	<li><2, 2, 1, 3>: There is an even path from cell (2, 2) to cell (1, 3), e.g., (2, 2),(2, 3),(1, 3). Of course, (2, 2),(1, 2),(1, 3) is also a valid even path.</li>
	<li><4, 2, 4, 3>: There is an even path from cell (4, 2) to cell (4, 3), namely (4, 2),(4, 3).</li>
	<li><5, 1, 3, 4>: There is no even path from cell (5, 1) to cell (3, 4). Observe that the only two neighboring cells of (5, 1) are cell (5, 2) and cell (4, 1), and both of them contain odd numbers (7 and 11, respectively), thus, there cannot be any even path originating from cell (5, 1).</li>
</ul>

### 입력 

 <p>Input begins with a line containing two integers: N Q (2 ≤ N ≤ 100 000; 1 ≤ Q ≤ 100 000) representing the size of the maze and the number of queries, respectively. The next line contains N integers: R<sub>i</sub> (0 ≤ R<sub>i</sub> ≤ 10<sup>6</sup>) representing the array R. The next line contains N integers: C<sub>i</sub> (0 ≤ C<sub>i</sub> ≤ 10<sup>6</sup>) representing the array C. The next Q lines each contains four integers: r<sub>a</sub> c<sub>a</sub> r<sub>b</sub> c<sub>b</sub> (1 ≤ r<sub>a</sub>, c<sub>a</sub>, r<sub>b</sub>, c<sub>b</sub> ≤ N) representing a query of <r<sub>a</sub>, c<sub>a</sub>, r<sub>b</sub>, c<sub>b</sub>>. It is guaranteed that (r<sub>a</sub>, c<sub>a</sub>) and (r<sub>b</sub>, c<sub>b</sub>) are two different cells in the maze and both of them contain even numbers.</p>

### 출력 

 <p>For each query in the same order as input, output in a line a string “YES” (without quotes) or “NO” (without quotes) whether there exists an even path from cell (r<sub>a</sub>, c<sub>a</sub>) to cell (r<sub>b</sub>, c<sub>b</sub>).</p>

