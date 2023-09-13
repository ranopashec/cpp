Найти количество повторений каждой цифры у заданного натурального числа
(не используя массивов).
```cpp
void repnumcount (int num){
	int tempnum = num, count = 0;
	for (int digit = 0; digit < 10; ++digit){
	    count = 0;
	    num = tempnum;
		while(num > 0){
			if(num % 10 == digit) 
				count++; 
			num /=10 ; 	
		}
		if(c!=0) 
		std::cout << digit << " is mentioned " << count << "times";
}
```
