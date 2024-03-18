     .386
	 PUBLIC _Merge1@20 ; ПОСЛЕ СОБАКИ СКОЛЬКО БАЙТ ЗАНИМАЮТ АРГУМЕНТЫ
	 PUBLIC _Merge2
     PUBLIC Merge3
	 PUBLIC Merge4
	 PUBLIC @Merge5@20 ; ПОСЛЕ СОБАКИ СКОЛЬКО БАЙТ ЗАНИМАЮТ АРГУМЕНТЫ

	.model flat
	.data
	.code

	_Merge1@20 proc ; 20 = 4 * 5 так как у меня 5 аргументов
        ; ------------------------------ дальше код моей задачи, который вам надо поменять

					; ВО ВСЕХ ПРОЦЕДУРАХ СОЗДАËМ ЛОКАЛЬНУЮ 
 					; ПЕРЕМЕННУЮ ЧТОБЫ НЕ ПИСАТЬ ПРОЛОГИ ЭПИЛОГИ
	        local n:dword,
			m:dword,
			cn:dword,
			ar:dword,
			br:dword,
			answ:dword
					; АРГУМЕНТЫ ПРИХОДЯТ ИЗ СТЭКА НАЧИНАЯ С [EBP+8]
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
		mov eax, [edx+esi*4]      ; ЗАМЕТЬТЕ НЕЛЬЗЯ ОБРАЩАТЬСЯ К МАССИВУ НЕ ЧЕРЕЗ РЕГИСТР
 					  ; ТОЛЬКО ВОТ ТАК КАК ТУТ МОЖНО
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
	; ------------------------
			ret 20     	; 20 = 4 * кол-во аргументов
			_Merge1@20 endp ; 20 = 4 * кол-во аргументов

			
	;//////////////////////////////////////////////////////////////////

	_Merge2 proc			; ТО ЖЕ САМОЕ только В ret ничего не пишем и никаких цифр с собачками
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

;//////////////////////////////////////////////////////////////////
; ТУТ АРГУМЕНТЫ ПИШЕМ СРАЗУ ВВЕРХУ, но не забываем создать local переменную чтобы не париться с прологом эпилогом
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
;//////////////////////////////////////////////////////////////////
; ТО ЖЕ САМОЕ, только другой тип фунцкции в c++ файле и в объявлении

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

//////////////////////////////////////////////////////////////////
; Как и в 1, но первые два аргументы лежат в ecx и еdx
	@Merge5@20 proc ; 20 = 4 * кол-во аргументов
			local n:dword,
			m:dword,
			cn:dword,
			ar:dword,
			br:dword,
			answ:dword

		mov n, ecx
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
	    ret 12 ; 12 = 4 * (кол-во аргументов - 2)
	@Merge5@20 endp ; 20 = 4 *  кол-во аргументов
	end
