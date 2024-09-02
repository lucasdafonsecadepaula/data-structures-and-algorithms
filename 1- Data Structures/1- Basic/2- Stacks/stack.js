class Stack {
  constructor() {
      this.items = [];
  }

  // Adicionar um elemento ao topo da pilha
  push(element) {
      this.items.push(element);
  }

  // Remover o elemento do topo da pilha
  pop() {
      if (this.isEmpty()) {
          return "A pilha está vazia";
      }
      return this.items.pop();
  }

  // Ver o elemento do topo da pilha sem remover
  peek() {
      if (this.isEmpty()) {
          return "A pilha está vazia";
      }
      return this.items[this.items.length - 1];
  }

  // Verificar se a pilha está vazia
  isEmpty() {
      return this.items.length === 0;
  }

  // Ver o tamanho da pilha
  size() {
      return this.items.length;
  }

  // Esvaziar a pilha
  clear() {
      this.items = [];
  }
}

// Exemplo de utilização
const stack = new Stack();
stack.push(10);
stack.push(20);
stack.push(30);

console.log("Topo da pilha:", stack.peek());  // Output: 30
console.log("Removendo topo:", stack.pop());  // Output: 30
console.log("Topo da pilha:", stack.peek());  // Output: 20
console.log("Tamanho da pilha:", stack.size()); // Output: 2
