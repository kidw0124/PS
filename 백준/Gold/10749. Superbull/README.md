# [Gold I] Superbull - 10749 

[문제 링크](https://www.acmicpc.net/problem/10749) 

### 성능 요약

메모리: 33412 KB, 시간: 40 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Bessie and her friends are playing hoofball in the annual Superbull championship, and Farmer John is in charge of making the tournament as exciting as possible. A total of N (1 <= N <= 2000) teams are playing in the Superbull. Each team is assigned a distinct integer team ID in the range 1...2^30-1 to distinguish it from the other teams. The Superbull is an elimination tournament -- after every game, Farmer John chooses which team to eliminate from the Superbull, and the eliminated team can no longer play in any more games. The Superbull ends when only one team remains.</p>

<p>Farmer John notices a very unusual property about the scores in matches! In any game, the combined score of the two teams always ends up being the bitwise exclusive OR (XOR) of the two team IDs. For example, if teams 12 and 20 were to play, then 24 points would be scored in that game, since 01100 XOR 10100 = 11000.</p>

<p>Farmer John believes that the more points are scored in a game, the more exciting the game is. Because of this, he wants to choose a series of games to be played such that the total number of points scored in the Superbull is maximized. Please help Farmer John organize the matches.</p>

### 입력 

 <p>The first line contains the single integer N. The following N lines contain the N team IDs.</p>

### 출력 

 <p>Output the maximum possible number of points that can be scored in the Superbull.</p>

