```cpp
void foo{
int i,j,k;
for(i=1;i<=9;i++){
	for(j=0;j<=9;j++){
		for(k=0;k<=9;k++){
			if( (i != j) && (i != k) && (j != k) ) 
			cout << i*100+j*10+k << " ";
			    
		}
	}
}

}
```
