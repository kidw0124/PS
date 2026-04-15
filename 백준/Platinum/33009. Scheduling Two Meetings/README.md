# [Platinum I] Scheduling Two Meetings - 33009 

[문제 링크](https://www.acmicpc.net/problem/33009) 

### 성능 요약

메모리: 30792 KB, 시간: 136 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍, 부분집합의 합 다이나믹 프로그래밍

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>You are the chief judge of the International Collegiate Quiz Contest (ICQC) this year. You want to hold judge meetings twice for preparing the problem set of the contest. You proposed candidate schedules for the meetings, and all the judges answered for each of the time slots whether they would attend the meeting on-site or remotely via a video conference tool.</p>

<p>You have to choose a pair of two distinct time slots, so that every judge attends at least one of the two meetings on-site. When there are multiple such pairs, you’d like to choose one with the largest number of judges attending both meetings on-site. If multiple pairs are still equally desirable with these criteria, one with the earlier first meeting is preferred. If there still remain multiple pairs with the same time slot for the first meeting, the one with the earliest second meeting should be chosen.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$n$ $m$</p>

<p>$a_{1,1}$ $\cdots$ $a_{1,m}$</p>

<p>$\vdots$</p>

<p>$a_{n,1}$ $\cdots$ $a_{n,m}$</p>
</blockquote>

<p>Two integers $n$ and $m$ are given in the first line. The first integer $n$ ($2 ≤ n ≤ 2 \times 10^5$) is the number of candidate time slots. Here, the candidate time slots are numbered $1$ through $n$, and smaller numbers mean earlier time slots. The second integer $m$ ($2 ≤ m ≤ 20$) is the number of judges.</p>

<p>In the following $n$ lines, $a_{i,j}$ is either a character <code>Y</code> indicating that the $j$-th judge attends a meeting at the $i$-th candidate time slot on-site, or a character <code>N</code> indicating remote attendance.</p>

### 출력 

 <p>Output a line containing the two time slot numbers of the most preferable choice, separated by a space, with the earlier time slot first. If there are no pairs of time slots satisfying the condition, output <code>No</code>.</p>

