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

### [03/09/2023]

Pesquisando mais sobre formas mais baratas de ordenar as arestas, trombamos com técnicas de distance‐preserving dimensionality reduction, em especial a Z-order curve.

Com isso poderia ser possível ordenar apenas os vértices, aumentando muito o desempenho com um pequeno custo de precisão.

Por enquanto essa ideia foi engavetada porque a Z-order curve exige o cálculo sobre numeros inteiros. Fazer a normalização dos pontos poderia não valer a pena/não funcionar.

Também, escrevemos um script, tsp_random, para gerar arquivos tsp aleatóriamente com o potencial de nos auxiliar no futuro com mais testes. Um detalhe é que os pontos são distribuídos aleatóriamente sobre a figura de um quadrado e gostaríamos de saber alguma técnica para definir a forma de um polígono, ou construir ilhas de pontos.

Automatizamos o benchmarking e testamos duas implementações do algoritmo: uma com heap e outra com array padrão. A solução com o heap se mostrou, empíricamente, cerca de 2.5x mais rápida com o preço de ocupar quase o dobro do espaço e fazer um número atronomicamente maior de allocs.

### [04/09/2023]

Aprimoramos o heap o colocando em base 1 e dispondo do seu indice zero como um espaço de variável temporária. Isso extinguiu milhões de allocs e revelou que ele consome menos memória que a solução com qsort. Imbatível!
