# [Gold IV] Jigsaw of Shadows - 33144 

[문제 링크](https://www.acmicpc.net/problem/33144) 

### 성능 요약

메모리: 5020 KB, 시간: 44 ms

### 분류

기하학, 스위핑

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>They finally did it! The flat-earthers managed to teleport themselves to an idealized flat world where no one can make fun of them anymore.</p>

<p>In this world, there is a perfectly straight, infinite road that runs along the $x$-axis. Instead of a sun, they have something more illuminating: a gigantic flashlight elevated above the road, positioned infinitely far away to the west (negative $x$-axis). This flashlight beams light at a precise angle with respect to the ground, illuminating the entire road.</p>

<p>There are $N$ flatlanders standing proudly at distinct positions along the road. As the light strikes each of them, it casts a shadow extending eastward (toward the positive $x$-axis).</p>

<p style="text-align: center;"><img alt="" src="" style="width: 500px; height: 219px;"></p>

<p>Eager to show off their flat-world knowledge, the citizens want to calculate how much of the road is covered by their shadows. However, with shadows potentially overlapping, they need your help to figure it out. Given the positions of the flatlanders and their heights, can you calculate the total length of the road covered by their shadows?</p>

### 입력 

 <p>The first line contains two integers $θ$ ($10 ≤ θ ≤ 80$) and $N$ ($1 ≤ N ≤ 10^5 $), indicating respectively the angle of the light beams and the number of flatlanders on the road. The angle is measured in degrees, clockwise from the ground to the light beams.</p>

<p>Each of the next $N$ lines contains two integers $X$ ($0 ≤ X ≤ 3 \cdot 10^5 $) and $H$ ($1 ≤ H ≤ 1000$), indicating that a flatlander of height $H$ is located at position $X$ along the road. It is guaranteed that no two flatlanders share the same location.</p>

### 출력 

 <p>Output a single line with the total length of the road covered by the shadows of all flatlanders. The output must have an absolute or relative error of at most $10^{-4}$.</p>

