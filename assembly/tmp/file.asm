.386
PUBLIC _Merge1@4
PUBLIC _Merge2
PUBLIC Merge3
PUBLIC Merge4
PUBLIC @Merge5@4

.model flat
.data
.code
_Merge1@4 proc
	push ebp
	mov ebp, esp
	mov ebx, [ebp+8]
  local n:dword
	mov n, ebx
	mov ebx, [ebp+12]
 local m:dword
	mov m, ebx
	mov ebx, [ebp+16]
 local c:dword
	mov c, ebx
	mov ebx, [ebp+20]
 local ar:dword
	mov ar, ebx
	mov ebx, [ebp+24]
 local br:dword
	mov br, ebx
	mov ebx, [ebp+28]
 local answ:dword
	mov answ, ebx
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
	

	mov eax, 0
	mov esp,ebp
	pop ebp
	ret 4
_Merge1@4	endp

; *********************************************

_Merge2 proc
	push ebp
	mov ebp, esp
	mov ebx, [ebp+8]
	mov n, ebx
	mov ebx, [ebp+12]
	mov m, ebx
	mov ebx, [ebp+16]
	mov c, ebx
	mov ebx, [ebp+20]
	mov ar, ebx
	mov ebx, [ebp+24]
	mov br, ebx
	mov ebx, [ebp+28]
	mov answ, ebx
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
	
	mov eax, 0
	mov esp,ebp
	pop ebp
	ret
_Merge2	endp
; ***********************************************

Merge3 	proc stdcall, n:dword
	mov ebx, n;
    

	mov eax, 0
	ret	4
Merge3	endp
; **************************************************

Merge4 proc C, n:dword
	mov ebx, n;
    


	mov eax, 0
	ret
Merge4	endp

; ********************************************************

@Merge5@4 proc
	mov ebx, ecx;
    


	mov eax, 0
	ret
@Merge5@4	endp

end
