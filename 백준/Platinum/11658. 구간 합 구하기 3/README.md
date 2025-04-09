# [Platinum IV] 구간 합 구하기 3 - 11658 

[문제 링크](https://www.acmicpc.net/problem/11658) 

### 성능 요약

메모리: 18656 KB, 시간: 168 ms

### 분류

자료 구조, 다차원 세그먼트 트리, 누적 합, 세그먼트 트리

### 제출 일자

2025년 4월 9일 23:19:36

### 문제 설명

<p>N×N개의 수가 N×N 크기의 표에 채워져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 표의 i행 j열은 (i, j)로 나타낸다. (x<sub>1</sub>, y<sub>1</sub>)부터 (x<sub>2</sub>, y<sub>2</sub>)까지 합이란 x<sub>1</sub> ≤ x ≤ x<sub>2</sub>, y<sub>1</sub> ≤ y ≤ y<sub>2</sub>를 만족하는 모든 (x, y)에 있는 수의 합이다.</p>

<p>예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.</p>

<table class="table table-bordered" style="width:20%">
	<tbody>
		<tr>
			<td style="text-align:center">1</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
		</tr>
		<tr>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
		</tr>
		<tr>
			<td style="text-align:center">3</td>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
		</tr>
		<tr>
			<td style="text-align:center">4</td>
			<td style="text-align:center">5</td>
			<td style="text-align:center">6</td>
			<td style="text-align:center">7</td>
		</tr>
	</tbody>
</table>

<p>여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이 된다. (2, 3)을 7로 바꾸고 (2, 2)부터 (3, 4)까지 합을 구하면 3+7+5+4+5+6=30 이 된다.</p>

<p>표에 채워져 있는 수와 변경하는 연산과 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 표의 크기 N과 수행해야 하는 연산의 수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져있는 수가 1행부터 차례대로 주어진다. 다음 M개의 줄에는 네 개의 정수 w, x, y, c 또는 다섯 개의 정수 w, x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>가 주어진다. w = 0인 경우는 (x, y)를 c (1 ≤ c ≤ 1,000)로 바꾸는 연산이고, w = 1인 경우는 (x<sub>1</sub>, y<sub>1</sub>)부터 (x<sub>2</sub>, y<sub>2</sub>)의 합을 구해 출력하는 연산이다. (1 ≤ x<sub>1</sub> ≤ x<sub>2</sub> ≤ N, 1 ≤ y<sub>1</sub> ≤ y<sub>2</sub> ≤ N) 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다.</p>

### 출력 

 <p>w = 1인 입력마다 구한 합을 순서대로 한 줄에 하나씩 출력한다.</p>

