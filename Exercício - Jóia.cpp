#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

int main ()
{
	//Esse programa faz o registro de 8 joias e cria um menu com 5 opções.
	setlocale (LC_ALL, "Portuguese");
	int registro, i, j, acha, alterar;
	char pesq[50], x[50];
	struct cad_joia
	{
		char nome[50];
		char codigo[50];
		char tipo[50];
		float preco;
	};
	struct cad_joia joia[8];
	registro=0;
	while (registro<=5)
	{
		printf ("\nRegistro\n");
		printf ("\nCadastro: 1");
		printf ("\nPesquisa pelo código da jóia: 2");
		printf ("\nOrdem alfabética dos nomes: 3");
		printf ("\nAlteração do preço: 4");
		printf ("\nFim: 5");
		printf ("\nSelecione a opção desejada: ");
		scanf ("%i", &registro);
		switch (registro)
		{
			case 1:
				{
					printf ("\nCadastro");
					for (i=0; i<8; i++)
					{
						printf ("\nInforme o %iº: ", i+1);
						printf ("\nNome: ");
						fflush(stdin); fgets (joia[i].nome, 50, stdin);
						printf ("Código: ");
						fflush(stdin); fgets (joia[i].codigo, 50, stdin);
						printf ("Tipo: ");
						fflush(stdin); fgets (joia[i].tipo, 50, stdin);
						printf ("Preço: ");
						scanf ("%f", &joia[i].preco);
					}
					getchar();
					system("cls");
				}
			break;
			case 2:
				{
					printf ("\nPesquisa pelo código da jóia\n");
					printf ("Informe o código a ser pesquisado: ");
					fflush(stdin); fgets (pesq, 50, stdin);
					i=0;
					acha=0;
					while (i<8 && acha==0)
					{
						if (strcmp(joia[i].codigo, pesq)==0)
                		acha=1;
						else
						i=i+1;
                    }
					if (acha==1)
                    {
						printf ("\nO código foi localizado na %iº posição", i+1);
						printf ("\nRegistro\n");
						printf ("Nome: %s", joia[i].nome);
						printf ("Código: %s", joia[i].codigo);
						printf ("Tipo: %s", joia[i].tipo);
						printf ("Preço: %.2f\n", joia[i].preco);
						getchar();
						system("cls");
					}
                	else 
                	{
                		printf ("O código não foi localizado\n");
                    	getchar();
						system("cls");
					}
				}
			break;
			case 3:
				{
					printf ("\nOrdem alfabética dos nomes\n");
					for (i=0; i<7; i++)
					for (j=i+1; j<8; j++)
					{
						if (strcmp(joia[i].nome, joia[j].nome)>0)
						{
							strcpy(x, joia[i].nome);
							strcpy(joia[i].nome, joia[j].nome);
							strcpy(joia[j].nome, x);
						}
					}
					for (i=0; i<8; i++)
					{
						printf ("%s", joia[i].nome);
						getche();
					}
					system("cls");
				}
			break;
			case 4:
				{
					printf ("\nAlteração do preço\n");
					printf ("Informe o código da jóia que terá seu preço alterado: ");
					fflush(stdin); fgets (pesq, 50, stdin);
					i=0;
					acha=0;
					while (i<8 && acha==0)
					{
						if (strcmp(joia[i].codigo, pesq)==0)
                		acha=1;
						else
						i=i+1;
                    }
					if (acha==1)
                    {
						printf ("\nO código foi localizado na %iº posição.", i+1);
						printf ("\nRegistro\n");
						printf ("Nome: %s", joia[i].nome);
						printf ("Código: %s", joia[i].codigo);
						printf ("Tipo: %s", joia[i].tipo);
						printf ("Preço: %.2f\n", joia[i].preco);
								
						printf ("\nInforme o novo preço: ");
						scanf ("%f", &joia[i].preco);
						printf ("Alteração concluída.");
						getche();
						system("cls");
					}
					else 
                	{
                		printf ("O código não foi localizado\n");
                    	getchar();
						system("cls");
					}
				}
			break;
			case 5:
				{
					printf ("\nSaindo do registro...");
					getch();
					return 0;
				}
			break;
			default: printf ("\nNúmero Inválido");
		}
	}
	getch();
	return 0;
}
