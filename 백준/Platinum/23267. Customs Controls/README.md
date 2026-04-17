# [Platinum II] Customs Controls - 23267 

[문제 링크](https://www.acmicpc.net/problem/23267) 

### 성능 요약

메모리: 51120 KB, 시간: 316 ms

### 분류

그래프 이론, 애드 혹, 최단 경로, 데이크스트라, 위상 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>With lifted restrictions, the border trade between Norway and Sweden will surely be back to its former glory. But the authorities are worried that this will also mean an increase of illegal smuggling of goods. The customs authorities of Norway and Sweden must cooperate to prevent this from becoming too big of a problem.</p>

<p>To pass through the customs, one must visit a series of checkpoints, the Nordic Customs and Passport Control. There are $n$ checkpoints in total, numbered from $1$ to $n$, where $1$ is the entrance and $n$ is the exit. There are $m$ pairs of bidirectional roads that connect distinct checkpoints. The $i$th checkpoint takes some amount of time $t_i$ to pass through, and this is the bottleneck in crossing the border (the time it takes to walk the roads is negligible).</p>

<p>Each checkpoint can be watched by one customs unit, either a Norwegian one or a Swedish one. There are $k$ Norwegian customs units available, and $n-k$ Swedish units. When a road has both of its endpoints watched by customs units from the same country, any smugglers using that road will be caught. Smugglers are of course always in a hurry, and will always attempt to go from $1$ to $n$ in as short amount of time as possible.</p>

<p>Your task is to decide where to put the $n$ customs units, so that any smugglers who take a fastest possible route from $1$ to $n$ will be caught.</p>

### 입력 

 <p>The first line of input contains three integers $n$, $m$, and $k$ ($2 \leq n \leq 10^5$, $1 \leq m \leq 2 \cdot 10^5$, $0 \leq k \leq n$), the number of checkpoints, roads, and Norwegian customs units. The second line of input contains $n$ positive integers $t_1, \ldots, t_n$ ($1 \leq t_i \leq 10^4$), the time it takes to pass through each checkpoint. Then follow $m$ lines of input each containing two integers $u$ and $v$ ($1 \leq u, v \leq n$), meaning that there is a road between checkpoints $u$ and $v$.</p>

<p>It is guaranteed that it is possible to go from any checkpoint to any other checkpoint using the roads. There is also at most one road between each pair of checkpoints, and no road connects a checkpoint to itself.</p>

### 출력 

 <p>If there is a way to place the customs units so that every smuggler is caught, output a string of length $n$, where the $i$th character indicates which type of customs unit to put at the $i$th checkpoint (an '<code>N</code>' for a Norwegian customs unit, and an '<code>S</code>' for a Swedish customs unit).  Otherwise, if there if there is no way to catch every smuggler, output "<code>impossible</code>".</p>

