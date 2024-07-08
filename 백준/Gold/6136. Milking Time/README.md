# [Gold III] Milking Time - 6136 

[문제 링크](https://www.acmicpc.net/problem/6136) 

### 성능 요약

메모리: 6064 KB, 시간: 300 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 7월 9일 05:27:00

### 문제 설명

<p>Bessie is such a hard-working cow. In fact, she is so focused on maximizing her productivity that she decides to schedule her next N (1 <= N <= 1,000,000) hours (conveniently labeled 0..N-1) so that she produces as much milk as possible.</p>

<p>Farmer John has a list of M (1 <= M <= 1,000) possibly overlapping intervals in which he is available for milking. Each interval i has a starting hour (0 <= starting_hour_i < N), an ending hour (starting_hour_i < ending_hour_i <= N), and a corresponding efficiency (1 <= efficiency_i <= 1,000,000) which indicates how many gallons of milk that he can get out of Bessie in that interval. Farmer John starts and stops milking at the beginning of the starting hour and ending hour, respectively. When being milked, Bessie must be milked through an entire interval.</p>

<p>Even Bessie has her limitations, though. After being milked during any interval, she must rest R (1 <= R <= N) hours before she can start milking again. Given Farmer Johns list of intervals, determine the maximum amount of milk that Bessie can produce in the N hours.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, M, and R</li>
	<li>Lines 2..M+1: Line i+1 describes FJ's ith milking interval with three space-separated integers: starting_hour_i, ending_hour_i, and efficiency_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The maximum number of gallons of milk that Bessie can product in the N hours</li>
</ul>

