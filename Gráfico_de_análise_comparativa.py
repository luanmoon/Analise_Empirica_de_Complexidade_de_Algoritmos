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

plt.figure(figsize=(10, 6))
plt.title("Comparação entre tempos medidos e funções teóricas")

# Bubble Sort
plt.plot(n, df["bubbleSort"], "o-", label="Bubble Sort (Empírico)")
plt.plot(n, normalizar(O_n2(n), df["bubbleSort"]), "--", label="O(n²) ref. Bubble")

# Insertion Sort
plt.plot(n, df["insertionSort"], "o-", label="Insertion Sort (Empírico)")
plt.plot(n, normalizar(O_n2(n), df["insertionSort"]), "--", label="O(n²) ref. Insertion")

# Busca Sequencial
plt.plot(n, df["buscaSeq"], "o-", label="Busca Sequencial (Empírico)")
plt.plot(n, normalizar(O_n(n), df["buscaSeq"]), "--", label="O(n) ref. Seq.")

# Busca Binária
plt.plot(n, df["buscaBin"], "o-", label="Busca Binária (Empírico)")
plt.plot(n, normalizar(O_log(n), df["buscaBin"]), "--", label="O(log n) ref. Binária")

plt.xlabel("n")
plt.ylabel("Tempo (s)")
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.savefig("comparacao_algoritmos.png")
plt.close()

print("✅ Gráfico único (sobreposto) salvo em comparacao_algoritmos.png")

