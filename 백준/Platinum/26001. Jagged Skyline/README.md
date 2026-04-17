# [Platinum III] Jagged Skyline - 26001 

[문제 링크](https://www.acmicpc.net/problem/26001) 

### 성능 요약

메모리: 13808 KB, 시간: 936 ms

### 분류

이분 탐색, 무작위화

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The future is here! The Boxes And Parcels Centre has decided to start delivering parcels using drones. Being a BrAinPort Company, naturally the first deliveries will be to Eindhoven.</p>

<p>To keep the flight logic simple, the first prototype will only deliver to the roofs of the tallest buildings. After take-off, the drone will take a $w\times h$ ($1 \leq w\leq 10\,000$, $1\leq h\leq 10^{18}$) photo of the skyline, as shown in Figure J.1. You have been tasked with the problem of determining the location and height of the tallest building in this photo, so that the drone knows where to go.</p>

<p>You have access to a classifier that can determine for each pixel whether it is "<code>sky</code>" or "<code>building</code>". You can use this multiple times for different pixels. To avoid unnecessary delays, you may run the classifier at most $12\,000$ times.</p>

<p>It is guaranteed that the buildings will not contain any hovering parts: whenever a pixel that is not on the bottom row of the photo is classified as building, the pixels below it will also be classified as building.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 300px; height: 174px;"></p>

<p style="text-align: center;">Figure J.1: The skyline of the sample interaction.</p>

### 입력 

 Empty

### 출력 

 Empty

