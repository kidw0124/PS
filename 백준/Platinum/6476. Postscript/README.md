# [Platinum IV] Postscript - 6476 

[문제 링크](https://www.acmicpc.net/problem/6476) 

### 성능 요약

메모리: 3172 KB, 시간: 0 ms

### 분류

구현, 파싱, 런타임 전의 전처리, 문자열

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The year is 1976 and a small upstart company has just invented the first  (albeit crude) laser postscript printer.  They have hired you to write Release 1 of the the postscript printer's device driver.  Release 1 is very limited (with only two very limited fonts) since some nay-sayers in the industry believe that postscript printers will never take off. </p>

<p>The device driver reads in a series of commands which describe positions of text characters on the output page.  (Graphics will be in release 2.)  Each page is a 60 x 60 grid of characters.  Each grid position can contain only the following characters: </p>

<pre>ABCDEFGHIJKLMNOPQRSTUVWXYZ .* </pre>

<p>The alphabetic characters above and the blank comprise the character set of the first font (C1).  The asterisk (<code>*</code>) is the base character from which the enlarged courier font (C5) is created.  Each C5 character is defined on a 5 (rows) x 6 (columns) grid which contains either *'s or periods (.).  The C5 font characters are as follows. </p>

<pre>.***..  ****..  .****.  ****..  *****.  *****.  .****.  *...*.  *****. 
*...*.  *...*.  *...*.  *...*.  *.....  *.....  *.....  *...*.  ..*... 
*****.  ****..  *.....  *...*.  ***...  ***...  *..**.  *****.  ..*... 
*...*.  *...*.  *.....  *...*.  *.....  *.....  *...*.  *...*.  ..*... 
*...*.  ****..  .****.  ****..  *****.  *.....  .***..  *...*.  *****. 
  A       B       C       D       E       F       G       H       I 
 
..***.  *...*.  *.....  *...*.  *...*.  .***..  ****..  .***..  ****.. 
...*..  *..*..  *.....  **.**.  **..*.  *...*.  *...*.  *...*.  *...*. 
...*..  ***...  *.....  *.*.*.  *.*.*.  *...*.  ****..  *...*.  ****.. 
*..*..  *..*..  *.....  *...*.  *..**.  *...*.  *.....  *..**.  *..*.. 
.**...  *...*.  *****.  *...*.  *...*.  .***..  *.....  .****.  *...*. 
  J       K       L       M       N       O       P       Q       R 
 
.****.  *****.  *...*.  *...*.  *...*.  *...*.  *...*.  *****.  ...... 
*.....  *.*.*.  *...*.  *...*.  *...*.  .*.*..  .*.*..  ...*..  ...... 
.***..  ..*...  *...*.  .*.*..  *.*.*.  ..*...  ..*...  ..*...  ...... 
....*.  ..*...  *...*.  .*.*..  **.**.  .*.*..  ..*...  .*....  ...... 
****..  .***..  .***..  ..*...  *...*.  *...*.  ..*...  *****.  ...... 
  S       T       U       V       W       X       Y       Z     blank 
</pre>

<p>Note that the sixth column of each character contains only periods.  This is to define a natural spacing useful in strings. </p>

<p>Your device driver is to read formatting commands from an input stream and format characters from fonts C1 and C5 onto a 60x60 grid which initially contains periods in every grid postion (a blank piece of paper).  Each format command may cause the contents of any of the cell positions to change with possible overrides to cell postions.  Note that blanks from either font and empty cell positions (containing periods) from the C5 font do not overwrite the contents of cells.  It is also possible that the commands cause formatting that would be placed off of either side or the bottom; such formatting is simply truncated.  Formatting continues until an end-of-page command is reached.  </p>

<p>The input stream consists of a series of lines each containing exactly one command and its argument(s).  Each command begins in column 1 with a period and is followed by 0 to 4 arguments.  Possible input commands to your device driver are as follows. </p>

<table class="table table-bordered" style="width: 100%;">
	<thead>
		<tr>
			<th>Command</th>
			<th>Arg 1 font (F)</th>
			<th>Arg 2 row (R)</th>
			<th>Arg 3 column (C)</th>
			<th>Arg 4 string (S)</th>
			<th>Description</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>.P</code></td>
			<td>C1 | C5</td>
			<td>1 to 60</td>
			<td>1 to 60</td>
			<td>yes</td>
			<td>Place string at absolute position</td>
		</tr>
		<tr>
			<td><code>.L</code></td>
			<td>C1 | C5</td>
			<td>1 to 60</td>
			<td> </td>
			<td>yes</td>
			<td>Left-justify string on row</td>
		</tr>
		<tr>
			<td><code>.R</code></td>
			<td>C1 | C5</td>
			<td>1 to 60</td>
			<td> </td>
			<td>yes</td>
			<td>Right-justify string on row</td>
		</tr>
		<tr>
			<td><code>.C</code></td>
			<td>C1 | C5</td>
			<td>1 to 60</td>
			<td> </td>
			<td>yes</td>
			<td>Center string on row</td>
		</tr>
		<tr>
			<td><code>.EOP</code></td>
			<td> </td>
			<td> </td>
			<td> </td>
			<td>no</td>
			<td>End-of-page</td>
		</tr>
	</tbody>
</table>

<p>All commands start in column 1 of the input line and arguments (if any) will be separated by at least one space.  Each command will have exactly the arguments as prescribed in the above table.  (Input ranges/values will be adhered to and there will be no extraneous or missing arguments.)   </p>

<p>The "<code>.P</code>"/place command places a string of font F whose top left corner is at location (R, C) with the first character in the string and continues horizontally to the right across the page. </p>

<p>The "<code>.L</code>"/left justify command places a string of font F whose top left corner is at location (R, 1) with the first character in the string and continues horizontally to the right across the page. </p>

<p>The "<code>.R</code>"/right justify command places a string of font F whose top right corner is at location (R, 60) with the last character in the string and continues horizontally to the left across the page. </p>

<p>The "<code>.C</code>"/center command horizontally centers a string of font F on the page with the top row of string at row R.  If the centering cannot be exact on the grid (ie the string takes an odd number of cells horizontally), the string should be centered equally on either side of the 31st column. </p>

<p>The "<code>.EOP</code>" command signals the end of page.  This command signals your program to output/flush its internal buffer, and start formatting a new blank page with the next line of input.  You are guaranteed that "<code>.EOP</code>" is the last line/command of the input file. </p>

<p>Argument 1 indicates the font to be used in the command.  Argument 2 indicates the row (R) in which text is to be placed.  If the font is C5, then text will be placed in rows R through R+4.  Argument 3 (if included) indicates the leftmost position of a string.  Argument 4 is a string of up to 60 valid (upper case alphabetic or space) characters delimited by the '|'. </p>

### 입력 

 <p>Input to your program will consist of a series of commands and their arguments (exactly 1 per line).  You are to start with a "blank" piece of paper and read the input file formatting and flushing paper until end of file. </p>

### 출력 

 <p>With each ".EOP" command, you are to output the 60x60 grid representing the current format of the page.  In order to denote the end of page for the judges, you are to follow each outputted page with a blank line, a line of 60 dashes ( '-' ), and another blank line. </p>

