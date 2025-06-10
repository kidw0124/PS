# [Platinum II] Football Match - 18736 

[문제 링크](https://www.acmicpc.net/problem/18736) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

많은 조건 분기, 해 구성하기, 수학

### 제출 일자

2025년 6월 11일 04:33:26

### 문제 설명

<p>Zenyk wants to play football, and n − 1 friends join him. All players have skill level — an integer between 1 and 10 000.</p>

<p>Players want to choose a referee and then divide into two teams such that each player is either the referee or a member of one of the teams, and the sums of skills of players in both teams are the same. So that will be a fair game.</p>

<p>Unfortunately all of them forgot their own skill levels. But each player remembers if it’s possible to divide into teams when he is a referee.</p>

<p>Find such skill values that satisfy all conditions. If several possible answers exist print any of them.</p>

### 입력 

 <p>The first line contains one integer n (3 ≤ n ≤ 50).</p>

<p>The second line contains a string of length n. The i-th character of this string equals “Y” if it’s possible to divide players into teams if i-th player is a referee, and “N” otherwise.</p>

### 출력 

 <p>In the first line, print “YES” if at least one possible set of values exists, and “NO” otherwise. If the answer is “YES”, print n integers — the corresponding values. These values should be between 1 and 10 000. If several possible answers exist, print any of them.</p>

