# [Gold I] Adjoin the Networks - 11267 

[문제 링크](https://www.acmicpc.net/problem/11267) 

### 성능 요약

메모리: 10476 KB, 시간: 60 ms

### 분류

애드 혹, 트리

### 제출 일자

2024년 6월 22일 23:36:38

### 문제 설명

<p>One day your boss explains to you that he has a bunch of computer networks that are currently unreachable from each other, and he asks you, the cable expert’s assistant, to adjoin the networks to each other using new cables. Existing cables in the network cannot be touched.</p>

<p>He has asked you to use as few cables as possible, but the length of the cables used does not matter to him, since the cables are optical and the connectors are the expensive parts. Your boss is rather picky on cable usage, so you know that the already existing networks have as few cables as possible.</p>

<p>Due to your humongous knowledge of computer networks, you are of course aware that the latency for an information packet travelling across the network is proportional to the number of hops the packet needs, where a hop is a traversal along a single cable. And since you believe a good solution to your boss’ problem may earn you that long wanted promotion, you decide to minimise the maximum number of hops needed between any pair of network nodes.</p>

### 입력 

 <p>On the first line, you are given two positive integers, the number 1 ≤ c ≤ 10<sup>5</sup> of computers and the number 0 ≤ ℓ ≤ c − 1 of existing cables. Then follow ℓ lines, each line consisting of two integers a and b, the two computers the cables connect. You may assume that every computer has a unique name between 0 and n − 1.</p>

### 출력 

 <p>The maximum number of hops in the resulting network.</p>

