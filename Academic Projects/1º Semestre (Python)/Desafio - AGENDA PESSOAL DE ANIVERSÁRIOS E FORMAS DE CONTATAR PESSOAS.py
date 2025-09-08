import re
padrao_nome = r'^[A-ZÀ-Ý]{1}[a-zà-ÿ]*( [A-ZÀ-Ý]?[a-zà-ÿ]*)*$'
padrao_data = r'^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(19|20)\d{2}$'
padrao_endereco = r'^([A-ZÀ-Ý]?[a-zà-ÿ\s]*)*, \d+[A-Za-zÀ-ÿ]? - ([A-ZÀ-Ý]?[a-zà-ÿ\s]*)*$'
padrao_telefone = r'^\([1-9]{2}\) \d{4}-\d{4}$'
padrao_celular = r'^\([1-9]{2}\) 9\d{4}-\d{4}$'
padrao_email = r'^[a-zA-Z0-9.-]*@([a-zA-Z0-9.-]*.){,2}[a-zA-Z]$'

'''
Implementar a opções do menu, sempre cuidando de validar os inputs do
usuário.
Usar, sempre que cabível, as funções prontas no código.

Fazer o trabalho em duplas e entregar duas semanas, ou seja, NÃO na
próxima aula, na seguinte.
Substituir, na função apresenteSe, o texto:
"Profs André Carvalho & J.G.Pícolo"
por um texto contendo os nomes e RAs dos alunos da dupla.
Também substituir o texto:
"Versão 1.0 de 12/maio/2025"
por
"Versão 2.0 de dd/mm/aaaa"
sendo dd/mm/aaaa a data que que a dupla concluiu seu trabalho.

A entrega será na forma de demonstração ao professor; os dois da dupla
deverão estar presentes na entrega e serão questionados pelo professor
sobre o programa que apresentam.
IMPORTANTE: este questionamento poderá resultar em notas diferentes para
os alunos da dupla, ou até em uma nota bem baixa para um programa que
funciona perfeitamente (basta estar perdido na demonstração).
'''




def apresenteSe ():
    print('+-------------------------------------------------------------+')
    print('|                                                             |')
    print('| AGENDA PESSOAL DE ANIVERSÁRIOS E FORMAS DE CONTATAR PESSOAS |')
    print('|                                                             |')
    print('| Alunos Caio Lucena Andrade & Davi Ferreira Alves            |')
    print('|                                                             |')
    print('| Versão 2.0 de 19/maio/2025                                  |')
    print('|                                                             |')
    print('+-------------------------------------------------------------+')

def umTexto (solicitacao, mensagem, valido):
    digitouDireito=False
    while not digitouDireito:
        txt=input(solicitacao)

        if txt not in valido:
            print(mensagem,'- Favor redigitar...')
        else:
            digitouDireito=True

    return txt



def opcaoEscolhida (mnu):
    print()

    opcoesValidas=[]
    posicao=0
    while posicao<len(mnu):
        print (posicao+1,') ',mnu[posicao],sep='')
        opcoesValidas.append(str(posicao+1))
        posicao+=1

    print()
    return umTexto('Qual é a sua opção? ', 'Opção inválida', opcoesValidas)



'''
procura nom em agd e, se achou, retorna:
uma lista contendo True e a posicao onde achou;
MAS, se não achou, retorna:
uma lista contendo False e a posição onde inserir,
aquilo que foi buscado, mas nao foi encontrado,
mantendo a ordenação da lista.
'''
def ondeEsta(nom, agd):
    inicio = 0
    final = len(agd)-1
    
    while inicio <= final:
        meio=(inicio+final)//2
        
        if nom == agd[inicio][0]:
            return [True, meio]
        if inicio == final:
            return [False, inicio+1]
            
        inicio += 1

    # continue a implementação que, entre outras coisas, deverá
    # calcular o meio, conforme segue:
        
    # a função deverá retornar a lista [True,meio] quando encontrar o
    # nome procurado ou então a lista [False,inicio], quando não
    # encontrar o nome procurado.




