repeated-digits-in-integer
#### PROBLEM:
Найти количество повторений каждой цифры у заданного натурального числа не используя массивов.
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
