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

		// armazena a tabela por linhas | matrix[linhas][colunas]
		char matrix[20][4];

		int linha = 0;
		int coluna = 0;

		while (fgets(buffer,
					 128, fp))
		{
			coluna = 0;
			linha++;

			// pula a primeira linha da tabela, para evitar printar o nome das colunas
			// if (linha == 1)
			// continue;

			// reparte as informações a cada virgula
			char *value = strtok(buffer, ", ");

			matrix[linha]
				// recebe os tokens e organiza em grupos de 4, para representar cada processo

				// while (value) {
				// 	// coluna 1
				// 	if (coluna == 0) {
				// 		printf("ID :");
				// 	}

				// 	// coluna 2
				// 	if (coluna == 1) {
				// 		printf("\tChegada. :");
				// 	}

				// 	// coluna 3
				// 	if (coluna == 2) {
				// 		printf("\tRajada :");
				// 	}

				// // coluna 4
				// 	if (coluna == 3) {
				// 		printf("\tPrioridade :");
				// 	}

				// 	printf("%s", value);
				// 	value = strtok(NULL, ", ");
				// 	coluna++;
				// }

				printf("\n");
		}

		// fecha o arquivo
		fclose(fp);
	}
	return 0;
}
