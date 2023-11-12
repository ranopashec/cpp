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
