Descriçãos dos conteúdos:

busca_binaria.c: código em c que recebe um arquivo txt que contém um array e faz uma busca binária pelo último elemento do array (pior caso para busca binária).

busca_interpolacao.c: código em c que recebe um arquivo txt que contém um array e faz uma busca por interpolação pelo último elemento do array.

script.py: código em python que envia os arrays em txt tanto para o busca_binaria.c quanto para o busca_interpolacao.c, faz com que cada busca seja executada 20 vezes para cada tipo de array e registra o tempo médio da busca para cada tipo num arquivo log em formato txt

plotar.py: Gera gráfico que compara os tempos de execuções dos 2 tipos de algoritmos de busca a partir do log gerado pelo script.py.

teste_basico/gerador.c: Gera arrays de 10, 100, 1000, 10000, 100000, 1000000 e 10000000 elementos com números aleatórios, únicos e organizados em ordem crescente.

teste_basico/plotBasico.png: Gráfico gerado pelo plotar.py depois de um teste feito com os arrays gerados pelo gerador.c

teste_1aN/gerador1aN.c: Gera arrays de 10, 100, 1000, 10000, 100000, 1000000 e 10000000 elementos com números de 1 até o tamanho do array, únicos e organizados em ordem crescente.

teste_1aN/plot1aN.c: Gráfico gerado pelo plotar.py depois de um teste feito com os arrays gerados pelo gerador1aN.c

ATENÇÃO: Os arrays que utilizamos nos nossos testes não estão contidos neste repositório por serem grandes demais para serem suportados pelo github, se desejar pode gerar arrays de teste com os códigos geradores contidos nas pastas.


Como rodar:

Para gerar o log basta executar o script.py pois ele já compila o código em c por conta própria, para executa-lo use o comando: python3 script.py.

para gerar o gráfico a partir do log execute o plotar.py com o seguinte comando: python3 plotar.py

ATENÇÂO: faça questão de que todos os arquivos chamados pelos códigos python (arquivos c e txt) estejam na mesma pasta que os códigos que os chamam e que a depender do tipo de teste que almeja ser feito (Básico ou 1 a N) algumas referências a arquivos dentro dos códigos python devem ser modificadas


Resultados esperados: 

Quando rodamos o código com os arquivos de texto com os arrays e plotamos os gráficos geramos as imagens já contidas no repositório.
