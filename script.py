import subprocess
import time

def compilar_programa_c(nome_executavel, nome_codigo_fonte):
    # Compilar o código C
    compilacao = subprocess.run(["gcc", "-o", nome_executavel, nome_codigo_fonte])
    if compilacao.returncode != 0:
        print(f"Erro ao compilar {nome_codigo_fonte}.")
        return False
    return True

def executar_busca(nome_executavel, nome_arquivo):
    # Executar o programa compilado e passar o arquivo .txt como argumento
    processo = subprocess.run([f"./{nome_executavel}", nome_arquivo], capture_output=True, text=True)
    
    if processo.returncode == 0:
        return processo.stdout
    else:
        print(f"Erro ao executar {nome_executavel} para {nome_arquivo}:")
        print(processo.stderr)
        return None

def medir_tempo_execucao(nome_executavel, nome_arquivo, num_execucoes=20):
    tempos = []
    for _ in range(num_execucoes):
        inicio = time.time()
        executar_busca(nome_executavel, nome_arquivo)
        fim = time.time()
        tempos.append(fim - inicio)
    
    media_tempo = sum(tempos) / len(tempos)
    return media_tempo

def salvar_log(medias_tempos_binaria, medias_tempos_interpolacao):
    with open("log_tempo_execucao.txt", "w") as log_file:
        log_file.write("Tamanho do Array\tTempo Médio de Execução - Busca Binária (s)\tTempo Médio de Execução - Busca por Interpolação (s)\n")
        for tamanho in medias_tempos_binaria.keys():
            tempo_binaria = medias_tempos_binaria[tamanho]
            tempo_interpolacao = medias_tempos_interpolacao[tamanho]
            log_file.write(f"{tamanho}\t{tempo_binaria:.6f}\t{tempo_interpolacao:.6f}\n")

if __name__ == "__main__": # Nomes dos arquivos devem ser modificados e deseja testar com os arrays de 1 a N.
    arquivos_arrays = [
        "array_teste_10.txt",
        "array_teste_100.txt",
        "array_teste_1000.txt",
        "array_teste_10000.txt",
        "array_teste_100000.txt",
        "array_teste_1000000.txt",
        "array_teste_10000000.txt"
    ]

    # Compilar os programas C
    if compilar_programa_c("busca_binaria", "busca_binaria.c") and compilar_programa_c("busca_interpolacao", "busca_interpolacao.c"):
        medias_tempos_binaria = {}
        medias_tempos_interpolacao = {}

        for arquivo in arquivos_arrays:
            print(f"Medindo tempo de execução para {arquivo}...")

            # Extrair o tamanho do array a partir do nome do arquivo
            tamanho = arquivo.split("_")[2].split(".")[0]

            # Medir o tempo de execução para a busca binária
            media_tempo_binaria = medir_tempo_execucao("busca_binaria", arquivo)
            medias_tempos_binaria[tamanho] = media_tempo_binaria

            # Medir o tempo de execução para a busca por interpolação
            media_tempo_interpolacao = medir_tempo_execucao("busca_interpolacao", arquivo)
            medias_tempos_interpolacao[tamanho] = media_tempo_interpolacao
        
        # Salvar o log com os tempos de execução
        salvar_log(medias_tempos_binaria, medias_tempos_interpolacao)
        print("Log de tempo de execução salvo em 'log_tempo_execucao.txt'.")
