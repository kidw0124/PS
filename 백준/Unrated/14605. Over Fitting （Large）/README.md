# [Unrated] Over Fitting (Large) - 14605 

[문제 링크](https://www.acmicpc.net/problem/14605) 

### 성능 요약

메모리: 2344 KB, 시간: 288 ms

### 분류

Empty

### 문제 설명

<p>요즘은 바야흐로 빅데이터 전성시대. 너도나도 머신러닝과 데이터사이언스를 배우기 위하여 노력하고 있다. 급하게 데이터마이닝과 머신러닝을 공부한 동이는 자신이 배운 내용을 바탕으로 주어진 데이터들을 분류할 수 있는 선형 분류기(Linear Classifier)를 찾는 알고리즘을 설계하고자 한다.</p>

<p>선형 분류기란 쉽게 말해서 어떤 데이터가 가지고 있는 두 특징 값(x1, x2)을 통하여 올바르게 데이터의 유형을 분류할 수 있는 직선의 방정식을 의미한다. 실제로 주어진 데이터들 사이에서 이러한 방정식 중 최적의 방정식을 자동으로 찾기 위해 수많은 알고리즘들이 개발되었다.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14604/1.png" style="height:225px; width:236px"></p>

<p style="text-align:center"><위의 데이터들은 선형 분류기를 이용해 두 그룹으로 정확히 나눌 수 있다></p>

<p>위의 예시를 보자 H1과 H2라는 직선은 두 특징 x1과 x2를 통해 흰 그룹과 검은 그룹을 완전히 분류할 수 있으므로 좋은 분류기이다. 하지만 H3은 직선만으로 두 그룹을 분류할 수 없으므로 좋은 분류기가 아니다.</p>

<p>하지만 항상 이렇게 정확하게 분류할 수 있는 선형 분류기가 존재하는 것은 아니다. 현실의 데이터들은 수많은 예외와 오차가 존재하고 이에 반해서 선형 분류기는 너무 단순하기 때문이다.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14604/2.png" style="height:211px; width:226px"></p>

<p>동이는 N명의 사람을 표현할 수 있는 두 특징값과 각 사람이 가장 좋아하는 걸그룹 정보를 수집하였다. 이를 바탕으로 동이는 두 특징값을 이용해 러블리즈를 가장 좋아하는 사람을 분류할 수 있는 선형 분류기를 찾고자 한다. 동이가 찾고자 하는 선형 분류기는 아래와 같은 조건을 만족하여야 한다.</p>

<ul>
	<li>선형 분류기는 특징값을 바탕으로 두 그룹 (Positive, Negative)으로 데이터를 분류한다.</li>
	<li>직선의 방정식을 기준으로 어떤 방향을 Positive, Negative로 분류할 것인지는 마음대로 설정할 수 있다.</li>
	<li>Positive 그룹에는 오직 러블리즈가 가장 좋다고 응답한 사람만 포함되어야 한다.</li>
	<li>Negative 그룹에 속한 사람 중 러블리즈가 가장 좋다고 응답한 사람의 수가 적을수록 좋은 선형 분류기이다.</li>
</ul>

<p>동이는 다양한 알고리즘을 도입하여 자동으로 최적의 선형분류기를 컴퓨터가 찾아낼 수 있도록 할 예정이었지만, 그 전에 자신이 가진 데이터상에서 이론적으로 위의 조건을 만족하는 최적의 선형분류기는 어느 정도의 성능을 가지는지 궁금해졌다. 그래야만 동이의 프로그램이 찾아낸 선형 분류기와 비교하여 성능 평가가 가능하기 때문이다.</p>

<p>동이가 선형 분류기를 만드는 데 사용할 데이터들이 주어질 때, 위의 조건을 만족하며 가장 좋은 선형분류기는 러블리즈를 가장 좋아하는 사람 중 몇 명을 Positive 그룹으로 분류할 수 있는지 계산하는 프로그램을 작성해주자.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14604/3.png" style="height:249px; width:276px"></p>

<p style="text-align:center"><흰 점을 가장 많이 Positive에 포함시키는 선형분류기는 L이다></p>

<p>위의 예시를 보자. 흰점이 러블리즈가 가장 좋다고 응답한 사람의 이고 검은 점이 다른 그룹이 가장 좋다고 응답한 데이터라고 하자. Positive에 흰 점을 가장 많이 포함하는 선형 분류기가 가장 좋은 분류기이므로 Lx를 설정하고 아래를 Positive, 위를 Negative로 설정하면 가장 좋은 선형 분류기가 된다. 이때 정답은 7이 된다.</p>

### 입력 

 <p>가장 첫 줄에 응답 데이터 수를 나타내는 자연수 N(6 ≤ N ≤ 5,000)이 주어진다. 이후 N줄에 걸쳐서 x1 x2 NAME 형식으로 데이터가 주어진다(-10<sup>9</sup> ≤ x1, x2 ≤ 10<sup>9</sup>, 1 ≤ Length of NAME ≤ 15). x1과 x2는 각각 그 사람의 특징을 나타내는 두 정수값이다. 그룹의 이름은 공백없이 알파벳 대문자로 주어진다.</p>

<p>러블리즈를 가장 좋아한다고 응답한 사람은 항상 그룹 이름이 “LOVELYZ”이다. 러블리즈를 가장 좋아하는 사람과 그렇지 않은 사람은 각각 최소 3명씩은 존재한다.</p>

<p>각 사람의 특징을 좌표로 2차원 평면 위에 데이터를 나타내었을 때 세 개 이상의 점이 한 직선 위에 놓이는 경우는 없다.</p>

### 출력 

 <p>최적의 선형분류기가 러블리즈를 좋아하는 사람을 Positive로 분류할 수 있는 수를 한 줄에 출력한다.</p>

