#include <iostream>
#include <fstream>
#include <unistd.h>
#define MAX 100000
/* ATENÇÃO ESSE CODIGO NAO FUNCIONA NO SO WINDOWS E TAMBÉM ELE CONTEM BUGS QUE AINDA NAO FORAM SOLUCIONADOS
    ALGUNS ARQUIVOS PODEM GERAR ERROS INESPERADOS , TAL CORREÇÃO SERÁ APLICADA FUTURAMENTE */         

void auxiliar(char** matriz_aux, int linha, int coluna){
    for(int i = 0 ; i < linha; i++){
        for(int j = 0; j < coluna; j++){
                matriz_aux[i][j] = '-';
        }
    }
}
/*Existe uma borda em torno da matriz para que caso uma celula viva esteja nos cantos, o calculo será feito 
    com essa sombra que sempre será morta e não é impressa ou analisada no jogo*/
void sombra(char** matriz_jogo,int linha, int coluna){
    for(int i = 0; i < linha; i++) matriz_jogo[i][0] = ' ';

    for(int j = 0; j < coluna; j++) matriz_jogo[0][j] = ' ';

    for(int i = 0; i < linha; i++) matriz_jogo[i][coluna-1] = ' ';

    for(int j = 0; j < coluna; j++) matriz_jogo[linha-1][j] = ' ';
}

void nova_geracao(char** matriz_jogo, char ** matriz_aux, int linha, int coluna){
    for(int i = 1 ; i < linha-1; i++){
        for(int j = 1; j < coluna-1 ; j++){
            if(matriz_aux[i][j] == ' ' || matriz_aux[i][j] == '*'){
                matriz_jogo[i][j] = matriz_aux[i][j];
            }
        }
    }
}
/*Note que ao analisar cada celula da matriz_jogo a sombra nao é analisada, ela só é valida caso por exemplo
chegue na parte em que i ou j é 1 e ela irá subtrair com 1, sendo somente nesse caso que a sombra é analisada.*/
void geracao(char** matriz_jogo, int linha, int coluna){ 
    char** matriz_aux;
    matriz_aux = new char*[linha];
    for(int i =0 ; i < linha; i++){
        matriz_aux[i] = new char[coluna];
    }
       for(int i = 1 ; i < linha; i++){ 
            for(int j = 1; j < coluna; j++){
                if(matriz_jogo[i][j] == '-'){
                matriz_jogo[i][j] = ' ';
            }
            }
        } 
    int contador;
/*Modificaçoes necessarias pra analisar as mortes(' ') ou vidas( '*' ) sendo substituida apenas na matriz
    auxiliar para que no fim possa sobrescrever a matriz original.*/ 
    auxiliar(matriz_aux,linha,coluna);
    for(int i = 1; i < linha-1  ; i++){
        for(int j = 1; j < coluna-1; j++){
            contador = 0;
            //auxiliar(matriz_aux,linha,coluna);
            if(matriz_jogo[i][j] == '*'){
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
            else if (matriz_jogo[i][j] == ' '){

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

    /* Substitui a matriz auxiliar na nova matriz */
    nova_geracao(matriz_jogo,matriz_aux, linha, coluna);
    for(int i = 0; i < linha; i++){
        delete[] matriz_aux[i];
    }
    delete[] matriz_aux;
}

int main(int argc, char** argv){
    char** matriz_jogo;
    std::ifstream arquivo;
    arquivo.open(argv[1]);
    int linha = 0, coluna;
    char suporte[MAX];
    int i = 0;
    while(!arquivo.eof()){ 
        arquivo.get(suporte[i]);
        if(suporte[i] == ' '){
            i++;
        }
        if(suporte[i] == '*'){
            i++;
        }
        if(suporte[i] == '\n'){
            suporte[i] = '-';
            linha++;
            i++;
        }                
     }
    coluna  = (i / linha);
    matriz_jogo = new char*[linha+2];
    for(int i = 0; i < linha+2; i++){
        matriz_jogo[i] =  new char[coluna+2];
    } 
    int contador = 0, m = 1 , n = 1;
    int aux1 = 0;
    while(aux1 < i){
            
            if(suporte[contador] == '-'){
                matriz_jogo[m][n] = suporte[contador];
                contador++;
                m++;
                n = 1;
            }
            else{
             matriz_jogo[m][n] = suporte[contador];
             n++;
             contador++;
            }
        aux1++;
    }
    n+=1;
    sombra(matriz_jogo,linha+2,coluna+2);     
    arquivo.close();
    int saida = 1;
    int limite_geracao = 0;
    while(saida == 1){
        geracao(matriz_jogo,linha ,coluna);
        for(int i = 0 ; i < linha; i++){ 
            for(int j = 0; j < coluna; j++){
                std::cout << matriz_jogo[i][j];
            }
            std::cout << std::endl;
        }                      
        sleep(1);
        limite_geracao++;
        if (limite_geracao == 30){  // <-- caso queira ver mais gerações altere o valor "30".
            saida = 0;
        }
         sleep(1);
    }
    
    for(int i = 0; i < linha; i++){
        delete[] matriz_jogo[i];
    }
    delete[] matriz_jogo;
    return 0;
}