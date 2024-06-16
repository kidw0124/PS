# [Gold II] Unusual Game Show - 27681 

[문제 링크](https://www.acmicpc.net/problem/27681) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

게임 이론, 수학, 확률론

### 제출 일자

2024년 6월 15일 20:36:39

### 문제 설명

<p>You may have already heard about the famous game show host Monty Hall. Back in the day, his game show had confused many a bright mathematician.</p>

<p>This is how it all looked like: The contestant was shown three doors, labeled 1 through 3. There was a prize (e.g., a new car) behind one of the doors, and a goat behind each of the other two doors. The door hiding the prize was chosen uniformly at random. Monty knew which door contains the prize. The game consisted of three steps:</p>

<ol>
	<li>At the beginning of the game, the contestant was asked to choose one of the three doors for herself.</li>
	<li>
	<p>Once the choice was made, Monty would open one of the doors the contestant did not choose.</p>
	Of course, Monty would never open the door with the prize. If the contestant chose the door with the prize, Monty would open either of the other two doors, chosen uniformly at random. In all other cases Monty would open the only door that was neither chosen by the contestant nor hiding the prize.</li>
	<li>
	<p>Then, Monty asked the contestant a very tricky question: "Do you want to <em>keep</em> the door you have, or do you want to <em>switch</em> to the other door?’’</p>

	<p>Once the contestant made her final decision, Monty opened the door she chose to show whether she found the prize.</p>
	</li>
</ol>

<p>This game became very famous among mathematicians because the optimal strategy is very counterintuitive. At the end of the game, the player gets to choose between two doors. One of them contains the prize, the other does not. Thus, on the surface it seems that the choice doesn’t matter and that the probability of winning the prize is always 1/2. <strong>This is not true.</strong> It can be shown that the optimal strategy for the contestant is to <em>never keep, always switch to the other door</em>. With this strategy, the actual probability of winning the prize is 2/3.</p>

<p>Monty Hall is still hosting the game show. However, there have been some changes:</p>

<ul>
	<li>
	<p>For financial reasons, the number of doors is now <em>d</em> (<em>d</em> ≥ 3). There is one prize and <em>d</em> − 1 goats.</p>
	</li>
	<li>
	<p>Monty is very old. When performing a show, with probability <em>p</em> he is tired.</p>

	<p>If Monty isn’t tired, he follows the above protocol. However, if he is tired, he wants to avoid unnecessary walking. Therefore, if he has a choice in step 2, he will always open <strong>the door with the smallest number</strong> among the doors he is allowed to open. (He is still not allowed to open the door with the prize nor the door currently chosen by the contestant.)</p>
	</li>
	<li>
	<p>In step 3, the contestant gets to choose whether she keeps the door she has or switches to <em>any other unopened door</em>. When switching, the contestant gets to choose which one of the other doors she now wants.</p>
	</li>
	<li>
	<p>After step 3, the game is over. The remaining <em>d</em> − 1 doors are opened and it is revealed whether the contestant won the prize.</p>
	</li>
</ul>

<p>You are given the number of doors <em>d</em> and the probability <em>p</em>. Find an optimal strategy for the contestant, and report her probability of winning the prize if she follows that strategy.</p>

### 입력 

 <p>The first line of the input file contains an integer <em>t</em> specifying the number of test cases. Each test case is preceded by a blank line. Each test case consists of a single line containing the numbers <em>d</em> and <em>p</em>. The value <em>p</em> is always a number from [0, 1] with exactly 6 decimal places.</p>

### 출력 

 <p>For each test case, output a single line with a single real number: the optimal probability of winning the prize. Output at least 10 decimal places. Answers within 10<sup>−9</sup> of our answer will be accepted as correct.</p>