def cadastrar(agd):
    while True:
        nome = input("Digite o nome do contato, ou 'cancela' para desistir (ex: João da Silva): ")

        if nome.lower() == "cancela":
            print("Operação cancelada.")
            return
    
        if re.fullmatch(padrao_nome, nome):

            existe, posicao = ondeEsta(nome, agd)

            if existe:
                print(f"O nome '{nome}' já está cadastrado. Tente outro nome.")
            else:
                while True:
                    aniversario = input("Digite o aniversário (DD-MM-AAAA): ")
                    if re.fullmatch(padrao_data, aniversario):
                        break
                    else:
                        print("Data inválida! Use o formato DD-MM-AAAA.")

                while True:
                    endereco = input("Digite o endereço (Nome da Rua, Número - Bairro): ")
                    if re.fullmatch(padrao_endereco, endereco):
                        break
                    else:
                        print("Endereço inválido! Use o formato: Nome da Rua, Número - Bairro.")
                
                while True:
                    telefone = input("Digite o telefone fixo ((##) ####-####): ")
                    if re.fullmatch(padrao_telefone, telefone):
                        break
                    else:
                        print("Telefone inválido! Use um formato como: (##) ####-####.")

                while True:
                    celular = input("Digite o celular ((##) 9####-####): ")
                    if re.fullmatch(padrao_celular, celular):
                        break
                    else:
                        print("Celular inválido! Use um formato como: (##) 9####-####.")
                
                while True:
                    email = input("Digite o e-mail (nome@dominio.com): ")
                    if re.fullmatch(padrao_email, email):
                        break
                    else:
                        print("E-mail inválido! Exemplo válido: nome@dominio.com")
                
                contato = [nome, aniversario, endereco, telefone, celular, email]

                agd.insert(posicao, contato)
                
                agd.sort(key=lambda contato: contato[0])

                print(f"Cadastro do contato '{nome}' realizado com sucesso!")
                return
        else:
            print("Nome inválido! Use letras com iniciais maiúsculas. Tente novamente.")

    # Ficar solicitando a digitação de um nome de um contato a ser
    # cadastrado na agenda, até que um nome NÃO CADASTRADO seja digitado.
    # Solicitar então a digitação do aniversario, do endereço, do
    # telefone (fixo), do celular e do e_mail da pessoa, cujo nome foi
    # digitado.
    # Gerar então uma lista conforme abaixo:
    # contato=[nome,aniversario,endereco,telefone,celular,email]
    # incluindo essa listinha chamada contato na listona chamada agd,
    # lembrando que agd é parâmetro formal desta função; o parâmetro
    # real que é fornecido no programa ao chamar esta função se chama
    # agenda.
    # Na listona, as listinhas deverão estar em ordem alfabética de
    # nome e o local apropriadoa para a inserção deverá ser obtido
    # usando a função ondeEsta, que realiza uma busca binária.
    # O usuário poderá desistir de cadastrar, escrevendo "cancela" no
    # momento de digitar o nome a ser cadastrado.
    # A função deverá terminar com uma mensagem informando cadastro
    # realizado com sucesso ou cadastro não realizado.





def procurar (agd):
    while True:
        nome = input("Digite o nome do contato a procurar,  ou 'cancela' para desistir: ")

        if nome.lower() == "cancela":
            print("Operação cancelada.")
            return
        
        if re.fullmatch(padrao_nome, nome):
            existe, posicao = ondeEsta(nome, agd)

            if existe:
                print(agd[posicao])
                return
            else:
                print(f"O nome '{nome}' não está cadastrado. Tente outro nome.")
        else:
            print("Nome inválido! Use letras com iniciais maiúsculas. Tente novamente.")
  
    # Ficar pedindo para digitar um nome até digitar um nome que existe
    # cadastrado;
    # mostrar então na tela TODOS os demais dados encontrados 
    # sobre aquela pessoa.
    # O usuário poderá desistir de procurar, escrevendo "cancela" no
    # momento de digitar o nome a ser procurado.

def atualizar (agd):
    while True:
        nome = input("Digite o nome do contato a procurar para atualizar,  ou 'cancela' para desistir: ")

        if nome.lower() == "cancela":
            print("Operação cancelada.")
            return
        
        
        if re.fullmatch(padrao_nome, nome):
            existe, posicao = ondeEsta(nome, agd)

            if existe:
                print(agd[posicao])
                opcao = opcaoEscolhida(["Aniversário;", "Endereco;", "Telefone;", "Celular;", "Email.", "-Encerrar atualizações-"])
                if opcao == "6":
                    return
                
                if opcao == "1":
                    while True:
                        mudanca = input("Digite a data mais atualizada (DD-MM-AAAA): ")
                        if re.fullmatch(padrao_data, mudanca):
                            break
                        else:
                            print("Data inválida! Use o formato DD-MM-AAAA.")

                if opcao == "2":
                    while True:
                        mudanca = input("Digite o endereço mais atualizada (Nome da Rua, Número - Bairro): ")
                        if re.fullmatch(padrao_endereco, mudanca):
                            break
                        else:
                            print("Endereço inválido! Use o formato: Nome da Rua, Número - Bairro.")
                    
                if opcao == "3":
                    while True:
                        mudanca = input("Digite o telefone fixo mais atualizado ((##) ####-####): ")
                        if re.fullmatch(padrao_telefone, mudanca):
                            break
                        else:
                            print("Telefone inválido! Use um formato como: (##) ####-####.")

                if opcao == "4":
                    while True:
                        mudanca = input("Digite o celular mais atualizado ((##) 9####-####): ")
                        if re.fullmatch(padrao_celular, mudanca):
                            break
                        else:
                            print("Celular inválido! Use um formato como: (##) 9####-####.")
                    
                if opcao == "5":
                    while True:
                        mudanca = input("Digite o e-mail mais atualizado (nome@dominio.com): ")
                        if re.fullmatch(padrao_email, mudanca):
                            break
                        else:
                            print("E-mail inválido! Exemplo válido: nome@dominio.com")


                agd[posicao][int(opcao)] = mudanca
            else:
                print(f"O nome '{nome}' não está cadastrado. Tente outro nome.")
        else:
            print("Nome inválido! Use letras com iniciais maiúsculas. Tente novamente.")

    # Ficar solicitando a digitação de um nome de um contato a ser
    # atualizado na agenda, até que um nome cadastrado seja digitado.
    # Ficar mostrando então um SUBMENU oferecendo as opções de atualizar
    # aniversário, ou endereco, ou telefone, ou celular, ou email, ou
    # finalizar as atualizações; ficar pedindo para digitar a opção até
    # digitar uma opção válida; realizar a atulização solicitada; tudo
    # isso até ser escolhida a opção de finalizar as atualizações.
    # REPARE que não foi prevista uma opção de atualizar o nome!
    # USAR A FUNÇÃO opcaoEscolhida, JÁ IMPLEMENTADA, PARA FAZER O MENU.
    # O usuário poderá desistir de atualizar, escrevendo "cancela" no
    # momento de digitar o nome a ser atualizado, ou, até mesmo, no
    # momento de digitar o aniversário ou o endereço ou o telefone (fixo)
    # ou o celular ou ainda o e_mail (caso o usuário tenha optado por
    # uma dessas atualizações, naturalmente).

