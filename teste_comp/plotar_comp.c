import matplotlib.pyplot as plt

def ler_log_comparacoes(nome_arquivo):
    tamanhos = []
    comparacoes_binaria = []
    comparacoes_interpolacao = []

    with open(nome_arquivo, "r") as arquivo:
        linhas = arquivo.readlines()
        for linha in linhas[1:]:
            dados = linha.split()
            tamanhos.append(int(dados[0]))
            comparacoes_binaria.append(int(dados[1]))
            comparacoes_interpolacao.append(int(dados[2]))

    return tamanhos, comparacoes_binaria, comparacoes_interpolacao

def plotar_grafico(tamanhos, comparacoes_binaria, comparacoes_interpolacao):
    plt.figure(figsize=(10, 6))
    
    # Plotar as comparações da busca binária
    plt.plot(tamanhos, comparacoes_binaria, label="Busca Binária", marker='o', color='blue')

    # Plotar as comparações da busca por interpolação
    plt.plot(tamanhos, comparacoes_interpolacao, label="Busca por Interpolação", marker='s', color='green')

    plt.xlabel("Tamanho do Array")
    plt.ylabel("Número de Comparações")
    plt.title("Comparação do Número de Comparações entre Busca Binária e Busca por Interpolação")
    plt.legend()
    plt.grid(True)
    plt.xscale('log')  
    plt.yscale('linear')  
    
    #plt.savefig("grafico_comparacoes.png")
    plt.show()

if __name__ == "__main__":
    # Ler os dados do log
    tamanhos, comparacoes_binaria, comparacoes_interpolacao = ler_log_comparacoes("log_comparacoes.txt")

    # Plotar o gráfico
    plotar_grafico(tamanhos, comparacoes_binaria, comparacoes_interpolacao)
