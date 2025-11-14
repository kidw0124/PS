# [Silver III] Coatless in Yakutsk - 34734 

[문제 링크](https://www.acmicpc.net/problem/34734) 

### 성능 요약

메모리: 2868 KB, 시간: 32 ms

### 분류

구현, 브루트포스 알고리즘

### 제출 일자

2025년 11월 15일 05:52:57

### 문제 설명

<p>It was your first time visiting Salvador, and you made the rookie mistake of sleeping on the beach. You woke up red, sunburned, and frankly, humiliated. Swearing vengeance against the sun and all its terrible consequences, you decided that your next vacation would be somewhere with a real winter – like Yakutsk, Russia, where the average temperature is $−42^\circ$ Celsius.</p>

<p>But you came prepared! You brought a warm, cozy coat. The coat is perfect, it warms you very well. Maybe too well, as you get sweaty and the coat gets dirty after $C$ days of use. Since your trip lasts more than $C$ days, you must find a way to avoid walking around smelling bad.</p>

<p>To do so, when the coat gets dirty, you cannot wear it until it is washed, but you may also choose to wash it earlier. On any day you do not wear the coat – whether because it is dirty or being washed – you must endure the day’s temperature without its protection. After being washed, the coat is fresh and ready to be worn again. At the start of your trip, the coat is clean.</p>

<p>Given the daily temperatures in Yakutsk for the duration of your trip, you must determine the lowest temperature on a day when you are forced to be without your coat, assuming you schedule wash days optimally to make this temperature as high as possible.</p>

### 입력 

 <p>The first line contains two integers $C$ and $N$ ($1 ≤ C < N ≤ 10^5$), indicating respectively the number of days you can wear the coat before it gets dirty, and the duration in days of your holidays.</p>

<p>The second line contains $N$ integers $T_1, T_2, \dots , T_N$ ($−50 ≤ T_i ≤ 50$ for $i = 1, 2, \dots , N$), where $T_i$ is the temperature on the $i$-th day.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum temperature you must endure without your coat.</p>

