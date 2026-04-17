# [Platinum IV] F1 Racing - 24242 

[문제 링크](https://www.acmicpc.net/problem/24242) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 미적분학, 삼분 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>All over Europe the F1-fever is burning stronger then ever after NextFlex released "Cars go vrooooom." Once you get in, there is no way out. The drama, the tactics, the drama, the racing, but most of all the drama. </p>

<p>This years series is one of the most exciting yet. The legendary battle between the two main stars Min Verstopen and Lery Slowington never fails to make a race entertaining. There are mind games, close battles and almost accidents all the way. But above all of this, the winner of a F1 race is the fastest driver, and the team with the best tactical decisions.</p>

<p>An above average committed fan named Dorothy has noticed that in our modern era of F1 there are numerous instruments on a F1 car, giving the teams data on how fast each car can race in different conditions. Dorothy believes one could use superior knowledge of algorithms to decide the best possible tactic given a set of race conditions. She has ran some statistics, and found that a car with $x$ round old tires uses $$r + b \cdot x$$ seconds on one lap where $r$ and $b$ are constants depending on the particular track.</p>

<p>Now she turns to you to provide her with an algorithm that finds the total race time for a team using optimal pitstops.</p>

### 입력 

 <p>The input consists of four space-separated integers $n$, $p$, $r$ and $b$.</p>

<ul>
	<li>$1 \leq n \leq 10^9$ denotes the number of laps in the race,</li>
	<li>$0 \leq p \leq 10^9$ denotes how long it takes to change tires measured in seconds,</li>
	<li>$1 \leq r \leq 100$ denotes how many seconds it takes to race around the track on fresh tires, and</li>
	<li>$0 \leq b \leq 4$ denotes the tear factor on the wheels.</li>
</ul>

### 출력 

 <p>A single integer, the minimum number of seconds required to finish the race.</p>

