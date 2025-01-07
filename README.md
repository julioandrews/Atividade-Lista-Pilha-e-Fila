# Atividade-Lista-Pilha-e-Fila
Essa é a minha resolução para a atividade "Lista, Pilha e Fila" de Estrutura de Dados.

### Lista Ligada
No código de lista ligada, foi adicionado apenas algumas linhas de código às funções _"excluirElemLista"_ e _"inserirElemListaOrd"_, no arquivo _"listaLigada.c"_.
Em ambas as funções, foi tomado o cuidado de alterar o ponteiro "ant" do próximo elemento corretamente, levando em conta situalçoes de lista vazia, ou de estar incluindo/excluindo o último ou primeiro elemento da lista.

### Pilha Estática
No arquivo "_pilhaEstatica.c", a nova função _"exibirPilhaInvertida"_ funciona espelhadamente à ja implementada _"exibirPilha"_, diferindo-se apenas na direção do loop (de 0 ao topo, para do topo a 0).
Também, foram feitos ajustes em _"main.c"_ para a nova função ser apresentada e chamada corretamente para o usuário.

### Fila
Nesse arquivo, a maneira como as funções _"excluirDaFila"_ e _"inserirNaFila"_ foram alteradas para que percorram a fila em questão a partir do nó cabeça, sem ter de se ancorarem nos valores de _ant_ e _prox_ dos elementos.
