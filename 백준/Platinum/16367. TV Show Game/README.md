# [Platinum II] TV Show Game - 16367 

[문제 링크](https://www.acmicpc.net/problem/16367) 

### 성능 요약

메모리: 4584 KB, 시간: 12 ms

### 분류

그래프 이론, 역추적, 강한 연결 요소, 2-sat

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Mr. Dajuda, who is famous for a TV show program, occasionally suggests an interesting game for the audience and gives them some gifts as a prize. The game he suggested this week can be explained as follows.</p>

<p>The <em>k</em>(> 3) lamps on the stage are all turned off at the beginning of the game. For convenience, lamps are numbered from 1 to <em>k</em>. Each lamp has a color, either red or blue. However, the color of a lamp cannot be identified until it is turned on. Game participants are asked to select three lamps at random and to guess the colors of them. Then each participant submits a paper on which the predicted colors of selected lamps are recorded to Mr. Dajuda, the game host. When all the lamps are turned on, each participant checks how many predicted colors match the actual colors of the lamps. If two or more colors match, he/she will receive a nice gift as a prize.</p>

<p>Mr. Dajuda prepared a special gift today. That is, after reviewing all the papers received from the game participants he tries to adjust the color of each lamp so that every participant can receive a prize if possible.</p>

<p>Given information about the predicted colors as explained above, write a program that determines whether the colors of all the lamps can be adjusted so that all the participants can receive prizes.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>k</em> and <em>n</em> (3 < <em>k</em> ≤ 5,000, 1 ≤ <em>n</em> ≤ 10,000), where <em>k</em> is the number of lamps and <em>n</em> the number of game participants. Each of the following <em>n</em> lines contains three pairs of (<em>l</em>, <em>c</em>), where <em>l</em> is the lamp number he/she selected and <em>c</em> is a character, either <code>B</code> for blue or <code>R</code> for red, which denotes the color he/she guessed for the lamp. There is a blank between <em>l</em> and <em>c</em> and each pair of (<em>l</em>, <em>c</em>) is separated by a blank as well as shown in following samples.</p>

### 출력 

 <p>Your program is to write to standard output. If it is possible that all the colors can be adjusted so that every participant can receive a prize, print <em>k</em> characters in a line. The <em>i</em><sup>th</sup> character, either <code>B</code> for blue or <code>R</code> for red represents the color of the <em>i</em><sup>th</sup> lamp. If impossible, print -1. If there are more than one answer, you can print out any of them.</p>

