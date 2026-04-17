# [Gold II] Kiosk Construction - 26002 

[문제 링크](https://www.acmicpc.net/problem/26002) 

### 성능 요약

메모리: 2160 KB, 시간: 4484 ms

### 분류

구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are planning to start a Beautifully Arranged Placid Camping. You already have bought a field, which you have divided into a $h \times w$-grid of plots, and numbered them with distinct numbers $a_{ij}$ from $1$ to $h \cdot w$. However, you forgot one thing: you still need to place the reception kiosk at one of the plots. You want to minimise the maximal distance that any guest will walk from the reception kiosk to their plot. Guests will however not take the shortest path to their plot, but instead they follow the following procedure, starting at the reception kiosk:</p>

<ul>
	<li>Look at the numbers of the four neighbouring plots.</li>
	<li>Go to the plot with the number closest to the destination number. In case of a tie, out of the two tying plots, go to the one with the number closest to the current plot number.</li>
	<li>Repeat until the destination is reached.</li>
</ul>

<p>Note that this procedure might not terminate in some cases.</p>

<p>Given the numbering of the plots, find the plot number of the optimal position for the reception kiosk and the maximal walking distance to any plot from this kiosk. If, for every possible position for the reception kiosk, there is at least one plot for which the procedure outlined above does not terminate, output that this is impossible.</p>

<p>Figure K.1 shows the third sample case: one solution is to put the kiosk in plot $4$, so that every other plot is at most distance $3$ away. Placing the kiosk in plot $7$ does not work as plot $9$ cannot be reached from there.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 181px;"></p>

<p style="text-align: center;">Figure K.1: Visualisation of the third sample case.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $h$ and $w$ ($2\leq h, w\leq 40$), the dimensions of the camping.</li>
	<li>$h$ lines, the $i$th of which contains $w$ integers $a_{i, 1}, \ldots, a_{i, n}$ ($1 \leq a_{i, j} \leq h \cdot w$), the plot numbers. It is guaranteed that all numbers from $1$ to $h \cdot w$ occur exactly once.</li>
</ul>

### 출력 

 <p>If there is a position for the reception kiosk such that every other plot can be reached, then output the optimal position for the reception kiosk and the corresponding maximal walking distance. Otherwise, output "<code>impossible</code>".</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

