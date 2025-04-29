# [Gold II] Lighting - 16342 

[문제 링크](https://www.acmicpc.net/problem/16342) 

### 성능 요약

메모리: 57192 KB, 시간: 84 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 4월 30일 04:04:16

### 문제 설명

<p>The lighting system in Binary Casino is controlled by a very complex and secure mechanism, which is connected to a central control console. At the console, the state of each light is stored as one bit of information (0=the corresponding light is off, 1=light is on), so the complete state of all lights in the building may be represented by a binary number a.</p>

<p>To avoid manipulation by unauthorized persons, the lighting system has a special method to control the lights. Should one want to change the configuration of the lights, it is necessary to enter a binary number b which gets added to the original configuration a using standard integer summation.</p>

<p>You need a particular number of lights to be switched ON and you are curious what are you chances of success. How many suitable binary numbers are there?</p>

### 입력 

 <p>The first line of input contains two integers N and K (1 ≤ N ≤ 1000, 0 ≤ K ≤ N), N representing the number of bits of a and of b, and K the target number of lights to be switched ON. The second line contains a binary integer a of length N.</p>

### 출력 

 <p>Print the number of different nonnegative N-bit integers b such that the sum a + b has exactly K bits set to 1. As the result might be large, output it modulo 10<sup>9</sup> + 7.</p>

