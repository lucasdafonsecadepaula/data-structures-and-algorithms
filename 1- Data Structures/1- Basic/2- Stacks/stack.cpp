#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Criando uma pilha (stack) de inteiros
    stack<int> s;

    // Adicionando elementos à pilha
    s.push(10);
    s.push(20);
    s.push(30);

    // Exibindo o elemento no topo da pilha
    cout << "Topo da pilha: " << s.top() << endl;  // Output: 30

    // Removendo o elemento do topo da pilha
    s.pop();
    cout << "Removendo o topo, novo topo: " << s.top() << endl;  // Output: 20

    // Exibindo o tamanho da pilha
    cout << "Tamanho da pilha: " << s.size() << endl;  // Output: 2

    // Verificando se a pilha está vazia
    if (s.empty()) {
        cout << "A pilha está vazia" << endl;
    } else {
        cout << "A pilha não está vazia" << endl;  // Output: A pilha não está vazia
    }

    return 0;
}
