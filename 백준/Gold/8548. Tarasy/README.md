# [Gold IV] Tarasy - 8548 

[문제 링크](https://www.acmicpc.net/problem/8548) 

### 성능 요약

메모리: 2740 KB, 시간: 528 ms

### 분류

누적 합, 두 포인터

### 제출 일자

2024년 7월 21일 03:17:35

### 문제 설명

<p>W bajtockich górach wybudowano tarasy widokowe połączone za pomocą wind. Z tarasu położonego niżej można wjechać na taras sąsiedni, położony wyżej, za tyle kredytek ile wynosi różnica pomiędzy wysokościami tarasów. Z tarasu położonego wyżej na taras położony niżej zjeżdża się za darmo. Tarasy połączone są w łańcuch widokowy, w którym z pierwszego tarasu można dostać się tylko na drugi, z drugiego na pierwszy i trzeci, itd. Policz jaka jest największa liczba różnych tarasów, które bezpośrednio (czyli bez zjeżdżania z tarasu na ziemię) może odwiedzić turysta posiadający tylko <em>k</em> kredytek. Za wjazd na taras, od którego zacznie swoją wędrówkę, turysta nic nie płaci.</p>

### 입력 

 <p>W pierwszym wierszu podane są dwie liczby całkowite <em>n</em>, <em>k</em> (1 ≤ <em>n</em> ≤ 20 000, 0 ≤ <em>k</em> ≤ 20 000), oddzielone pojedynczym odstępem. Liczba tarasów to <em>n</em>, a <em>k</em> to liczba kredytek, którymi dysponuje turysta. W kolejnych <em>n</em> wierszach podane są wysokości kolejnych tarasów: <em>h</em><sub>1</sub>, <em>h</em><sub>2</sub>, ..., <em>h<sub>n</sub></em>. Każde <em>h<sub>i</sub></em> spełnia nierówności: 1 ≤ <em>h<sub>i</sub></em> ≤ 10 000.</p>

### 출력 

 <p>Program powinien wypisać tylko jedną liczbę, równą największej liczbie tarasów, które może odwiedzić turysta za <em>k</em> kredytek.</p>

