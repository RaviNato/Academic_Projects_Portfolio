/*   09/09   */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct {
    unsigned int RA, telefone, celular;
} Aluno;
typedef struct {
    unsigned int codigo, duracao/*em anos*/;
} Curso;
typedef struct {
    unsigned int RA, codCurso, semIngr, anoIngr;
} Ingresso;
typedef struct {
    unsigned int id, qtdAulasSemanais;
} Materia;
typedef struct {
    unsigned int RA, turma, idMateria, semestre, ano;
    float nota, frequencia;
} Matricula;




/*
1) Faça uma função em C que, recebendo um vetor de Aluno, 
um vetor de Curso e um vetor de Ingresso, 
bem como as quantidades de elementos de cada um desses vetores, 
descubra quantos alunos ingressaram no meio de algum ano em um curso que dura mais do que 4 anos.
*/
unsigned int QtdAlunosIngressaramMeioAnoCursoMaisQuatroAnos (Aluno*vetA, int tamA, Curso*vetC, int tamC, Ingresso*vetI, int tamI){
    unsigned int contador = 0;
    
    for (int i = 0; i < tamA; i++){
        for (int f = 0; f < tamI; f++){
            if (vetA[i].RA == vetI[f].RA && vetI[f].semIngr == 2){
                for (int n = 0; n < tamC; n++){
                    if (vetI[f].codCurso == vetC[n].codigo && vetC[n].duracao > 4){
                        contador++;
                    }
                }
            }
        }
    }
    return contador;
}



/*
2) Faça uma função em C que, recebendo um vetor de Aluno,
um vetor de Curso e um vetor de Ingresso, bem como as quantidades de elementos de cada um desses vetores,
mostre na tela o telefone de todos os alunos que ingressaram num dado ano em
um curso que dura uma dada duracao.
*/
void TelefoneAlunosEntraramAnoDuracao (Aluno*vetA, int tamA, Curso*vetC, int tamC, Ingresso*vetI, int tamI, unsigned int ano, unsigned int duracao){
    for (int c = 0; c < tamC; c++){
        if (vetC[c].duracao == duracao){
            for (int i = 0; i < tamI; i++){
                if (vetC[c].codigo == vetI[i].codCurso && vetI[i].anoIngr == ano){
                    for (int a = 0; a < tamA; a++){
                        if (vetI[i].RA == vetA[a].RA){
                            printf("%u\n", vetA[a].telefone);
                        }
                    }
                }
            }
        }
    }
}



/*
3) Faça uma função em C que, recebendo um vetor de Aluno,
um vetor de Curso, um vetor de Ingresso, um vetor de Materia,
um vetor de Matricula, bem como as quantidades de elementos de
cada um desses vetores, descubra e retorne quantas matérias não 
tiveram reprovações em nenhuma turma em um dado ano. Caso observe
que tem algum dos vetores acima é desnecessário, elimine-o dos parâmetros.
*/
unsigned int QtdNaoReprovadosEmAno(Materia*vetMate, int tamMate, Matricula*vetMatr, int tamMatr, unsigned int ano){
    unsigned int contador = 0;

    for (int mate = 0; mate < tamMate; mate++){
        unsigned char RAreprovado = 0, MatriComAluno = 0;
        for (int matr = 0; matr < tamMatr; matr++){
            if (vetMate[mate].id == vetMatr[matr].idMateria && vetMatr[matr].ano == ano){
                MatriComAluno = 1;
                if (vetMatr[matr].nota < 5 || vetMatr[matr].frequencia < 0.75){
                    RAreprovado = 1;
                    break;
                }
            }
        }
        if (!RAreprovado && MatriComAluno){
            contador++;
        }
    }
    return contador;
}


