#include <iostream>

int main(){
    const int n = 5;
    const int m = 6;
    const int c = n + m;
    int ar[n] = {1, 2, 4, 4, 5};
    int br[m] = {3, 5, 6, 7, 8, 9};
    int answ[c] = {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0,0 };
	_asm{
		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, c
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov eax, ar[esi*4]
		mov ebx, br[edi*4]
		cmp eax, ebx
		jl adda
		mov answ[ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov answ[ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, c
	    jge endend
		cmp esi, n
		jge endend
		mov eax, ar[esi*4]
		mov answ[ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, c
	    jge endend
		cmp edi, m
		jge endend
		mov eax, br[edi*4]
		mov answ[ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
	}
    for(int i = 0; i < n+m; ++i){
	    std::cout << answ[i] << ' ';
    }
	return 0;
}
