# Nome do executável
TARGET = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -O2

# Bibliotecas extras (math)
LIBS = -lm

# Arquivos fonte e objetos
SRC = main.c algorithms.c benchmark.c
OBJ = $(SRC:.c=.o)

# Script Python
PLOT_SCRIPT = Gráfico_de_análise_comparativa.py

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compilar cada .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rodar programa e gerar resultados
run: $(TARGET)
	./$(TARGET)

# Rodar tudo e gerar gráfico
plot: run
	python3 $(PLOT_SCRIPT)

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)

# Limpeza total (inclusive CSV e gráficos)
clean-all: clean
	rm -f resultados.csv comparacao_algoritmos.png
