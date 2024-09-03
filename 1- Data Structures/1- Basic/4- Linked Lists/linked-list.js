class Node {
  constructor(data) {
      this.data = data;
      this.next = null;
  }
}

class LinkedList {
  constructor() {
      this.head = null;
  }

  // Adicionar um elemento no final da lista
  append(data) {
      let newNode = new Node(data);
      if (this.head === null) {
          this.head = newNode;
      } else {
          let current = this.head;
          while (current.next !== null) {
              current = current.next;
          }
          current.next = newNode;
      }
  }

  // Remover o primeiro elemento da lista
  removeFirst() {
      if (this.head !== null) {
          this.head = this.head.next;
      } else {
          console.log("A lista está vazia");
      }
  }

  // Exibir os elementos da lista
  display() {
      if (this.head === null) {
          console.log("A lista está vazia");
          return;
      }
      let current = this.head;
      while (current !== null) {
          console.log(current.data);
          current = current.next;
      }
  }
}

// Exemplo de utilização
let list = new LinkedList();
list.append(10);
list.append(20);
list.append(30);

console.log("Elementos da lista:");
list.display();  // Output: 10 20 30

console.log("Removendo o primeiro elemento");
list.removeFirst();
list.display();  // Output: 20 30
