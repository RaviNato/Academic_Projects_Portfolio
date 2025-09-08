print("#######  Programa para converter temperaturas.   ########");

print(
" [1] celcius\n",\
"[2] fahrenheit\n",\
"[3] kelvin\n",\
"[4] rankine");

tipotemp = int(input("Escolha um tipo de temperatura: "));
if tipotemp != (1 or 2 or 3 or 4): print("Erro: Tipo de temperatura inválida");
valortemp = float(input("Qual o valor da temperatura? "));

print(
" [1] celcius\n",\
"[2] fahrenheit\n",\
"[3] kelvin\n",\
"[4] rankine");

converttemp = int(input("Qual quer converter: "));
if converttemp != (1 or 2 or 3 or 4): print("Erro: Tipo de temperatura inválida");



kelvin = None;

if tipotemp == 1: 
    kelvin = (valortemp + 273.15);

elif tipotemp == 2: 
    kelvin = ((valortemp  - 32) * 5/9 + 273.15);
    
elif tipotemp == 3:
    kelvin = valortemp;

elif tipotemp == 4: 
    kelvin = (valortemp * 5/9);


result = None;

if kelvin is not None:
    if converttemp == 1: 
        result = (kelvin - 273.15);

    elif converttemp == 2: 
        result = ((kelvin - 273.15) * 9/5 + 32);
    
    elif converttemp == 3:
        result = kelvin;

    elif converttemp == 4: 
        result = (kelvin * 1.8);



if kelvin and result != None: print("Sua temperatura deu: ", result);
else: print("Erro: Valores inválidos")



print("Programa encerrado :D");