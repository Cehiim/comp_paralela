# Integrantes do grupo:
- Daniel Reis Raske
- Cesar Hideki Imai
- João Victor Dallapé Madeira

# Como compilar o programa na plataforma disponibilizada

1- Abrir o terminal

2- Abrir o repositório do projeto

3- Executando o seguinte comando é possivel compilar a versão paralela: `gcc -o proj ProjetoFinal.c -lpthread -lmpfr`

4- Executando o seguinte comando é possivel compilar a versão critical: `gcc -o crit Critico.c -lpthread -lmpfr -lrt`

# Como executar o programa

1- O diretorio deve estar no local do executavel

2- Para executar na versão serial, é utilizado o comando: `time taskset -c 0 ./proj`

3- Para executar na versão paralela, é utilizado o mesmo comando, porém com mais threads: `time taskset -c 0-7 ./proj`

4- Para monitorar o tempo de execução de um programa sem interferir no seu funcionamento, usamos o comando `time`.

5- Além disso, utilizamos o comando `taskset -c 0` para especificar os núcleos da CPU que serão utilizados durante a execução. Esse comando pode ser ajustado conforme necessário, mas para esta atividade, adotamos a seguinte abordagem:
- 1 processador = taskset -c 0
- 2 processadores = taskset -c 0-1
- 4 processadores = taskset -c 0-3
- 6 processadores = taskset -c 0-5
- 8 processadores = taskeset -c 0-7

# Resultados

Aqui estão as especificações do processador utilizado, executamos o comando cat /proc/cpuinfo para obter essas informações.
![image](https://github.com/Cehiim/comp_paralela/assets/125515277/a6304cc1-c6d7-43ab-b5d5-13108edc3799)

Considere o problema da tartaruga envolvido no projeto final da disciplina. Desenvolva uma primeira versão serial e paralela levando em consideração os seguintes requisitos:

  1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução

     Tempo de execução serial para 1, 2, 4, 6, 8 processadores:
     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/d46d3cba-14b6-4676-9052-c2de50543abd)
     
     Tempo de execução paralela para 1, 2, 4, 6, 8 processadores usando 8 threads:
     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/d2dcf9b7-ea96-442b-a4fd-b8fed6347ae7)

     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/939825a9-c14b-4a95-bdb3-150d8003f91a)


  2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.
    
     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/4bdd4dd6-bd0c-46b4-b3b1-bbec65782d93)

  3. Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 
    2, 4, 6 e 8 processadores.

     Ao introduzir a diretiva critical em nossa solução, o comportamento do programa é alterado de modo que apenas uma thread será usada para executar o bloco de código protegido de cada vez. Isso elimina qualquer problema de concorrência que possa surgir.

     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/1e3b467a-c0b1-4d98-9d8f-309739dd2114)

     ![image](https://github.com/Cehiim/comp_paralela/assets/125515277/fdf2de30-be90-457a-89ea-55e0f458dd0f)

