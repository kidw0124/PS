# [Platinum I] Tobacco Growing - 23096 

[문제 링크](https://www.acmicpc.net/problem/23096) 

### 성능 요약

메모리: 5228 KB, 시간: 20 ms

### 분류

수학, 애드 혹, 해 구성하기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>In the city, there is a beautiful park full of blossoming flowers. This park is very popular among citizens and especially families with children are common visitors. The gangsters want to extend their criminal activities to this area, mainly in the tobacco production. They decided to secretly plant tobacco seeds in the park and let it grow right under policemen noses. When the time is right, they plan to harvest as much tobacco as possible in a single operation and smuggle it over borders.</p>

<p>The park consists of flower tiles with coordinates ranging from −10<sup>6</sup> to 10<sup>6</sup> in either direction. A tile on coordinates (X, Y) neighbors with tiles on coordinates (X + 1, Y), (X − 1, Y), (X, Y + 1) and (X, Y − 1) (within coordinates range). On the first day, the gangsters may cut the flowers on any of the tiles. Also only on the first day, if a tile is cut, the gangsters may either plant a tobacco on it, or let the tile contain only grass. In the beginning, the tobacco quantity on a tile with tobacco is 1 and the tobacco quantity on a tile with grass or on a tile with flowers is 0. Local tobacco spreads rather aggressively, and so on each consecutive day, the tobacco quantity on park tiles grows as follows:</p>

<ul>
	<li>Tobacco quantity on tiles with tobacco and grass is increased by the sum of tobacco quantity on the neighboring tiles on the previous day.</li>
	<li>Tobacco quantity on tiles with flowers always remains 0.</li>
</ul>

<p>After some days of growing, the harvest operation will take place on a particular day. The gangsters will choose some of the tiles (of any type) to be harvested and obtain the total tobacco quantity on such tiles on that day. Each tile may be harvested at most once and all tobacco quantity on a chosen tile must be harvested. The gangsters can’t harvest everything, because there is a limit on the tobacco quantity that can be somewhat safely smuggled. At the same time, the gangsters do not want to take any unnecessary losses and so they want to harvest exactly the limit amount.</p>

<p>The task is to help the gangsters to plan the operation to the very detail. That is in particular:</p>

<ol>
	<li>For the first day, choose flower tiles to be cut, and from these choose tiles to plant tobacco on. At most 2 · 10<sup>5</sup> flower tiles may be cut, to not raise suspicion among policemen.</li>
	<li>Choose the number of days to keep tobacco growing. The number of days must be at most 100 to not make this tobacco business blatantly obvious.</li>
	<li>Choose tiles to be harvested after the given number of days pass. At most 10<sup>4</sup> tiles may be harvested, as any more would take the gangsters too much time.</li>
</ol>

<p>Will you manage to help the gangsters? Good luck!</p>

### 입력 

 <p>The input contains a single line with an integer N (0 ≤ N ≤ 10<sup>18</sup>), the exact tobacco quantity to be harvested.</p>

### 출력 

 <p>On the first line, print the number C (0 ≤ C ≤ 2 · 10<sup>5</sup>) of cut flower tiles. For each such tile, output a line in the form of either X Y 1 for a cut tile with integer coordinates (X, Y) and with a planted tobacco, or X Y 0 for a cut tile left as a grass area (−10<sup>6</sup> ≤ X, Y ≤ 10<sup>6</sup>).</p>

<p>Afterwards print a line with two space separated numbers H and D (0 ≤ H ≤ 10<sup>4</sup>, 0 ≤ D ≤ 100), the number of harvested fields and the number of days for tobacco to grow, respectively. Then print H lines with two space separated integers X and Y (−10<sup>6</sup> ≤ X, Y ≤ 10<sup>6</sup>), the coordinates of tiles to be harvested after D days.</p>

