# [Gold III] ABB to BA (Hard) - 32293 

[문제 링크](https://www.acmicpc.net/problem/32293) 

### 성능 요약

메모리: 3620 KB, 시간: 20 ms

### 분류

자료 구조, 문자열, 스택

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p><strong>이 문제는 "ABB to BA"의 어려운 버전입니다. 두 버전은 $t$와 $n$의 제한을 제외하고 동일합니다.</strong></p>

<p><code>'<span style="color:#e74c3c;">A</span>'</code>와 <code>'<span style="color:#e74c3c;">B</span>'</code>만으로 이루어진 문자열 $S$가 주어집니다. 여러분은 다음 동작을 더 이상 수행할 수 없을 때까지 반복해야 합니다.</p>

<ul>
	<li>$S$에서 첫 번째로 부분 문자열 <code>"<span style="color:#e74c3c;">ABB</span>"</code>가 등장한 위치를 $i$라고 할 때, 이 위치의 부분 문자열 <code>"<span style="color:#e74c3c;">ABB</span>"</code>를 지우고 <code>"<span style="color:#e74c3c;">BA</span>"</code>로 바꿉니다.</li>
	<li>다시 말해, $S_iS_{i+1}S_{i+2}$가 <code>"<span style="color:#e74c3c;">ABB</span>"</code>인 가장 작은 $i$를 찾아, $S_i$와 $S_{i+1}$을 각각 <code>'<span style="color:#e74c3c;">B</span>'</code>와 <code>'<span style="color:#e74c3c;">A</span>'</code>로 바꾸고 $S_{i+2}$를 $S$에서 지웁니다.</li>
	<li>$S$에 <code>"<span style="color:#e74c3c;">ABB</span>"</code>가 부분 문자열로 등장하지 않는다면 동작을 수행할 수 없습니다.</li>
</ul>

<p>반복이 끝난 후 $S$의 내용을 출력하는 프로그램을 작성해 주세요.</p>

### 입력 

 <p>각 입력은 여러 개의 테스트 케이스로 구성됩니다. 입력의 첫 번째 줄에 테스트 케이스의 개수 $t$가 주어집니다. ($1 \le t \le 5 \cdot 10^4$)</p>

<p>이후 테스트 케이스의 정보가 주어지며, 각 테스트 케이스의 입력은 다음과 같이 두 줄로 구성됩니다.</p>

<ul>
	<li>첫 번째 줄에 $S$의 길이를 나타내는 정수 $n$이 주어집니다. ($1 \le n \le 5\cdot 10^5$)</li>
	<li>두 번째 줄에 길이 $n$의 문자열 $S$가 주어집니다. ($S_i$는 모두 <code>'<span style="color:#e74c3c;">A</span>'</code> 또는 <code>'<span style="color:#e74c3c;">B</span>'</code>)</li>
</ul>

<p>모든 테스트 케이스에 대한 $n$의 합이 $5\cdot 10^5$을 초과하지 않습니다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 반복이 끝난 후 $S$의 내용을 한 줄에 출력합니다.</p>

