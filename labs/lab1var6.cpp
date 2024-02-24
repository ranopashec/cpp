#include <iostream>

int main (){
    int n = -99991;
    int arr[10];
    _asm{
        mov ecx, 10
        mov esi, 0
    lup0:
        mov arr[4*esi], 0
        inc esi
    loop lup0
        mov ebx, n
        cmp ebx, 0
        jge lup
        mov eax, ebx
        mov ebx, -1
        imul ebx
        mov ebx, eax
    lup:
        cmp ebx, 0
        je endlup
        mov eax, ebx
        mov ebx, 10
        xor edx, edx
        div ebx
        mov ebx, eax
        inc arr[4*edx]
        jmp lup
    endlup:
        mov ecx, 0 ; i
        mov ebx, 0 ; max_i
        mov edx, 0 ; max_occ
    lup2:
        cmp ecx, 9
        jg endlup2
        mov eax, arr[4*ecx]
        cmp eax, edx
        jle skipadd
        mov ebx, ecx
        mov edx, eax
    skipadd:
        inc ecx
        jmp lup2
    endlup2:
        mov n, ebx
    }
    std::cout << n;
}
