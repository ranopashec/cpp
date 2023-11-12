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
