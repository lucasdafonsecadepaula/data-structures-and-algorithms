#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Criando uma fila (queue) de inteiros
    queue<int> q;

    // Adicionando elementos à fila
    q.push(10);
    q.push(20);
    q.push(30);

    // Exibindo o elemento no início da fila
    cout << "Primeiro da fila: " << q.front() << endl;  // Output: 10

    // Removendo o elemento do início da fila
    q.pop();
    cout << "Removendo o primeiro, novo primeiro: " << q.front() << endl;  // Output: 20

    // Exibindo o tamanho da fila
    cout << "Tamanho da fila: " << q.size() << endl;  // Output: 2

    // Verificando se a fila está vazia
    if (q.empty()) {
        cout << "A fila está vazia" << endl;
    } else {
        cout << "A fila não está vazia" << endl;  // Output: A fila não está vazia
    }

    return 0;
}
