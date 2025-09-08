import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carregar CSV
df = pd.read_csv("resultados.csv")

# Funções teóricas
def O_n(n): return n
def O_nlogn(n): return n * np.log2(n)
def O_n2(n): return n**2
def O_log(n): return np.log2(n)

# Normalizar funções teóricas para mesma escala
def normalizar(y, ref):
    return y * (ref.max() / y.max())

# Dados
n = df["n"].values

# Configuração dos subplots
fig, axs = plt.subplots(2, 2, figsize=(12, 8))
fig.suptitle("Comparação entre tempos medidos e funções teóricas", fontsize=14)

# 1 - Bubble Sort
axs[0, 0].plot(n, df["bubbleSort"], "o-", label="Bubble Sort (Empírico)")
axs[0, 0].plot(n, normalizar(O_n2(n), df["bubbleSort"]), "--", label="O(n²)")
axs[0, 0].set_title("Bubble Sort")
axs[0, 0].set_xlabel("n")
axs[0, 0].set_ylabel("Tempo (s)")
axs[0, 0].legend()
axs[0, 0].grid(True)

# 2 - Insertion Sort
axs[0, 1].plot(n, df["insertionSort"], "o-", label="Insertion Sort (Empírico)")
axs[0, 1].plot(n, normalizar(O_n2(n), df["insertionSort"]), "--", label="O(n²)")
axs[0, 1].set_title("Insertion Sort")
axs[0, 1].set_xlabel("n")
axs[0, 1].set_ylabel("Tempo (s)")
axs[0, 1].legend()
axs[0, 1].grid(True)

# 3 - Busca Sequencial
axs[1, 0].plot(n, df["buscaSeq"], "o-", label="Busca Seq (Empírico)")
axs[1, 0].plot(n, normalizar(O_n(n), df["buscaSeq"]), "--", label="O(n)")
axs[1, 0].set_title("Busca Sequencial")
axs[1, 0].set_xlabel("n")
axs[1, 0].set_ylabel("Tempo (s)")
axs[1, 0].legend()
axs[1, 0].grid(True)

# 4 - Busca Binária
axs[1, 1].plot(n, df["buscaBin"], "o-", label="Busca Binária (Empírico)")
axs[1, 1].plot(n, normalizar(O_log(n), df["buscaBin"]), "--", label="O(log n)")
axs[1, 1].set_title("Busca Binária")
axs[1, 1].set_xlabel("n")
axs[1, 1].set_ylabel("Tempo (s)")
axs[1, 1].legend()
axs[1, 1].grid(True)

# Ajustar layout e salvar
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.savefig("comparacao_algoritmos.png")
plt.close()

print("✅ Gráfico único salvo em comparacao_algoritmos.png")
