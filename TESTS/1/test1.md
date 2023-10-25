# Вариант 1
## 1)
Указатель на функцию
```cpp
char (*c)(int p2); // b)
```
## 2) 
очев. 
## 3)
[photo](https://github.com/ranopashec/FAMCS-PROG/blob/main/TESTS/1/photo_2023-10-23_17-48-44.jpg)
## 4) 
Целой переменной S присвоить значение минимальной цифры целого числа:
```cpp
int main(){
	int S = 9; // минимальная цифра
	int num; // число
	std::cin >> num;
	for (int i = 1; num > 0; num /= 10 ){
		S = (S < num % 10) ? S : num % 10;
	}
	std::cout << S;
}
```
## 5)
Написать функцию для вычисления у=3x6x9x...3n
```cpp
int foo(int n){
	if (n == 1){ // база рекурсии
		return 3;
	}
	return 3 * n * foo(n -1);
}
```
## 6)
Написать рекурсивную функцию для вычисления N-го числа Фибоначчи.
Число называется числом Фибоначчи, если оно является одним из членов последовательности:
fn = fn-1 + fn-2 где  
f0 = 1 и f1 = 1.
```cpp
int fib(int n){
	if (n == 1){
	return 0;
	}
	if (n == 2){
	return 1;
	}
	return fib(n - 1) + fib (n - 2);
}
```
## 7)
Написать фрагмент программы подсчета количества нечетных натуральных трехзначных чисел.
сумма цифр которых меньше N (2<=N<=27). Операции деления не использовать. Предусмотреть проверку значения N.
```cpp
#include <iostream>  

int main(){  
    int n = 1; // число  
    do{  
        std::cout << "enter n: ";  
        std::cin >> n;  
    } while (!(n <= 27 && n >= 2));  
    int cnt = 0;  
    for (int i = 1; i <= 9; i ++){  
        for (int j = 0; j <= 9; j ++){  
            for (int k = 1; k <= 9; k += 2){  
                int num = (100 * i) + (10 * j) + k;  
                int sum = i + j + k;  
                if (sum < n){  
                    cnt++;  
                }  
            }  
        }  
    }  
    std::cout << '\n' << cnt;  
}
```
## 8)
Написать программу, в которой исходный статический массив заполнить случайным образом элементами в пределах от 200 до 300. Вывести на экран.
Не используя дополнительного массива, расположить элементы массива и обратном порядке. Вывести результат на экран.
```cpp
#include <iostream>  
  
int main() {  
    const int n = 20;  
    int arr[n];  
    for (int i = 0; i < n; ++i) {  
        arr[i] = 200 + int(random()) % ((300 + 1) - 200);  
        std::cout << arr[i] << ' ';  
    }  
    std::cout << '\n';  
    for (int i = 0; i < n / 2; ++i) {  
        int tmp = arr[i];  
        arr[i] = arr[n - i - 1];  
        arr[n - i - 1] = tmp;  
    }  
    for (int i = 0; i < n; ++i) {  
        std::cout << arr[i] << ' ';  
    }  
    return 0;  
}
```
## 9)
Написать функцию нахождения скалярного произвеления днух пекторол, образованных элементами главной и побочной диагоналей квадратной матрины размерности\
```cpp
int skalar(int **matr, int n) {  
    int sum = 0;  
    for (int i = 0, a = n - 1; i < n; ++i, --a) {  
        sum += (matr[i][i] * matr[i][a]);  
    }  
    return sum;  
}
```
## 10)
Написать фрагмент программы для формирования и вывода на экран статической матрицы: 
10000  
02000  
00300  
00040  
00005

```cpp
#include <iostream>  
  
int main() {  
    int matr[5][5];  
    for (int i = 0; i < 5; ++i) {  
        for (int j = 0; j < 5; ++j) {  
            if (i == j) {  
                matr[i][j] = i + 1;  
            } else {  
                matr[i][j] = 0;  
            }  
            std::cout << matr[i][j] << ' ';  
        }  
        std::cout << '\n';  
    }  
}
```
## 11)
Написать фрагмент программы вывода на экран динамической матрицы:  
    n n ... n n
    ..............
    3 3 3  
    2 2
    1
```cpp
#include <iostream>  
  
void vivod(int n) {  
    if (n == 1) {  
        std::cout << 1 << '\n';  
        return;  
    }  
    for (int i = 0; i < n; i++) {  
        std::cout << n << ' ';  
    }  
    std::cout << '\n';  
    vivod(n - 1);  
}  
  
int main() {  
    int n;  
    std::cin >> n;  
    vivod(n);  
}
```
## 12)
Написать фрагмент программы преобразования одномерного массива целых чисел по следующему правилу: первый и последний элементы оставить без изменения, а все остальные заменить, суммой их соседей.
```cpp
#include <iostream>  
  
int main() {  
    int n = 20;  
    int arr[n];  
    int arr_copy[n];  
    for (int i = 0; i < n; i++) {  
        int num;  
        std::cin >> num;  
        arr[i] = num;  
        arr_copy[i] = num;  
    }  
    for (int i = 1; i < n - 1; i++) {  
        arr[i] = arr_copy[i - 1] + arr_copy[i + 1];  
    }  
}
```
## 13)
Написать программу нахождения номера столбца прямоугольной матрины с максимальным значением отрицательного элемента (чзх не понял просто максимального отрицательного?). Если таких столбцов несколько, брать первый.
```cpp
int index_min = 0;
int min_num = -9999; // надо писать numeric_limits, но мы вроде не проходили
for (int j = n - 1; j >= 0; --j) { // матрица mxn, m - номер строки, n - номер столбца
	for(int i = 0; i < m; ++j){
		if (matr[i][j] >= min_num && matr[i][j] < 0 ){
			min_num = matr[i][j];
			index_min = j;
		} 
	}
}
```
## 14) 
Нарисовать блок-схему слияния двух упорядоченных по ублаванно массивов вешественных чисел.

# Вариант 2 (от tg: @pro_100_vova)

/// TASK 1 /// 
a) Если после фор стоит ; то ошибку, иначе: 
i=0
i=1
i=2
i=3
i=4

