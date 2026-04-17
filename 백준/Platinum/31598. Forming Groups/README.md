# [Platinum I] Forming Groups - 31598 

[문제 링크](https://www.acmicpc.net/problem/31598) 

### 성능 요약

메모리: 72580 KB, 시간: 2720 ms

### 분류

수학, 자료 구조, 그리디 알고리즘, 정수론, 집합과 맵, 트리를 사용한 집합과 맵, 소수 판정

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>There are $n$ students, numbered from $1$ to $n$, who need to form groups for the upcoming hackathon. You are student $1$, the captain of the students. Student $i$ has <em>skill level</em> $a_i$.</p>

<p>Students $2$ to $n$ are standing in a line from left to right in order. You can choose to stand in between any two students, to the left of student $2$, or to the right of student $n$. You cannot change the order of the $n - 1$ students.</p>

<p>You can also choose the number of groups $k$ ($k > 1$ and $k$ must be a divisor of $n$) to participate in the hackathon. The groups will be numbered from $1$ to $k$. After you have chosen your position and the value of $k$, the students will be grouped as follows:</p>

<ul>
	<li>The first student from the left will be assigned to group $1$.</li>
	<li>The second student from the left will be assigned to group $2$.</li>
	<li>$\dots$</li>
	<li>The $k$-th student from the left will be assigned to group $k$.</li>
	<li>The $(k + 1)$-th student from the left will be assigned to group $1$.</li>
	<li>The $(k + 2)$-th student from the left will be assigned to group $2$.</li>
	<li>$\dots$</li>
	<li>The $n$-th student from the left will be assigned to group $k$.</li>
</ul>

<p>Formally, for each $j$ ($1 ≤ j ≤ k$) and for each $i$ ($0 ≤ i < n/k$), the $(i \times k +j)$-th student from the left will be assigned to group $j$. It can be shown that each student will be assigned to exactly one group and all the groups have the same number of students.</p>

<p>The <em>skill level of a group</em> is the sum of the skill levels of the students inside the group. By choosing where you stand as well as the number of groups $k$ optimally, you want to minimize the ratio $x_\max/x_\min$ where</p>

<ul>
	<li>$x_\max$ is the skill level of the group with the largest skill level, and</li>
	<li>$x_\min$ is the skill level of the group with the smallest skill level.</li>
</ul>

### 입력 

 <p>The first line of input contains one integer $t$ ($1 ≤ t ≤ 100\, 000$) representing the number of test cases. After that, $t$ test cases follow. Each of them is presented as follows.</p>

<p>The first line of a test case contains two integers $n$ and $a_1$ ($2 ≤ n ≤ 10^6$; $1 ≤ a_1 ≤ 1000$). The next line contains $n - 1$ integers $a_2, a_3, \dots , a_n$ ($1 ≤ a_i ≤ 1000$ for all $i$).</p>

<p>The sum of $n$ across all test cases in one input file does not exceed $10^6$.</p>

### 출력 

 <p>For each test case, output one line containing two positive integers $p$ and $q$ such that the minimum ratio is $p/q$. The fraction $p/q$ should be irreducible. In other words, $p$ and $q$ should be coprime.</p>