/*
4) Faça uma função em C que, recebendo um vetor de Aluno,
um vetorde Curso, um vetor de Ingresso, um vetor de Materia,
um vetor de Matricula, bem como as quantidades de elementos de
cada um desses vetores, descubra e retorne quantos alunos
ingressaram em um dado ano, num curso com uma dada duração,
nunca reprovaram numa materia com uma dada quantidade de aulas
semanais. Caso observe que algum dos vetores acima é desnecessário,
elimine-o dos parâmetros.
*/
unsigned int QtdAlunosIngressaramNumAnoCursoNumaDuracaoQueNaoReprovaramMateriaComQtdAulasSemanais (Curso*vetC, int tamC, Ingresso*vetI, int tamI, Materia*vetMate, int tamMate, Matricula*vetMatr, int tamMatr, unsigned int ano, unsigned int duracao, unsigned int aulasemanais){
    /*Cursos > Ingressos > RA > 
                     materias > matriculas */
    /* alunos que ingressaram em um ANO
    num curso com DURAÇÃO
    nunca reprovaram nas materias com dada QTDAULASSEMANAIS*/
    
    unsigned int RAreprovado, MatriComAluno, contador = 0;
    
    for (int c = 0; c < tamC; c++){
        if (vetC[c].duracao == duracao){
            for (int i = 0; i < tamI; i++){
                if (vetI[i].codCurso == vetC[c].codigo && vetI[i].anoIngr == ano){
                    RAreprovado = 0;
                    MatriComAluno = 0;
                    for (int mate = 0; mate < tamMate; mate++){
                        if (vetMate[mate].qtdAulasSemanais == aulasemanais){
                            for (int matr = 0; matr < tamMatr; matr++){
                                if (vetMatr[matr].idMateria == vetMate[mate].id && vetMatr[matr].RA == vetI[i].RA){
                                    MatriComAluno = 1;
                                    if (vetMatr[matr].nota < 5.0 || vetMatr[matr].frequencia < 0.75){
                                        RAreprovado = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (!RAreprovado && MatriComAluno){
                        contador++;
                    }
                }
            }
        }
    }
    return contador;   
}



int main(){
    Aluno alunos[] = {
    //   RA  telefone celular 
        {25011275, 981179613, 981179613},
        {25019744, 999209414, 999209414},
    };
    Curso cursos[] = {
    //codigo  duracao
        {1, 4},
        {2, 5},
    };
    Ingresso ingressos[] = {
    //RA, codCurso, semIngr, anoIngr
        {25011275, 1, 1, 2025},
        {25019744, 2, 2, 2025},
    };
        Materia materias[] = {
    //   id  qtdAulasSemanais
        {201, 4},
        {202, 3},
        {203, 2},
    };

    Matricula matriculas[] = {
    //    RA,     turma,  idMateria,semestre,ano,  nota, frequencia
        {25011275,     1,      201,    2,  2025,   8.5,    0.90},
        {25011275,     1,      202,    2,  2025,   8.0,    0.80},
        {25019744,     2,      201,    1,  2025,   9.0,    0.95},
        {25019744,     2,      202,    1,  2025,   5.5,    0.75},
    };
    
    
    unsigned int tamA = sizeof(alunos) / sizeof(alunos[0]);
    unsigned int tamC = sizeof(cursos) / sizeof(cursos[0]);
    unsigned int tamI = sizeof(ingressos) / sizeof(ingressos[0]);
    unsigned int tamMate = sizeof(materias) / sizeof(materias[0]);
    unsigned int tamMatr = sizeof(matriculas) / sizeof(matriculas[0]);
    unsigned int ano = 2025, duracao = 4, aulasemanais = 4;
    

    printf("Quantidade de alunos que ingressaram no meio do ano, num curso com mais de quatro anos: %u\n", QtdAlunosIngressaramMeioAnoCursoMaisQuatroAnos(alunos, tamA, cursos, tamC, ingressos, tamI));
    
    printf("Telefone de alunos que ingressaram em %u, num curso com %u anos de duração: \n", ano, duracao);
    TelefoneAlunosEntraramAnoDuracao(alunos, tamA, cursos, tamC, ingressos, tamI, ano, duracao);
    
    printf("Quantidade de matérias sem aluno reprovado em %u: %u\n", ano, QtdNaoReprovadosEmAno(materias, tamMate, matriculas, tamMatr, ano));
    
    printf("Quantidade de alunos que ingressaram em %u, em curso com %u anos de duração, e nunca reprovaram numa matéria com %u aulas semanais: %u", ano, duracao, aulasemanais, QtdAlunosIngressaramNumAnoCursoNumaDuracaoQueNaoReprovaramMateriaComQtdAulasSemanais(cursos, tamC, ingressos, tamI, materias, tamMate, matriculas, tamMatr, ano, duracao, aulasemanais));
    
    
    return 0;
}