def listar (agd):
    if not agd:
        print("Não há contatos na agenda. :(")

    i = 0
    while i <= len(agd) -1:
        print(
        f" Nome.........: {agd[i][0]}\n",\
        f"Aniversário..: {agd[i][1]}\n",\
        f"Endereço.....: {agd[i][2]}\n",\
        f"Telefone.....: {agd[i][3]}\n",\
        f"Celular......: {agd[i][4]}\n",\
        f"Email........: {agd[i][5]}")
        print()
        i += 1

    # implementar aqui a listagem de todos os dados de todos
    # os contatos cadastrados
    # printar aviso de que não há contatos cadastrados se
    # esse for o caso

def excluir (agd):
    while True:
        nome = input("Digite o nome do contato a procurar para excluir,  ou 'cancela' para desistir: ")

        if nome.lower() == "cancela":
            print("Operação cancelada.")
            return
        
        if re.fullmatch(padrao_nome, nome):
            existe, posicao = ondeEsta(nome, agd)
            
            if existe:
                print(f"{agd[posicao]} excluído com sucesso")
                del agd[posicao]
                return
            else:
                print(f"O nome '{nome}' não está cadastrado. Tente outro nome.")
        else:
            print("Nome inválido! Use letras com iniciais maiúsculas. Tente novamente.")
        
        
    # Ficar solicitando a digitação de um nome a ser excluido da agenda,
    # até que um nome cadastrado seja digitado.
    # Os dados encontrados deveriam então ser mostrados e a exclusão
    # deveria ser confirmada.
    # Sendo confirmada, a exclusão deveria ser realizada e uma mensagem
    # de exclusão bem sucedida deveria ser mostrada. Não sendo confirmada,
    # uma mensagem de exclusão não realizada deveria ser mostrada.
    # O usuário poderá desistir de excluir, escrevendo "cancela" no
    # momento de digitar o nome a ser excluído.
    
    
    
# daqui para cima, definimos subprogramas (ou módulos, é a mesma coisa)
# daqui para baixo, implementamos o programa
# (nosso CRUD, C=create(cadastrar), R=read(recuperar),
# U=update(atualizar), D=delete(remover,apagar)




apresenteSe()

agenda=[['Caio Lucena Andrade','05-06-2005','Rua Confidencial n000','00 4002-8922','00 4002-8922','caio.la@puccampinas.edu.br'], ['Davi Ferreira Alves','24-05-1500','Rua Confidencial n000','00 4002-8922','00 4002-8922','davi.fa@puccampinas.edu.br'], ['Maligno','19-01-1966','Rua Confidencial n000','00 4002-8922','00 4002-8922','andre@puc-campinas.edu.br']] # essa é a listona que deverá conter listinhas

menu=['Cadastrar Contato',\
      'Procurar Contato',\
      'Atualizar Contato',\
      'Listar Contatos',\
      'Excluir Contato',\
      'Sair do Programa']

deseja_terminar_o_programa=False
while not deseja_terminar_o_programa:
    opcao = int(opcaoEscolhida(menu))

    if opcao==1:
        cadastrar(agenda)
    elif opcao==2:
        procurar(agenda)
    elif opcao==3:
        atualizar(agenda)
    elif opcao==4:
        listar(agenda)
    elif opcao==5:
        excluir(agenda)
    else: # opcao==6
        deseja_terminar_o_programa=True
        
print('PROGRAMA ENCERRADO COM SUCESSO!')