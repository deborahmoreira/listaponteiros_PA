//
//  main.cpp
//  08.09 1
//
//  Created by Fabio Calderon on 09/08/18.
//  Copyright © 2018 Fabio Calderon. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 Exercicio de utilizacao de funcoes em conjunto com arrays alocados dinamicamente (ponteiros)
 
 Nesse exercicio, voce deve definir o novo tipo Matriz utilizando uma struct, que armazena
 tanto o numero de linhas e de colunas de cada matriz quanto o ponteiro
 
 A partir desse tipo Matriz, voce deve programar as funcoes necessarias para executar o programa
 principal a seguir. A ideia eh permitir fazer as operacoes indicadas com matrizes de quaisquer
 dimensoes, fornecidas pelo usuario no momento da execucao (e nao na compilacao).
 
 */

struct Matriz{
    unsigned Linhas;
    unsigned Colunas;
    float** Dados;
};

Matriz novaMatriz (unsigned L, unsigned C);
Matriz produtoMatrizes (const Matriz &A, const Matriz &B);
void leMatriz (Matriz &M);
void imprimeMatriz (const Matriz &M);
void liberaMatriz (Matriz M);


Matriz novaMatriz (unsigned L, unsigned C){
    Matriz tmp;
    /// Validação de parâmetros
    if (L <= 0 || C <= 0){
        cerr << "Erro: dimensão inválida!\n";
        // cerr -> console de erro
        tmp.Linhas = tmp.Colunas = 0;
        tmp.Dados = NULL;
        return tmp;
    }
    tmp.Linhas = L;
    tmp.Colunas = C;
    tmp.Dados = new float* [tmp.Linhas];
    for (int i = 0 ; i < tmp.Linhas ; i++){
        tmp.Dados[i] = new float [tmp.Colunas];
    }
    return tmp;
}


void liberaMatriz (Matriz M){
    for (int i = 0 ; i < M.Linhas ; i++){
        delete [] M.Dados[i];
    }
    delete [] M.Dados;
    // na hora de apagar, tanto faz o que
    M.Linhas = M.Colunas = 0;
    M.Dados = NULL;
    // Proteção contra utilização indevida da matriz liberada
}

Matriz produtoMatrizes (const Matriz &A, const Matriz &B){
    Matriz tmp;
    if (A.Colunas != B.Linhas || A.Linhas <=0 || A.Colunas <= 0 || B.Linhas <=0 || B.Colunas <=0){
        cerr << "Operação inválida: as matries não podem ser multiplicadas!\n";
        tmp.Linhas = tmp.Colunas = 0;
        tmp.Dados = NULL;
        return tmp;
    }
    tmp = novaMatriz(A.Linhas, B.Colunas);
    for (int i = 0 ; i < tmp.Linhas ; i++){
        for (int j = 0 ; j < tmp.Colunas ; j++){
            tmp.Dados[i][j] = 0;
            for (int k = 0 ; k < A.Colunas ; k++){
                tmp.Dados[i][j] += A.Dados[i][k] * B.Dados[k][j];
            }
        }
    }
    return tmp;
}

void leMatriz (Matriz &M){
    for (int i = 0 ; i < M.Linhas ; i++){
        for (int j = 0 ; j < M.Colunas ; j++){
            cout << "[" << i << "," << j << "]: ";
            cin >> M.Dados[i][j];
        }
    }
}

void imprimeMatriz (const Matriz &M){
    for (int i = 0 ; i < M.Linhas ; i++){
        for (int j = 0 ; j < M.Colunas ; j++){
            cout << M.Dados[i][j] << '\t';
            // \t -> caractere especial de tabulação
        }
        cout << endl;
    }
}



// (const XXXXX &XXX) -> apenas por eficiência, para não ter que copiar uma informação à toa


int main(void)
{
    /// Declaracao das matrizes
    Matriz A, B, C;
    
    unsigned NLa, NCa, NLb, NCb;
    do {
        cout << "Linhas de A: ";
        cin >> NLa;
    } while (NLa <= 0);
    do {
        cout << "Colunas de A: ";
        cin >> NCa;
    } while (NCa <= 0);
    // Obs: NLb = NCa
    NLb = NCa;
    do {
        cout << "Colunas de B: ";
        cin >> NCb;
    } while (NCb <= 0);
    
    /// Alocacao das matrizes
    A = novaMatriz(NLa,NCa);
    B = novaMatriz(NLb,NCb);
    
    /// Leitura das matrizes A e B
    leMatriz(A);
    leMatriz(B);
    
    /// produto das matrizes
    C = produtoMatrizes(A,B);
    
    /// Impressao das matrizes
    imprimeMatriz(C);
    
    /// Liberacao das memorias
    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(C);
    
    return  0;
}

