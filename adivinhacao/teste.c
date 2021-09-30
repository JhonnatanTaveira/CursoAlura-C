#include<cstdio>

int main()
{
    int numero;
    scanf("%d", &numero);
    for (int i = 1; i <= 10; i++){
       printf("%d x %d = %d\n", numero, i, numero*i);
    }
}