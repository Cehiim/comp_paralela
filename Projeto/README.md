# Integrantes do grupo:
- Daniel Reis Raske
- Cesar Hideki Imai
- João Victor Dallapé Madeira

# Como compilar o programa na plataforma disponibilizada
1- Abrir o terminal
2- Abrir o repositório do projeto
3- Executando o seguinte comando é possivel compilar a versão paralela: gcc -o proj ProjetoFinal.c -lpthread -lmpfr   
4- Executando o seguinte comando é possivel compilar a versão critical: 
# Como executar o programa
1- O diretorio deve estar no local do executavel
2- Para executar na versão serial, é utilizado o comando: time taskset -c 0 ./proj
3- Para executar na versão paralela, é utilizado o mesmo comando, porém com mais threads: time taskset -c 0 ./proj 
4- Para monitorar o tempo de execução de um programa sem interferir no seu funcionamento, usamos o comando time.
5- Além disso, utilizamos o comando taskset -c 0 para especificar os núcleos da CPU que serão utilizados durante a execução. Esse comando pode ser ajustado conforme necessário, mas para esta atividade, adotamos a seguinte abordagem:
./proj

# Como comprovar que os resultados propostos foram alcançados

# Resultados
Aqui estão as especificações do processador utilizado, executamos o comando cat /proc/cpuinfo para obter essas informações.
![image](https://github.com/Cehiim/comp_paralela/assets/125515277/a6304cc1-c6d7-43ab-b5d5-13108edc3799)

Considere o problema da tartaruga envolvido no projeto final da disciplina. Desenvolva uma primeira versão serial e paralela levando em consideração os seguintes requisitos:

  1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução

  2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

  3. Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 2,     4, 6 e 8 processadores.
