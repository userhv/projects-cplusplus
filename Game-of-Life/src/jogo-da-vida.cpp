#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include "libjdv.h"

/* 
    version: 3.8.beta05
        Patch Notes:
            - Fixed bugs

                            */

char** auxiliar(int linha, int coluna){
    char** matrizAuxiliar;
    matrizAuxiliar = new char*[linha];
    for(int i = 0; i < linha; i++){
        matrizAuxiliar[i] = new char[coluna];
    }
    for(int i = 0 ; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matrizAuxiliar[i][j] = 'O';
        }
    }
    return matrizAuxiliar;
}
void bordasViva(char** matriz_jogo,char** matriz_aux,int i,int j, int linha, int coluna){
    int contador = 0;

    if(i == 0 && j == coluna){
        if(matriz_jogo[i+1][j] == '*') contador++; 
        if(matriz_jogo[i][j-1] == '*') contador++; 
        if(matriz_jogo[i+1][j-1] == '*') contador++;            
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';  
        }
    else if((i == 0) && (j > 0) && (j < coluna)){
        if(matriz_jogo[i][j+1] == '*') contador++; 
        if(matriz_jogo[i+1][j] == '*') contador++; 
        if(matriz_jogo[i+1][j+1] == '*') contador++; 
        if(matriz_jogo[i][j-1] == '*') contador++;  
        if(matriz_jogo[i+1][j-1] == '*') contador++;               
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';           
        }
    else if(i == 0 && j == 0){
        if(matriz_jogo[i][j+1] == '*') contador++; 
        if(matriz_jogo[i+1][j] == '*') contador++; 
        if(matriz_jogo[i+1][j+1] == '*') contador++;            
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';          
        }
    else if((i > 0) && (i < linha) && (j == 0)){
        if(matriz_jogo[i][j+1] == '*') contador++; 
        if(matriz_jogo[i+1][j] == '*') contador++; 
        if(matriz_jogo[i+1][j+1] == '*') contador++; 
        if(matriz_jogo[i-1][j] == '*') contador++;  
        if(matriz_jogo[i-1][j+1] == '*') contador++;               
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';           
        }
    else if( (i == linha) && (j == 0)){
        if(matriz_jogo[i-1][j] == '*') contador++; 
        if(matriz_jogo[i][j+1] == '*') contador++; 
        if(matriz_jogo[i-1][j+1] == '*') contador++;            
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';            
        }
    else if((i == linha) && (j > 0) && (j < coluna)){
        if(matriz_jogo[i][j-1] == '*') contador++; 
        if(matriz_jogo[i-1][j] == '*') contador++; 
        if(matriz_jogo[i-1][j-1] == '*') contador++; 
        if(matriz_jogo[i][j+1] == '*') contador++;  
        if(matriz_jogo[i-1][j+1] == '*') contador++;               
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';           
        }
    else if( i == linha && j == coluna){
        if(matriz_jogo[i-1][j] == '*') contador++; 
        if(matriz_jogo[i][j-1] == '*') contador++; 
        if(matriz_jogo[i-1][j-1] == '*') contador++;            
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';            
        }
    else if((j == coluna) && (i > 0) && (i < linha)){
        if(matriz_jogo[i][j-1] == '*') contador++; 
        if(matriz_jogo[i-1][j] == '*') contador++; 
        if(matriz_jogo[i-1][j-1] == '*') contador++; 
        if(matriz_jogo[i+1][j] == '*') contador++;  
        if(matriz_jogo[i+1][j-1] == '*') contador++;               
        if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';           
        }
    }
void bordasMorta(char** matriz_jogo,char** matriz_aux,int i,int j, int linha, int coluna){    
    int contador = 0;
        if(i == 0 && j == coluna){
            if(matriz_jogo[i+1][j] == '*') contador++; 
            if(matriz_jogo[i][j-1] == '*') contador++; 
            if(matriz_jogo[i+1][j-1] == '*') contador++;            
            if(contador == 3) matriz_aux[i][j] = '*';  
        }
        else if((i == 0) && (j > 0) && (j < coluna)){
            if(matriz_jogo[i][j+1] == '*') contador++; 
            if(matriz_jogo[i+1][j] == '*') contador++; 
            if(matriz_jogo[i+1][j+1] == '*') contador++; 
            if(matriz_jogo[i][j-1] == '*') contador++;  
            if(matriz_jogo[i+1][j-1] == '*') contador++;               
            if(contador == 3) matriz_aux[i][j] = '*';           
        }
        else if(i == 0 && j == 0){
            if(matriz_jogo[i][j+1] == '*') contador++; 
            if(matriz_jogo[i+1][j] == '*') contador++; 
            if(matriz_jogo[i+1][j+1] == '*') contador++;            
            if(contador == 3) matriz_aux[i][j] = '*';          
        }
        else if((i > 0) && (i < linha) && (j == 0)){
            if(matriz_jogo[i][j+1] == '*') contador++; 
            if(matriz_jogo[i+1][j] == '*') contador++; 
            if(matriz_jogo[i+1][j+1] == '*') contador++; 
            if(matriz_jogo[i-1][j] == '*') contador++;  
            if(matriz_jogo[i-1][j+1] == '*') contador++;               
            if(contador == 3) matriz_aux[i][j] = '*';           
        }
        else if( (i == linha) && (j == 0)){
            if(matriz_jogo[i-1][j] == '*') contador++; 
            if(matriz_jogo[i][j+1] == '*') contador++; 
            if(matriz_jogo[i-1][j+1] == '*') contador++;            
            if(contador == 3) matriz_aux[i][j] = '*';            
        }
        else if((i == linha) && (j > 0) && (j < coluna)){
            if(matriz_jogo[i][j-1] == '*') contador++; 
            if(matriz_jogo[i-1][j] == '*') contador++; 
            if(matriz_jogo[i-1][j-1] == '*') contador++; 
            if(matriz_jogo[i][j+1] == '*') contador++;  
            if(matriz_jogo[i-1][j+1] == '*') contador++;               
            if(contador == 3) matriz_aux[i][j] = '*';           
        }
        else if( i == linha && j == coluna){
            if(matriz_jogo[i-1][j] == '*') contador++; 
            if(matriz_jogo[i][j-1] == '*') contador++; 
            if(matriz_jogo[i-1][j-1] == '*') contador++;            
            if(contador == 3) matriz_aux[i][j] = '*';            
        }
        else if((j == coluna) && (i > 0) && (i < linha)){
            if(matriz_jogo[i][j-1] == '*') contador++; 
            if(matriz_jogo[i-1][j] == '*') contador++; 
            if(matriz_jogo[i-1][j-1] == '*') contador++; 
            if(matriz_jogo[i+1][j] == '*') contador++;  
            if(matriz_jogo[i+1][j-1] == '*') contador++;               
            if(contador == 3) matriz_aux[i][j] = '*';           
            }


        }
