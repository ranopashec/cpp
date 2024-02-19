#include <iostream>
int main(){
    int s = 1123411;
    {
        int tmp = s;
        int arr[10];
        for (int i = 0; i < 10; ++i) {
            arr[i] = 0;
        }
        int mx = 0;
        int i = 0;
        while (tmp > 0) {
            int k = tmp % 10;
            ++arr[k];
            if (arr[k] > arr[mx]) mx = k;
            tmp /= 10;
        }
        std::cout << mx << '\n';
    }
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
            if (cnt > mx) mx = cnt, mxi = i;
        }
        std::cout << mxi << '\n';
    }
    /*
    int mx;
    _asm {
        mov ecx, 10
        mov esi, 0
        xor eax, eax
        loop1:
            

        loop initarr
    }
    std::cout << mx;
    */
	


}
