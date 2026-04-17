# [Bronze III] Testing LEDs - 33652 

[문제 링크](https://www.acmicpc.net/problem/33652) 

### 성능 요약

메모리: 2860 KB, 시간: 80 ms

### 분류

구현

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>LEDs are an amazing technology, in part due to their longevity. But they can’t last forever right? So you decide to put it to the test; you turn on an LED, and a machine periodically records the time in milliseconds since you started. Eventually it turns off! Your machine kept recording though, and unforunately your data is all jumbled up! What is the first time the machine recorded the LED being off?</p>

<p>Note that the LED may turn back on; you want to find the very first time the LED was recorded being off.</p>

### 입력 

 <p>The first line of input contains the integer $N$ ($1≤N≤10^5$). The following $N$ lines consist of $2$ integers $M$ ($0≤M<2^{31}$) and $O$ ($O\in\{0,1\}$), where $M$ is the time this recording was taken in milliseconds, and $O$ denotes whether the LED was on or off. The number $1$ corresponds to the LED being on, and $0$ off.</p>

### 출력 

 <p>Output a single integer denoting the time of the first recording where the LED was off, or output $-1$ if it was never off for any recording.</p>

