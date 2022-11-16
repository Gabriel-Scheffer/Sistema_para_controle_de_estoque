#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int opcao()
{
	int opc=0;
	printf("\n 1 - Cadastrar metal \n 2 - Remover metal \n "
	"3 - Quantidade de chapas estocadas por tipo \n 4 - Tipos de chapas"
    " sem estoque \n 5 - Quantidade total de chapas estocadas \n 6 - Quantidade"
	"de metros quadrados estocados \n 7 - Alteração da quantidade de chapas estocadas\n"
	" 8 - Fim \n Digite a opção desejada: "); 
	scanf("%d", &opc);
	return opc;
}


void conclu()
{
	printf("\n ******** AÇÃO REALIZADA COM SUCESSO ********** \n");
}





main()
{	
	setlocale(LC_ALL, "PORTUGUESE");
	printf("Sistema de controle de estoque:");
	printf("\n\nLembrete sobre tipos de chapas \n 1 tipo - Largura de 140 cm \n 2 tipo"
	"- Largura de 80 cm \n 3 tipo - Largura de 50 cm\n ");

	int opc=0, cod=0, i=0, tipo=0, qtd=0, vet1[5]={0}, vet2[5]={0};

	while (opc!=8)
	{
		switch (opcao())
		{
			case 1: 
				{
					printf("\n \nAdicionar metal - Selecionado(a).\n");	
					i=cod;
					if (cod<5)
					{
						printf("Digite o tipo do metal:");
						scanf("%d", &tipo);
						printf("digite a quantidade:");
						scanf("%d", &qtd);
							if (tipo<=3 && tipo>=1)
							{
								if (qtd>=1 && qtd<=5)
								{
									vet1[i]=tipo;
									vet2[i]=qtd;
								}
							}
							else 
							{
								printf("\nTipo do metal inválido.\n");
								cod--;
								i--;
							}
						
						printf("\nEstoque atual: \n");
						for (i=0; i<5;i++)
						{
							printf("Código %d = TIPO %d ||| QTD %d \n",i ,vet1[i], vet2[i]);
						}	
					}
						else 
							{
								printf("Quantidade máxima de proudutos atingida.\n");
							}
							conclu();
							cod++;
				}
				break;
			case 2: 
				{
					printf("\n Remover metal - Selecionado(a).\n");
					printf("Digite o código do produto que deseja ser removido:");
					scanf("%d", &cod);
					i=cod;
					if (vet1[i] >0 )
						{
							vet1[i]=0;
							vet2[i]=0;
							printf("\n \n Produto removido\n Estoque atual:\n");
							for (i=0; i<5;i++)
										{
											printf("%d e %d \n", vet1[i], vet2[i]);
										}	
						}
							else
								{
									printf("\n Não existe produto cadastrado no código: %d", i);
								}
				
					
				}
				conclu();
				break;
			case 3:
				{
					{
				printf("\nVisualizar quantidade de chapas estocadas por tipo - Selecionado(a).\n");
				printf("Qual tipo de chapa você deseja visualizar o estoque:");
				scanf("%d", &tipo);
				i=tipo;
				if (tipo>=1 && tipo<=3)
				{
					for (i=0; i<5;i++)
					{
						if (vet1[i]==tipo)
						{
							printf("\nMetal do tipo %d temos %d unidade(s) no estoque\n", vet1[i], vet2[i]);
						}
					}
				}
				else 
				{
					printf("Tipo Inválido.\n");
				}
				conclu();		
			
			}
							break;
						case 4: 
							{
								int cont1=0,cont2=0,cont3=0;
								printf("Tipos de chapas sem estoque - Selecionado(a).\n");
								int falta;
								for (i=0; i<5;i++)
								{
									if (vet1[i]==1)
									{
										cont1++;
									}
									if (vet1[i]==2)
									{
										cont2++;
									}
									if (vet1[i]==3)
									{
										cont3++;
									}
								}
								if (cont1<=0)
								{
									printf("O tipo 1 está em falta\n");
								}
								if (cont2<=0)
								{
									printf("O tipo 2 está em falta\n");
								}	
								if (cont3<=0)
								{
									printf("O tipo 3 está em falta\n");
								}
								else 
								{
									if (cont1>=1 && cont2>=1 && cont3>=1)
									{
										printf("\nTodas as chapas estão em estoque\n");
									}
								}
								
							}
				break;
			case 5:
				{
	
					int total;	
					
					printf ("Quantidade total de chapas de metal estocados - Selecionado(a).\n");
					for (i=0;i<5;i++)
					{
						total= total+vet2[i];
					}
					printf("\nO total de chapas estocadas é de %d unidades", total);
					}
				
								break;
			case 6:
				{
					float metros1,metros2, metros3;
					printf("\nQuantidade de metros quadrados estocados - Selecionado(a).\n");
					for (i=0; i<5;i++)
					{
						if (vet1[i]==1)
						{
							metros1=vet2[i]*3;
						}
						if (vet1[i]==2)
						{
							metros2=vet2[i]*2.5;
						}
						if (vet1[i]==3)
						{
							metros3=vet2[i]*6;
						}
					}
					
					printf("Metal do tipo 1 = %.2f Metros quadrados\n"
							"Metal do tipo 2 = %.2f Metros quadrados\n"
							"Metal do tipo 3 = %.2f Metros quadrados\n", metros1, metros2, metros3);	
					
				}
				break;
			case 7:
				{
					int operacao;
					printf("\n Alteração da quantidade de chapas estocadas - Selecionado(a).\n");
					printf("Digite o código do produto que deseja alterar a quantidade:");
					scanf("%d", &cod);
					i=cod;
					
					
					if (vet1[i]>0)
					{
						printf("Para adicionar chapas digite = 1 \n para remover chapas digite = 2 \n opção:");
						scanf("%d", &operacao);
							if (operacao==1)
								{
									printf("Quantas chapas deseja adicionar no produto %d", cod);
									scanf("%d", &qtd);
									vet2[i]=qtd+vet2[i];
									if(vet2[i]<=5)
									{
										printf("Quantidade adicionada.");
									}
									else
									{
										printf("Quantidade máxima atingida, nada foi adicionado.");
										vet2[i]=vet2[i]-qtd;
									}
								}
								else
									{
										if (operacao==2)
										{
											printf("Quantas chapas deseja remover no produto %d", cod);
											scanf("%d", &qtd);
											vet2[i]=vet2[i]-qtd;
										}
									}
					}
					else
					{
						printf("\nnão existe produto nesse código.");
					}
					
					printf("\nEstoque atual:\n");
						
					for (i=0; i<5;i++)
						{
							printf("%d e %d \n", vet1[i], vet2[i]);
						}			
					
				}
				
				break;
			case 8:
				printf("\n Fim - Selecionado(a).\n");
				opc=8;
				break;
		}
}
}
}