char** geracao(char** matriz_jogo, int linha, int coluna){
    char** matriz_aux;
    int contador;
    matriz_aux = auxiliar(linha,coluna);   
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            contador = 0;
            if(matriz_jogo[i][j] == '*'){
                if (i == 0 or j == 0 or i == linha-1 or j == coluna-1){
                    bordasViva(matriz_jogo,matriz_aux,i,j,linha,coluna); 
                }
                else{
                    if(matriz_jogo[i][j+1] == '*') contador++; 
                    if(matriz_jogo[i+1][j] == '*') contador++; 
                    if(matriz_jogo[i+1][j+1] == '*') contador++; 
                    if(matriz_jogo[i][j-1] == '*') contador++; 
                    if(matriz_jogo[i-1][j] == '*') contador++;
                    if(matriz_jogo[i-1][j-1] == '*') contador++; 
                    if(matriz_jogo[i+1][j-1] == '*') contador++; 
                    if(matriz_jogo[i-1][j+1] == '*') contador++;               
                    if(contador < 2 || contador > 3) matriz_aux[i][j] = ' ';
                }
            }
 
            else if(matriz_jogo[i][j] == ' '){
                if (i == 0 or j == 0 or i == linha-1 or j == coluna-1){
                    bordasMorta(matriz_jogo,matriz_aux,i,j,linha,coluna); 
                }
                else{
                    if(matriz_jogo[i][j+1] == '*') contador++; 
                    if(matriz_jogo[i+1][j] == '*') contador++; 
                    if(matriz_jogo[i+1][j+1] == '*') contador++;               
                    if(matriz_jogo[i][j-1] == '*') contador++; 
                    if(matriz_jogo[i-1][j] == '*') contador++;
                    if(matriz_jogo[i-1][j-1] == '*') contador++;
                    if(matriz_jogo[i+1][j-1] == '*') contador++;
                    if(matriz_jogo[i-1][j+1] == '*') contador++;              
                    if(contador == 3) matriz_aux[i][j] = '*';
                }
           }
        }
    }

    for(int i = 0 ; i < linha; i++){
        for(int j = 0; j < coluna ; j++){
            if(matriz_aux[i][j] == ' ' || matriz_aux[i][j] == '*'){
                matriz_jogo[i][j] = matriz_aux[i][j];
            }
        }
    }  
    return matriz_jogo;    
}

int main(int argc, char** argv){
    
    std :: ifstream arquivo;
    char** matrizJogo;
    arquivo.open(argv[1]);   
    std :: string auxiliar;
    int sizeArquivo = 0, sizeLinha;
    if(arquivo.is_open()){
        while(getline(arquivo, auxiliar)){
            sizeLinha = auxiliar.size();
            sizeArquivo++;
        }
    }
    else{
        std :: cout << "Erro ao abrir " << std :: endl;
    }
    //sizeLinha += 1; analisar pra ver se o bug não está aqui
    matrizJogo = new char*[sizeArquivo];
    for(int i = 0; i < sizeArquivo; i++){
        matrizJogo[i] = new char[sizeLinha];
    }
    std :: string linha;
    arquivo.clear();
    arquivo.seekg(0);
    int sizeX = 0, sizeY = 0;
    char caracter;   
    if(arquivo.is_open()){
        while(arquivo >> std :: noskipws >> caracter){
            if(caracter == '\n'){
                sizeX++;
                sizeY = 1;
            }
            else{
                matrizJogo[sizeX][sizeY] = caracter;
                sizeY++;
            }
        }
    }
    else{
        std :: cout << "Erro ao abrir " << std :: endl;
    }
    arquivo.close();   
    for(int i = 0; i < sizeArquivo; i++){
        for(int j = 0; j < sizeLinha; j++){
        std :: cout << matrizJogo[i][j];     
        } 
        std :: cout << std :: endl;
    }
    while(1){       
        matrizJogo = geracao(matrizJogo,sizeArquivo,sizeLinha);//patch inicial corrigido
        for(int i = 0 ; i < sizeArquivo; i++){
            for(int j = 0; j < sizeLinha; j++){
                std :: cout << matrizJogo[i][j];
            } 
            std :: cout << std :: endl;  
        }                   
            sleep(1);
    }
    for(int i = 0; i < sizeArquivo; i++){
        delete [] matrizJogo[i];
    }
    delete[] matrizJogo;
    
    return 0;
}