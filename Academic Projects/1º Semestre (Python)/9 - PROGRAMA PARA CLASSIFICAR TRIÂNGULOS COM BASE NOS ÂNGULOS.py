print("PROGRAMA PARA CLASSIFICAR TRIÂNGULOS COM BASE NOS ÂNGULOS")
nome=input("Qual é o seu nome? ")

resposta="S"
while resposta=="S":

    três_angulos_não_deram_180=False
    while not três_angulos_não_deram_180:

        dois_angulos_não_deram_180=False
        while not dois_angulos_não_deram_180:

            digitou_direito=False
            while not digitou_direito:
                try: # tentando conseguir a digitação de um número
                    angulo1=float(input("Quanto mede em cm o 1º ângulo? "))
                except ValueError: # quando der ruim
                    print(nome,", o 1º ângulo deve ser numérico!")
                else: # senão, quando não deu ruim
                    if angulo1<=0 or angulo1>=180: # tenho um número, mas está fora da faixa válida
                        print(nome,", o 1º ângulo deve ser maior que 0 e menor que 180 graus!")
                    else: # tenho o 1º angulo apropriadamente digitado
                        digitou_direito=True


            digitou_direito=False
            while not digitou_direito:
                try: # tentando conseguir a digitação de um número
                    angulo2=float(input("Quanto mede em cm o 2º ângulo? "))
                except ValueError: # quando der ruim
                    print(nome,", o 2º ângulo deve ser numérico!")
                else: # senão, quando não deu ruim
                    if angulo2<=0 or angulo2>=180: # tenho um número, mas está fora da faixa válida
                        print(nome,", o 2º ângulo deve ser maior que 0 e menor que 180 graus!")
                    else: # tenho o 2º angulo apropriadamente digitado
                        digitou_direito=True

            if angulo1+angulo2>=180:
                print(nome,", esses ângulos não podem ser ângulos de um triângulo!")                        
            else:
                dois_angulos_não_deram_180=True
                            


        digitou_direito=False
        while not digitou_direito:
            try: # tentando conseguir a digitação de um número
                angulo3=float(input("Quanto mede em cm o 3º ângulo? "))
            except ValueError: # quando der ruim
                print(nome,", o 3º ângulo deve ser numérico!")
            else: # senão, quando não deu ruim
                if angulo3<=0 or angulo3>=180: # tenho um número, mas está fora da faixa válida
                    print(nome,", o 3º ângulo deve ser maior que 0 e menor que 180 graus!")
                else: # tenho o 3º angulo apropriadamente digitado
                    digitou_direito=True
                    
        if angulo1+angulo2+angulo3!=180: # individualmente, todos os angulos estão OK, mas, em conjunto, não combinam para formar um triângulo
            print(nome,", esses ângulos não podem ser ângulos de um triângulo!")                        
        else:
            três_angulos_não_deram_180=True # tenho os 3 ângulos de um triângulo


    if angulo1<90 and angulo2<90 and angulo3<90: # tenho 3 ângulos agudos, "pontudinhos"
        print(nome,", trata-se de um triângulo acutângulo!")
    else: # acutângulo, o triângulo não é
        if angulo1==90 or angulo2==90 or angulo3==90: # tenho um ângulo reto
            print(nome,", trata-se de um triângulo retângulo!")
        else: # nem acutângulo, nem retângulo o triângulo é; o que sobrou?
            print(nome,", trata-se de um triângulo obtusângulo!")


    digitou_direito=False
    while not digitou_direito:
        resposta=input("Deseja classificar mais triângulos, (S/N)? ")
        resposta=resposta.upper()
        if resposta!="S" and resposta!="N":
            print("Você deve responder S ou N; tente novamente")
        else:
            digitou_direito=True



print("PROGRAMA ENCERRADO!")