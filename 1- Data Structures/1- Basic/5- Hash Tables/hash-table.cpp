#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int size;

    // Função hash simples
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % size;
    }

public:
    // Construtor
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Adicionar um par chave-valor
    void set(const string& key, int value) {
        int index = hashFunction(key);
        auto& cell = table[index];
        for (auto& pair : cell) {
            if (pair.first == key) {
                pair.second = value;  // Atualiza o valor se a chave já existir
                return;
            }
        }
        cell.push_back(make_pair(key, value));  // Insere um novo par chave-valor
    }

    // Recuperar o valor por chave
    int get(const string& key) {
        int index = hashFunction(key);
        auto& cell = table[index];
        for (auto& pair : cell) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;  // Se a chave não existir
    }

    // Remover um par chave-valor
    void remove(const string& key) {
        int index = hashFunction(key);
        auto& cell = table[index];
        cell.remove_if([&](const pair<string, int>& pair) {
            return pair.first == key;
        });
    }

    // Exibir a tabela hash
    void display() {
        for (int i = 0; i < size; i++) {
            if (!table[i].empty()) {
                cout << i << ": ";
                for (auto& pair : table[i]) {
                    cout << "[" << pair.first << ": " << pair.second << "] ";
                }
                cout << endl;
            }
        }
    }
};

// Exemplo de utilização
int main() {
    HashTable hashTable(50);
    hashTable.set("name", 100);
    hashTable.set("age", 25);
    hashTable.set("city", 300);

    cout << "Valor para 'name': " << hashTable.get("name") << endl;  // Output: 100
    hashTable.remove("age");
    hashTable.display();  // Mostra a tabela com os pares restantes

    return 0;
}
