#include <iostream>
#include <array>

using namespace std;

bool latch(bool relogio, bool entrada, bool &saida_anterior) {
    bool NAND1 = !(relogio && entrada);
    bool NAND2 = !(relogio && saida_anterior);
    saida_anterior = !(NAND1 && NAND2);
    return saida_anterior;
}

array<bool, 8> converterParaBinario(unsigned int numero_decimal) {
    array<bool, 8> numero_binario;
    for (int i = 0; i < 8; ++i) {
        numero_binario[7 - i] = (numero_decimal >> i) & 1;
    }
    return numero_binario;
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

array<bool, 8> armazenarBits(const array<bool, 8> &numero_binario) {
    bool saida = 0;
    bool relogio = 1;
    array<bool, 8> armazenado;

    for (int i = 0; i < 8; ++i) {
        armazenado[i] = latch(relogio, numero_binario[i], saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=" << numero_binario[i] << ")" << endl;
    }

    return armazenado;
}

array<bool, 8> recuperarBits() {
    bool saida = 0;
    bool relogio = 0;
    array<bool, 8> recuperado;

    for (int i = 0; i < 8; ++i) {
        recuperado[i] = latch(relogio, 0, saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=0)" << endl;
    }

    return recuperado;
}

void exibirBinario(const array<bool, 8> &numero_binario) {
    for (bool bit : numero_binario) {
        cout << bit;
    }
    cout << endl;
}

int main() {
    unsigned int numero_decimal = solicitarEntrada();

    array<bool, 8> numero_binario = converterParaBinario(numero_decimal);
    cout << "Valor em binário: ";
    exibirBinario(numero_binario);

    cout << "\nArmazenando os bits no latch (CLK=1):" << endl;
    array<bool, 8> armazenado = armazenarBits(numero_binario);
    cout << "Valor armazenado pelo latch: ";
    exibirBinario(armazenado);

    cout << "\nRecuperando os bits do latch (CLK=0):" << endl;
    array<bool, 8> recuperado = recuperarBits();
    cout << "Valor recuperado do latch: ";
    exibirBinario(recuperado);

    return 0;
}
