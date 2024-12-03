#include <iostream>
#include <vector>

using namespace std;

bool latch(bool relogio, bool entrada, bool &saida_anterior) {
    bool NAND1 = !(relogio && entrada);
    bool NAND2 = !(relogio && saida_anterior);
    saida_anterior = !(NAND1 && NAND2);
    return saida_anterior;
}

vector<bool> converterParaBinario(unsigned int numero_decimal, size_t tamanho) {
    vector<bool> numero_binario(tamanho);
    for (size_t i = 0; i < tamanho; ++i) {
        numero_binario[tamanho - 1 - i] = (numero_decimal >> i) & 1;
    }
    return numero_binario;
}

unsigned int solicitarEntrada(unsigned int limite_superior) {
    unsigned int numero_decimal;
    do {
        cout << "Digite um número decimal (0-" << limite_superior << "): ";
        cin >> numero_decimal;

        if (numero_decimal > limite_superior) {
            cerr << "Erro: Número fora do intervalo permitido (0-" << limite_superior << ")." << endl;
        }
    } while (numero_decimal > limite_superior);
    return numero_decimal;
}

vector<bool> armazenarBits(const vector<bool> &numero_binario) {
    bool saida = 0;
    bool relogio = 1;
    vector<bool> armazenado(numero_binario.size());

    for (size_t i = 0; i < numero_binario.size(); ++i) {
        armazenado[i] = latch(relogio, numero_binario[i], saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=" << numero_binario[i] << ")" << endl;
    }

    return armazenado;
}

vector<bool> recuperarBits(size_t tamanho) {
    bool saida = 0;
    bool relogio = 0;
    vector<bool> recuperado(tamanho);

    for (size_t i = 0; i < tamanho; ++i) {
        recuperado[i] = latch(relogio, 0, saida);
        cout << "latch(CLK=" << relogio << ", Q=" << saida
             << ", D=0)" << endl;
    }

    return recuperado;
}

void exibirBinario(const vector<bool> &numero_binario) {
    for (bool bit : numero_binario) {
        cout << bit;
    }
    cout << endl;
}

int main() {
    const size_t TAMANHO_BITS = 8;
    const unsigned int LIMITE_SUPERIOR = (1 << TAMANHO_BITS) - 1; // 2^8 - 1 = 255

    unsigned int numero_decimal = solicitarEntrada(LIMITE_SUPERIOR);

    vector<bool> numero_binario = converterParaBinario(numero_decimal, TAMANHO_BITS);
    cout << "Valor em binário: ";
    exibirBinario(numero_binario);

    cout << "\nArmazenando os bits no latch (CLK=1):" << endl;
    vector<bool> armazenado = armazenarBits(numero_binario);
    cout << "Valor armazenado pelo latch: ";
    exibirBinario(armazenado);

    cout << "\nRecuperando os bits do latch (CLK=0):" << endl;
    vector<bool> recuperado = recuperarBits(TAMANHO_BITS);
    cout << "Valor recuperado do latch: ";
    exibirBinario(recuperado);

    return 0;
}
