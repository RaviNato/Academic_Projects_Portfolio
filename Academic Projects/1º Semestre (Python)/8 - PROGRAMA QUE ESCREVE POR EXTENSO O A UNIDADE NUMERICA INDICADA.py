print("##########     PROGRAMA QUE ESCREVE POR EXTENSO O A UNIDADE NUMERICA INDICADA      ##########")
print("")
print("")


try:
    num = int(input("Olá usuário, por favor digite uma UNIDADE numérica!  "));
    
    if num < 0:
        negativo = ("NEGATIVO!");
    else:
        negativo = ("");
    
    print("");
except ValueError:
    print("O valor descrito não é uma unidade inteira :(");
else:
    if num < -9 or num > 9:
        print("O valor descrito não é uma unidade :(");
    else:
        if num == 0:
            print("Sua unidade é ZERO!");
        else:
            if num == -1 or num == 1:
                print("Sua unidade é UM", negativo);
            else:
                if num == -2 or num == 2:
                    print("Sua unidade é DOIS", negativo);
                else:
                    if num == -3 or num == 3:
                        print("Sua unidade é TRÊS", negativo);
                    else:
                        if num == -4 or num == 4:
                            print("Sua unidade é QUATRO", negativo);
                        else:
                            if num == -5 or num == 5:
                                print("Sua unidade é CINCO", negativo);
                            else:
                                if num == -6 or num == 6:
                                    print("Sua unidade é SEIS", negativo);
                                else:
                                    if num == -7 or num == 7:
                                        print("Sua unidade é SETE", negativo);
                                    else:
                                        if num == -8 or num == 8:
                                            print("Sua unidade é OITO", negativo);
                                        else:
                                            if num == -9 or num == 9:
                                                print("Sua unidade é NOVO", negativo);



print("")
print("")
print("##########                         PROGRAMA ENCERRADO XD                           ##########");