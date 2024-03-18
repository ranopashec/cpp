#include <iostream>
using namespace std;
extern "C" int __stdcall Merge1(int, int, int, int*, int*, int*);
extern "C" int __cdecl Merge2(int, int, int, int*, int*, int*);
extern "C" int __stdcall Merge3(int, int, int, int*, int*, int*);
extern "C" int __cdecl Merge4(int, int, int, int*, int*, int*);
extern "C" int __fastcall Merge5(int, int, int, int*, int*, int*);

int main() {
    const int n = 5;
    const int m = 6;
    const int c = n + m;
    int* ar = new int[n]{ 1, 2, 4, 4, 5 };
    int* br = new int[m]{ 3, 5, 6, 7, 8, 9 };
    int* answ = new int[c]{ 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0};
    Merge1(n, m, c, ar, br, answ);
    for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
    std::cout << '\n';
    Merge2(n, m, c, ar, br, answ);
    for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
    std::cout << '\n';
    Merge3(n, m, c, ar, br, answ);
    for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
    std::cout << '\n';
    Merge4(n, m, c, ar, br, answ);
    for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
    std::cout << '\n';
    Merge5(n, m, c, ar, br, answ);
    for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
    std::cout << '\n';
    delete[] ar;
    delete[] br;
    delete[] answ;
    system("Pause");
    return 0;
}
