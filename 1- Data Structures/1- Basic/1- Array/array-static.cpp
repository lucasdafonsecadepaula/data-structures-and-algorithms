#include <iostream>
using namespace std;

int main() {
    // Inicialização de um array com alguns números
    int numbers[] = {10, 20, 30, 40, 50};

    // Acessando elementos do array
    cout << "Primeiro número: " << numbers[0] << endl;  // Output: 10
    cout << "Segundo número: " << numbers[1] << endl;   // Output: 20

    // Modificando um elemento do array
    numbers[2] = 35;
    cout << "Array atualizado: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";  // Output: 10 20 35 40 50
    }
    cout << endl;

    return 0;
}
