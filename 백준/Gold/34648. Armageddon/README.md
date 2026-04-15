# [Gold II] Armageddon - 34648 

[문제 링크](https://www.acmicpc.net/problem/34648) 

### 성능 요약

메모리: 2868 KB, 시간: 20 ms

### 분류

수학, 그리디 알고리즘, 정수론, 모듈로 곱셈 역원, 페르마의 소정리

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Cocoa, <em>the magic sword president</em> of RUN, has obtained a new magic sword named <strong>Armageddon</strong>. To maximize its power, Cocoa intends to enhance it.</p>

<p>Specifically, the sword's power is determined by its length $x$, enchantment level $y$, and brilliance $z$, according to the formula:</p>

<p style="text-align: center;">$\frac{x(x+1)}{2}\cdot\frac{y(y+1)}{2}\cdot a^z$</p>

<p>where $x,y,z$ are <strong>nonnegative integers</strong>. Here, $a$ is a fixed constant determined when <strong>Armageddon </strong>was forged. Initially, $x,y,z$ are all initialized to 0.</p>

<p>Cocoa can invest her mana to improve the sword. For each $1$ mana spent, she can increase either $x$, $y$, or $z$ by $1$.</p>

<p>For each $k = 1, 2, \cdots, n$, determine the maximum possible power of the sword if Cocoa uses exactly $k$ mana to enhance the sword.</p>

### 입력 

 <p>The first line contains three integers $p$, $q$, and $n$ separated by spaces, where $a = p/q$.</p>

### 출력 

 <p>Print $n$ values in a single line, separated by spaces.  </p>

<p>For the $i$-th value, output $s \times t^{-1} \pmod{10^9+7}$, where $s/t$ is the irreducible fraction representing the maximum possible power after investing exactly $i$ mana.</p>

