# [Silver V] カードの並び替え - 5599 

[문제 링크](https://www.acmicpc.net/problem/5599) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현(implementation), 시뮬레이션(simulation)

### 문제 설명

<p>1 から 2n の数が書かれた 2n 枚のカードがあり， 上から 1, 2, 3, ... , 2n の順に積み重なっている．</p>

<p>このカードを， 次の方法を何回か用いて並べ替える．</p>

<p><strong>整数 k でカット</strong></p>

<p>上から k 枚のカードの山 A と 残りのカードの山 B に分けた後， 山 A の上に山 B をのせる．</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/5599/1.png" style="height: 157px; width: 374px;"></p>

<p><strong>リフルシャッフル</strong></p>

<p>上から n 枚の山 A と残りの山 B に分け， 上から A の1枚目， B の1枚目， A の2枚目， B の2枚目， …， A の n枚目， B の n枚目， となるようにして， 1 つの山にする．</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/5599/2.png" style="height: 160px; width: 313px;"></p>

<p>入力ファイルの指示に従い， カードを並び替えたあとのカードの番号を， 上から順番に出力するプログラムを作成せよ．</p>

### 입력 

 <ul>
	<li>1 行目には n （1 ≦ n ≦ 100）が書かれている． すなわちカードの枚数は 2n 枚である．</li>
	<li>2 行目には操作の回数 m （1 ≦ m ≦ 1000）が書かれている．</li>
	<li>3 行目から m + 2 行目までの m 行には， 0 から 2n-1 までのいずれか 1 つの整数 k が書かれており， カードを並べ替える方法を順に指定している．
	<ul>
		<li>k = 0 の場合は， リフルシャッフルを行う．</li>
		<li>1 ≦ k ≦ 2n-1 の場合は， k でカットを行う．</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>2n 行からなる出力ファイルを提出せよ． 1 行目には並べ替え終了後の一番上のカードの番号， 2 行目には並べ替え終了後の上から 2 番目のカードの番号というように， i 行目には上から i 番目のカードの番号を出力せよ．</p>

