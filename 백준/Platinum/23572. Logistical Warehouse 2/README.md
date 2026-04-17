# [Platinum II] Logistical Warehouse 2 - 23572 

[문제 링크](https://www.acmicpc.net/problem/23572) 

### 성능 요약

메모리: 14540 KB, 시간: 56 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그리디 알고리즘, 그래프 탐색, 트리, 트리에서의 다이나믹 프로그래밍

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>KOPANG is one of largest online vendors in Korea and introduced so called “early-morning delivery” for the first time. To cope with the growing demand, KOPANG plans to build new logistical warehouses. The locations of logistical warehouses must be within a certain distance from customers to keep the delivery time guaranteed by KOPANG to the customers.</p>

<p>The logistics network is modelled as a connected tree $T$. Each node of $T$ represents a region such as a city or a province in Korea, and each edge of $T$ represents a transportation road connecting two regions. KOPANG wants to select one or more nodes of $T$ satisfying the distance restriction for the logistical warehouses. Before the selection, KOPANG first fixed a distance parameter $K$ through sufficient research. KOPANG now wants to select the minimum number of nodes satisfying the distance restriction that the distance from every node of $T$ to its closest selected node (warehouse) is at most $K$. The distance of two nodes $u$ and $v$ is the number of edges of the (unique) path in $T$ that connects $u$ and $v$. Note that the distance is defined as zero if $u = v$.</p>

<p>For example, Figure G.1 below shows a tree $T$ with nine nodes and eight edges. For $K = 1$, if three warehouses are located at nodes $2$, $5$, and $8$, marked with red circles as in Figure G.1 (a), then the distance of every node of $T$ to the closest warehouse is at most one. Two warehouses are not enough to satisfy the distance restriction, so three warehouses are the minimum. For $K = 2$, three warehouses are still required; warehouses at nodes $2$, $5$, and $8$ for $K = 1$ are the ones for $K = 2$. Of course, the locations of the minimum number of warehouses are not unique; three warehouses at nodes $4$, $7$, and $1$ as in Figure G.1 (b) also satisfy the distance restriction for $K = 2$.</p>

<p>Given a connected tree $T$ and a positive integer $K$, write a program to select the minimum number of nodes (warehouses) of $T$ satisfying the distance restriction, that is, the distance of every node of $T$ to its closest warehouse is at most $K$.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 171px; height: 150px;"></td>
			<td><img alt="" src="" style="width: 171px; height: 150px;"></td>
		</tr>
		<tr>
			<td>(a)</td>
			<td>(b)</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">Figure G.1 The nodes marked with red circles are the ones selected for warehouses.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers $n$ and $K$ ($1 ≤ K ≤ n ≤ 10^5$), where $n$ is the number of nodes in a connected tree and the maximum distance from each node in the tree to its closest selected node is at most $K$. In the following $n-1$ lines, the edge information is given; the $i$-th line contains two positive integers representing two indices of the end nodes of the $i$-th edge. The nodes are indexed from $1$ to $n$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line that contains the minimum number of the selected nodes for logistical warehouses satisfying the distance restriction for the given tree and the distance parameter $K$.</p>

