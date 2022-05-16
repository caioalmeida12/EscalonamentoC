#include <conio.h>
#include <stdio.h>
#include <string.h>

// argc armazena a quantidade de parametros passados, enquanto argv armazena os valores dos parametros
int main(int argc, char *argv[])
{
	// Carrega o arquivo com a funcao fopen(nome arquivo, modo)
	FILE *fp = fopen(argv[1], "r");

	if (!fp)
		printf("Não foi possível abrir o arquivo\n");

	else
	{

		char buffer[128];

		// armazena a tabela por linhas | matriz[linha][coluna]
		// as 4 colunas de cada linha são [idProcesso][tempoChegada][tempoRajada][prioridadeProcesso]
		int matriz[20][4];
		int linha = 0;
		int coluna = 0;

		while (fgets(buffer, 128, fp))
		{
			linha++;
			coluna = 0;

			// pula a primeira linha da tabela, para evitar printar o nome das colunas
			// if (linha == 1)
			// continue;

			// reparte as informações a cada virgula
			char *valor = strtok(buffer, ", ");

			// recebe os tokens e organiza em linhas de 4 colunas, para representar cada processo
			while (valor)
			{
				matriz[linha][coluna] = valor;
				valor = strtok(NULL, ", ");
				coluna++;
			}
		}

		// fecha o arquivo
		fclose(fp);
		return 0;
	}
}
