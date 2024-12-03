#include <iostream>
#include <bitset>

using namespace std;

bool latch(bool relogio, bool entrada, bool &saida_anterior) {
    bool NAND1 = !(relogio && entrada);
    bool NAND2 = !(relogio && saida_anterior);
    saida_anterior = !(NAND1 && NAND2);
    return saida_anterior;
}

bitset<8> converterParaBinario(unsigned int numero_decimal) {
    return bitset<8>(numero_decimal);
}

unsigned int solicitarEntrada() {
    unsigned int numero_decimal;
    do {
        cout << "Digite um número decimal (0-255): ";
        cin >> numero_decimal;

        if (numero_decimal > 255) {
            cerr << "Erro: Número fora do intervalo permitido (0-255)." << endl;
        }
    } while (numero_decimal > 255);
    return numero_decimal;
}

bitset<8> armazenarBits(const bitset<8> &numero_binario) {
    bool saida = 0;
    bool relogio = 1;
    bitset<8> armazenado;

    for (int i = 0; i < 8; ++i) {
        armazenado[i] = latch(relogio, numero_binario[i], saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=" << numero_binario[i] << ")" << endl;
    }

    return armazenado;
}

bitset<8> recuperarBits() {
    bool saida = 0;
    bool relogio = 0;
    bitset<8> recuperado;

    for (int i = 0; i < 8; ++i) {
        recuperado[i] = latch(relogio, 0, saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=0)" << endl;
    }

    return recuperado;
}

int main() {
    unsigned int numero_decimal = solicitarEntrada();

    bitset<8> numero_binario = converterParaBinario(numero_decimal);
    cout << "Valor em binário: " << numero_binario << endl;

    cout << "\nArmazenando os bits no latch (CLK=1):" << endl;
    bitset<8> armazenado = armazenarBits(numero_binario);
    cout << "Valor armazenado pelo latch: " << armazenado << endl;

    cout << "\nRecuperando os bits do latch (CLK=0):" << endl;
    bitset<8> recuperado = recuperarBits();
    cout << "Valor recuperado do latch: " << recuperado << endl;

    return 0;
}
