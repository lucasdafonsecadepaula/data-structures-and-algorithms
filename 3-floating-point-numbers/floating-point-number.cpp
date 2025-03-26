#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <cstdint>
using namespace std;

// Estrutura dos números de ponto flutuante
// Um número de ponto flutuante em IEEE 754 é composto por:
// - 1 bit de sinal (0 para positivo, 1 para negativo)
// - 8 bits de expoente (para determinar a escala do número)
// - 23 bits de mantissa (ou fração), que armazena a precisão do número

// Função para exibir os bits de um número float
// Isso ajuda a entender como o número é representado internamente em IEEE 754
void printFloatBits(float number)
{
    union
    {
        float f;
        uint32_t i;
    } u;
    u.f = number;
    cout << "Bits: " << bitset<32>(u.i) << "\n";
}

int main()
{
    // Definição de variáveis float
    float a = 0.1f;
    float b = 0.2f;
    float c = a + b;

    // Configuração para exibir mais casas decimais e visualizar melhor as diferenças
    cout << fixed << setprecision(10);

    // Exibição do resultado da soma
    cout << "0.1 + 0.2 = " << c << "\n";

    // Comparação direta de igualdade, que geralmente falha devido a erros de precisão
    cout << "0.1 + 0.2 == 0.3 ? " << (c == 0.3f ? "true" : "false") << "\n\n";

    // Exibição da representação binária dos números envolvidos
    cout << "Representação em bits:\n";
    cout << "0.1: ";
    printFloatBits(a);
    cout << "0.2: ";
    printFloatBits(b);
    cout << "0.3: ";
    printFloatBits(0.3f);
    cout << "0.1 + 0.2: ";
    printFloatBits(c);

    // Explicação sobre a estrutura do número de ponto flutuante
    // O bit de sinal define se o número é positivo ou negativo
    // O expoente desloca a mantissa para determinar a escala
    // A mantissa armazena os bits significativos do número, mas sofre de erros de precisão quando
    // valores como 0.1 e 0.2 não podem ser representados exatamente em binário.

    // Explicação sobre erro de arredondamento
    // A diferença entre c e 0.3 ocorre porque 0.1 e 0.2 não podem ser representados exatamente
    // no formato binário IEEE 754 de ponto flutuante, resultando em pequenos erros de arredondamento
    cout << "\nDiferença absoluta entre 0.1 + 0.2 e 0.3: " << abs(c - 0.3f) << "\n";

    return 0;
}
