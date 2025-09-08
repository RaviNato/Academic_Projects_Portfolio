print("##############       PROGRAMA PARA CRIAR TRIANGULOS       ################")
nome = input("Qual seu nome?")
digito_bem=False
while not digito_bem:
    try:
        qtd_linhas=int(input("Olá, quantas linhas o triangulo ocupará?"))
    except ValueError:
        print(nome,", o valor deverá ser um número inteiro!")
    else:
        if qtd_linhas<2:
            print(nome,", o valor deverá ser maior que 1!")
        else:
            digito_bem=True
qtd_de_espacos_iniciais=0
qtd_de_Os=2*qtd_linhas-1
nro_da_linha_sendo_escrita=0
while nro_da_linha_sendo_escrita<qtd_linhas:
    nro_da_linha_sendo_escrita+=1
    nro_do_espaco_sendo_escrito=0
    while nro_do_espaco_sendo_escrito<qtd_de_espacos_iniciais:
        nro_do_espaco_sendo_escrito+=1
        print(" ",end="")
    qtd_de_espacos_iniciais+=1
    nro_do_O_sendo_escrito=0
    while nro_do_O_sendo_escrito<qtd_de_Os:
        nro_do_O_sendo_escrito+=1
        print("O",end="")
    qtd_de_Os-=2
    print()
print("##############             PROGRAMA ENCERRADO             ################")