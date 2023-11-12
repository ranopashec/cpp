## 
#### PROBLEM:
Найти НОД(GCD) (или НОК) двух (можно и больше) чисел
#### ALGORITHM:
```The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. For example, 21 is the GCD of 252 and 105 (as 252 = 21 × 12 and 105 = 21 × 5), and the same number 21 is also the GCD of 105 and 252 − 105 = 147. Since this replacement reduces the larger of the two numbers, repeating this process gives successively smaller pairs of numbers until the two numbers become equal.``` - В изначальном виде алгоритм назывался “взаимным вычитанием”, так как заключался в поочерёдном вычитании меньшего числа из большего, пока одно из них не станет равным 0. Сегодня чаще всего вместо вычитания используется взятие остатка от деления, но суть алгоритма сохранилась.

Алгоритм заключается в построении ряда чисел следующего вида (a>b): a,b,r1,r2,…,rn, где каждое последующее число является остатком от деления предпредыдущего на предыдущее: r1 = a mod b, r2=b mod r1, … rn = rn−2 mod rn−1. Ряд заканчивается, когда остаток от деления предпоследнего числа на последнее становится равным 0:
rn−1 mod rn = 0. В таком случае утверждается, что: gcd(a,b) = rn

Доказательство:
Сначала докажем следующее: наборы общих делителей (a,b) и (b,r1) полностью совпадают:
Рассмотрим произвольный (не обязательно наибольший) общий делитель a и b:
t - общий делитель a и b.
r1 = amod b, или a = bq + r1. 
Если потерялись, то q это просто множитель, на который если домножить b и прибавить r1 получится a.

Докажем, что t также является общим делителем b и r1.
b делится на t по определению.
r1 = a − bq =t*( a/t − b/t * q), где a/t и b/t целые по определению.
Значит, r1 также делится на t, чтд

Из того, что все общие делители (a,b) и (b,r1) совпадают, в частности следует, что gcd(a,b) = gcd(b,r1).
Далее по индукции можно доказать следующее:
gcd(a,b) = gcd(b,r1) = gcd(r1,r2) =…= gcd(rn−1,rn) = gcd(rn,0)
(Нуль в последнем выражении появился из условия rn−1 mod rn = 0).
Нуль делится на все числа, отличные от нуля, поэтому справедливо следующее свойство:
gcd(x,0)=x, для любого x∈ℕ.
Следовательно, gcd(a,b) = rn, что и требовалось доказать.

Если вы ничего не поняли, не страшно, можете просто забрать документы и идти проходить курсы по figma. Ладно шучу, тут всё просто. Это всего лишь алгоритм нахождения нода, который использовали ещё в древней греции. Вам даже не обязательно знать почему это так работает, достаточно знать, что это просто работает.
#### PSEUDOCODE:
```
function gcd(a, b)
    while b ≠ 0
        t := b
        b := a mod b
        a := t
    return a
```
#### C++ IMPLEMENTATION:
##### итеративная (через loop) - cамая быстрая реализация алгоритма:

```cpp
int gcd(int a, int b) {
    if (a < b) { // этот кондишн необходим, только если мы не знаем что больше a или b, ведь нам надо, чтобы второе число было меньше.
        swap(a, b);
    }

    while (b) { // реализация отлична от псевдокода так как мы меняем местами переменные в отдельной функции swap, а не в самом цикле
        a %= b;
        swap(a, b);
    }
    return a;
}
```
##### Рекурсивная реализация:

```cpp
int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    if (b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}
```
В сущности своей рекурсия представляет собой тот же loop, только написанный через вызов самой же себя
#### Если точно a > b, то рекурсию можно записать в строчку: 

```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```
#### НОК (LCM) C++ IMPLEMENTATION:

```cpp
int lcm(int a, int b) {
    return a / gcd(a, b) * b; 
}
```
#### НОД и НОК для произвольного количества чисел

`gcd(a,b,c,d)=gcd(gcd(gcd(a,b),c),d)`
`lcm(a,b,c,d)=lcm(lcm(lcm(a,b),c),d)`
##### реализация при помощи битовых операторов
```cpp
using namespace std; // признак говнокода)
int gcd(int x, int y)
{


	if (x == 0 || y == 0)    // если x или y = 0
		nod = x | y;         // тогда делаем НОД равным числу, неравному 0, по факту просто складываем x и y битовым оператором или ( работает как в ДМиМЛе)
	else
	{ 			             // Иначе мы просто запускаем луп, который делит x и y на 2 до момента пока хотя бы одно из них чётное.
	
		for (shift = 0; ((x | y) & 1) == 0; ++shift)
		{                    // (x | y) ставит единички везде, где они есть хотя бы в одном числе, 1 указывает на второй бит, и в условии проверяется, делится ли хотя бы одно из чисел на 2 без остатка. т.е луп продолжается, пока x или y чётное.
         		x >>= 1;     // деление на 2
         		y >>= 1;     // деление на 2
	 	}

							 // луп, который делит x на 2 пока x чётное.
		while ((x & 1) == 0) 
	    	x >>= 1;     

		do                   // пока y не станет равным нулю
		{
							 // луп, который делит y на 2 пока y чётное.
			while ((y & 1) == 0)
				y >>= 1;     
							 // теперь x и y оба нечетны, разность их четная
							 
			if (x < y)       // Если x < y, 
				y -= x;      // то делаем y равным y - x
			else
			{                // иначе (если x > y), то  y = x - y
				unsigned int diff = x - y;
		        x = y;
		        y = diff;
		    }
		    
			y >>= 1;         // y / 2 т.к y стало чётным (неч-неч = чётн)
		}
		while (y != 0);            

	    nod = x << shift;    // nod равен x умноженному на 2 в степени shift, где shift равна степени двоек в x и y одновременно

}
	return nod;
}
```