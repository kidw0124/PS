# [Platinum IV] Chess Tournament - 11446 

[문제 링크](https://www.acmicpc.net/problem/11446) 

### 성능 요약

메모리: 13780 KB, 시간: 936 ms

### 분류

배낭 문제

### 제출 일자

2024년 7월 24일 04:36:21

### 문제 설명

<p>There is a large chess tournament being held in your town, and you decide to go and have a look. Two teams A and B each consisting of n players face each other. Every player from team A will play a match against every player from team B. In the end, the team with the most wins will be declared the winner. (In case of a draw, both players receive 1/2 point.)</p>

<p>You don’t know which players are on which team, but you have meticulously crafted a list of all matches that have been played during the tournament. The only problem is that some players have played matches outside the tournament schedule, facing a player from their own team or possibly even a player from the opposing team, either for practice or for fun. Can you still tell which players belong to which team?</p>

### 입력 

 <p>The input starts with a line containing an integer T, the number of test cases. Then for each test case:</p>

<ul>
	<li>One line with two space-separated integers N and M, denoting the number of players per team and the total number of matches that have been played. These satisfy 1 ≤ N ≤ 250 and N<sup>2</sup> ≤ M ≤ 10<sup>6</sup>.</li>
	<li>After that, M lines follow with two different space-separated integers A and B per line, indicating that players A and B have played a match against one another. These satisfy 1 ≤ A < B ≤ 2N.</li>
</ul>

<p>Note that a pair of players may be listed more than once.</p>

### 출력 

 <p>For every test case, output two lines:</p>

<ul>
	<li>One line with the number of solutions. As the number of solutions can be very large, you must reduce your answer modulo 10<sup>8</sup>. No answer < 0 or ≥ 10<sup>8</sup> will be accepted.</li>
	<li>One line with N space separated integers, denoting the team members of the first team in ascending order. The first team is defined to be the team that contains player 1. If this cannot be uniquely determined, output one possible configuration. There will always be at least one solution (though the number of solutions may nevertheless be 0 modulo 10<sup>8</sup>)</li>
</ul>

