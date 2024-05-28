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
2- Para executar o projeto é utilizado o comando: time taskset -c 0 ./proj
3- Para monitorar o tempo de execução de um programa sem interferir no seu funcionamento, usamos o comando time.
4- Além disso, utilizamos o comando taskset -c 0 para especificar os núcleos da CPU que serão utilizados durante a execução. Esse comando pode ser ajustado conforme necessário, mas para esta atividade, adotamos a seguinte abordagem:
./proj

# Como comprovar que os resultados propostos foram alcançados

# Resultados
![image](https://github.com/Cehiim/comp_paralela/assets/125515277/a6304cc1-c6d7-43ab-b5d5-13108edc3799)

