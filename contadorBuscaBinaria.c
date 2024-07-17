#include <stdio.h>

/*minha solucao utilizando o contador direto*/

int binary_search(int s[], int key, int low, int high, int* cont)
{
    int middle; /* índice do elemento central */

    if (low > high) return (-1); /* chave não encontrada */

    middle = (low+high)/2;
    if (s[middle] == key) {
        (*cont) ++;
        binary_search(s, key, low, middle-1, cont);
        binary_search(s, key, middle+1, high, cont);
    
        return middle;
    }
    if (s[middle] > key)
        return(binary_search(s, key, low, middle-1, cont));
    else
        return(binary_search(s, key, middle+1, high, cont));
        
        
};

   


int main()
{
    int v[] = {1, 2, 3, 4, 5, 6,7,7,7,7, 7, 8, 9, 10};
    int size = sizeof(v)/sizeof(v[0]);
    int cont = 0;
    
    int pos = binary_search(v, 7, 0, size-1, &cont);
    
    if (pos < 0)
        printf("elemento não encontrado\n");
    else
        printf("elemento encontrado na posição: %d, e sao tantos: %d", pos, cont);

    return 0;
}
