#include <iostream>
using namespace std;
//      возврашаемый тип            тип аргументов
extern "C" void __stdcall Merge1(int, int, int*, int*, int*);
extern "C" void __cdecl Merge2(int, int,  int*, int*, int*);
extern "C" void __stdcall Merge3(int, int, int*, int*, int*);
extern "C" void __cdecl Merge4(int, int, int*, int*, int*);
extern "C" void __fastcall Merge5(int, int, int*, int*, int*);

int main() {
	const int n = 5;
	const int m = 6;
	const int c = n + m;
	int ar[n]{ 1, 2, 4, 4, 5 };
	int br[m]{ 3, 5, 6, 7, 8, 9 };
	int answ[c];
  // используем статический массив!!!
	Merge1(n, m, ar, br, answ);
	for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
	std::cout << '\n';
	 Merge2(n, m, ar, br, answ);
	 for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
	 std::cout << '\n';
	 Merge3(n, m, ar, br, answ);
	 for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
	 std::cout << '\n';
	 Merge4(n, m, ar, br, answ);
	 for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
	 std::cout << '\n';
	 Merge5(n, m, ar, br, answ);
	 for (int i = 0; i < c; ++i) std::cout << answ[i] << ' ';
	 std::cout << '\n';
	return 0;
}
