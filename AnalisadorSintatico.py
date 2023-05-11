cadeia = input('Digite a cadeia: ')
pos = 0

#FUNÇÕES AUXILIARES
def match(token):
    global cadeia, pos
    
    if (pos < len(cadeia) and cadeia[pos] == token):
        pos += 1
    else: 
        print("Não faz parte da gramática")

def prox():
    global cadeia, pos
    if (pos < len(cadeia)):
        return cadeia[pos]
    else:
        return False

# não terminais
def S():
    match('c')
    A()
    match('d')

def A():
    if prox() == 'a':
        match('a')
        match('b')
        A()
    elif prox() == 'c':
        match('c')
    else:
        # print("Erro sintático.")
        return True

def main():
    global cadeia, pos
    
    S()

    if pos == len(cadeia) and cadeia[pos-1] == 'd':
        print("Gramática válida.")

main()