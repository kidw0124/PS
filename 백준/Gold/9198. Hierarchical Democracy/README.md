# [Gold IV] Hierarchical Democracy - 9198 

[문제 링크](https://www.acmicpc.net/problem/9198) 

### 성능 요약

메모리: 2304 KB, 시간: 8 ms

### 분류

깊이 우선 탐색, 분할 정복, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 구현, 파싱, 재귀, 정렬, 문자열, 트리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The presidential election in Republic of Democratia is carried out through multiple stages as follows.</p>

<ol>
	<li>There are exactly two presidential candidates.</li>
	<li>At the first stage, eligible voters go to the polls of his/her electoral district. The winner of the district is the candidate who takes a majority of the votes. Voters cast their ballots only at this first stage.</li>
	<li>A district of the k-th stage (k > 1) consists of multiple districts of the (k − 1)-th stage. In contrast, a district of the (k − 1)-th stage is a sub-district of one and only one district of the k-th stage. The winner of a district of the k-th stage is the candidate who wins in a majority of its sub-districts of the (k − 1)-th stage.</li>
	<li>The final stage has just one nation-wide district. The winner of the final stage is chosen as the president.</li>
</ol>

<p>You can assume the following about the presidential election of this country.</p>

<ul>
	<li>Every eligible voter casts a vote.</li>
	<li>The number of the eligible voters of each electoral district of the first stage is odd.</li>
	<li>The number of the sub-districts of the (k − 1)-th stage that constitute a district of the k-th stage (k > 1) is also odd.</li>
</ul>

<p>This means that each district of every stage has its winner (there is no tie).</p>

<p>Your mission is to write a program that finds a way to win the presidential election with the minimum number of votes. Suppose, for instance, that the district of the final stage has three sub-districts of the first stage and that the numbers of the eligible voters of the sub-districts are 123, 4567, and 89, respectively. The minimum number of votes required to be the winner is 107, that is, 62 from the first district and 45 from the third. In this case, even if the other candidate were given all the 4567 votes in the second district, s/he would inevitably be the loser. Although you might consider this election system unfair, you should accept it as a reality.</p>

### 입력 

 <p>The entire input looks like:</p>

<pre>the number of datasets (=n) 
1st dataset 
2nd dataset 
… 
n-th dataset </pre>

<p>The number of datasets, n, is no more than 100.</p>

<p>The number of the eligible voters of each district and the part-whole relations among districts are denoted as follows.</p>

<ul>
	<li>An electoral district of the first stage is denoted as [c], where c is the number of the eligible voters of the district.</li>
	<li>A district of the k-th stage (k > 1) is denoted as [d1d2…dm], where d1, d2, …, dm denote its sub-districts of the (k − 1)-th stage in this notation.</li>
</ul>

<p>For instance, an electoral district of the first stage that has 123 eligible voters is denoted as [123]. A district of the second stage consisting of three sub-districts of the first stage that have 123, 4567, and 89 eligible voters, respectively, is denoted as [[123][4567][89]].</p>

<p>Each dataset is a line that contains the character string denoting the district of the final stage in the aforementioned notation. You can assume the following.</p>

<ul>
	<li>The character string in each dataset does not include any characters except digits ('0', '1', …, '9') and square brackets ('[', ']'), and its length is between 11 and 10000, inclusive.</li>
	<li>The number of the eligible voters of each electoral district of the first stage is between 3 and 9999, inclusive.</li>
</ul>

<p>The number of stages is a nation-wide constant. So, for instance, [[[9][9][9]][9][9]] never appears in the input. [[[[9]]]] may not appear either since each district of the second or later stage must have multiple sub-districts of the previous stage.</p>

### 출력 

 <p>For each dataset, print the minimum number of votes required to be the winner of the presidential election in a line. No output line may include any characters except the digits with which the number is written.</p>

