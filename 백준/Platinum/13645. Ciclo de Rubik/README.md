# [Platinum V] Ciclo de Rubik - 13645 

[문제 링크](https://www.acmicpc.net/problem/13645) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

구현(implementation)

### 문제 설명

<p>Provavelmente todos conhecem o Cubo de Rubik, um passatempo 3-D desafiador, que tem cada uma das seis faces cobertas com nove etiquetas, cada etiqueta de uma cor (azul, amarelo, laranja, branco, verde e vermelho). No estado inicial, todas as nove etiquetas de uma face têm a mesma cor. Um mecanismo engenhoso permite que cada face seja rotacionada independentemente, fazendo com que as cores das etiquetas nas faces possam ser misturadas.</p>

<p>Cada uma das faces do Cubo de Rubik é denotada por uma letra: F, B, U, D, L, e R, como ilustrado na figura abaixo.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13645/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-05%20%EC%98%A4%ED%9B%84%209.38.48.png" style="height:207px; width:219px"></p>

<p>A rotação de uma face é denominada de um movimento. Para descrever os movimentos utilizamos as letras identificadoras das faces:</p>

<ul>
	<li>uma letra maiúscula representa um giro de 90<sup>o</sup> no sentido horário da face correspondente;</li>
	<li>uma letra minúscula representa um giro de 90<sup>o</sup> no sentido anti-horário da face correspondente.</li>
</ul>

<p>Por exemplo, F representa um giro de 90<sup>o</sup> no sentido horário da face F; r representa um giro de 90<sup>o</sup> no sentido anti-horário da face R. Uma sequência de movimentos é denotada por uma sequência de letras identificadoras de faces. Assim, rDF representa um giro de 90<sup>o</sup> no sentido anti-horário da face R, seguido de um giro de 90<sup>o</sup> no sentido horário da face D, seguido de um giro de 90<sup>o</sup> no sentido horário da face F.</p>

<p>Uma propriedade interessante do Cubo de Rubik é que qualquer sequência de movimentos, se aplicada repetidas vezes, faz com que o cubo retorne ao estado original (estado que tinha antes da primeira aplicação da sequência). Por exemplo, após quatro aplicações da sequência B o cubo retorna ao estado original.</p>

<p>Você deve escrever um programa que, dada uma sequência de movimentos, determine o menor número de aplicações completas dessa sequência para que o cubo retorne ao seu estado original.</p>

### 입력 

 <p>Cada caso de teste é descrito em uma única linha, que contém a sequência de movimentos.</p>

<p>Restrições</p>

<ul>
	<li>Cada sequência tem no mínimo um movimento e no máximo 80 movimentos.</li>
</ul>

### 출력 

 <p>Para cada caso de teste seu programa deve imprimir uma única linha, contendo um único inteiro, indicando o menor número de aplicações completas da sequência para que o cubo retorne ao seu estado original.</p>

