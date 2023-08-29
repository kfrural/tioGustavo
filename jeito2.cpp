#include <iostream>
using namespace std;

void decimalBin(int decimal) { //esponsável por converter um número decimal para sua representação binária de 8 bits
    for (int i = 7; i >= 0; i--) { // for é utilizado para loopar de 7 até 0, representando os 8 bits da representação binária.
        int bit = (decimal >> i) & 0b1; //a variável i representa a posição do bit atual.O número decimal é deslocado para a direita em i posições usando a operação de deslocamento de bits (>>).
        cout << bit; //o resultado é combinado com o valor 0b1 usando a operação de AND (&), para extrair o bit mais à direita do número decimal.
    }
}

int somaBinaria(int a, int b) { //é responsável por calcular a soma binária entre dois números inteiros
    int resultado = 0; //Duas variáveis são inicializadas: resultado para armazenar o resultado da soma binária e c para armazenar o carry (vai-um)
    int c = 0; // c representa o carry (vai um).
    while(b != 0){ //Um loop while é utilizado para realizar a soma bit a bit entre a e b até que b seja igual a zero (não há mais carry para ser adicionado).
        resultado = a ^ b; //Dentro do loop, a variável resultado é atualizada com a soma bit a bit entre a e b usando a operação de XOR (^).
        c = (a & b) << 1; //O carry (vai-um) é calculado utilizando a operação de AND (&) entre a e b, e em seguida, é deslocado para a esquerda em uma posição usando a operação de deslocamento de bits (<<).
        a = resultado; //Os valores de a e b são atualizados para resultado e c, respectivamente, para que a próxima iteração do loop possa ser realizada.
        b = c; //O loop continua até que b seja igual a zero, indicando que não há mais carry para ser adicionado.
    }
    return resultado;
}

int main(){
    
    int n1, n2;
    cout << "digite um numero: ";
    cin >> n1;
    
    cout << "digite o outro numero: ";
    cin >> n2;
    
    cout << "o primeiro numero em binario eh: ";
    decimalBin(n1);
    cout << "\no segundo numero em binario eh: ";
    decimalBin(n2);
    cout << "\nA soma dos decimais eh: " << somaBinaria(n1, n2);
    cout << "\nA soma em binario eh: ";
    decimalBin(somaBinaria(n1, n2));
    

    return 0;
}