b) 0103040

c) ничего не выведет

d) yes

/// TASK 2 ///
c) const char* pc3 (указатель на константу, константный указатель: char* const pc3)

/// TASK 3 ///
double(*func)(double* m, int size);

/// TASK 4 ///
```cpp
/// TASK 5 ///
int sum_k (int k) {
    int res = 0;
    res += k % 10;
    while (k > 9) {
        k /= 10;
    }
    res += k;
    return res;
}
```

/// TASK 6 ///
```cpp
int rec_sum(int k) {
    if (k < 10)
    {
        return k;
    } else {
        return k % 10 + rec_sum(k / 10);
    }
}
```


/// TASK 7 ///
```cpp
    int N = 5;
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k += 2){
                if (i + j + k == N) {
                    sum++;
                }
            }
        }
    }
```

/// TASK 8 ///
```cpp
    const int n = 8;
    int m[n];
    for (int i = 0; i < n; i++) {
        m[i] = rand() % (300 - 150 + 1) + 150;
    }

    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i < n / 4; i++) {
        swap(m[i], m[n / 2 - 1 - i]);
    }

    for (int i = n / 2; i < n / 2 + n/ 4; i++) {
        swap(m[i], m[n - 1 - i + n / 2]);
    }

    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
```

/// TASK 9 ///
```cpp
    int matrix[5][5];
    for(int i = 1; i <= 5; i++) {
        for (int k = 0; k < 5 - i; k++) {
            *(*(matrix + i - 1) + k) = 0;
        }
        *(*(matrix + i - 1) + 5 - i) = i * i;
        for (int m = 6 - i; m < 5; m++) {
            *(*(matrix + i - 1) + m) = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << setw(2) << right << *(*(matrix + i) + j) << ' ';
        }
        std::cout << std::endl;
    }
```

// TASK 10 ///
```cpp
    int n = 5;
    int **matrix;
    matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            *(*(matrix + i - 1) + j) = n - i + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << *(*(matrix + i - 1) + j) << ' ';
        }
        std::cout << std::endl;
    }
```
/// TASK 11 ///
//by ranopashec
```cpp
    int n = 10;
    int arr[n];
    int arr_copy[n];
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        arr[i] = num;
        arr_copy[i] = num;
    }
    for (int i = 1; i < n - 1; i++) {
        arr[i] = arr_copy[i - 1] + arr_copy[i + 1];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    ```

/// TASK 12 ///
```cpp
    int minn = -1; int row = 0
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < nSize; j++) {
            if ((*(*(matrix + i) + j)) > 0 && ((*(*(matrix + i) + j)) < minn || mmin == - 1)) {
                mmin = (*(*(matrix + i) + j));
                row = i;
            }
        }
    }
    if (minn == -1) {
        cout << "there are no positive";
    } else {
        cout << row;
    }
```
