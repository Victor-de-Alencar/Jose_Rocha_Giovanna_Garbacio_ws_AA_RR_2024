# Análise do algoritmo de Busca Binária
**Projeto realizado para a disciplina de Análise de Algoritmos**

* **Alunos:** José Victor Alencar Rocha e Giovanna Mendes Garbácio

### 1. Descriçãos dos conteúdos desse repositório:

**_busca_binaria.c_:** Código na linguagem C que recebe um arquivo de texto que contém uma sequência de números, os armazena em um array e realiza uma busca binária pelo último elemento do array (pior caso para busca binária).

**_busca_interpolacao.c:_** Código na linguagem C que recebe um arquivo de texto que contém uma sequência de números, os armazena em um array e faz uma busca por interpolação pelo último elemento do array.

**_script.py:_** Código em Python que envia o conteúdo de arquivos de textos tanto para  _busca_binaria.c_ quanto para _busca_interpolacao.c_, faz com que cada busca seja executada 20 vezes para cada tipo de array (cada arquivo de texto com quantidade de números diferente) e registra o tempo médio da busca para cada algoritmo num arquivo log em formato .txt.

**_plotar.py:_** Gera um gráfico que compara os tempos de execuções dos dois tipos de algoritmos de busca a partir do log gerado pelo _script.py_.

**_teste_basico/gerador.c:_** Gera os arquivos de texto com arrays de 10, 100, 1000, 10000, 100000, 1000000 e 10000000 elementos com números aleatórios, únicos e organizados em ordem crescente.

**_teste_basico/plotBasico.png_**: Gráfico gerado pelo _plotar.py_ depois de um teste feito com os arrays gerados pelo _gerador.c_.

**_teste_1aN/gerador1aN.c_**: Gera arrays de 10, 100, 1000, 10000, 100000, 1000000 e 10000000 elementos com números de 1 até o tamanho do array, únicos e organizados em ordem crescente.

**_teste_1aN/plot1aN.c_**: Gráfico gerado pelo plotar.py depois de um teste feito com os arrays gerados pelo gerador1aN.c

NOTA: Os arrays que utilizamos nos nossos testes não estão contidos neste repositório por serem grandes demais para serem suportados pelo github, para a reprodução é possível gerar arrays de teste com os códigos geradores contidos nas pastas.


### 2. Como executar:

Para gerar o log basta executar o _script.py_, ele compila os códigos em C automaticamente. para executa-lo use o comando: 
```
python3 script.py
```

Para gerar o gráfico a partir do log execute _plotar.py_ com o seguinte comando: 
```
python3 plotar.py
```
ATENÇÃO: faça questão de que todos os arquivos chamados pelos códigos Python (arquivos .c e .txt) estejam na mesma pasta que os códigos que os chamam e que a depender do tipo de teste que almeja ser feito (Básico ou 1 a N) algumas referências a arquivos dentro dos códigos python devem ser modificadas.


### 3. Resultados esperados: 

Quando testamos o código com os arquivos de texto com os arrays e plotamos os gráficos geramos as imagens já contidas no repositório.

* Resultado do teste básico:
![plotBasico](https://github.com/user-attachments/assets/6c9c011c-cc3d-4e23-b183-a8ee0c080670)


* Resultado do teste 1 a n:
![plot1aN](https://github.com/user-attachments/assets/42554d67-1b64-430c-926b-ce1701e76dde)
