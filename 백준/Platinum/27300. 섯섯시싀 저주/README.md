# [Platinum II] 섯섯시싀 저주 - 27300 

[문제 링크](https://www.acmicpc.net/problem/27300) 

### 성능 요약

메모리: 5180 KB, 시간: 36 ms

### 분류

수학, 기하학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>왜도(Skewness)는 대상이 얼마나 편향적으로 치우쳐 있는지 비대칭도를 의미하며 주로 통계학에서 사용한다.</p>

<p>MatKor의 기하를 담당하는 현철이는 왜도를 도형에도 적용해 도형이 얼마나 비대칭인지 확인하고 싶어 했고, 우선 삼각형에서의 왜도를 생각해 보았다.</p>

<p>비대칭도가 삼각형의 오심과 관련 있다고 생각한 현철이는 삼각형의 오심 중 수심과 무게중심이 비대칭도와 어떤 관련이 있는지 연구를 해보았다. 그 결과, 정삼각형에서 수심과 무게중심 사이의 거리는 $0$이며, 둔각 삼각형이 될수록 수심은 삼각형 외부 쪽으로 가지만 무게중심은 삼각형 내부에 존재하므로 그 사이 거리가 멀어진다는 사실을 알게 되었다. 이러한 이유로 $\triangle ABC$의 수심을 $H$, 무게중심을 $G$라 할 때, 삼각형의 왜도를 다음과 같이 정의하였다.</p>

<p>$$\triangle_{skewness}(ABC) = \overline {HG}$$</p>

<p>이제 현철이는 삼각형에서의 왜도의 정의를 다각형으로 확장하려고 생각하며 검색하다 다음과 같은 그림들을 순서대로 봤다.</p>

<table align="center" border="0" cellpadding="0" cellspacing="1" class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<td style="text-align: center;"><img alt="네모네모 멈뭄미믜 저주" src="" style="width: 362px; height: 400px;"></td>
			<td style="text-align: center;"><img alt="동글동글 엉엉이의 저주" src="" style="width: 244px; height: 400px;"></td>
			<td><img alt="섯섯시싀 저주" src="" style="width: 337px; height: 400px;"></td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">출처 : OP.GG 사이트 커뮤니티 게시물</p>

<p>결국 섯섯시싀 저주에 걸려버린 현철이는 이제 삼각형만 생각할 수 있게 되었다. 그래서 다각형의 왜도를 삼각형으로 나타내야만 한다. 다각형의 점을 $A_1, A_2, A_3, \cdots, A_n$이라고 할 때, 현철이는 다각형의 왜도를 해당 $n$개의 점으로 만들 수 있는 모든 $\binom {n}{3}$개 삼각형의 왜도의 제곱의 평균에 루트를 씌운 값으로 정의했다. 이를 수식으로 나타내면 아래와 같다.</p>

<p>$$\sqrt{{\displaystyle\sum_{1 \le i \lt j \lt k \le n} \triangle_{skewness}^2(A_iA_jA_k)}\over{\binom {n}{3}}}$$</p>

<p>원점을 중심으로 하고, 반지름이 $r$인 원 위에 서로 다른 $n$개의 점이 주어질 때, 이 $n$개의 점으로 이루어진 다각형의 왜도의 제곱값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 번째 줄에 원 위의 점의 개수 $n$ ($3\le n \le 10^5$)과 원의 반지름의 제곱을 나타내는 정수 $r^2$ ($1\le r^2 \le 10^9$)이 주어진다.</p>

<p>이후 $n$개의 줄에 원 위의 점 각각 $(x_i, y_i)$에 대해 $x_i\lvert x_i\rvert$와 $y_i\lvert y_i\rvert$ ($x_i^2+y_i^2 = r^2$, $0\le x_i^2, y_i^2 \le r^2$)를 나타내는 정수 두 개가 공백으로 구분되어 주어진다.</p>

<p>주어지는 $n$개의 점은 서로 다르다.</p>

### 출력 

 <p>첫 번째 줄에 주어진 점들로 이루어진 다각형의 왜도의 제곱값을 출력한다.</p>

<p>정답과의 절대/상대 오차는 $10^{-9}$까지 허용한다.</p>

