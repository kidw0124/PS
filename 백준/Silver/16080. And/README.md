# [Silver IV] And - 16080 

[문제 링크](https://www.acmicpc.net/problem/16080) 

### 성능 요약

메모리: 3236 KB, 시간: 452 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>N ба K бүхэл хоёр тоо өгөгдөнө. Таны даалгавар бол K гишүүнтэй дарааллын тоог олох юм. Дараалал нь дараах нөхцөлийг хангах ёстой. </p>

<ul>
	<li>A<sub>1</sub> + A<sub>2</sub> + A<sub>3</sub> + ... + A<sub>k</sub> = N</li>
	<li>A<sub>i+1</sub> = A<sub>i</sub> & A<sub>i+1</sub>, (хоёртын үржих буюу ба үйлдэл) i = 0,1,2,...,K-1;</li>
</ul>

### 입력 

 <p>Эхний мөрөнд тестийн тоо болох T-г илэрхийлэх эерэг бүхэл ганц тоо өгөгдөнө. (0 ≤ T ≤ 10)</p>

<p>Дараагийн Т-ширхэг мөрөнд хоёр эерэг бүхэл тоо болох K (0 ≤ K ≤ 10<sup>5</sup>) ба N (0 ≤ N ≤ 10<sup>4</sup>) тоо өгөгдөнө. </p>

### 출력 

 <p>Тест бүрийн хариуг ганц мөрөнд хэвлэнэ. Бодлогын хариу том тоо байж болох тул 10<sup>9</sup>+7хувааж үлдэгдлийг хэвлээрэй.</p>

