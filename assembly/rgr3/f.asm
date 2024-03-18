     .386
	 PUBLIC _Merge1@20
	 PUBLIC _Merge2
     PUBLIC Merge3
	 PUBLIC Merge4
	 PUBLIC @Merge5@20

	.model flat
	.data
	.code

	_Merge1@20 proc 
	        local n:dword,
			m:dword,
			cn:dword,
			ar:dword,
			br:dword,
			answ:dword

		mov eax, [ebp+8]
		mov n, eax
		mov eax, [ebp+12]
		mov m, eax
		add eax, n
		mov cn, eax
		mov eax, [ebp+16]
		mov ar, eax
		mov eax, [ebp+20]
		mov br, eax
		mov eax, [ebp+24]
		mov answ, eax

		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, br
		mov ebx, [edx+edi*4]
		cmp eax, ebx
		jl adda
		mov edx, answ
		mov [edx+ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov edx, answ
		mov [edx+ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge endend
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, cn
	    jge endend
		cmp edi, m
		jge endend
		mov edx, br
		mov eax, [edx+edi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
			ret 20
			_Merge1@20 endp

			
	;//////////////////////////////////////////////////////////////////

	_Merge2 proc
			local n:dword,
			m:dword,
			cn:dword,
			ar:dword,
			br:dword,
			answ:dword

		mov eax, [ebp+8]
		mov n, eax
		mov eax, [ebp+12]
		mov m, eax
		add eax, n
		mov cn, eax
		mov eax, [ebp+16]
		mov ar, eax
		mov eax, [ebp+20]
		mov br, eax
		mov eax, [ebp+24]
		mov answ, eax

		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, br
		mov ebx, [edx+edi*4]
		cmp eax, ebx
		jl adda
		mov edx, answ
		mov [edx+ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov edx, answ
		mov [edx+ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge endend
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, cn
	    jge endend
		cmp edi, m
		jge endend
		mov edx, br
		mov eax, [edx+edi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
			ret
			_Merge2 endp

	Merge3   proc stdcall, n:dword, m:dword, ar:dword, br:dword, answ:dword
		local cn:dword
		mov eax, n
		add eax, m
		mov cn, eax
	
		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, br
		mov ebx, [edx+edi*4]
		cmp eax, ebx
		jl adda
		mov edx, answ
		mov [edx+ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov edx, answ
		mov [edx+ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge endend
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, cn
	    jge endend
		cmp edi, m
		jge endend
		mov edx, br
		mov eax, [edx+edi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
			ret 
			Merge3 endp

			;/////////////////////////

			Merge4   proc C, n:dword, m:dword, ar:dword, br:dword, answ:dword
		local cn:dword
		mov eax, n
		add eax, m
		mov cn, eax
	
		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, br
		mov ebx, [edx+edi*4]
		cmp eax, ebx
		jl adda
		mov edx, answ
		mov [edx+ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov edx, answ
		mov [edx+ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge endend
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, cn
	    jge endend
		cmp edi, m
		jge endend
		mov edx, br
		mov eax, [edx+edi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
			ret 
			Merge4 endp

	;//////////////////////////////////////////////////////////

	@Merge5@20 proc
			local n:dword,
			m:dword,
			cn:dword,
			ar:dword,
			br:dword,
			answ:dword

		mov eax, ecx
		mov n, eax
		mov eax, edx
		mov m, eax
		add eax, n
		mov cn, eax
		mov eax, [ebp+8]
		mov ar, eax
		mov eax, [ebp+12]
		mov br, eax
		mov eax, [ebp+16]
		mov answ, eax

		mov ecx, 0 ; arr index
		mov esi, 0 ; a index
		mov edi, 0 ; b index
	lup:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge lupb
		cmp edi, m
		jge lupa
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, br
		mov ebx, [edx+edi*4]
		cmp eax, ebx
		jl adda
		mov edx, answ
		mov [edx+ecx*4], ebx
		inc ecx
		inc edi
		jmp lup
	adda:
		mov edx, answ
		mov [edx+ecx*4], eax
		inc ecx
		inc esi
		jmp lup
	lupa:
	    cmp ecx, cn
	    jge endend
		cmp esi, n
		jge endend
		mov edx, ar
		mov eax, [edx+esi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc esi
		inc ecx
		jmp lupa
	lupb: 
	    cmp ecx, cn
	    jge endend
		cmp edi, m
		jge endend
		mov edx, br
		mov eax, [edx+edi*4]
		mov edx, answ
		mov [edx+ecx*4], eax
		inc edi
		inc ecx
		jmp lupb
	endend:
	    xor edx, edx
	    ret 12
	@Merge5@20 endp
	end