# Relatório

## Diário de bordo

### Início

A ideia era colocar todo o trabalho em um giovanni.c só com até mil linhas, que nem o prometido na especificação do trabalho.

Como isso não parecia muito possível, a alternativa mais simples (ironia) foi dividir todo o trabalho em cinco Makefiles, três bibliotecas, um cliente, dezenas de arquivos e adiante.

### [29/08/2023]

Nós começamos implementando o algoritmo padrão de Kruskal:

1. Gera todas as arestas do grafo completo, com seus respectivos pesos.
2. As ordena.
3. Constrói a MST da união das arestas de menor peso.

Ao final, obtemos uma MST com peso INFERIOR ao do professor e foi então que percebemos que erramos.

O professor contou que o segredo estava na parte de maior complexidade: ordenar as arestas.

A conclusão foi que nesse trabalho o objetivo era possível sacrificar precisão em troca de performance.

### [31/08/2023]

Melhoramos o Jupyter Notebook para facilitar os testes e os benchmarks no futuro. Modificamos os tsp_plot para isso.

Encontramos algumas respostas no Stack Overflow falando sobre como otimizar o algoritmo sobre um grafo completo.

O plano é fazer algumas versões usando métodos e estruturas diferentes. Todas as versões seriam testáveis graças ao uso de diretivas de compilação.
