# [Diamond IV] Almost Aligned - 31751 

[문제 링크](https://www.acmicpc.net/problem/31751) 

### 성능 요약

메모리: 82572 KB, 시간: 908 ms

### 분류

수학, 구현, 기하학, 많은 조건 분기, 임의 정밀도 / 큰 수 연산, 볼록 껍질을 이용한 최적화, 수치해석

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A meteor shower is about to happen! As the enthusiastic astronomy photographer that you are, you want to take a single picture of all the meteors that will be part of the phenomenon. Not only that, you want to take the best possible picture. You know that the smaller the area of the photo, the better the picture. But how small can you make the picture to capture them all?</p>

<p>You can take a picture of any rectangular region of your camera’s view, but you cannot rotate the camera. That is, your photo can be any axis-aligned rectangle. The challenge? The meteors are constantly moving. Think of time ($t$) as the number of seconds that have passed since the start of the meteor shower. Your goal is to find a non-negative value of $t$ at which you can capture every single meteor with the smallest possible rectangle. A photo captures all the meteors within the rectangle, including those on the border.</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 ≤ N ≤ 10^6$) indicating the number of meteors.</p>

<p>Each of the next $N$ lines describes a meteor with four integers $X$, $Y$, $V_X$ and $V_Y$ ($-10^9 ≤ X, Y, V_X, V_Y ≤ 10^9$), representing the location and velocity of the meteor, as seen by your camera. This means that at any time $t ≥ 0$ the coordinates of the meteor are $(X + t \cdot V_X, Y + t \cdot V_Y$). If $t < 0$ the location of the meteor is undefined.</p>

### 출력 

 <p>Output a single line with the minimum area of an axis-aligned rectangle containing all the meteors at a time $t ≥ 0$. The output must have an absolute or relative error of at most $10^{-9}$.</p>

