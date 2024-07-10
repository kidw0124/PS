# [Platinum I] Jogging Tour - 30907 

[문제 링크](https://www.acmicpc.net/problem/30907) 

### 성능 요약

메모리: 5616 KB, 시간: 548 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 기하학, 외판원 순회 문제

### 제출 일자

2024년 7월 11일 02:31:23

### 문제 설명

<p>You may know that in the 17th century, a group of Dutchmen founded a settlement called New Amsterdam on Manhattan Island that later went on to become New York City. Less well-known is the story of another group of Dutchmen that also moved over to America and founded a city called <em>New Delft</em>. Like its bigger counterpart, New Delft has been built on a grid made up of two sets of parallel streets that meet each other at a perpendicular angle.</p>

<p>Some stroopwafel bakeries have already been built in New Delft, but none of the streets have been constructed. Your task is to lay out the grid of streets. For this, you need to decide on an orientation for the grid so that there are two orthogonal directions for the two types of streets. Once the orientation is fixed, you may build arbitrary streets, as long as each of them has one of the two given directions, as shown in Figure J.1. Each street can be traversed in either direction.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 300px; height: 300px;"></p>

<p style="text-align: center;">Figure J.1: Illustration of Sample Input 2 with a possible street layout that gives the shortest possible path that visits all bakeries in some order.</p>

<p>The street layout should be created in an optimal way for the annual <em>Stroopwafel Run</em>. This is an event in which a group of runners visits all the bakeries in some order of their choosing, and they may start and end their run at any point in the city. Your task is to come up with a grid layout that makes this shortest path as short as possible.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($2 \le n \le 12$), the number of stroopwafel bakeries in New Delft.</li>
	<li>$n$ lines, each with two integers $x$ and $y$ ($0 \le x,y \le 10^6$), the coordinates of one of the bakeries.</li>
</ul>

<p>The bakeries are at distinct coordinates, so for any $1 \le i,j \le n$ with $i \neq j$, it holds that $(x_i, y_i) \neq (x_j, y_j)$.</p>

### 출력 

 <p>Output the length of the shortest possible path that visits all bakeries in some order, assuming an optimal grid layout.</p>

<p>Your answer should have an absolute or relative error of at most $10^{-6}$.</p>

