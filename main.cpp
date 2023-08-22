#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binario(int n){
    string numBinario = " ";
    
    while(n > 0){
        int resto =  n % 2;
        numBinario += to_string(resto);
        n /= 2;
    }
    
    return  numBinario;
}

int binarioBits(int n){
    string numBinario = " ";
    
    while(n > 0){
        int resto =  n % 2;
        numBinario += to_string(resto);
        n /= 2;
    }
    cout << numBinario << endl;
    return  numBinario.length()-1;
}

string binarioOrdenado(string binario, int binarioBits){
    char ordenacao[binarioBits];
    int j = 0;
    for(int i = binarioBits; i > 0; i--){
        ordenacao[j] = binario[i];
        j++;
    }
    return ordenacao;
    
}

int main(){
    
    int n1, n2;
    cout << "digite um numero: ";
    cin >> n1;
   // cout << "digite o outro numero: ";
   // cin >> n2;
   // cout << binario(n1) << endl;
    //cout << binario(n2);
    binarioBits(n1);
    //cout <<binarioOrdenado(binario(n1),binarioBits(n1));
    

    return 0;
}
