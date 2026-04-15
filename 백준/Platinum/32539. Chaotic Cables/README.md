# [Platinum III] Chaotic Cables - 32539 

[문제 링크](https://www.acmicpc.net/problem/32539) 

### 성능 요약

메모리: 17088 KB, 시간: 104 ms

### 분류

비트마스킹, 그래프 이론

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Your friend Claas is in charge of designing the network for the newly constructed computer lab. Aware of the critical importance of efficiency in network design, Claas opted for the sophisticated Binary Access Point Configuration (BAPC) network topology.</p>

<p>A network is classified as a BAPC network precisely if we can assign a binary address of a fixed length to each device within the network, ensuring that:</p>

<ol>
	<li>Devices are connected if and only if their addresses differ in exactly one bit.</li>
	<li>Each possible address is assigned to exactly one device.</li>
</ol>

<p>Claas started out wiring devices together, but as the intricate web of connections began to take shape, doubt crept into his mind. Was the network he painstakingly constructed truly a BAPC network?</p>

<p>Help Claas determine if the network is a BAPC network.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $m$ ($2 \le n \le 2\cdot 10^5$, $1 \le m \le 2\cdot 10^5$) the number of devices and the number of wires in the network.</li>
	<li>$m$ lines with integers $a$ and $b$ ($1 \leq a, b \leq n$, $a \ne b$), indicating that there is a wire between devices $a$ and $b$.</li>
</ul>

<p>It is guaranteed that each pair of devices is connected by at most one wire.</p>

### 출력 

 <p>Output "<code>yes</code>" if the network is a BAPC network. Otherwise, output "<code>no</code>".</p>

