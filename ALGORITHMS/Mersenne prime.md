```cpp
{//поиск чисел Мерсенна
 int m=10;
 for (int i=1;i<=m;i++)
 {
  int r=1,x=2;
  int n=i;
  while  (n != 0)
  {
    if (n % 2 == 1) r=r*x;
    x=x*x;
    n=n/2;
  }
  r=r-1;
  cout << r << endl;
} }
```
