/*OBS: Usar a entrada.txt do tamanho descrito no programa! Caso tenha um arquivo com um tamanho diferente,
basta alterar as variáveis linhas e colunas no main!*/

#include <iostream>
#include <fstream>
#include <unistd.h>

void print_mat(char** mat1, int ls, int cs){

	for(int i = 0; i < ls; i++){
		for(int j = 0; j < cs; j++){
			std::cout << mat1[i][j];
		}
		std::cout << std::endl;
	}
}

/* Função que analisa quantas células estão vivas num vetor de 8 posições */
int counter(char* vetor){
	
	int x = 0;

	for(int rep = 0; rep < 8; rep++){
		if(vetor[rep] == '*'){
			x++;
		}
	}

	return(x);
}

/*Função que calcula quais as modificações nos status das células vivas e mortas. Salva as alterações e inalterações
numa matriz auxiliar "nm". No final da função, a matriz atualizada por uma geração nm sobrescreve a original.*/

void geracao(char** m, int taml, int tamc){
	
	char nm[taml][tamc];

	int nofs= 0;
	char vet[8];

	for(int i = 0; i < taml; i++){
		for(int j = 0; j < tamc; j++){
			if(i == 0 || j == 0 || i == taml-1 || j == tamc-1){
					nm[i][j] = ' ';
					continue;
			}

			nm[i][j] = m[i][j];
			
			/* Loop para pegar às 8 condições ao redor de uma célula, e salvá-los num vetor, para analisar
			com a função count quantos * existem. Desconsidera as células das bordas*/

			for(int rep = 0, l = (i-1), k = (j-1), z = 0; rep < 9; rep++, k++){
				if(i == 0 || j == 0 || i == taml-1 || j == tamc-1){
					break;
			}
				if(k == j && l == i){
					continue;
				}
				if(k == j+2){
					k = j-1;
					l++;
				}
				vet[z] = m[l][k];
				z++;	
			}


			nofs = counter(vet);

			if(m[i][j] == '*' && nofs < 2 || nofs > 3){
				nm[i][j] = ' ';
			}
			if(m[i][j] == ' ' && nofs == 3){
				nm[i][j] = '*';
			}
		}
	}

	for(int i = 0; i < taml; i++){
		for(int j = 0; j < tamc; j++){
			m[i][j] = nm[i][j];
		}
		std::cout << std::endl;
	}
}

		
int main(int argc, char* argv[]){
  
	std::ifstream A1("entrada2.txt");

	char** matriz; char x;
	
	int linhas = 24, colunas = 40;

	matriz = new char*[linhas];
	for(int rep = 0; rep < linhas; rep++){
		matriz[rep] = new char[colunas];
	}


	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			A1 >> std::noskipws >> matriz[i][j];
			std::cout << matriz[i][j];

		}
		std::cout << std::endl;
	}

	while( 1 ){
		geracao(matriz, linhas, colunas);
		sleep(3);
		print_mat(matriz, linhas, colunas);
	}
}
