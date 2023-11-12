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
