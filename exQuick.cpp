
#include <iostream>
using namespace std;

// Função de particionamento
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Escolhe o último elemento como pivô
    int i = (low - 1);        // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor que o pivô
        if (arr[j] < pivot) {
            i++;    // Incrementa o índice do menor elemento
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort2(int arr[], int low, int high, int meio){
    if(low < high){
        int pi = partition(arr, low, high);
         if (pi == meio){
                cout << "Mediana :"<< arr[pi];
        } else if (pi < meio) {
            quickSort2(arr, pi + 1, high, meio);
        } else {
            quickSort2(arr, low, pi - 1, meio);
        }
    }
}



void quickSort(int arr[], int low, int high, int meiinho, int meiao) {
    int mediana2, mediana1;
        
        if (low < high) {
        // pi é o índice de particionamento, arr[pi] está no lugar certo agora
        int pi = partition(arr, low, high);
        if(pi == arr[meiinho]){
            mediana1 = arr[meiinho];
            partition(arr, low, high-1);
            if(pi == arr[meiao]){
                mediana2 = arr[meiao];
            } else if (pi > meiinho) {
                quickSort(arr, pi + 1, high, meiinho, meiao);
            } else {
                quickSort(arr, low, pi - 1,meiinho, meiao);
            }
        }
            cout << "A mediana :" << (mediana1 + mediana2) / 2;
        
    }
    
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5, 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);//
    int meio= n /2;
    
    if ( n % 2 == 0){
        int meiao = meio + 1;
        int meiinho = meio - 1;
        quickSort(arr, 0, n-1, meiinho, meiao);
    } else {
        quickSort2(arr, 0, n - 1, meio);
    }

    
    return 0;
}
