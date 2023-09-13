Ну что сказать, эта xxxня никому, кроме людей, притендующих на 10, не здалась, так как она не даёт ничего нового, а просто показывает, что вы знаете точно и сам [алгоритм](https://github.com/ranopashec/FAMCS-PROG/blob/main/ALGORITHMS/Euclidean%20algorithm.md) и C++, в частности раздел [бинарных опираторов](https://www.learncpp.com/cpp-tutorial/bitwise-operators/). Поехали!


```cpp
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL,".1251");
   	int shift;
   	int x,y,nod;
   	cout << "введите 2 числа\n";
	cin >> x >> y;

	if (x == 0 || y == 0)        // если x или y = 0
		nod = x | y;         // тогда делаем НОД равным числу, неравному 0, по факту просто складываем x и y битовым оператором или ( работает как в ДМиМЛе)
	else
	{ 			     // Тут мы просто запускаем луп, который делит x и y на 2 до момента пока хотя бы одно из них не станет нечётным.
		for (shift = 0; ((x | y) & 1) == 0; ++shift)
		{                    // (x | y) ставит единички везде, где они есть хотя бы в одном числе, 1 указывает на второй бит, и в условии проверяется, делится ли хотя бы одно из чисел на 2 без остатка. т.е луп продолжается, пока числа чётные.
         		x >>= 1;     // деление на 2
         		y >>= 1;     // деление на 2
	 	}

		while ((x & 1) == 0) // пока  x не станет нечетным
    			x >>= 1;     // делим на 2

		do{
			while ((y & 1) == 0)    // для y тоже
				y >>= 1;                // делим на 2 
	    
                                // теперь x и y оба нечетны, разность их четная
		if (x < y) { y -= x; }  // положим x = min(x,y)
		else{                   // y = разность большего и меньшегo
			unsigned int diff = x - y;
	        x = y;
	        y = diff;
}
		y >>= 1;                // y / 2
		}
	while (y != 0);             // пока y не станет равным нулю
    nod = x << shift;           // nod равен x умноженному на 2 в общей степени 2

}
   cout << "NOD=" << nod;
return 0;

}
```