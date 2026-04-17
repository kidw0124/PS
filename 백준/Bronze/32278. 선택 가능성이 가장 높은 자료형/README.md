# [Bronze IV] 선택 가능성이 가장 높은 자료형 - 32278 

[문제 링크](https://www.acmicpc.net/problem/32278) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>선린이는 효율적으로 코딩하는 걸 좋아해서 아래와 같은 방식으로 자료형을 선택한다고 한다. 선린이가 선택할 자료형을 알아내자!</p>

<p><strong>선린이가 자료형을 선택하는 기준은 다음과 같다.</strong></p>

<ul>
	<li>정확하게 표현할 수 있으면서, 메모리를 적게 차지하는 자료형을 선택한다.</li>
	<li>선택할 수 있는 자료형은 <span style="color:#e74c3c;"><code>short</code></span>, <span style="color:#e74c3c;"><code>int</code></span>, <span style="color:#e74c3c;"><code>long long</code></span> 중 하나이다.</li>
</ul>

<table class="table table-bordered td-center td-middle table-center-60">
	<tbody>
		<tr>
			<td>자료형</td>
			<td>최솟값</td>
			<td>최댓값</td>
		</tr>
		<tr>
			<td><span style="color:#e74c3c;"><code>short</code></span></td>
			<td>
			<p>$-2^{15}$</p>

			<p>$-32,768$</p>
			</td>
			<td>
			<p>$2^{15}-1$</p>

			<p>$32,767$</p>
			</td>
		</tr>
		<tr>
			<td><span style="color:#e74c3c;"><code>int</code></span></td>
			<td>
			<p>$-2^{31}$</p>

			<p>$-2,147,483,648$</p>
			</td>
			<td>
			<p>$2^{31}-1$</p>

			<p>$2,147,483,647$</p>
			</td>
		</tr>
		<tr>
			<td><span style="color:#e74c3c;"><code>long long</code></span></td>
			<td>
			<p>$-2^{63}$</p>

			<p>$-9,223,372,036,854,775,808$</p>
			</td>
			<td>
			<p>$2^{63}-1$</p>

			<p>$9,223,372,036,854,775,807$</p>
			</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>정수 $N$이 주어진다.</p>

### 출력 

 <p>선린이가 선택할 자료형을 출력한다.</p>

