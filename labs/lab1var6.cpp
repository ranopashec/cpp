#include <iostream>

int main (){
    int n = 100001;
    int arr[10];
    _asm{
        mov ebx, n
        mov eax, n
        shr eax, 31
        xor ebx, eax
        sub ebx, eax
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
