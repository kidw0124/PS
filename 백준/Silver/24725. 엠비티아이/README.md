# [Silver III] 엠비티아이 - 24725 

[문제 링크](https://www.acmicpc.net/problem/24725) 

### 성능 요약

메모리: 2164 KB, 시간: 8 ms

### 분류

구현, 문자열, 브루트포스 알고리즘

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Myers-Briggs Type Indicator (MBTI) is an introspective self-report questionnaire indicating differing psychological preferences in how people perceive the world and make decisions. </p>

<p>MBTI divides human personality into 16 types and each type consists of 4 alphabets.</p>

<ul>
	<li>The first letter represents extroversion (<strong>E</strong>) or introversion (<strong>I</strong>), indicating how they gain their energy.</li>
	<li>The second letter represents intuition (<strong>N</strong>) or sensation (<strong>S</strong>), indicating how new information is understood and interpreted.</li>
	<li>The third letter represents emotions (<strong>F</strong>) or thinking (<strong>T</strong>), indicating how they make decisions.</li>
	<li>The last letter represents perception (<strong>P</strong>) or judgment (<strong>J</strong>), indicating lifestyle preferences how they organize their time.</li>
</ul>

<p>There are 16 types of MBTI because a total of four alphabets are selected according to each description (e.g. <strong>ENFP</strong>, <strong>ISTP</strong>, <strong>ENTJ</strong>, etc.) </p>

<p>One day, you find an alphabet board while going to the laboratory. As you are too obsessed with MBTI, you start looking for how many MBTI types are on the board. If the four horizontal, vertical, or diagonal letters on the board are one of the types of MBTI, you will shout "<strong>MBTI!</strong>". The direction of the word does not matter, i.e. it could be the bottom right to top left, left to right, and so on. Also, even though the type is previously found, "<strong>MBTI!</strong>" should be shouted again if the word is in a different location or direction.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 168px; height: 150px;"></td>
			<td><img alt="" src="" style="height: 150px; width: 168px;"></td>
			<td><img alt="" src="" style="width: 169px; height: 150px;"></td>
		</tr>
		<tr>
			<td><strong>Figure 1.</strong></td>
			<td><strong>Figure 2.</strong></td>
			<td><strong>Figure 3.</strong></td>
		</tr>
	</tbody>
</table>

<p> Let's find all the MBTI types on the board and shout "<strong>MBTI!</strong>" together.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with an integer $N, M$ ( $1 \leq N,M \leq 200$ ) representing rows and columns of boards. Following this are $N$ lines containing $M$ uppercase characters how does the alphabet board consist with.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain total occurrences of 16 MBTI types, which will be equal to the number of times you shouted '<strong>MBTI!</strong>'</p>

