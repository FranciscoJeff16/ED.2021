# Exemplo muito simples de arquivo Makefile

STD = -std=c++17
# -std=C++17: padrao C++17 da linguagem C++

OPTIONS = -Wall -O0
# -Wall: é uma abreviação para "warn all". Ele habilita quase todos os warnings que o g++ pode te dar.
# -O0: nao otimiza o codigo ao compilar 

LIBRARIES = -lm
# necessario no caso de usar math.h

# para produzir o arquivo executavel xxx, 
# basta dizer "make xxx"

executa : main.cpp  
	g++ $(STD) $(OPTIONS) *.cpp -o main $(LIBRARIES) & ./main

# o que parecem ser espacos no comeco da linha anterior
# sao, na verdade, um unico caractere de tabulacao (\t) 

# última regra: apaga todos os arquivos objeto
# gerados durante a compilação
clean:
	rm -rf *.o
