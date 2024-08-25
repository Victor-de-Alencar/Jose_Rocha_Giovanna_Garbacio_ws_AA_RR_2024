import matplotlib.pyplot as plt

def ler_log(log_file):
    tamanhos = []
    tempos_binaria = []
    tempos_interpolacao = []

    with open(log_file, "r") as file:
        # Ignorar a primeira linha (cabeçalho)
        next(file)
        for linha in file:
            partes = linha.split()
            tamanhos.append(int(partes[0]))
            tempos_binaria.append(float(partes[1]))
            tempos_interpolacao.append(float(partes[2]))

    return tamanhos, tempos_binaria, tempos_interpolacao

def plotar_grafico(tamanhos, tempos_binaria, tempos_interpolacao):
    plt.figure(figsize=(10, 6))

    # Plotando os tempos da busca binária
    plt.plot(tamanhos, tempos_binaria, label='Busca Binária', marker='o')

    # Plotando os tempos da busca por interpolação
    plt.plot(tamanhos, tempos_interpolacao, label='Busca por Interpolação', marker='o')

    # Configurações do gráfico
    plt.title('Tempo de Execução vs Tamanho do Array')
    plt.xlabel('Tamanho do Array')
    plt.ylabel('Tempo Médio de Execução (s)')
    plt.xscale('log') 
    plt.yscale('log')  
    plt.legend()
    plt.grid(True, which="both", ls="--")
    plt.show()

if __name__ == "__main__":
    log_file = "log_tempo_execucao.txt"

    # Ler os dados do log
    tamanhos, tempos_binaria, tempos_interpolacao = ler_log(log_file)

    # Plotar o gráfico
    plotar_grafico(tamanhos, tempos_binaria, tempos_interpolacao)
