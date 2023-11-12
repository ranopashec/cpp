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
