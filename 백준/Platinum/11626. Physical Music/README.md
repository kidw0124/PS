# [Platinum V] Physical Music - 11626 

[문제 링크](https://www.acmicpc.net/problem/11626) 

### 성능 요약

메모리: 7616 KB, 시간: 216 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2024년 9월 17일 06:23:58

### 문제 설명

<p>The music business is changing rapidly, and this is reflected by the single charts. Initially, the Dutch Single Top 100 was based purely on sale numbers of CD singles. In the course of time, however, these numbers dropped dramatically, in favour of legal and illegal downloads of music from the internet. Therefore, since 2006, downloads of singles from specific legal downloads sites are incorporated into the chart. Nowadays, even streams from certain streaming platforms contribute to the Single Top 100.</p>

<p>Between 2006 and 2013, when the Single Top 100 was based on both CD singles and downloads, there was also a chart called the Download Top 100, based purely on the downloads. Assuming that both charts used the same numbers of weekly downloads, one could tell from a comparison between the two charts, which singles were selling well physically. And in fact, since some singles did not even appear as CD singles any more, one could tell which singles were certainly available as CD single: the ones that were doing better (as compared to some other singles) in the Single Top 100 than in the Download Top 100.</p>

<p>Now, you are asked to write a program to determine these singles. To be prepared for other communities, which may also have single charts of other sizes, your program should not be limited to charts containing exactly one hundred singles.</p>

### 입력 

 <p>The input starts with a line containing an integer T, the number of test cases. Then for each test case:</p>

<ul>
	<li>One line containing an integer N, satisfying 1 ≤ N ≤ 100,000, the size of both single charts.</li>
	<li>N lines, each containing a single integer, which together form a permutation of the numbers 1, . . . , N. The i-th integer P<sub>i</sub> is the position in the Download Top N of the single that is ranked i in the Single Top N.</li>
</ul>

<p>As the above specification implies, the Download Top N and the Single Top N contain exactly the same N singles, possibly in different orders.</p>

### 출력 

 <p>For each test case, output:</p>

<ul>
	<li>One line containing the number of singles M that are certainly available as CD single.
	<ul>
		<li>M lines, each containing a single integer, the positions of the singles in the Download Top N that are certainly available as CD single, in ascending order.</li>
	</ul>
	</li>
</ul>

