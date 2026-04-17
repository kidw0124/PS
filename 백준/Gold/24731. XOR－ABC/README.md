# [Gold I] XOR-ABC - 24731 

[문제 링크](https://www.acmicpc.net/problem/24731) 

### 성능 요약

메모리: 17644 KB, 시간: 12 ms

### 분류

수학, 정수론, 조합론, 분할 정복을 이용한 거듭제곱, 모듈로 곱셈 역원, 페르마의 소정리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>$\mathrm{xor}$ 연산은 두 수의 이진수 표현에서 각 자릿수를 비교해 값이 같으면 $0$, 다르면 $1$을 계산한다.</p>

<p>다음은 $16$자리 이진수 $A=12$, $B=10$, $R = A$ $\mathrm{xor}$ $B$에 대한 예시이다.</p>

<table class="table table-bordered th-center td-center">
	<thead>
		<tr>
			<th>index</th>
			<th>16</th>
			<th>15</th>
			<th>14</th>
			<th>13</th>
			<th>12</th>
			<th>11</th>
			<th>10</th>
			<th>9</th>
			<th>8</th>
			<th>7</th>
			<th>6</th>
			<th>5</th>
			<th>4</th>
			<th>3</th>
			<th>2</th>
			<th>1</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>$A$</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td>$B$</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<td>$R$</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

<p>$A$와 $B$가 모두 $16$자리 이진수이므로, $R$ 또한 $16$자리 이진수이다.</p>

<p>$R$의 $4$번째 비트는 $A$의 $4$번째 비트와 $B$의 $4$번째 비트가 $1$로 같으므로 $0$이다.</p>

<p>$R$의 $2$번째 비트는 $A$의 $2$번째 비트와 $B$의 $2$번째 비트가 각각 $0$, $1$로 다르므로 $1$이다.</p>

<p>모든 자릿수에 대해 연산을 수행하면 $R$은 위와 같이 계산된다.</p>

<p>$K$자리 이진수 $A$ ,$B$ ,$C$에 대해 $1 \leq A < B < C \leq 2^K - 1$이고 $A$ $\mathrm{xor}$ $B = C$인 $(A,B,C)$ 쌍의 개수를 구하시오.</p>

### 입력 

 <p>첫 번째 줄에 $K$ 가 주어진다. $(2 \leq K \leq 10^{18})$</p>

### 출력 

 <p>주어진 조건을 만족하는 $(A,B,C)$ 쌍의 개수를 $1\,000\,003$으로 나눴을 때 나머지를 출력한다. 단, $1\,000\,003$은 소수이다.</p>

