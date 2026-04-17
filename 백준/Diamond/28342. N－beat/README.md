# [Diamond IV] N-beat - 28342 

[문제 링크](https://www.acmicpc.net/problem/28342) 

### 성능 요약

메모리: 18052 KB, 시간: 1088 ms

### 분류

애드 혹, 조합론, 다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱, 선형대수학, 수학, 모듈로 곱셈 역원, 정수론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>N-beat is a popular rhythm arcade game, in which you push buttons arranged in a $x \times y$ grid. The buttons light up when you have to push them; you have to push them with precise timing to get scores.</p>

<p>One game of N-beat consists of one or more screens. A <strong>screen</strong> is a configuration of lit buttons which you have to push.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 550px; height: 123px;"></p>

<p>For example, the picture above shows $4$ successive <strong>screen</strong>s for a N-beat machine with $4 \times 4$ grid. Here, boxes with the target mark are the lit buttons you have to press.</p>

<p>A sequence of screens in a game is called a <strong>transcription</strong>.</p>

<p>Now, Jaeha Koo, a genius composer, just made a new song for N-beat. You’re going to make transcription for this song.</p>

<p>There are $B$ beats in this song, so this transcription will consist of $B$ <strong>screen</strong>s. Therefore, without any restriction, there are a total of $(2^{xy})^B$ possible transcriptions.</p>

<p>But <strong>transcription</strong>s differ in difficulty. Generally, you can push one button with one finger, so it’s harder when a single screen has more lit buttons. Especially, if a screen has more than $10$ lit buttons, it’s very difficult to push them successfully. Also, adjacent screens having a lot of lit buttons can also can make the game difficult. For example, two successive screens with $7$ and $6$ lit buttons each might be more difficult than two screens with $2$ and $8$ lit buttons each.</p>

<p>As a generous transcriptor, you decided to limit the number of lit buttons. The limit is given as three nonnegative integers: $p_1$, $p_2$, and $p_3$. $p_1$ is the maximum number of lit buttons you can have in any one screen. $p_2$ is the maximum number of lit buttons you can have in any two consecutive screens. Also, as you guessed, $p_3$ is the maximum number of lit buttons you can have in any three consecutive screens. In the picture above, $4$ screens each have $4$, $8$, $6$, $8$ of turned-on buttons, so this transcription will only be valid if $p_1 ≥ 8$, $p_2 ≥ 14$, and $p_3 ≥ 22$.</p>

<p>Your task is to calculate the number of possible transcriptions given $x$, $y$, $B$, $p_1$, $p_2$ and $p_3$. As the result can be quite huge, just calculate the answer mod $10^9 + 7$.</p>

### 입력 

 <p>The input consists of $T$ test cases. The first line of the input contains $T$.</p>

<p>Each test case starts with $6$ integers $x$, $y$ ($1 ≤ x, y ≤ 1000$), $B$ ($1 ≤ B ≤ 10^9$), $p_1$ ($0 ≤ p_1 ≤ 10$), $p_2$ ($0 ≤ p_2 ≤ 20$), $p_3$ ($0 ≤ p_3 ≤ 30$) separated by a whitespace.</p>

### 출력 

 <p>For each test case, print the number of possible transcriptions mod $10^9 + 7$, in a single line.</p>

