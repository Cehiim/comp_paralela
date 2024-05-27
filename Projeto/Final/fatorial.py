import sys
sys.set_int_max_str_digits(1000000)
def calculafat(n, fat):
  fat[len(fat)-1] = int(fat[len(fat)-2]) * (len(fat)-1)
  for i in range(len(fat)-1, n):
    fat = fat + [int(fat[i])*(i+1)]
  return fat

arquivo = open('fatorial.txt', 'r') 
conteudo = arquivo.read()
fat = conteudo.split("\n")
fat = calculafat(10000, fat)
arquivo.close()
arquivo = open('fatorial.txt', 'w')
for i in range(len(fat)):
  arquivo.write(str(fat[i]) + "\n")
