# [Gold II] Fenced In (Gold) - 11995 

[문제 링크](https://www.acmicpc.net/problem/11995) 

### 성능 요약

메모리: 279308 KB, 시간: 1960 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Farmer John has realized that many of his cows are strangely agoraphobic (being fearful of large open spaces). To try and make them less afraid of grazing, he partitions his large field into a number of smaller regions by building vertical (north-south) and horizontal (east-west) fences.</p>

<p>The large field is a rectangle with corner points at \((0,0)\) and \((A,B)\). FJ builds \(n\) vertical fences (\(0 \leq n \leq 2000\)) at distinct locations \(a_1 \ldots a_n\) (\(0 < a_i < A\)); each fence runs from \((a_i, 0)\) to \((a_i, B)\). He also builds \(m\) horizontal fences (\(0 \leq m \leq 2000\)) at locations \(b_1 \ldots b_m\) (\(0 < b_i < B\)); each such fence runs from \((0, b_i)\) to \((A, b_i)\). Each vertical fence crosses through each horizontal fence, subdividing the large field into a total of \((n+1)(m+1)\) regions.</p>

<p>Unfortunately, FJ completely forgot to build gates into his fences, making it impossible for cows to leave their enclosing region and travel around the entire field! He wants to remedy this situation by removing pieces of some of his fences to allow cows to travel between adjacent regions. He wants to select certain pairs of adjacent regions and remove the entire length of fence separating them; afterwards, he wants cows to be able to wander through these openings so they can travel anywhere in his larger field.</p>

<p>For example, FJ might take a fence pattern looking like this:</p>

<pre>+---+--+
|   |  |
+---+--+
|   |  |  
|   |  |
+---+--+
</pre>

<p>and open it up like so:</p>

<pre>+---+--+
|      |  
+---+  +  
|      |  
|      |
+---+--+
</pre>

<p>Please help FJ determine the minimum total length of fencing he must remove to accomplish his goal.</p>

### 입력 

 <p>The first line of input contains \(A\), \(B\), \(n\), and \(m\) (\(1 \leq A, B \leq 1,000,000,000\)). The next \(n\) lines contain \(a_1 \ldots a_n\), and the next \(m\) lines after that contain \(b_1 \ldots b_m\).</p>

### 출력 

 <p>Please write the minimum length of fencing FJ must remove. Note that this might be too large to fit into a standard 32-bit integer, so you may need to use 64-bit integer types (e.g., "long long" in C/C++).</p>

