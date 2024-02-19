#include <iostream>
int main(){
    int s = 44455550;
    {
        int mx = 0;
        int mxi = 0;
        for (int i = 0; i < 10; ++i) {
            int tmp = s;
            int cnt = 0;
            while (tmp > 0) {
                int tmp2 = tmp % 10;
                tmp /= 10;
                if (tmp2 == i) ++cnt;
            }
            if (cnt > mx) 
                mx = cnt, 
                mxi = i;
        }
        std::cout << mxi << '\n';
    }
    {
        int mxi = 0;
        _asm{
            mov edx, 0   ; edx = mx
	        mov ecx, 10  ; loop counter
	        mov esi, 0   ; cur_i
	    Lup:
		    mov ebx, s   ; ebx = s
		    mov edi, 0   ; edi = cur_cnt
		Inlup:
		    cmp ebx, 0   ; if s <= 0
		    jle OutLup   ; end while
		    mov eax, ebx ; eax = s
            mov ebx, 10  ; ebx = 10
            push edx
            xor edx, edx ; clear edx
            div ebx      ; eax = s/10 edx = s%10 
            mov ebx, eax ; ebx = s/10
            mov eax, edx ; eax = s%10
            pop edx
		    cmp eax, esi ; if eax == esi (cur_i)
			je IncCnt    ; goto IncCnt
			jmp InLup    ; else goto InLup
		IncCnt:
			inc edi      ; ++cur_cnt
			cmp edi, edx ; if cur_cnt > mx
			jg ChangeMx  ; goto CnhangeMx
 			jmp InLup    ; else goto InLup
		ChangeMx:
			mov edx, edi ; mx = cur_cnt
			mov mxi, esi ; mxi = cur_i
		    jmp InLup
		OutLup:
		    inc esi      ; ++cur_i
	    loop Lup         ; end outer loop
        }
        std::cout << mxi;
    }
}
