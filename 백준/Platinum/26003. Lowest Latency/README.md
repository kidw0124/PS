# [Platinum IV] Lowest Latency - 26003 

[문제 링크](https://www.acmicpc.net/problem/26003) 

### 성능 요약

메모리: 96620 KB, 시간: 4440 ms

### 분류

브루트포스 알고리즘, 기하학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>It is the year 2222. The whole universe has been explored, and settlements have been built on every single planet. You live in one of these settlements. While life is comfortable on almost all aspects, there is one dire problem: the latency on the internet connection with other planets is way too high.</p>

<p>Luckily, you have thought of a solution to solve this problem: you just need to put Bonded, Astronomically Paired Cables between all planets, and internet will be super fast! However, as you start developing this idea, you discover that constructing a cable between two planets is more difficult than expected. For this reason, you would like the first prototype of your cable to be between two planets which are as close as possible to each other.</p>

<p>From your astonomy class, you know that the universe is best modelled as a large cube measuring $10^9$ lightyears in each dimension. There are exactly $10^5$ stationary planets, which are distributed completely randomly through the universe (more precisely: all the coordinates of the planets are independent uniformly random integers ranging from $0$ to $10^9$).</p>

<p>Given the random positions of the planets in the universe, your goal is to find the minimal Euclidean distance between any two planets.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$, the number of planets.</li>
	<li>$n$ lines, each with three integers $x$, $y$, and $z$ ($0 \leq x, y, z < 10^9$), the coordinates of one of the planets.</li>
</ul>

<p>Your submissions will be run on exactly $100$ test cases, all of which will have $n = 10^5$. The samples are smaller and for illustration only.</p>

<p>Each of your submissions will be run on new random test cases.</p>

### 출력 

 <p>Output the minimal Euclidean distance between any two of the planets.</p>

<p>Your answer should have an absolute or relative error of at most $10^{-6}$.</p>

