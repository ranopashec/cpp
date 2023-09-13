
xn = x/2 + a/(2 * x) - это просто формула, по которой находится квадратный корень с заданной точностью. Где a - accurtncy (точность) 

```cpp
#include <сmath> // for abs

int aqrt (double num, double acc)
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
