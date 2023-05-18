id = 'abcdefghijklmnopqrstuvwxyz'

cadeia = input(str("Digite a cadeia: "))
cadeia = cadeia + '$'
pos = 0

#FUNÇÕES AUXILIARES
def match(token):
    global cadeia, pos
    
    if (pos < len(cadeia) and cadeia[pos] == token):
        pos += 1
    else: 
        print("Não faz parte da gramática")

# tabela
col = ['+','*','(',')','id','$']

# produções
# def E():


for i in id:
    print(i)
