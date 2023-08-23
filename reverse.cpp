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
    reverse(numBinario.begin(), numBinario.end());
    return  numBinario;
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
    
    cout << "o primeiro numero em binario eh: " << binario(n1);
    cout << "\no segundo numero em binario eh: " << binario(n2);
    cout << "\nA soma dos decimais eh: " << calcDecimal(n1, n2);
    cout << "\nA soma em binario eh: " << binario(calcDecimal(n1, n2));
    

    return 0;
}
