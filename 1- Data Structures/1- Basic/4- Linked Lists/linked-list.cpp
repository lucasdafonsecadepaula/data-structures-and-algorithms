#include <iostream>
using namespace std;

// Definição de um nó da lista
struct Node {
    int data;
    Node* next;
};

// Classe da lista encadeada
class LinkedList {
private:
    Node* head;

public:
    // Construtor
    LinkedList() {
        head = nullptr;
    }

    // Adicionar um elemento no final da lista
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Remover o primeiro elemento da lista
    void removeFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "A lista está vazia" << endl;
        }
    }

    // Exibir os elementos da lista
    void display() {
        if (head == nullptr) {
            cout << "A lista está vazia" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Exemplo de utilização
int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Elementos da lista:" << endl;
    list.display();  // Output: 10 20 30

    cout << "Removendo o primeiro elemento" << endl;
    list.removeFirst();
    list.display();  // Output: 20 30

    return 0;
}
