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

int calcDecimal(int a, int b){
	for(int i = 0; i < 7; i++){
	    int c = a & b;
		a ^= b;
		b = c << 1;
	}
	return a;
}

int main(){
    
    int n1, n2;
    cout << "digite um numero: ";
    cin >> n1;
    
    cout << "digite o outro numero: ";
    cin >> n2;
    cout << "o primeiro numero em binario eh: " << binarioOrdenado(binario(n1),binarioBits(n1));
    cout << "\no segundo numero em binario eh: " << binarioOrdenado(binario(n2),binarioBits(n2));
    cout << "\nA soma dos decimais eh: " << calcDecimal(n1, n2);
    cout << "\nA soma em binario eh: " << binarioOrdenado(binario(calcDecimal(n1, n2)), binarioBits(calcDecimal(n1, n2)));
    

    return 0;
}
