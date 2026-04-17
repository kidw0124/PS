# [Silver I] Failing Flagship - 25997 

[문제 링크](https://www.acmicpc.net/problem/25997) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

수학, 구현

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Ahoy! You are sailing towards the next "Boats Are Pretty Cool" convention to sell your latest gadget: a new type of compass.</p>

<p>On a normal compass, it is difficult to read off the precise wind direction. However, your new type of compass lets you read off wind directions to a much higher precision! The display can display strings of at most $1000$ characters.</p>

<p>Unfortunately, you have encountered some bad weather. After a few hours of heavy winds and big waves, you can finally look at your compass again. You read off the wind direction $X$ you are going and know in which wind direction $Y$ you need to go. However, to make the ship turn you have to enter the degrees of the angle the ship has to make in the control system. What is the smallest turn, in degrees, you have to make to get back on the right course?</p>

<p style="text-align: center;"><img alt="" src="" style="width: 250px; height: 257px;"></p>

<p style="text-align: center;">Figure F.1: Wind directions</p>

<p>The conversion of a wind direction to degrees goes as follows. The four basic wind directions are N, E, S, and W pointing at $0$, $90$, $180$, and $270$ degrees, respectively. There are also four wind directions consisting of two letters: NE, SE, SW, and NW, pointing at $45$, $135$, $225$, and $315$ degrees, respectively.</p>

<p>A wind direction can also consist of $k\geq 3$ letters $l_1l_2\ldots l_k$. In that case, the last two letters indicate one of the four two-letter wind directions, i.e., $l_{k-1}l_k \in \{\text{NE}, \text{SE}, \text{SW}, \text{NW}\}$ and the other letters are equal to one of these, i.e., $l_i \in \{l_{k-1}, l_k\}$ for all $i \leq k-2$. This wind direction points precisely in the middle of the following two wind directions:</p>

<ul>
	<li>wind direction $l_2\ldots l_k$,</li>
	<li>the first wind direction of at most $k-1$ letters you encounter when starting in $l_2\ldots l_k$ and move along the circle towards $l_1$.</li>
</ul>

<p>For example, the wind direction SSSE points in the middle of SSE and S, because S is the first wind direction with at most 3 letters when moving from SSE towards S, as can also been seen in Figure F.1.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two strings $X$ and $Y$ ($1 \leq |X|, |Y| \leq 1000$), indicating the wind directions as described above.</li>
</ul>

### 출력 

 <p>Output the smallest turn you have to make to go from direction $X$ to $Y$.</p>

<p>Your answer should have an <em>absolute</em> error of at most $10^{-6}$.</p>

