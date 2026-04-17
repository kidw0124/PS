# [Platinum V] Safari - 30451 

[문제 링크](https://www.acmicpc.net/problem/30451) 

### 성능 요약

메모리: 2420 KB, 시간: 44 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Safari is a journey that involves going into nature to watch wild animals. Typically, safari participants travel through vast grasslands in four-wheel-drive cars, shortly 4WD cars. Imagine you are on safari in a 4WD car $C$.</p>

<p>Animals appear in specific places on the grassland, where you can consider the places as the points on the plane. There are $n$ animals, indicated as $1$ to $n$, in which the animal $i$ appears at the point $p_i$ in the plane. Each animal appears only in its own certain time interval. Specifically, the animal $i$ appears in the time interval $[a_i, b_i]$. So, when the car $C$ stays at $p_i$ for the duration $[v, w]$, you have the opportunity to observe the animal $i$ for the time period $[v, w] \cap [a_i , b_i]$. Note that if you observe an animal during $[\alpha, \beta]$, the length of time when you observe it is $|\beta − \alpha|$.</p>

<p>The car $C$ departs from the starting point $s = (0, 0)$ at time $0$ and it moves at speed $1$. Thus time $d$ has passed when $C$ moves distance $d$. The distance is measured in the $L^1$-metric. That is, the distance $d(p_1, p_2)$ between points $p_1 = (x_1, y_1)$ and $p_2 = (x_2, y_2)$ is $|x_1 - x_2 | + |y_1 - y_2|$. It always takes as long as the distance $d(p_1, p_2)$ while the car moves from $p_1$ to $p_2$. Also, the car may stay at a point as long as you need, if necessary. When your safari tour ends at the last sighting point of an animal, you want to know the longest possible time for which you observe the animals.</p>

<p>For example, the figure below shows six animals, indicated as $1$ to $6$, which appear at the coordinates $(1, 2)$, $(2, 1)$, $(2, 4)$, $(4, 1)$, $(5, 3)$, $(5, 5)$, respectively, of points in the plane. Let us also indicate as $1$ to $6$ the points of animals. The time intervals when the animals appear are also displayed. First, consider the case the car $C$ is driving along the blue path. The car departs from $s$ at time $0$ and arrives at the point $2$ at time $3$. Departing from it immediately at time $3$, the length of time when you observe the animal $2$ is $0$. Afterward, you arrive at the point $3$ at time $6$ and stay there during $[6, 8]$. Next, you arrive at the point $6$ at time $12$ and observe the animal $6$ during $[12, 16]$. Then the total length of time when you observe the animals is $0 + 2 + 4 = 6$. Secondly, consider the case the car $C$ is driving along the red path. At first, you arrive at the point $1$ at time $3$ and stay during $[3, 6]$. Departing from it at time $6$, you arrive at the point $4$ at time $10$ and stay during $[10, 12]$. Then you arrive at the point $5$ at time $15$ and observe the animal $5$ during $[15, 18]$. In this case, the total length of time when you observe the animals is $2 + 2 + 3 = 7$, which is longer than the blue path and actually, the length of the longest time when you can observe the animals.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 253px; height: 211px;"></p>

<p>Given $n$ coordinates of points and $n$ time intervals for the appearances of animals, write a program to output the length of the longest possible time when you observe the animals.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integer $n$ ($1 ≤ n ≤ 5\,000$), where $n$ is the number of animals. The animals are numbered from $1$ to $n$. In the following $n$ lines, the $i$-th line contains two integers $x_i$ and $y_i$ that represent the coordinate $(x_i , y_i)$ of the point $p_i$ in the plane where the animal $i$ appears ($0 ≤ x_i , y_i ≤ 10^6$). Note that the car $C$ is located at $(0, 0)$ at time $0$. The given points containing $(0, 0)$ are all distinct. In the following $n$ lines, the $i$-th line contains two integers $v_i$ and $w_i$ that represent the duration $[v_i , w_i]$ when the animal $i$ appears at $p_i$ ($0 ≤ v_i < w_i ≤ 10^9$).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the length of the longest time when you can observe the animals.</p>

