# [Platinum IV] Wipe Your Whiteboards - 11635 

[문제 링크](https://www.acmicpc.net/problem/11635) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

확장 유클리드 호제법, 수학, 정수론

### 제출 일자

2024년 9월 17일 00:07:52

### 문제 설명

<p>You enter an empty classroom to do some homework, and you find out that someone did not clean the whiteboard properly. Apparently, the previous instruction in that room has been about the Extended Euclidean algorithm, because you see lots of intermediate results of this algorithm on the whiteboard. However, some parts of it have been wiped out, so you don’t see everything they did. In particular, you’re not sure what numbers they used as the inputs for the algorithm. As you didn’t really feel like doing your homework in the first place, you decide to see if you can figure out the numbers they started with.</p>

<p>Looking at the algorithm as executed on the whiteboard, you can determine one thing for certain from their intermediate results: given that their inputs were A and B (A, B ≥ 1, both integers), you see three integers R, S and Q (with R ≥ 2, S ≤ −2 and Q ≥ 1), for which you know that A · R + B · S = Q. Now, given these three numbers, you want to figure out the A and B they started out with. Unfortunately, you quickly realize that there may not be a single A and B pair that fit this, so you decide to go looking for the pair with smallest positive A and B. Finally, you decide to not actually bother trying to find an A and B such that R, S and Q are intermediate results of the Extended Euclidean algorithm applied on A and B: you decide you’re happy if they just satisfy A · R + B · S = Q.</p>

### 입력 

 <p>The input starts with a line containing an integer T, the number of test cases. Then for each test case:</p>

<ul>
	<li>One line with three space-separated integers R, S and Q. These satisfy 2 ≤ R ≤ 10<sup>8</sup> , −10<sup>8</sup> ≤ S ≤ −2 and 1 ≤ Q ≤ 10<sup>8</sup>. You are given that Q is a multiple of the greatest common divisor of R and S.</li>
</ul>

### 출력 

 <p>For each test case, output one line with two space-separated integers A ≥ 1 and B ≥ 1, the smallest such pair of numbers so that A · R + B · S = Q. By the smallest pair, we mean the pair such that A is minimal and if there are multiple such pairs the one of these for which B is minimal.</p>

