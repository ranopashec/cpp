# content
## [Предисловие](#preface)
## Полезное
- [Проверка введённого значения](##if-cin-fail)
## Структуры данных:
- [Linked List ADT](#linked-list)
## С лекций  БГУ: 
### задачи:
#### [Алгоритмы обработки чисел |  Алгебра](#number-processing-algorithms):
- [Поменять местами значение двух переменных](#swap-two-variables) 
- [Алгоритм Евклида | Нахождение НОД и НОК](#euclidean-algorithm) 
- [Переворачивание целого числа](#reverse-integer) 
- [Повторяемые цифры в числе](#repeated-digits-in-integer) 
- [Нахождение всех делителей натурального числа](#all-devisors) 
- [Проверка числа на простоту](#is-prime) 
- [Нахождение 3-х значных чисел без повторяющихся цифр (без использования операций деления)](#three-digit-numbers-without-repeating-digits) 
- [Вычисление квадратного корня числа по итерационной формуле с заданной точностью](#square-root-with-a-given-accuracy) 
- [Числа Мерсенна](#mersenne-numbers) 
- [Совершенные числа](#perfect-numbers) 
- [Дружественные числа](#friend-numbers) 
- [Числа Армстронга](#armstrong) `*`no implementation
- [Числа Смитта](#smitt) `*`no implementation
- [Числа Фибоначчи](#fibonachi) `*`no implementation
- Для заданного натурального числа определить количество единичных бит в его представлении
- [Переставить последнюю цифру исходного числа на место впереди первой](#set-last-digit-first)
- Перевод чисел в различные системы счисления
---
## LeetCode:
### задачи:
1. Two Sum
2. [Add Two Numbers](#lcd2-add-two-numbers)
3. [Longest Substring Without Repeating Characters](#longest-substring-without-eepeating-characters)
---
## С олимпиадных сайтов:
### топики:
- [Понятие асимптотической сложности](#asymptotic-complexity)
- [Операции по модулю](#mod)
### задачи:
- Расширенный алгоритм Евклида 
- [Длинная арифметика](#long-arithmetic)
- Факторизация(разложение на простые множители)
- Вычисление факториала по модулю
---
## С ТЫндекс группы:
### задачи и алгоритмы:
#### разное:
- Гипотеза Коллатца // done
- Разбиение строки на подстроки по заданному разделителю // done
- Валидация кредитной карты // done
- Минимальная отсутсвтующая цифра в числе // done
- [Проход про промежутку с шагом](#range) 
- [Бинарное возведение числа в степень](#bin-pow) 
-  [Длинная арифметика](#long-arithmetic) // то же, что и выше
#### std::vector
- Перемножение матриц // not done
- Обратная польская запись 
- Разворот массива 
- Удаление нулей из массива 
- Общие элементы возрастающих массивов 
- Циклический сдвиг 
- Отрицательные элементы, затем нулевые, потом положительные элементы 
- Посчитать все различные пары дающие в сумме x 
- [Вектор уникальных чисел из другого вектора](#unique) 
- [Все перестановки массива](#permutations) 
std::map
- Инвертирование мапы
#### std::string
- Счётчик разных слов
---
## preface
Спасибо каждому, кто открыл данную замечательную markdown заметку. У вас может возникнуть вопрос, зачем она вам, Я отвечу, что вы можете использовать информацию здесь по своему усмотрению. Здесь содержатся все задачи, алгоритмы решения и их реализация на c++, с которыми я столкнулся (столкнусь) за период обучения программированию. Разумеется, всё это можно найти в гугле, но никто не предоставляет подробного решения таких задач с объяснением, кроме хороших преподов. Задачи здесь будут полезны как олимпиадникам, так и тем, кто готовится к собесам. Задачи разбросаны по заметке врассыпную, структурность есть только в  [оглавлении](#content). Текст заметки подразумевает, что вы подробно ознакомлены с синтаксисом C++ и что-нибудь слышали о математике.

---
## asymptotic-complexity
[link 1](https://brestprog.by/topics/complexity/)
[link 2](https://www.geeksforgeeks.org/types-of-asymptotic-notations-in-complexity-analysis-of-algorithms/)
[link 3](https://en.wikipedia.org/wiki/Big_O_notation)

---
## number-processing-algorithms
(Алгоритмы обработки чисел)
Данные алгоритмы представляют собой скорее обычные задачи, на знание синтаксиса языка, нежели алгоритмы, но всё равно достойны вашего внимания, если вы интересуетесь математикой. Столкнуться с задачами на эти алгоритмы вы можете на первом курсе института, когда только начнёте изучать программирование.
## swap-two-variables 
#### PROBLEM:
Поменять местами значения двух переменных 
#### ALGORITHM:
Это на столько просто, что даже нельзя назвать алгоритмом. Это скорее функция, которая меняет местами значения переменных, которая даже имеется в стандартной библиотеке - [std::swap](https://en.cppreference.com/w/cpp/algorithm/swap). 
#### C++ IMPLEMENTATION:
```c++
void swap (int& x, int& y){ // & - ссылка(reference) на переменную. Необходимо передавать ссылку а не копию, чтобы изменить значение переменных.
  int temp = x;
  x = y;
  y = temp;
}
```
---
## if-cin-fail
Кусок кода, который можно использовать  для проверки введённого значения:
```cpp
while (true) { // пока мы правильно не введём переменную цикл будет продолжаться
	std::cin >> x;
	if (std::cin.fail() || "Your condition for x") {// при ошибке очищаем буфер 
		std::cin.clear();
		std::cin.ignore(99999, '\n');
	} else break;
}
```
## euclidean-algorithm
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
#### COMPLEXITY:
##### time: 
O( log(min(a,b)) ) - кол-во операций умножения

---
### reverse-integer
#### PROBLEM:
Перевернуть целое число так что если было 1234, то станет 4321
#### ALGORITHM:
#### C++ IMPLEMENTATION 
```cpp
int reverse (int num)
{
	int rnum = 0;                    // от reverse_number (перевёрнутое число)
	while (num != 0)
	{            			         // пока число не станет равным нулю мы выполняем:
		rnum = rnum * 10 + num % 10; // перевёрнутое число на каждом этапе цикла становится больше в 10 раз и складывается с остатком от деления изначального числа на 10.
		num /= 10;
	}
	return rnum;
}
```
---
### repeated-digits-in-integer
#### PROBLEM:
Найти количество повторений каждой цифры у заданного натурального числа не используя массивов.
#### ALGORITHM:
#### C++ IMPLEMENTATION:
```cpp
void repnumcount (int num){
	int tempnum = num, count = 0;
	for (int digit = 0; digit < 10; ++digit){ // пробежим по каждой цифре
	    count = 0;                            // сбросим счётчик повторов
	    num = tempnum;                        // вернём начальному числу его значение 
		while(num > 0){                       // не люблю while-loop но поясню
			if(num % 10 == digit)             // если остаток от деления числа на 10 равен цифре, то 
				count++;                      // увеличиваем счётчик,
			num /=10 ; 	                      // делим число на 10 и
		}                                     // продолжаем пока число не станет равным 0
		if(count!=0)                          // выводим счётчик для каждой цифры
		std::cout << digit << " is mentioned " << count << "times";
}
```
---
### all-devisors
#### PROBLEM:
Найти все натуральные делители целого числа
#### ALGORITHM:
Loop который пробегает по всем значениям от 2 до n/2 и проверяет, делит ли d число n нацело.
#### C++ IMPLEMENTATION 
```cpp
void foo (int n){
// d - число на которое проверяется делимость
// е - конец проверки (на середине числа)
	cout << "1" << endl; // 1 является делителем любого натурального числа

	for(int d = 2, int e = n / 2; div <= e ; d++){
	if ( n % d == 0) cout << d << endl;
	}
    
	cout << n << endl;  // само число тоже является своим же делителем
}
```

---
### is-prime
#### PROBLEM:
Создать алгоритм проверки натурального числа на простоту
#### ALGORITHM:
Чтобы проверить, является ли натуральное число x простым, достаточно просто проверить, существует ли в отрезке [2 ; √x] число, на которое делится x. Это достаточно очевидно: если бы существовало такое число y, что x делится на y и √x<y<x, то гарантированно существовало бы и число z=x/y, которое было бы меньше корня, а значит, изначального условия хватило бы для проверки на простоту. Чтобы понять это можно просто подставить числа вместо x и y, например 100 и 20.
#### C++ IMPLEMENTATION:
```cpp
bool is_prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}
```
---
### three-digit-numbers-without-repeating-digits
#### PROBLEM:
Написать алгоритм нахождения всех трёхзначных чисел, не имеющих повторяющихся чисел
#### ALGORITHM:
Всё очень просто. Для каждого числа сотен, десятков и единиц находим число, где сотни не равны десяткам, десятки единицам и единицы сотням.
#### C++ IMPLEMENTATION 
```cpp
void foo{
int hundreds, dozens, units;
for(hundreds=1;hundreds<=9;hundreds++){
	for(dozens=0;dozens<=9;dozens++){
		for(units=0;units<=9;units++){
			if( (hundreds != dozens) && (hundreds != units) && (dozens != units) ) 
			cout << hundreds*100 + dozens*10 + units << " ";
			    
		}
	}
}

}
```
---
### square-root-with-a-given-accuracy
#### PROBLEM:
Найти квадратный корень числа с заданной точностью
#### ALGORITHM:
xn = x/2 + a/(2 * x) - это просто формула, по которой находится квадратный корень с заданной точностью. Где a - accurtncy (точность) 
#### C++ IMPLEMENTATION: 

```cpp
#include <сmath> // for abs

int asqrt (double num, double acc)
{ 
	double x, xn = num / 2;
	
	do{
		x = xn;
		xn = x/2 + acc/(2 * x);
	}
	while ( abs( xn - x) > acc);

	return x;
}
```
---
### mersenne-numbers
#### PROBLEM:
Найти первые n [чисeл Мерсенна](https://www.youtube.com/watch?v=Zdqur0Cstbg)
#### ALGORITHM:
#### C++ IMPLEMENTATION
```cpp
int mersenne (int n){
	for ( int i; i <= n; i++)
		std::cout << pow(2, i) -1;
}
```
---
### perfect-numbers
#### PROBLEM:
1) Найти все [совершенные числа](https://www.youtube.com/watch?v=GuoAz5OMon8) меньше какого-то числа
2) Найти первые n совершенных чисел.
#### ALGORITHM:
bruteforce
#### C++ IMPLEMENTATION:
1) Выводит все совершенные числа, не превышающие n
```cpp
void perfectNumbers (uint64_t n)
{
	uint64_t sum = 1;
	for (uint64_t i = 6; i <= n; i++) // пробегаем по всем числам от i до n
	{
		sum = 1 ;
		for (uint64_t div = 2; div*div <= i; div++) // div от divisor(делитель)
		{
			if (i % div == 0) // если число является делителем
				sum = sum + div + (i / div); // суммируем его с предыдущими делителями
		}
		if (i == sum ) // если сумма делителей числа равна самому числу,
			std::cout << i << '\n'; //  то мы нашли то, что искали
	}
}
```
2) Выводит первых n совершенных чисел
```cpp
void perfectNumbers (int n)

{
	int c = 0; // счётчик найденных совершенных чисел
	for (uint64_t i = 6;c < n;i+=2) // пробегаем по всем числам от i до n
	{
		uint64_t sum = 1;
		for (uint64_t div = 2; div*div <= i; div++) // div от divisor(делитель)
		{
			if (i % div == 0) // если число является делителем
			sum = sum + div + (i / div); // суммируем его с предыдущими делителями
		}
		// если сумма делителей числа равна самому числу, то мы нашли совершенное число
		if (i == sum )
		{
			std::cout << i << "\n";
			c++;
		}
	} 
}
```

### friend-numbers
#### PROBLEM:
1) Найти все пары дружественных чисел, меньше числа n. 
2) Найти первые n пар дружественных чисел
#### ALGORITHM:
Дружественные - это такие два числа, каждое из которых равно сумме делителей второго. Наименьшие из дружественных чисел 220 и 284.
Воспользуемся обычным bruteforce с вложенным циклом (nested loop или цикл в цикле). Делители чисел найдём так же через цикл, как в предыдущей задаче.
#### C++ IMPLEMENTATION:
1)
```cpp
void friendNums(int64_t n)
{
	int64_t sum = 1;
	for (int64_t i1 = 220 ; i1 <= n; i1++) // пробегаем по всем числам от i до n
	{
		sum = 1 ;
		for (int64_t div = 2; div*div <= i1; div++) // div от divisor(делитель)
		{
			if (i1 % div == 0) // если число является делителем
				sum = sum + div + (i1 / div); // суммируем его с предыдущими делителями
		}
		
		int64_t i2 = i1; // добавляем счётчике для второго числа
		
		while (i2 <= n) 
		{
			++i2;
			if (i2 == sum) // среди чисел i2 > i1 находим то, которое равно сумме делителей числа i1
			{
				sum = 1 ; // аналогично суммируем его делители
				for (int64_t div = 2; div*div <= i2; div++) 
				{
					if (i2 % div == 0) 
						sum = sum + div + (i2 / div);
				}
				
				if (i1 == sum) // если i1 равно сумме делителей i2, то мы нашли нашего друга
				std::cout << i1 << " & " << i2 << '\n';
				
				break; // прерываем цикл while, цикл for продолжает поиск до n
			}
		}
	}
}
/* Можно использовать uint64_t или любой другой int в зависимости от размеров n. Чем больше int, тем дольше работает программа (использует больше памяти).
```
2) Распишу позже, но если кому нужна подсказка, то делаем всё аналогично [совершенным числам](#perfect-numbers)
### armstrong-numbers
### smith-numbers
### fibonacci-numbers
### mod
Остаток от деления числа a на m:
a mod m = a % m 
Свойства;
(a + b) mod m = ((a mod m) + (b mod m)) mod m;
(a − b) modm = ((a mod m) −(b mod m)) mod m;
(ab) mod m = ((a mod m) ∗ (b mod m)) mod m;
Доказательства всех свойств можно обнаружить в интернете.
### bin-pow
#### PROBLEM:
Возвести число a в степень n и вернуть остаток от деления результата на c. Количество операций должно быть равно log(b);
#### ALGORITHM:
Для чётного n верно: a^n = a^(n/2) * a^(n/2)
Для нечётного: a^n = a * a^(n-1).
Получаем рекурсивную формулу реализованную ниже, работающую за O(log n)
#### C++ IMPLEMENTATION:
##### Рекурсивная:
```cpp
int binpow (uint64_t a, uint64_t n, uint64_t c) {
	if (n == 0) 
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1, c) * a % c;
	else {
		uint64_t b = binpow (a, n/2, c);
		return b * b % c;
	}
}
```
##### Нерекурсивная:
```cpp
int BinPow (uint64_t a, uint64_t  b, uint64_t c )  
    uint64_t res = 1;  
    while (b){  
        if (b & 1) {  
            res *= a;  
            res %=c;  
            --b;  
        }  
        else {  
             a *= a;  
             a %= c;  
             b >>= 1;  
        }  
        }  
    return res;
```
### range
#### PROBLEM:
Создать массив, в котором находятся все числа из промежутка от from до to на прямой целых чисел с шагом step
#### ALGORITHM:
Просто пробегаем с шагом по промежутку и забрасываем числа в массив.
#### С++ IMPLEMENTATION:
```cpp
std::vector<int> range(int from, int to, int step = 1) {  
    std::vector<int> res;  
    long long i = from;  
    if ((step > 0 && from > to) || (step < 0 && from < to))  
        return res;  
  
    while ((step > 0 && i < to) || (step < 0 && i > to)) {  
        res.push_back(static_cast<int>(i));  
        i += step;  
    }  
    
    return res;  
}
```

### permutations 
#### PROBLEM:
- Необходимо создать массив массивов (динамический), который содержит все перестановки последовательности целых чисел от 0 до n - 1. 
- Задачу можно упростить: не создавать массив массивов, а просто вывести все перестановки в терминал.
#### ALGORITHM:
Подробно можно ознакомится [здесь](https://www.algotree.org/algorithms/recursive/permutations_recursion/). 
##### eng:
GeneratePermutation ( Permutation, Array, Positions )
 - If the length of Permutation equals the length of Array  
        Permutation Found.  
- Else   
        For each position ‘p’ from 0 till the length of Array  
            If element at position ‘p’ has been taken  
                Continue to check for next position.  
            Mark position ‘p’ as Taken.  
            Append the element at position ‘p’ to the Permutation.  
            GeneratePermutation ( Permutation, Array, Positions ) 
            Remove the element at position ‘p’ from the Permutation.  
            Mark position ‘p’ as Available.
##### rus:
СоздатьПерестановку (перестановка, массив, позиция)
- Если кол-во элементов перестановки равно кол-ву элементов массива, тогда перестановка найдена
- Иначе
	Для каждой позиции 'п' от первой до конца массива
		если элемент в позиции 'п' был взят
			то переходим к следущей позиции;
		иначе же помечаем позицию как занятую (взятую)
		присвайваем элемент массива в позиции 'п' перестановке
		СоздатьПерестановку (перестановка, массив, позиция
		удалить элемент в позиции 'п' из перестановки
		отметить позицию 'п' как доступную
##### Мой комментарий:
Вообще понять почему это работает не очень просто. Сложности добавляет то, что рекурсия вызывается из цикла, что немного сбивает столку. Лично у меня отсутствовало понимание того, почему это вообще раболтает, пока я не проследил построчно что происходит в дебагере.
#### C++ IMPLEMENTATION:
```cpp
#include <vector>
// вся функция подробно описана сверху
void Gen(std::vector<int>& set, std::vector<int>& perm, std::vector<bool>& pos, std::vector<std::vector<int>>& v) {
    if (perm.size() == set.size()) {
        v.push_back(perm);
    } else {
        for (int i = 0; i < static_cast<int>(set.size()); i++) {
            if (pos[i]) {
                continue;
            }
            pos[i] = true;
            perm.push_back(set[i]);
            Gen(set, perm, pos, v);
            perm.pop_back();
            pos[i] = false;
        }
    }
}
// сама функция которая возвращает массив массивов
std::vector<std::vector<int>> GeneratePermutations(size_t len) {
    std::vector<std::vector<int>> v; // создаём массив массивов
    // создаём сам массив и заполняем его от 0 до n-1
    std::vector<int> set(static_cast<int>(len));
    for (int i = 0; i < static_cast<int>(len); ++i) {
        set[i] = i;
    }
    // создаём массив для перестановки
    std::vector<int> perm;
    // создаём массив с картой занятых позиций
    std::vector<bool> pos(set.size(), false);
    // вызываем рекурсивное создание нашего массива перестановок
    Gen(set, perm, pos, v);
    return v;
}
```
---
### unique
#### PROBLEM:
Реализуйте функцию `Unique`, которая принимает отсортированный по неубыванию вектор чисел и возвращает отсортированный вектор, в котором оставлены только различные элементы исходного вектора.
#### ALGORITHM:
Обычный перебор (bruteforce)
#### С++ IMPLEMENTATION:
```cpp
std::vector<int> Unique(const std::vector<int>& data) {
	std::vector<int> v;
	if (static_cast<int>(data.size()) == 0 || static_cast<int>(data.size()) == 1) {
		return data;
	}
	for (int i = 0; i < int(data.size()) - 1; ++i) {
		if (data[i] == data[i + 1]) {
			continue;
		}
		v.push_back(data[i]);
	}
	v.push_back(data[static_cast<int>(data.size()) - 1]);
	return v;
}
```
## long-arithmetic
Длинная арифметика - набор алгоритмов для поразрядной работы с числами произвольной длины. Она применяется как с относительно небольшими числами, превышающими ограничения типа `long long` в несколько раз, так и с по-настоящему большими числами.
#### ALGORITHM:
Для работы с “длинными” числами их разбивают на _разряды_. Размер разряда может быть произвольным.
#### С++ IMPLEMENTATION:
```cpp
struct bigint { // структура, созданная для работы с длинными числами

    static const long long BASE = 1e9; // размер разряда
    static const long long SIZE = 10;  // для массива, в котором лежат разряды

    long long digits[SIZE];            // массив, содержащий разряды

    bigint() {                         // стандартный конструктор инициализирует нулями
        for (int i = 0; i < SIZE; i++) { 
            digits[i] = 0;
        }
    }

    bigint(long long x) {              // конструктор инициализирующий лонгом
        for (int i = 0; i < SIZE; i++) { // создаёт массив заполненный нулями
            digits[i] = 0;
        }

        int next = 0;
        while (x) {                    // режет лонг на разряды по 1e9
            digits[next++] = x % BASE; 
            x /= BASE;
        }
    }

    bigint(const bigint& other) {      // copy constructor
        for (int i = 0; i < SIZE; i++) {
            digits[i] = other.digits[i];
        }
    }

    bigint& operator=(const bigint& other) { // copy assign
        for (int i = 0; i < SIZE; i++) {
            digits[i] = other.digits[i];
        }

        return *this;
    }
 
    void operator+=(const bigint& other) { // перегрузка += оператора 
        for (int i = 0; i < SIZE; i++) {
            digits[i] += other.digits[i]; // поразрядно суммирует числа
        }

        for (int i = 0; i < SIZE - 1; i++) { // смотрит на наличие переполнений и добавляет 1 в следущий разряд в случае переполнения
            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                digits[i + 1]++;
            }
        }
    }

    bigint operator+(const bigint& other) { // использует предыдущую перегрузку
        bigint n(*this);
        n += other;
        return n;
    }

    bigint& operator++() {                 // использует предыдущую перегрузку
        *this += 1;
        return *this;
    }

    void operator-=(const bigint& other) { // вычитает числа
        for (int i = 0; i < SIZE; i++) {   // поразрядно вычитает числа   
            digits[i] -= other.digits[i];
        }

        for (int i = 0; i < SIZE - 1; i++) { // проверяет удалено ле больше чем возможно и перекидывает -1e9 в новый разряд
            if (digits[i] < 0) {
                digits[i] += BASE;
                digits[i + 1]--;
            }
        }
    }

    bigint operator-(const bigint& other) { // использует предыдущую перегрузку
        bigint n(*this);
        n -= other;
        return n;
    }

    bigint& operator--() {                 // использует предыдущую перегрузку
        *this -= 1;
        return *this;
    }

    void operator*=(const bigint& other) {// использует следующую перегрузку
        *this = *this * other;
    }

    bigint operator*(const bigint& other) { 
        bigint result;
// перемножим каждый разряд одного числа на каждый разряд другого. 
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - i; j++) {
// При умножении разряда i на разряд j добавим результат к разряду i+j произведения (0-индексация). 
                result.digits[i + j] += digits[i] * other.digits[j];
            }
        }
// После этого выполним переносы аналогично сложению
        for (int i = 0; i < SIZE - 1; i++) {
            result.digits[i + 1] += result.digits[i] / BASE;
            result.digits[i] %= BASE;
        }

        return result;
    }

    void operator/=(long long x) { // деление длинного числа на короткое
// делим по очереди каждый разряд длинного числа на короткое число
        for (int i = SIZE - 1; i >= 0; i--) {
// сохраняем целую часть, а остаток переносим в предыдущий (младший) разряд
            if (i) {
                digits[i - 1] += (digits[i] % x) * BASE;
            }
            digits[i] /= x;
        }
    }

    bigint operator/(long long x) { // использует предыдущую перегрузку
        bigint n(*this);
        n /= x;
        return n;
    }
};

ostream& operator<<(ostream& out, const bigint& num) { // вывод длинного числа
    string result;

    char buffer[10];

    for (int i = bigint::SIZE - 1; i >= 0; i--) {
        sprintf(buffer, "%09d", num.digits[i]);
        result += buffer;
    }

    int first_idx = result.find_first_not_of('0');
    if (first_idx == string::npos) {
        out << "0";
    } else {
        out << result.substr(first_idx);
    }

    return out;
}
```
---
## set-last-digit-first
#### PROBLEM: 
Переставить последнюю цифру исходного числа на место впереди первой. Из 789 должно получится 978.
#### ALGORITHM: 
Определить количество чисел в числе -> (i)
Прибавить последнюю цифру, умножнную на 10 в степени i - 1 к числу, делённному на 10
#### С++ IMPLEMENTATION:
```cpp
#include <iostream>
int main (){
	int n;// число
	std::cin >> n; 

// находим количество цифр в числе	
	int tmp = n;
	int i = 0 ; 
	while (tmp > 0){
		tmp /= 10; // делим временуую n на 10 пока она не станет нулём
		i++;       // и прибавляем счётчик цифр
	}
	
	n = (n / 10) + ((n % 10) * pow(10, i - 1));
	std::cout << n;

	}

```
---
## armstrong
153, 370, 371, 407, ...
n-значное число называется числом Армстронга, если оно равно сумме n-ых степеней своих цифр.

---
## smitt

Число называется числом Смита, если сумма цифр числа равна сумме цифр разложения этого числа на простые множители. Например: 4937775 - число Смита  
4937775=3 х 5 х 5 х 65837

Сумма цифр числа - 42  
Сумма цифр множителей - 42  
Числа Смита: 4, 22, 27, ...  
На интервале (0, 10 000) - 376 чисел Смита  
На интервале (0, 100 000) - около 3300 чисел Смита На интервале (0, 1 000 000) - 29928 чисел Смита Количество чисел Смита бесконечно.

---
##  fibonachi 
Число называется числом Фибоначчи, если оно является одним из членов последовательности:
fn = fn-1 + fn-2 где  
f0 = 1 и f1 = 1.

---
## linked-list
[Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/) - простейшая структура данных, представляющая собой связанные ноды (nodes). Каждая нода содержит значение и адрес следущей ноды.
### Типы linked list'ов:
- Singly Linked List

Singly Linked List - это линейная структура данных, в которой каждый элемент связан только со следующим элементом с помощью указателя. Подробную информацию по созданию этой структурки на плюсах и других языках вы найдёте по ссылке в начале страницы, я же напишу как использовать [std::forward_list](#std_forward_list)
- Doubly Linked List

Doubly Linked List - это линейная структура данных, которая содержит указатель на следующий, а также на предыдущий элемент в последовательности.
Подробную информацию по созданию этой структурки на плюсах и других языках вы найдёте по ссылке в начале страницы, я же напишу как использовать [std::list](#std_list)
- Circular Linked List

Circular Linked List - это линейная структура данных, в которой последний элемент содержит указатель на первыйэлемент списка.
- Circular Doubly Linked List

Вся инфа по ссылке выше
-  Header Linked List

Header Linked List - это особый тип связанного списка, который содержит элемент заголовка в начале списка.



---
## std_list
[std::list](https://en.cppreference.com/w/cpp/container/list)- это контейнер стандартной библиотеки c++, который используется как doubly linked list.

---
## std_forward_list
[std::forward_list](https://cplusplus.com/reference/forward_list/forward_list/)- это контейнер стандартной библиотеки c++, который используется как singly linked list.

---
## lcd2-add-two-numbers
#### PROBLEM: 
[link](https://leetcode.com/problems/add-two-numbers/description/) 
Вам даются два непустых связанных списка ( [Linked List ADT](#linked-list) ), представляющих два неотрицательных целых числа. Цифры хранятся в обратном порядке, и каждый из их узлов содержит одну цифру. Добавьте два числа и верните сумму в виде связанного списка. Вы можете предположить, что два числа не содержат ни одного ведущего нуля, за исключением самого числа 0.
#### ALGORITHM:

#### С++ IMPLEMENTATION:
```cpp
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};
 ```
##### recursive:
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// базовые случаи рекурсии, когда оба листа закончились, то возвращаем любой
        if (l1 == NULL && l2 == NULL) return l2;  
// базовые случаи рекурсии, когда один из листов закончился
        else if (l1 == NULL) return l2; // то возвращаем другой
        else if (l2 == NULL) return l1;
// суммируем два числа
        int sum = l1->val + l2->val; 
// создаём новую ноду со значением остатка от деления суммы на 10
        ListNode* p = new ListNode(sum%10);
// в следущую ноду записываем сумму следущих двух чисел (рекурсивно)
        p->next = addTwoNumbers (l1->next, l2->next);
// если сумма переполнилась, то к следущей ноде добавляем ещё и единичку 
        if(sum >= 10){
            p->next = addTwoNumbers(p->next, new ListNode(1));
        }
// возвращаем ссылку на новую ноду, которая я вляется началом рекурсивно созданного linked list'а
        return p;
	}
};
```
##### non-recursive:
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // создаём ноду, которая будет держать лист с результатом. Такое смешное название, ибо сама нода нам не нужна, нужен только указатель на следущую ноду
        ListNode* dummyHead = new ListNode();
    // создаём указатель, который будет указывать на конец листа
        ListNode* tail = dummyHead;
    // создаём переменную, которая будет держать десятки
        int carry = 0;
	// запускаем луп, который остановится, когда закончатся числа во всех листах 
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
    // создаём два инта, в которые засовываем значения из текущих нод с двух лситов, если эти ноды существуют, или ноль, если не существуют
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;
	// складываем числа и десяток из предыдущего вычисления, если он имеется
            int sum = digit1 + digit2 + carry;
    // записываем в digit остаток от деления суммы на 10
            int digit = sum % 10;
    // записываем в carry количество десятков, для следущего этапа цикла
            carry = sum / 10;
	// создаём новую ноду и закидываем в неё нашу сумму
            ListNode* newNode = new ListNode(digit);
    // говорим хвосту, что после него будет наша новая нода и перемещаем конец на неё
            tail->next = newNode;
            tail = tail->next;
	// ставим указатель на следущую ноду в листах, если они не закончились
            l1 = (l1 != nullptr) ? l1->next : nullptr
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
	// после окончания цикла возвращаем эту самую следущую после начальной (бесполезной) ноды ноду, которая и начинает наш лист с суммой
        return dummyHead->next;
    }
};
```
Если решение было вам непонятно, то рекомендую пробежать по коду с какими-нибудь числами, или поискать другие решения на странице задачи.

---
## longest-substring-without-eepeating-characters
#### PROBLEM:
Дана строка s, найти длинну самой большой подстроки без повторяющихся символов.
Ограничения:
- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.
#### ALGORITHM:\
bruteforce + pseudo hash table

#### С++ IMPLEMENTATION:
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
			if (s.empty()) return 0;  // если строка паустая, говорим, что в ней нет нужных подстрок
		  int result = 0;  // Длинна саммой большой подстроки
		  int start = 0;  // Индекс начала текущей подстроки
		  std::vector<bool> is_chars_in_substring(256); // Проверяет есть ли символ в промежутке [start, i]. В char 8-bit или 256 возможных вариантов. Также можно использовать std::unordered_set<char>, но это будет более затратно.
		  for (int i = 0; i < s.size(); ++i) { // пробегаем индексом i по всей строке
				// В промежутке [start, i] будем держать только разные символы
				// Значит s[i] не находится в [start, i-1]
			  while (is_chars_in_substring[s[i]]) { // пока символ с индексом i из строки находится в промежутке
				  chars_in_substring[s[start++]] = false; // сдвигаем левую границу промежутка вправо и стираем её значение из вектора
			  }
			  is_chars_in_substring[s[i]] = true; // забрасываем символ в вектор
			  result = std::max(result, i-start+1);	// проверяем стала ли максимальная подстрока больше
		  }
		  return result;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)
```

---
