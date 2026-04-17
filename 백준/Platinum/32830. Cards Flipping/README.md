# [Platinum V] Cards Flipping - 32830 

[문제 링크](https://www.acmicpc.net/problem/32830) 

### 성능 요약

메모리: 46996 KB, 시간: 300 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 분리 집합

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The magician $B$ has $n$ cards in a row on a desk. Each card has two sides with colors. The top side of a card is the side facing upwards. The bottom side of a card is the side facing downwards. Each side of a card has one color. We want to find the maximum number of distinct colors on the top sides. In the following example, we are given $5$ cards in a row on a desk. The colors of the top sides of the cards are violet, red, violet, violet, and red from the left to the right as shown in the following figure. The colors of the bottom sides of the cards are red, violet, blue, yellow, and red from the left to the right.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 623px; height: 150px;"></p>

<p>If we flip a card, then the top side and the bottom side of the card are exchanged. If we flip the $3$<sup>rd</sup> and the $4$<sup>th</sup> card from the left, then the colors of the cards on the top sides become like the following.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 623px; height: 150px;"></p>

<p>The number of distinct colors on the top sides becomes $4$ which is the maximum for the example.</p>

<p>Given $n$ cards placed in a row on a desk and the colors on the sides of cards, write a program to output the maximum number of distinct colors on the top sides.</p>

### 입력 

 <p>Your program is to read from the standard input. The input starts with a line containing an integer $n$ ($1 ≤ n ≤200\,000$), where $n$ is the number of cards. The cards are numbered from $1$ to $n$. In the following two lines, the first line contains the colors on the top sides of cards from the card $1$ to the card $n$. The second line contains the colors on the bottom sides of cards from the card $1$ to the card $n$. Each color is represented by a nonnegative integer, not exceeding $10^6$.</p>

### 출력 

 <p>Your program is to write to the standard output. Print exactly one line. The line should contain the maximumnumber of distinct colors on the top sides.</p>

