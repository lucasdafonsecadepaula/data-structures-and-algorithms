class HashTable {
  constructor(size) {
      this.table = new Array(size);
      this.size = size;
  }

  // Função hash simples
  _hash(key) {
      let hash = 0;
      for (let i = 0; i < key.length; i++) {
          hash += key.charCodeAt(i);
      }
      return hash % this.size;
  }

  // Adicionar um par chave-valor
  set(key, value) {
      const index = this._hash(key);
      if (!this.table[index]) {
          this.table[index] = [];
      }
      this.table[index].push([key, value]);
  }

  // Recuperar o valor por chave
  get(key) {
      const index = this._hash(key);
      if (this.table[index]) {
          for (let pair of this.table[index]) {
              if (pair[0] === key) {
                  return pair[1];
              }
          }
      }
      return undefined;
  }

  // Remover um par chave-valor
  remove(key) {
      const index = this._hash(key);
      if (this.table[index]) {
          this.table[index] = this.table[index].filter(pair => pair[0] !== key);
      }
  }

  // Exibir a tabela hash
  display() {
      for (let i = 0; i < this.size; i++) {
          if (this.table[i]) {
              console.log(i, this.table[i]);
          }
      }
  }
}

// Exemplo de utilização
const hashTable = new HashTable(50);
hashTable.set("name", "Lucas");
hashTable.set("age", 25);
hashTable.set("city", "São Paulo");

console.log("Valor para 'name':", hashTable.get("name"));  // Output: Lucas
hashTable.remove("age");
hashTable.display();  // Mostra a tabela com os pares restantes
