class Queue {
  constructor() {
      this.items = [];
  }

  // Adicionar um elemento no final da fila
  enqueue(element) {
      this.items.push(element);
  }

  // Remover o elemento do início da fila
  dequeue() {
      if (this.isEmpty()) {
          return "A fila está vazia";
      }
      return this.items.shift();
  }

  // Ver o elemento no início da fila sem remover
  front() {
      if (this.isEmpty()) {
          return "A fila está vazia";
      }
      return this.items[0];
  }

  // Verificar se a fila está vazia
  isEmpty() {
      return this.items.length === 0;
  }

  // Ver o tamanho da fila
  size() {
      return this.items.length;
  }

  // Esvaziar a fila
  clear() {
      this.items = [];
  }
}

// Exemplo de utilização
const queue = new Queue();
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

console.log("Primeiro da fila:", queue.front());  // Output: 10
console.log("Removendo o primeiro:", queue.dequeue());  // Output: 10
console.log("Novo primeiro da fila:", queue.front());  // Output: 20
console.log("Tamanho da fila:", queue.size());  // Output: 2
