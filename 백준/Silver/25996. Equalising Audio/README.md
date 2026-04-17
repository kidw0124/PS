# [Silver III] Equalising Audio - 25996 

[문제 링크](https://www.acmicpc.net/problem/25996) 

### 성능 요약

메모리: 2820 KB, 시간: 108 ms

### 분류

수학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>As a radio engineer at the Balanced Audio Podcast \copyright{} your job is to deliver an equal listening experience at all times. You did a poll among the listeners and they are especially concerned about fluctuations in loudness. To resolve this you bought a transformer to equalise the audio, but alas, its software got corrupted during transport.</p>

<p>Your job is to rewrite the equalising software. As input the transformer gets $n$ amplitudes $a_1, \ldots, a_n$, with an average perceived loudness of $\frac{1}{n}\sum_{i=1}^n a_i^2$. The output should contain the same amplitudes, but renormalised by some constant positive factor, such that the average perceived loudness is $x$. There is one exception: total silence should always be preserved.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with a two integers $n$ and $x$ ($1\leq n\leq 10^5$, $0 \leq x \leq 10^6)$, the number of amplitudes and the average perceived loudness to achieve.</li>
	<li>One line with $n$ integers $a_1, \ldots, a_n$ ($\left| a_i \right| \leq 10^6$), the amplitudes.</li>
</ul>

### 출력 

 <p>Output one line containing $n$ numbers, the renormalised amplitudes with an average perceived loudness of $x$.</p>

<p>Your answers should have an absolute or relative error of at most $10^{-6}$.</p>

