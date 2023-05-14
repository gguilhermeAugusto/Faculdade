#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define tfc 100
#define tfpi 100
#define tfpe 100
#define tfmo 100

struct TpClientes
{
	int cep;
	char nome[30],endereco[30],cidade[30],telefone[15];
};

struct TpPizzas
{
	int codigo;
	float preco;
	char nome[20];
};

struct TpPedido
{
	int numPedido,codPizza,dia,mes,ano,situacao;
	char numTelefone[15],cpfMoto[12];
};

struct TpMotoqueiro
{
	int dia,mes,ano;
	char nome[30],endereco[30],cpf[12],telefone[15];
};

struct TpRankingPizza
{
	int cod,qtde;
};

struct TpGastos
{
	float gasto;
	char tel[15];	
};

struct TpConsumoCliente
{
	char tel[15];
	int qtde;	
};

struct TpMotoEntrega
{
	char cpf[12];
	int qtde;
};

int buscaPedido(TpPedido vetor[],int tl,int elemento);

void tela (int ci,int li,int cf,int lf,int cor)
{
	int i;
	textcolor(cor);	
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,lf);
	printf("%c",188);
	for(i=ci+1;i<cf;i++)
	{
		gotoxy(i,li);
		printf("%c",205);
		gotoxy(i,lf);
		printf("%c",205);
	}
	for(i=li+1;i<lf;i++)
	{
		gotoxy(ci,i);
		printf("%c",186);
		gotoxy(cf,i);
		printf("%c",186);
	}
	textcolor(7);
}

void menu ()
{
	gotoxy(5,7);
	printf("*************MENU*************");
	gotoxy(5,8);
	printf("1 - Cadastro Cliente");
	gotoxy(5,9);
	printf("2 - Cadastro Pizza");
	gotoxy(5,10);
	printf("3 - Cadastro Motoqueiro");
	gotoxy(5,11);
	printf("4 - Inserir Dados Automatico");
	gotoxy(5,12);
	printf("5 - Fazer Pedido");
	gotoxy(5,13);
	printf("6 - Consultar Clientes");
	gotoxy(5,14);
	printf("7 - Consultar Pizzas");
	gotoxy(5,15);
	printf("8 - Consultar Motoqueiros");
	gotoxy(5,16);
	printf("9 - Consultar Pedidos");
	gotoxy(5,17);
	printf("10 - Alterar Dados Cliente");
	gotoxy(5,18);
	printf("11 - Alterar Dados Pizza");
	gotoxy(5,19);
	printf("12 - Alterar Dados Motoqueiro");
	gotoxy(5,20);
	printf("13 - Alterar Pedido");
	gotoxy(5,21);
	printf("14 - Buscar Cliente(TELL)");
	gotoxy(5,22);
	printf("15 - Buscar Pizza(COD)");
	gotoxy(5,23);
	printf("16 - Buscar Motoqueiro(CPF)");
	gotoxy(5,24);
	printf("17 - Buscar Pedido(NUM)");
	gotoxy(5,25);
	printf("18 - Excluir Cliente");
	gotoxy(5,26);
	printf("19 - Excluir Pizza");
	gotoxy(5,27);
	printf("20 - Excluir Motoqueiro");
	gotoxy(5,28);
	printf("21 - Excluir Pedido");
	gotoxy(5,29);
	printf("22 - Mais opcoes");
	gotoxy(5,30);
	printf("0 - Sair");
}

void menu2 ()
{
	gotoxy(5,7);
	printf("                              ");
	gotoxy(5,7);
	printf("**********RELATORIOS**********");
	gotoxy(5,8);
	printf("                              ");
	gotoxy(5,8);
	printf("23 - Motoqueiro Pizza Periodo");
	gotoxy(5,9);
	printf("                              ");
	gotoxy(5,9);
	printf("24 - Busca Cliente(1 LETRA)");
	gotoxy(5,10);
	printf("                              ");
	gotoxy(5,10);
	printf("25 - Busca Cliente(TRECHO)");
	gotoxy(5,11);
	printf("                              ");
	gotoxy(5,11);
	printf("26 - Ranking de Pizzas");
	gotoxy(5,12);
	printf("                              ");
	gotoxy(5,12);
	printf("27 - Gasto dos Clientes");
	gotoxy(5,13);
	printf("                              ");;
	gotoxy(5,13);
	printf("28 - Pizzas em Andamento");
	gotoxy(5,14);
	printf("                              ");
	gotoxy(5,14);
	printf("29 - Pizzas a Caminho");
	gotoxy(5,15);
	printf("                              ");
	
	gotoxy(5,16);
	printf("                              ");
	gotoxy(5,16);
	printf("*********ESTATISTICAS*********");
	gotoxy(5,17);
	printf("                              ");
	gotoxy(5,17);
	printf("30 - Pizza Mais Pedida");
	gotoxy(5,18);
	printf("                              ");
	gotoxy(5,18);
	printf("31 - Pizza Menos Pedida");
	gotoxy(5,19);
	printf("                              ");
	gotoxy(5,19);
	printf("32 - Cliente Mais Consome");
	gotoxy(5,20);
	printf("                              ");
	gotoxy(5,20);
	printf("33 - Mais Consome(PIZZA)");
	gotoxy(5,21);
	printf("                              ");
	gotoxy(5,21);
	printf("34 - Qtde Pizzas Em Um Dia");
	gotoxy(5,22);
	printf("                              ");
	gotoxy(5,22);
	printf("35 - Motoqueiro + EXP");
	gotoxy(5,23);
	printf("                              ");
	gotoxy(5,23);
	printf("36 - Motoqueiro - EXP");
	gotoxy(5,24);
	printf("                              ");
	gotoxy(5,24);
	printf("37 - Motoqueiro + Entrega(DIA)");
	gotoxy(5,25);
	printf("                              ");
	
	gotoxy(5,26);
	printf("                              ");
	
	gotoxy(5,27);
	printf("                              ");
	
	gotoxy(5,28);
	printf("                              ");
	
	gotoxy(5,29);
	printf("                              ");
	
	gotoxy(5,30);
	printf("                              ");
	
	gotoxy(5,30);
	getch();
}

int buscaCliente (TpClientes vetor[],int tl,char elemento[])
{
	int pos=0;
	while(pos<tl && strcmp(vetor[pos].telefone,elemento)!=0)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void cadastroCliente (TpClientes vetor[],int &tl)
{
	char aux[15];
	gotoxy(41,7);
	printf("Digite o telefone do cliente:");
	gotoxy(71,7);
	fflush(stdin);
	gets(aux);
	if(buscaCliente(vetor,tl,aux)==-1)
	{
		strcpy(vetor[tl].telefone,aux);
		gotoxy(41,8);
		printf("Digite o nome do cliente:");
		fflush(stdin);
		gotoxy(67,8);
		gets(vetor[tl].nome);
		gotoxy(41,9);
		printf("Digite o endereco do cliente:");
		fflush(stdin);
		gotoxy(71,9);
		gets(vetor[tl].endereco);
		gotoxy(41,10);
		printf("Digite a cidade do cliente:");
		fflush(stdin);
		gotoxy(69,10);
		gets(vetor[tl].cidade);
		gotoxy(41,11);
		printf("Digite o CEP do cliente:");
		gotoxy(66,11);
		scanf("%d",&vetor[tl].cep);
		tl++;
		gotoxy(41,13);
		printf("Cliente cadastrado!");
		getch();
	}
	else
	{
		gotoxy(41,9);
		printf("Cliente ja cadastrado!");
		getch();
	}
}

int buscaPizza(TpPizzas vetor[],int tl,int elemento)
{
	int pos=0;
	while(pos<tl && vetor[pos].codigo!= elemento)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void cadastroPizza(TpPizzas vetor[],int &tl)
{
	int aux;
	gotoxy(41,7);
	printf("Digite o codigo da pizza:");
	gotoxy(67,7);
	scanf("%d",&aux);
	if(buscaPizza(vetor,tl,aux)==-1)
	{
		vetor[tl].codigo = aux;
		gotoxy(41,8);
		printf("Digite o nome da pizza:");
		fflush(stdin);
		gotoxy(65,8);
		gets(vetor[tl].nome);
		gotoxy(41,9);
		printf("Digite o valor da pizza:");
		gotoxy(66,9);
		scanf("%f",&vetor[tl].preco);
		tl++;
		gotoxy(41,11);
		printf("Pizza cadastrada!");
		getch();
	}
	else
	{
		gotoxy(41,9);
		printf("Pizza ja cadastrada!");
		getch();
	}
}

int buscaMotoqueiro (TpMotoqueiro vetor[],int tl,char elemento[])
{
	int pos=0;
	while(pos<tl && strcmp(vetor[pos].cpf,elemento)!=0)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

int validaCPF (char aux[])
{
	int vcpf[11],dig1,dig2,i,mult,soma=0,resto;
	for(i=0;i<11;i++)
	{
		vcpf[i]= (aux[i]-48);
	}
	for(i=0,mult=10;i<9;i++,mult--)
	{
		soma+=vcpf[i]*mult;
	}
	resto = soma%11;
	dig1 = 11-resto;
	if(dig1 == 11 || dig1 == 10)
	{
		dig1 = 0;
	}
	if(dig1 == vcpf[9])
	{
		soma = 0;
		for(i=0,mult=11;i<10;i++,mult--)
		{
			soma+=vcpf[i]*mult;
		}
		resto = soma%11;
		dig2 = 11-resto;
		if(dig2 == 11|| dig2 == 10)
		{
			dig2 = 0;
		}
		if(dig2==vcpf[10])
		{
			return 1; //valido
		}
		else
		{
			return 0; //invalido
		}
	}
	else
	{
		return 0; //invalido
	}
}

void cadastroMotoqueiro (TpMotoqueiro vetor[], int &tl)
{
	char aux[11];
	gotoxy(41,7);
	printf("Digite o CPF do motoqueiro:");
	gotoxy(69,7);
	fflush(stdin);
	gets(aux);
	if(validaCPF(aux))
	{
		if(buscaMotoqueiro(vetor,tl,aux)==-1)
		{
			strcat(vetor[tl].cpf,aux);
			gotoxy(41,8);
			printf("Digite o nome do motoqueiro:");
			fflush(stdin);
			gotoxy(70,8);
			gets(vetor[tl].nome);
			gotoxy(41,9);
			printf("Digite o endereco do motoqueiro:");
			fflush(stdin);
			gotoxy(74,9);
			gets(vetor[tl].endereco);
			gotoxy(41,10);
			printf("Digite o telefone do motoqueiro:");
			gotoxy(74,10);
			fflush(stdin);
			gets(vetor[tl].telefone);
			gotoxy(41,11);
			printf("Digite a data de admissao do motoqueiro:");
			gotoxy(82,11);
			scanf("%d %d %d",&vetor[tl].dia,&vetor[tl].mes,&vetor[tl].ano);
			tl++;
			gotoxy(41,13);
			printf("Motoqueiro cadastrado!");
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Motoqueiro ja cadastrado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,9);
		printf("CPF invalido!");
		getch();
	}
}

void inserir (TpClientes cliente[],int &tlc,TpPizzas pizza[],int &tlpi,TpMotoqueiro motoqueiro[],int &tlmo,TpPedido pedido[],int &tlpe)
{
	char auxTel[15],auxCPF[12];
	int auxCod,auxPedido;
	
	strcpy(auxTel,"1163423312");
	auxCod = 1;
	strcpy(auxCPF,"51245796844");
	auxPedido = 1;
	
	if(buscaCliente(cliente,tlc,auxTel)==-1 && buscaPizza(pizza,tlpi,auxCod)==-1 && buscaMotoqueiro(motoqueiro,tlmo,auxCPF)==-1 && buscaPedido(pedido,tlpe,auxPedido)==-1)
	{
		strcpy(cliente[tlc].telefone,"1163423312");
		strcpy(cliente[tlc].nome,"Mariana");
		strcpy(cliente[tlc].endereco,"Avenida dos Nacionalistas"); 
		strcpy(cliente[tlc].cidade,"Sao Paulo");
		cliente[tlc].cep = 01311000;
		tlc++;
		pizza[tlpi].codigo = 1;
		strcpy(pizza[tlpi].nome,"Calabresa");
		pizza[tlpi].preco = 50;
		tlpi++;
		strcpy(motoqueiro[tlmo].cpf,"51245796844");
		strcpy(motoqueiro[tlmo].nome,"Vitor");
		strcpy(motoqueiro[tlmo].endereco,"Rua Serra de Maracaju");
		strcpy(motoqueiro[tlmo].telefone,"1199465679");
		motoqueiro[tlmo].dia = 25;
		motoqueiro[tlmo].mes = 04;
		motoqueiro[tlmo].ano = 2019;
		tlmo++;
		pedido[tlpe].numPedido = 1;
		strcpy(pedido[tlpe].numTelefone,"1163423312");
		pedido[tlpe].codPizza = 1;
		strcpy(pedido[tlpe].cpfMoto,"51245796844");
		pedido[tlpe].situacao = 1;
		pedido[tlpe].dia = 4;
		pedido[tlpe].mes = 1;
		pedido[tlpe].ano = 2021;
		tlpe++;
		gotoxy(41,7);
		printf("Dados 1 inseridos");
	}
	else
	{
		gotoxy(41,7);
		printf("Dados 1 nao podem ser inseridos");
	}
	
	strcpy(auxTel,"1182695524");
	auxCod = 2;
	strcpy(auxCPF,"31591775809");
	auxPedido = 2;
	
	if(buscaCliente(cliente,tlc,auxTel)==-1 && buscaPizza(pizza,tlpi,auxCod)==-1 && buscaMotoqueiro(motoqueiro,tlmo,auxCPF)==-1 && buscaPedido(pedido,tlpe,auxPedido)==-1)
	{
		strcpy(cliente[tlc].telefone,"1182695524");
		strcpy(cliente[tlc].nome,"Daniela");
		strcpy(cliente[tlc].endereco,"Rua Francisco Lettiere"); 
		strcpy(cliente[tlc].cidade,"Sao Paulo");
		cliente[tlc].cep = 05655070;
		tlc++;
		pizza[tlpi].codigo = 2;
		strcpy(pizza[tlpi].nome,"Portuguesa");
		pizza[tlpi].preco = 50;
		tlpi++;
		strcpy(motoqueiro[tlmo].cpf,"31591775809"); 
		strcpy(motoqueiro[tlmo].nome,"Mateus");
		strcpy(motoqueiro[tlmo].endereco,"Rua Gaivota 9");
		strcpy(motoqueiro[tlmo].telefone,"1198101017");
		motoqueiro[tlmo].dia = 15;
		motoqueiro[tlmo].mes = 11;
		motoqueiro[tlmo].ano = 2019;
		tlmo++;
		pedido[tlpe].numPedido = 2;
		strcpy(pedido[tlpe].numTelefone,"1182695524");
		pedido[tlpe].codPizza = 2;
		strcpy(pedido[tlpe].cpfMoto,"31591775809");
		pedido[tlpe].situacao = 2;
		pedido[tlpe].dia = 20;
		pedido[tlpe].mes = 8;
		pedido[tlpe].ano = 2021;
		tlpe++;
		gotoxy(41,8);
		printf("Dados 2 inseridos");
	}
	else
	{
		gotoxy(41,8);
		printf("Dados 2 nao podem ser inseridos");
	}
	
	strcpy(auxTel,"1172677941");
	auxCod = 3;
	strcpy(auxCPF,"19350097885");
	auxPedido = 3;
	
	if(buscaCliente(cliente,tlc,auxTel)==-1 && buscaPizza(pizza,tlpi,auxCod)==-1 && buscaMotoqueiro(motoqueiro,tlmo,auxCPF)==-1 && buscaPedido(pedido,tlpe,auxPedido)==-1)
	{
		strcpy(cliente[tlc].telefone,"1172677941");
		strcpy(cliente[tlc].nome,"Raul");
		strcpy(cliente[tlc].endereco,"Praca Serra dos Tapes"); 
		strcpy(cliente[tlc].cidade,"Sao Paulo");
		cliente[tlc].cep = 03615020;
		tlc++;
		pizza[tlpi].codigo = 3;
		strcpy(pizza[tlpi].nome,"Marguerita");
		pizza[tlpi].preco = 50;
		tlpi++;
		strcpy(motoqueiro[tlmo].cpf,"19350097885");
		strcpy(motoqueiro[tlmo].nome,"Caio");
		strcpy(motoqueiro[tlmo].endereco,"Avenida Gustavo Adolfo");
		strcpy(motoqueiro[tlmo].telefone,"1198470576");
		motoqueiro[tlmo].dia = 03;
		motoqueiro[tlmo].mes = 06;
		motoqueiro[tlmo].ano = 2020;
		tlmo++;
		pedido[tlpe].numPedido = 3;
		strcpy(pedido[tlpe].numTelefone,"1172677941");
		pedido[tlpe].codPizza = 3;
		strcpy(pedido[tlpe].cpfMoto,"19350097885");
		pedido[tlpe].situacao = 3;
		pedido[tlpe].dia = 25;
		pedido[tlpe].mes = 3;
		pedido[tlpe].ano = 2022;
		tlpe++;
		gotoxy(41,9);
		printf("Dados 3 inseridos");
	}
	else
	{
		gotoxy(41,9);
		printf("Dados 3 nao podem ser inseridos");
	}
	getch();
}


int buscaPedido(TpPedido vetor[],int tl,int elemento)
{
	int pos=0;
	while(pos<tl && vetor[pos].numPedido!=elemento)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void consultarCliente (TpClientes cliente[],int tlc)
{
	int i=0;
	if(tlc>0)
	{
		for(i=0;i<tlc;i++)
		{
			gotoxy(41,7);
			printf("Telefone: %s",cliente[i].telefone);
			gotoxy(41,8);
			printf("Nome: %s",cliente[i].nome);
			gotoxy(41,9);
			printf("Endereco: %s",cliente[i].endereco);
			gotoxy(41,10);
			printf("Cidade: %s",cliente[i].cidade);
			gotoxy(41,11);
			printf("CEP: %d",cliente[i].cep);
			getch();
			gotoxy(41,7);
			printf("                                                    ");
			gotoxy(41,8);
			printf("                                                    ");
			gotoxy(41,9);
			printf("                                                    ");
			gotoxy(41,10);
			printf("                                                    ");
			gotoxy(41,11);
			printf("                                                    ");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Nenhum cliente cadastrado!");
		getch();
	}
}

void consultarPizza (TpPizzas pizza[],int tlpi)
{
	int i=0;
	if(tlpi>0)
	{
		for(i=0;i<tlpi;i++)
		{
			gotoxy(41,7);
			printf("Codigo: %d",pizza[i].codigo);
			gotoxy(41,8);
			printf("Nome: %s",pizza[i].nome);
			gotoxy(41,9);
			printf("Preco: %.2f",pizza[i].preco);
			getch();
			gotoxy(41,7);
			printf("                                                    ");
			gotoxy(41,8);
			printf("                                                    ");
			gotoxy(41,9);
			printf("                                                    ");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Nenhuma pizza cadastrada!");
		getch();
	}
}

void consultarMoto (TpMotoqueiro motoqueiro[],int tlmo)
{
	int i =0;
	if(tlmo>0)
	{
		for(i=0;i<tlmo;i++)
		{
 			gotoxy(41,7);
			printf("CPF: %s",motoqueiro[i].cpf);
			gotoxy(41,8);
			printf("Nome: %s",motoqueiro[i].nome);
			gotoxy(41,9);
			printf("Endereco: %s",motoqueiro[i].endereco);
			gotoxy(41,10);
			printf("Tell: %s",motoqueiro[i].telefone);				
			gotoxy(41,11);
			printf("Admissao: %d/%d/%d",motoqueiro[i].dia,motoqueiro[i].mes,motoqueiro[i].ano);
			getch();
			gotoxy(41,7);
			printf("                                                    ");
			gotoxy(41,8);
			printf("                                                    ");
			gotoxy(41,9);
			printf("                                                    ");
			gotoxy(41,10);
			printf("                                                    ");
			gotoxy(41,11);
			printf("                                                    ");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Nenhum motoqueiro cadastrado!");
		getch();
	}
}

void consultarPedido (TpPedido pedido[],int tlpe)
{
	int i=0;
	if(tlpe>0)
	{
		for(i=0;i<tlpe;i++)
		{
			gotoxy(41,7);
			printf("Numero: %d",pedido[i].numPedido);
			gotoxy(41,8);
			printf("Telefone cliente: %s",pedido[i].numTelefone);
			gotoxy(41,9);
			printf("Cod pizza: %d",pedido[i].codPizza);
			gotoxy(41,10);
			printf("CPF motoqueiro: %s",pedido[i].cpfMoto);
			gotoxy(41,11);
			printf("Situacao: %d",pedido[i].situacao);
			gotoxy(41,12);
			printf("Data do pedido: %d/%d/%d",pedido[i].dia,pedido[i].mes,pedido[i].ano);
			getch();
			gotoxy(41,7);
			printf("                                                    ");
			gotoxy(41,8);
			printf("                                                    ");
			gotoxy(41,9);
			printf("                                                    ");
			gotoxy(41,10);
			printf("                                                    ");
			gotoxy(41,11);
			printf("                                                    ");
			gotoxy(41,12);
			printf("                                                    ");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Nenhum pedido para mostrar!");
		getch();
	}
}

void fazerPedido (TpPedido pedido[], int &tlpe,TpClientes cliente[],int tlc,TpPizzas pizza[],int tlpi,TpMotoqueiro motoqueiro[],int tlmo)
{
	int auxPedido,auxCod;
	char auxCPF[11],auxTel[15];
	if(tlc>0)
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido:");
		gotoxy(68,7);
		scanf("%d",&auxPedido);
		if(buscaPedido(pedido,tlpe,auxPedido)==-1)
		{
			pedido[tlpe].numPedido = auxPedido;
			gotoxy(41,8);
			printf("Digite o telefone do cliente:");
			gotoxy(71,8);
			fflush(stdin);
			gets(auxTel);
			if(buscaCliente(cliente,tlc,auxTel)>-1)
			{
				strcpy(pedido[tlpe].numTelefone,auxTel);
				gotoxy(41,9);
				printf("Digite o codigo da pizza:");
				gotoxy(67,9);
				scanf("%d",&auxCod);
				if(buscaPizza(pizza,tlpi,auxCod)>-1)
				{
					pedido[tlpe].codPizza = auxCod;
					gotoxy(41,10);
					printf("Digite o CPF do motoqueiro:");
					gotoxy(69,10);
					fflush(stdin);
					gets(auxCPF);
					if(validaCPF(auxCPF))
					{
						if(buscaMotoqueiro(motoqueiro,tlmo,auxCPF)>-1)
						{
							strcpy(pedido[tlpe].cpfMoto,auxCPF);
							gotoxy(41,11);
							printf("Digite a situacao do pedido:");
							gotoxy(70,11);
							scanf("%d",&pedido[tlpe].situacao);
							gotoxy(41,12);
							printf("Digite a data do pedido:");
							gotoxy(66,12);
							scanf("%d %d %d",&pedido[tlpe].dia,&pedido[tlpe].mes,&pedido[tlpe].ano);
							tlpe++;
							gotoxy(41,14);
							printf("Pedido Realizado!");
							getch();
						}
						else
						{
							gotoxy(41,12);
							printf("Motoqueiro nao cadastrado!");
							getch();
						}
					}
					else
					{
						gotoxy(41,12);
						printf("CPF invalido");
						getch();
					}
				}
				else
				{
					gotoxy(41,11);
					printf("Pizza nao cadastrada!");
					getch();
				}
			}
			else
			{
				gotoxy(41,10);
				printf("O cliente nao esta cadastrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("O pedido ja foi realizado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem clientes!");
		getch();
	}
}

void alterarCliente (TpClientes vetor[],int tl)
{
	int pos;
	char aux[15];
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente:");
		gotoxy(71,7);
		fflush(stdin);
		gets(aux);
		pos = buscaCliente(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,8);
			printf("Digite o nome do cliente:");
			gotoxy(66,8);
			fflush(stdin);
			gets(vetor[pos].nome);
			gotoxy(41,9);
			printf("Digite o endereco do cliente:");
			gotoxy(70,9);
			fflush(stdin);
			gets(vetor[pos].endereco);
			gotoxy(41,10);
			printf("Digite a cidade do cliente:");
			gotoxy(69,10);
			fflush(stdin);
			gets(vetor[pos].cidade);
			gotoxy(41,11);
			printf("Digite o CEP do cliente:");
			gotoxy(66,11);
			scanf("%d",&vetor[pos].cep);
			gotoxy(41,13);
			printf("Dados Atualizados!");
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Cliente nao encontrado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Clientes Cadastrados!");
		getch();
	}
}

void alterarPizza (TpPizzas vetor[],int tl)
{
	int aux,pos;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza:");
		gotoxy(67,7);
		scanf("%d",&aux);
		pos = buscaPizza(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,8);
			printf("Digite o nome da pizza:");
			gotoxy(66,8);
			fflush(stdin);
			gets(vetor[pos].nome);
			gotoxy(41,9);
			printf("Digite o preco da pizza:");
			gotoxy(66,9);
			scanf("%f",&vetor[pos].preco);
			gotoxy(41, 11);
			printf("Dados Atualizados!");
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pizzas Cadastradas!");
		getch();
	}
}

void alterarMoto (TpMotoqueiro vetor[],int tl)
{
	int pos;
	char aux[11];
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro:");
		gotoxy(69,7);
		fflush(stdin);
		gets(aux);
		if(validaCPF(aux))
		{
			pos = buscaMotoqueiro(vetor,tl,aux);
			if(pos>-1)
			{
				gotoxy(41,8);
				printf("Digite o nome do motoqueiro:");
				gotoxy(70,8);
				fflush(stdin);
				gets(vetor[pos].nome);
				gotoxy(41,9);
				printf("Digite o endereco do motoqueiro:");
				gotoxy(74,9);
				fflush(stdin);
				gets(vetor[pos].endereco);
				gotoxy(41,10);
				printf("Digite o telefone do motoqueiro:");
				gotoxy(74,10);
				fflush(stdin);
				gets(vetor[pos].telefone);
				gotoxy(41,11);
				printf("Digite a data de admissao:");
				gotoxy(68,11);
				scanf("%d %d %d",&vetor[pos].dia,&vetor[pos].mes,&vetor[pos].ano);
				gotoxy(41,13);
				printf("Dados Atualizados!");
				getch();
			}
			else
			{
				gotoxy(41,9);
				printf("Motoqueiro nao encontrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("CPF invalido!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Motoqueiros Cadastrados!");
		getch();
	}
}

void alterarPedido (TpPedido vetor[],int tl)
{
	int pos,aux;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido:");
		gotoxy(68,7);
		scanf("%d",&aux);
		pos = buscaPedido(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,8);
			printf("Digite a situacao do pedido:");
			gotoxy(70,8);
			scanf("%d",&vetor[pos].situacao);
			gotoxy(41,9);
			printf("Digite a data do pedido:");
			gotoxy(66,9);
			scanf("%d %d %d",&vetor[pos].dia,&vetor[pos].mes,&vetor[pos].ano);
			gotoxy(41,10);
			printf("Dados Atualizados!");
			getch();
		}
		else
		{
			printf("Pedido nao encontrado!");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos Cadastrados!");
		getch();
	}
}

void clienteTell (TpClientes vetor[],int tl)
{
	int pos;
	char aux[15];
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente a ser buscado:");
		gotoxy(85,7);
		fflush(stdin);
		gets(aux);
		pos = buscaCliente(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Telefone: %s",vetor[pos].telefone);
			gotoxy(41,10);
			printf("Nome: %s",vetor[pos].nome);
			gotoxy(41,11);
			printf("Endereco: %s",vetor[pos].endereco);
			gotoxy(41,12);
			printf("Cidade: %s",vetor[pos].cidade);
			gotoxy(41,13);
			printf("CEP: %d",vetor[pos].cep);
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Cliente nao encontrado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem clientes cadastrados!");
		getch();
	}
}

void pizzaCod (TpPizzas vetor[],int tl)
{
	int aux,pos;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza a ser buscada:");
		gotoxy(81,7);
		scanf("%d",&aux);
		pos = buscaPizza(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Codigo: %d",vetor[pos].codigo);
			gotoxy(41,10);
			printf("Nome: %s",vetor[pos].nome);
			gotoxy(41,11);
			printf("Preco: %.2f",vetor[pos].preco);
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem pizzas cadastradas!");
		getch();
	}
}

void motoCPF (TpMotoqueiro vetor[],int tl)
{
	int pos;
	char aux[11];
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro a ser buscado:");
		gotoxy(83,7);
		fflush(stdin);
		gets(aux);
		if(validaCPF(aux))
		{
			pos = buscaMotoqueiro(vetor,tl,aux);
			if(pos>-1)
			{
				gotoxy(41,9);
				printf("CPF: %s",vetor[pos].cpf);
				gotoxy(41,10);
				printf("Nome: %s",vetor[pos].nome);
				gotoxy(41,11);
				printf("Endereco: %s",vetor[pos].endereco);
				gotoxy(41,12);
				printf("Tell: %s",vetor[pos].telefone);
				gotoxy(41,13);
				printf("Admissao: %d/%d/%d",vetor[pos].dia,vetor[pos].mes,vetor[pos].ano);
				getch();
			}
			else
			{
				gotoxy(41,9);
				printf("Motoqueiro nao encontrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("CPF invalido!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem motoqueiros cadastrados!");
		getch();
	}
}

void pedidoNum(TpPedido vetor[],int tl)
{
	int pos,aux;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido:");
		gotoxy(68,7);
		scanf("%d",&aux);
		pos = buscaPedido(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Numero: %d",vetor[pos].numPedido);
			gotoxy(41,10);
			printf("Telefone cliente: %s",vetor[pos].numTelefone);
			gotoxy(41,11);
			printf("Cod pizza: %d",vetor[pos].codPizza);
			gotoxy(41,12);
			printf("CPF motoqueiro: %s",vetor[pos].cpfMoto);
			gotoxy(41,13);
			printf("Situacao: %d",vetor[pos].situacao);
			gotoxy(41,14);
			printf("Data do pedido: %d/%d/%d",vetor[pos].dia,vetor[pos].mes,vetor[pos].ano);
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Pedido nao encontrado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem pedidos cadastrados!");
		getch();
	}
}

int buscaPedidoTel(TpPedido vetor[],int tl,char elemento[15])
{
	int pos=0;
	while(pos<tl && strcmp(vetor[pos].numTelefone,elemento)!=0)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void excluirCliente (TpClientes vetor[],int &tl,TpPedido pedido[],int &tlpe)
{
	int pos,i,j;
	char op,aux[15];
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente a ser excluido:");
		gotoxy(86,7);
		fflush(stdin);
		gets(aux);
		pos = buscaCliente(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Telefone: %s",vetor[pos].telefone);
			gotoxy(41,10);
			printf("Nome: %s",vetor[pos].nome);
			gotoxy(41,11);
			printf("Endereco: %s",vetor[pos].endereco);
			gotoxy(41,12);
			printf("Cidade: %s",vetor[pos].cidade);
			gotoxy(41,13);
			printf("CEP: %d",vetor[pos].cep);
			gotoxy(41,15);
			printf("Deseja excluir? (S/N)");
			fflush(stdin);
			gotoxy(63,15);
			scanf("%c",&op);
			op = toupper(op);
			if(op == 'S')
			{
				for(i=pos;i<tl-1;i++)
				{
					vetor[i] = vetor[i+1];
				}
				tl--;
				//certo
				i=0;
				while(i<=tlpe)
				{
					pos = buscaPedidoTel(pedido,tlpe,aux);
					if(pos>-1)
					{
						for(j=pos;j<tlpe-1;j++)
						{
							pedido[j] = pedido[j+1];
						}
						tlpe--;
					}
					i++;
				}
				//
				gotoxy(41,17);
				printf("Cliente excluido!");
				getch();
			}
			else
			{
				gotoxy(41,17);
				printf("Operacao encerrada!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Cliente nao encontrado");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem clientes cadastrados!");
		getch();
	}
}

int buscaPedidoCod(TpPedido vetor[],int tl,int elemento)
{
	int pos=0;
	while(pos<tl && vetor[pos].codPizza!=elemento)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void excluirPizza (TpPizzas vetor[],int &tl,TpPedido pedido[],int &tlpe)
{
	int aux,pos,i,j;
	char op;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza a ser excluida:");
		gotoxy(82,7);
		scanf("%d",&aux);
		pos = buscaPizza(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Codigo: %d",vetor[pos].codigo);
			gotoxy(41,10);
			printf("Nome: %s",vetor[pos].nome);
			gotoxy(41,11);
			printf("Preco: %.2f",vetor[pos].preco);
			gotoxy(41,13);
			printf("Deseja excluir? (S/N)");
			fflush(stdin);
			gotoxy(63,13);
			scanf("%c",&op);
			op = toupper(op);
			if(op == 'S')
			{
				for(i=pos;i<tl-1;i++)
				{
					vetor[i] = vetor[i+1];
				}
				tl--;
				//
				i=0;
				while(i<=tlpe)
				{
					pos = buscaPedidoCod(pedido,tlpe,aux);
					if(pos>-1)
					{
						for(j=pos;j<tlpe-1;j++)
						{
							pedido[j]=pedido[j+1];
						}
						tlpe--;
					}
					i++;
				}
				//
				gotoxy(41,15);
				printf("Pizza excluida!");
				getch();
			}
			else
			{
				gotoxy(41,15);
				printf("Operacao encerrada!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Pizza nao encontrada");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem pizzas cadastradas!");
		getch();
	}
}

int buscaPedidoCPF (TpPedido vetor[],int tl,char elemento[])
{
	int pos=0;
	while(pos<tl && strcmp(vetor[pos].cpfMoto,elemento)!=0)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void excluirMoto (TpMotoqueiro vetor[],int &tl,TpPedido pedido[],int &tlpe)
{
	int pos,i,j;
	char aux[12],op;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro a ser excluido:");
		gotoxy(84,7);
		fflush(stdin);
		gets(aux);
		if(validaCPF(aux))
		{
			pos = buscaMotoqueiro(vetor,tl,aux);
			if(pos>-1)
			{
				gotoxy(41,9);
				printf("CPF: %s",vetor[pos].cpf);
				gotoxy(41,10);
				printf("Nome: %s",vetor[pos].nome);
				gotoxy(41,11);
				printf("Endereco: %s",vetor[pos].endereco);
				gotoxy(41,12);
				printf("Tell: %s",vetor[pos].telefone);				
				gotoxy(41,13);
				printf("Admissao: %d/%d/%d",vetor[pos].dia,vetor[pos].mes,vetor[pos].ano);
				gotoxy(41,15);
				printf("Deseja excluir? (S/N)");
				fflush(stdin);
				gotoxy(63,15);
				scanf("%c",&op);
				op = toupper(op);
				if(op == 'S')
				{
					for(i=pos;i<tl-1;i++)
					{
						vetor[i] = vetor[i+1];
					}
					tl--;
					// 
					i=0;
					while(i<=tlpe)
					{
						pos = buscaPedidoCPF(pedido,tlpe,aux);
						if(pos>-1)
						{
							for(j=pos;j<tlpe-1;j++)
							{
								pedido[j] = pedido[j+1];
							}
							tlpe--;
						}
						i++;
					}
					//
					gotoxy(41,17);
					printf("Motoqueiro excluido!");
					getch();
				}
				else
				{
					gotoxy(41,17);
					printf("Operacao encerrada!");
					getch();
				}
			}
			else
			{
				gotoxy(41,9);
				printf("Motoqueiro nao encontrado");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Digite um CPF valido");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem motoqueiros cadastrados!");
		getch();
	}
}

void excluirPedido (TpPedido vetor[],int &tl)
{
	int pos,i,aux;
	char op;
	if(tl>0)
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido a ser excluido:");
		gotoxy(83,7);
		scanf("%d",&aux);
		pos = buscaPedido(vetor,tl,aux);
		if(pos>-1)
		{
			gotoxy(41,9);
			printf("Numero: %d",vetor[pos].numPedido);
			gotoxy(41,10);
			printf("Telefone cliente: %s",vetor[pos].numTelefone);
			gotoxy(41,11);
			printf("Cod pizza: %d",vetor[pos].codPizza);
			gotoxy(41,12);
			printf("CPF motoqueiro: %s",vetor[pos].cpfMoto);
			gotoxy(41,13);
			printf("Situacao: %d",vetor[pos].situacao);
			gotoxy(41,14);
			printf("Data do pedido: %d/%d/%d",vetor[pos].dia,vetor[pos].mes,vetor[pos].ano);
			gotoxy(41,16);
			printf("Deseja excluir? (S/N)");
			fflush(stdin);
			gotoxy(63,16);
			scanf("%c",&op);
			op = toupper(op);
			if(op == 'S')
			{
				for(i=pos;i<tl-1;i++)
				{
					vetor[i] = vetor[i+1];
				}
				tl--;
				gotoxy(41,18);
				printf("Pedido excluido!");
				getch();
			}
			else
			{
				gotoxy(41,18);
				printf("Operacao encerrada!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Pedido nao encontrado!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem pedidos cadastrados!");
		getch();
	}
}

int datas (int dia1,int mes1,int ano1,int dia2,int mes2,int ano2)
{
	if(ano1 < ano2)
	{
		return 1;
	}
	else
	if(ano1 > ano2)
	{
		return 2;
	}
	else
	if(mes1<mes2)
	{
		return 1;
	}
	else
	if(mes1>mes2)
	{
		return 2;
	}
	else
	if(dia1 < dia2)
	{
		return 1;
	}
	else
	if(dia1 > dia2)
	{
		return 2;
	}
}

int buscaVet (char vetor[][12],int tl,char elemento[])
{
	int pos=0;
	while (pos<tl && strcmp(vetor[pos],elemento)!=0)
		pos++;
	if(pos==tl)
		return 0;
	else
		return 1;
}

void leDatas (TpPedido pedido[],int tlpe)
{
	int dia1,mes1,ano1,dia2,mes2,ano2,i,qtde=0,tl=0;
	char vetor[tfmo][12];
	if(tlpe>0)
	{
		gotoxy(41,7);
		printf("Digite a data inicial:");
		gotoxy(64,7);
		scanf("%d %d %d",&dia1,&mes1,&ano1);
		gotoxy(41,8);
		printf("Digite a data final:");
		gotoxy(62,8);
		scanf("%d %d %d",&dia2,&mes2,&ano2);
		for(i=0;i<tlpe;i++)
		{
			if(datas(pedido[i].dia,pedido[i].mes,pedido[i].ano,dia1,mes1,ano1)==2)
			{
				if(datas(pedido[i].dia,pedido[i].mes,pedido[i].ano,dia2,mes2,ano2)==1)
				{
					qtde++;
				}
			}
		}
		for(i=0;i<tlpe;i++)
		{
			if(datas(pedido[i].dia,pedido[i].mes,pedido[i].ano,dia1,mes1,ano1)==2)
			{
				if(datas(pedido[i].dia,pedido[i].mes,pedido[i].ano,dia2,mes2,ano2)==1)
				{
					gotoxy(41,10);
					printf("Qtde pizzas: %d",qtde);
					if(buscaVet(vetor,tl,pedido[i].cpfMoto)==0)
					{
						strcpy(vetor[tl],pedido[i].cpfMoto);
						tl++;
						gotoxy(41,12);
						printf("Motoqueiros: %s",pedido[i].cpfMoto);
						getch();
						gotoxy(41,12);
						printf("                                      ");
					}
				}
			}
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void buscaLetra(TpClientes vetor[],int tl,char aux)
{
	int i = 0;
	while(i<tl)
	{
		if(vetor[i].nome[0] == aux)
		{
			gotoxy(41,9);
			printf("Telefone: %s",vetor[i].telefone);
			gotoxy(41,10);
			printf("Nome: %s",vetor[i].nome);
			gotoxy(41,11);
			printf("Endereco: %s",vetor[i].endereco);
			gotoxy(41,12);
			printf("Cidade: %s",vetor[i].cidade);
			gotoxy(41,13);
			printf("CEP: %d",vetor[i].cep);
			getch();
			gotoxy(41,9);
			printf("                                                    ");
			gotoxy(41,10);
			printf("                                                    ");
			gotoxy(41,11);
			printf("                                                    ");
			gotoxy(41,12);
			printf("                                                    ");
			gotoxy(41,13);
			printf("                                                    ");
		}
		i++;
	}
}

void buscaTrecho (TpClientes vetor[],int tl,char trecho[])
{
	int i=0;
	while(i<tl)
	{
		if(strstr(vetor[i].nome,trecho))
		{
			gotoxy(41,9);
			printf("Telefone: %s",vetor[i].telefone);
			gotoxy(41,10);
			printf("Nome: %s",vetor[i].nome);
			gotoxy(41,11);
			printf("Endereco: %s",vetor[i].endereco);
			gotoxy(41,12);
			printf("Cidade: %s",vetor[i].cidade);
			gotoxy(41,13);
			printf("CEP: %d",vetor[i].cep);
			getch();
			gotoxy(41,9);
			printf("                                                    ");
			gotoxy(41,10);
			printf("                                                    ");
			gotoxy(41,11);
			printf("                                                    ");
			gotoxy(41,12);
			printf("                                                    ");
			gotoxy(41,13);
			printf("                                                    ");
		}
		i++;
	}
	gotoxy(41,9);
	printf("Operacao Finalizada");
	getch();
}

int buscaRanking (TpRankingPizza vetor[],int tl,int elemento)
{
	int pos = 0;
	while(pos<tl && vetor[pos].cod!= elemento)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

void mostrarRanking (TpRankingPizza ranking[],int tl)
{
	int i=0;
	for(i=0;i<tl;i++)
	{
		gotoxy(41,7);
		printf("CodPizza: %d",ranking[i].cod);
		gotoxy(41,9);
		printf("Qtde: %d",ranking[i].qtde);
		getch();
		gotoxy(41,7);
		printf("                      ");
		gotoxy(41,9);
		printf("                      ");
	}
}

void rankingPizza (TpPedido pedido[],int tlpe,TpRankingPizza ranking[],int tlpi,int &tl)
{
	TpRankingPizza aux;
	int i=0,j,pos;
	if(tlpe>0)
	{
		for(i=0;i<tfpi;i++)
		{
			ranking[i].qtde = 0;
		}
		i=0;
		while(i<tlpe)
		{
			pos = buscaRanking(ranking,tl,pedido[i].codPizza);
			if(pos==-1)
			{
				ranking[tl].cod = pedido[i].codPizza;
				ranking[tl].qtde +=1;
				tl++;
			}
			else
			{
				ranking[pos].qtde +=1;
			}
			i++;
		}
		for(i=tl-1;i>0;i--)
		{
			if(ranking[i].qtde>ranking[i-1].qtde)
			{
				aux = ranking[i];
				ranking[i] = ranking[i-1];
				ranking[i-1] = aux;
			}
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

int buscaGasto (TpGastos vetor[],int tl,char elemento[])
{
	int pos=0;
	while(pos<tl && strcmp(vetor[pos].tel,elemento)!=0)
		pos++;
	if(pos==tl)
		return -1;
	else
		return pos;
}

float buscaPreco (TpPizzas vetor[],int tl,int elemento)
{
	int pos=0;
	float preco;
	while(pos<tl && vetor[pos].codigo!=elemento)
		pos++;
	if(pos<tl)
	{
		preco = vetor[pos].preco;
		return preco;
	}
}

void gastoCliente (TpPedido pedido[],int tlpe,TpGastos gastos[],int tlc,TpPizzas pizza[],int tlpi)
{
	int tl=0,i=0,j=0,pos;
	float preco;
	if(tlpe>0)
	{
		for(i=0;i<tfc;i++)
		{
			gastos[i].gasto = 0;
		}
		i=0;
		while(i<tlpe)
		{
			pos = buscaGasto(gastos,tl,pedido[i].numTelefone);
			if(pos == -1)
			{
				preco = buscaPreco(pizza,tlpi,pedido[i].codPizza);
				strcpy(gastos[tl].tel,pedido[i].numTelefone);
				gastos[tl].gasto = preco;
				tl++;
			}
			else
			{
				preco = buscaPreco(pizza,tlpi,pedido[pos].codPizza);
				gastos[pos].gasto += preco;
			}
			i++;
		}
		for(i=0;i<tl;i++)
		{
			gotoxy(41,7);
			printf("Tell: %s",gastos[i].tel);
			gotoxy(41,9);
			printf("Gastos: %.2f",gastos[i].gasto);
			getch();
			gotoxy(41,7);
			printf("                      ");
			gotoxy(41,9);
			printf("                      ");
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void pizzaAndamento (TpPedido pedido[],int tlpe)
{
	int i=0;
	if(tlpe>0)
	{
		while(i<tlpe)
		{
			if(pedido[i].situacao==1)
			{
				gotoxy(41,7);
				printf("Numero: %d",pedido[i].numPedido);
				gotoxy(41,8);
				printf("Telefone cliente: %s",pedido[i].numTelefone);
				gotoxy(41,9);
				printf("Cod pizza: %d",pedido[i].codPizza);
				gotoxy(41,10);
				printf("CPF motoqueiro: %s",pedido[i].cpfMoto);
				gotoxy(41,11);
				printf("Situacao: %d",pedido[i].situacao);
				gotoxy(41,12);
				printf("Data do pedido: %d/%d/%d",pedido[i].dia,pedido[i].mes,pedido[i].ano);
				getch();
				gotoxy(41,7);
				printf("                                                    ");
				gotoxy(41,8);
				printf("                                                    ");
				gotoxy(41,9);
				printf("                                                    ");
				gotoxy(41,10);
				printf("                                                    ");
				gotoxy(41,11);
				printf("                                                    ");
				gotoxy(41,12);
				printf("                                                    ");
			}
			i++;
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void pizzaCaminho (TpPedido pedido[],int tlpe)
{
	int i=0;
	if(tlpe>0)
	{
		while(i<tlpe)
		{
			if(pedido[i].situacao==2)
			{
				gotoxy(41,7);
				printf("Numero: %d",pedido[i].numPedido);
				gotoxy(41,8);
				printf("Telefone cliente: %s",pedido[i].numTelefone);
				gotoxy(41,9);
				printf("Cod pizza: %d",pedido[i].codPizza);
				gotoxy(41,10);
				printf("CPF motoqueiro: %s",pedido[i].cpfMoto);
				gotoxy(41,11);
				printf("Situacao: %d",pedido[i].situacao);
				gotoxy(41,12);
				printf("Data do pedido: %d/%d/%d",pedido[i].dia,pedido[i].mes,pedido[i].ano);
				getch();
				gotoxy(41,7);
				printf("                                                    ");
				gotoxy(41,8);
				printf("                                                    ");
				gotoxy(41,9);
				printf("                                                    ");
				gotoxy(41,10);
				printf("                                                    ");
				gotoxy(41,11);
				printf("                                                    ");
				gotoxy(41,12);
				printf("                                                    ");
			}
			i++;
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void pizzaMaisPedida (int tlpe,TpRankingPizza ranking[],int tlr,TpPedido pedido[],int tlpi)
{
	int i=0,aux=0;
	if(tlpe>0)
	{
		rankingPizza(pedido,tlpe,ranking,tlpi,tlr);
		while(i<tlr-1)
		{
			if(ranking[i].qtde>=ranking[i+1].qtde && ranking[i].qtde>aux)
			{
				aux = ranking[i].qtde;
			}
			i++;
		}
		i=0;
		while(i<tlr)
		{
			if(ranking[i].qtde == aux)
			{
				gotoxy(41,7);
				printf("Pizza mais Pedida: %d",ranking[i].cod);
				getch();
				gotoxy(41,7);
				printf("                         ");
			}
			i++;
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void pizzaMenosPedida (int tlpe,TpRankingPizza ranking[],int tlr,TpPedido pedido[],int tlpi)
{
	int i=0,aux=99999,j=0;
	if(tlpe>0)
	{
		rankingPizza(pedido,tlpe,ranking,tlpi,tlr);
		for(i=0;i<tlr;i++)
		{
			for(j=0;j<tlr;j++)
			{
				if(ranking[i].qtde<=ranking[j].qtde && ranking[i].qtde<aux)
				{
					aux = ranking[i].qtde;
				}
			}
		}
		i=0;
		while(i<tlr)
		{
			if(ranking[i].qtde == aux)
			{
				gotoxy(41,7);
				printf("Pizza menos Pedida: %d",ranking[i].cod);
				getch();
				gotoxy(41,7);
				printf("                         ");
			}
			i++;
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

int buscaConsumo (TpConsumoCliente vetor[],int tl,char elemento[])
{
	int pos =0;
	while(pos<tl && strcmp(vetor[pos].tel,elemento)!=0)
		pos++;
	if(pos == tl)
		return -1;
	else
		return pos;
}

void clienteMaisConsome (TpConsumoCliente consumo[],int tlpe,TpPedido pedido[],int tlc)
{
	TpConsumoCliente aux;
	int i=0,pos,tl=0,mConsumo=0;
	if(tlpe>0)
	{
		while(i<tlc)
		{
			consumo[i].qtde = 0;
			i++;
		}
		i=0;
		while(i<tlpe)
		{
			pos = buscaConsumo(consumo,tl,pedido[i].numTelefone);
			if(pos == -1)
			{
				strcpy(consumo[tl].tel,pedido[i].numTelefone);
				consumo[tl].qtde+=1;
				tl++;
			}
			else
			{
				consumo[pos].qtde+=1;
			}
			i++;
		}
		for(i=tl-1;i>0;i--)
		{
			if(consumo[i].qtde>consumo[i-1].qtde)
			{
				aux = consumo[i];
				consumo[i] = consumo[i-1];
				consumo[i-1] = aux;
			}
		}
		mConsumo = consumo[0].qtde;
		for(i=0;i<tl;i++)
		{
			if(consumo[i].qtde == mConsumo)
			{
				gotoxy(41,7);
				printf("Cliente que mais consome: %s",consumo[i].tel);
				getch();
				gotoxy(41,7);
				printf("                                                     ");
			}
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void consomePizza (TpPedido pedido[],int tlpe,int tlc,TpConsumoCliente consumo[])
{
	int resp,pos,i=0,tl=0,mConsumo=0;
	TpConsumoCliente aux;
	if(tlpe>0)
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza que deseja:");
		gotoxy(78,7);
		scanf("%d",&resp);
		pos = buscaPedidoCod(pedido,tlpe,resp);
		if(pos>-1)
		{
			while(i<tlc)
			{
				consumo[i].qtde = 0;
				i++;
			}
			i=0;
			while(i<tlpe)
			{
				pos = buscaConsumo(consumo,tl,pedido[i].numTelefone);
				if(pedido[i].codPizza == resp)
				{
					if(pos == -1)
					{
						strcpy(consumo[tl].tel,pedido[i].numTelefone);
						consumo[tl].qtde+=1;
						tl++;
					}
					else
					{
						consumo[pos].qtde+=1;
					}
				}
				i++;
			}
			i=0;
			for(i=tl-1;i>0;i--)
			{
				if(consumo[i].qtde>consumo[i-1].qtde)
				{
					aux = consumo[i];
					consumo[i] = consumo[i-1];
					consumo[i-1] = aux;
				}
			}
			mConsumo = consumo[0].qtde;
			for(i=0;i<tl;i++)
			{
				if(consumo[i].qtde == mConsumo)
				{
					gotoxy(41,9);
					printf("Cliente que mais consome: %s",consumo[i].tel);
					getch();
					gotoxy(41,9);
					printf("                                                     ");
				}
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Pizza Nao Encontrada!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

void pizzaDia (int tlpe,TpPedido pedido[],int tlc,TpConsumoCliente consumo[],TpPizzas pizza[],int tlpi)
{
	int respP,respD,respM,respA,i=0,qtde=0;
	TpConsumoCliente aux;
	if(tlpe>0)
	{
		gotoxy(41,7);
		printf("Digite a pizza que deseja:");
		gotoxy(68,7);
		scanf("%d",&respP);
		if(buscaPizza(pizza,tlpi,respP)>-1)
		{
			gotoxy(41,8);
			printf("Digite o dia que deseja:");
			gotoxy(66,8);
			scanf("%d %d %d",&respD,&respM,&respA);
			for(i=0;i<tlpe;i++)
			{
				if(pedido[i].codPizza == respP && pedido[i].dia == respD && pedido[i].mes == respM && pedido[i].ano == respA)
				{
					qtde++;
				}
			}
			gotoxy(41,10);
			printf("Qtde da pizza %d no dia %d/%d/%d: %d",respP,respD,respM,respA,qtde);
			getch();
		}
		else
		{
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
	
}

void motoMaisExp (TpMotoqueiro vetor[],int tlmo)
{
	int i=0,j=0,d=99,m=99,a=9999;
	char cpf[12];
	if(tlmo>0)
	{
		for(i=0;i<tlmo;i++)
		{
			for(j=0;j<tlmo;j++)
			{
				if(datas(vetor[i].dia,vetor[i].mes,vetor[i].ano,vetor[j].dia,vetor[j].mes,vetor[j].ano)==1)
				{
					if(datas(vetor[i].dia,vetor[i].mes,vetor[i].ano,d,m,a)==1)
					{
						strcpy(cpf,vetor[i].cpf);
						d = vetor[i].dia;
						m = vetor[i].mes;
						a = vetor[i].ano;
					}
				}
			}
		}
		gotoxy(41,7);
		printf("Motoqueiro com mais exp: %s",cpf);
		gotoxy(41,9);
		printf("Data de admissao: %d/%d/%d",d,m,a);
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Motoqueiros!");
		getch();
	}
}

void motoMenosExp (TpMotoqueiro vetor[],int tlmo)
{
	int i=0,j=0,d=00,m=00,a=0000;
	char cpf[12];
	if(tlmo>0)
	{
		for(i=0;i<tlmo;i++)
		{
			for(j=0;j<tlmo;j++)
			{
				if(datas(vetor[i].dia,vetor[i].mes,vetor[i].ano,vetor[j].dia,vetor[j].mes,vetor[j].ano)==2)
				{
					if(datas(vetor[i].dia,vetor[i].mes,vetor[i].ano,d,m,a)==2)
					{
						strcpy(cpf,vetor[i].cpf);
						d = vetor[i].dia;
						m = vetor[i].mes;
						a = vetor[i].ano;
					}
				}
			}
		}
		gotoxy(41,7);
		printf("Motoqueiro com menos exp: %s",cpf);
		gotoxy(41,9);
		printf("Data de admissao: %d/%d/%d",d,m,a);
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Motoqueiros!");
		getch();
	}
}

int buscaEntrega (TpMotoEntrega vetor[],int tl,char elemento[])
{
	int pos=0;
	while (pos<tl && strcmp(vetor[pos].cpf,elemento)!=0)
		pos++;
	if(pos == tl)
		return -1;
	else
		return pos;
}

void motoMaisEntrega (int tlpe,TpMotoEntrega entrega[],TpPedido pedido[])
{
	int i,pos,tl=0,mEntrega,d,m,a;
	TpMotoEntrega aux;
	if(tlpe>0)
	{
		gotoxy(41,7);
		printf("Digite a data desejada:");
		gotoxy(65,7);
		scanf("%d %d %d",&d,&m,&a);
		for(i=0;i<tfmo;i++)
		{
			entrega[i].qtde = 0;
		}
		for(i=0;i<tlpe;i++)
		{
			if(pedido[i].dia == d && pedido[i].mes == m && pedido[i].ano == a)
			{
				pos = buscaEntrega(entrega,tl,pedido[i].cpfMoto);
				if(pos==-1)
				{
					strcpy(entrega[tl].cpf,pedido[i].cpfMoto);
					entrega[tl].qtde+=1;
					tl++;
				}
				else
				{
					entrega[pos].qtde+=1;
				}
			}
		}
		for(i=tl-1;i>0;i--)
		{
			if(entrega[i].qtde>entrega[i-1].qtde)
			{
				aux = entrega[i];
				entrega[i] = entrega[i-1];
				entrega[i-1] = aux;
			}
		}
		mEntrega = entrega[0].qtde;
		for(i=0;i<tl;i++)
		{
			if(entrega[i].qtde == mEntrega)
			{
				gotoxy(41,9);
				printf("Motoqueiro que mais entrega: %s",entrega[i].cpf);
				
			}
		}
		gotoxy(41,11);
		printf("Operacao Finalizada!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Sem Pedidos!");
		getch();
	}
}

int main ()
{
	TpClientes cliente[tfc];
	TpPizzas pizza[tfpi];
	TpPedido pedido[tfpe];
	TpMotoqueiro motoqueiro[tfmo];
	TpRankingPizza ranking[tfpi];
	TpGastos gastos[tfc];
	TpConsumoCliente consumo[tfc];
	TpMotoEntrega entrega[tfmo];
	int resp,tlc=0,tlpi=0,tlpe=0,tlmo=0,tlr=0;
	char letra,trecho[30];
	
	do
	{
		clrscr();
		//mold Principal
		tela(2,2,100,35,2);
		//mold Pizzaria
		tela(25,3,55,5,4);
		gotoxy(36,4);
		printf("PIZZARIA");
		//mold Menu
		tela(4,6,35,31,15);
		menu();
		//mold opcao
		tela(4,32,35,34,4);
		gotoxy(5,33);
		printf("OPCAO:");
		//mold Resp
		tela(40,6,95,20,15);
		gotoxy(12,33);
		scanf("%d",&resp);
		if(resp == 1)
		{
			if(tlc<tfc)
				cadastroCliente(cliente,tlc);
			else
			{
				gotoxy(41,7);
				printf("Sem espaco para mais clientes!");
				getch();
			}
		}
		else
		if(resp == 2)
		{
			if(tlpi<tfpi)
				cadastroPizza(pizza,tlpi);
			else
			{
				gotoxy(41,7);
				printf("Sem espaco para mais pizzas!");
				getch();
			}
		}
		else
		if(resp == 3)
		{
			if(tlmo<tfmo)
				cadastroMotoqueiro(motoqueiro,tlmo);
			else
			{
				gotoxy(41,7);
				printf("Sem espaco para mais motoqueiros");
				getch();
			}
		}
		else
		if(resp == 4)
		{
			if(tlc<tfc && tlpi<tfpi && tlmo<tfmo && tlpe<tfpe)
				inserir(cliente,tlc,pizza,tlpi,motoqueiro,tlmo,pedido,tlpe);
			else
			{
				gotoxy(41,7);
				printf("Sem espaco");
				getch();
			}
		}
		else
		if(resp == 5)
		{
			if(tlpe<tfpe)
				fazerPedido(pedido,tlpe,cliente,tlc,pizza,tlpi,motoqueiro,tlmo);
			else
			{
				gotoxy(41,7);
				printf("Sem espaco para mais pedidos");
				getch();
			}
		}
		else
		if(resp == 6)
		{
			consultarCliente(cliente,tlc);
		}
		if(resp == 7)
		{
			consultarPizza(pizza,tlpi);
		}
		else
		if(resp == 8)
		{
			consultarMoto(motoqueiro,tlmo);
		}
		else
		if(resp == 9)
		{
			consultarPedido(pedido,tlpe);
		}
		else
		if(resp == 10)
		{
			alterarCliente(cliente,tlc);
		}
		else
		if(resp == 11)
		{
			alterarPizza(pizza,tlpi);
		}
		else
		if(resp == 12)
		{
			alterarMoto(motoqueiro,tlmo);
		}
		else
		if(resp == 13)
		{
			alterarPedido(pedido,tlpe);
		}
		else
		if(resp == 14)
		{
			clienteTell(cliente,tlc);
		}
		else
		if(resp == 15)
		{
			pizzaCod(pizza,tlpi);
		}
		else
		if(resp == 16)
		{
			motoCPF(motoqueiro,tlmo);
		}
		else
		if(resp == 17)
		{
			pedidoNum(pedido,tlpe);
		}
		else
		if(resp == 18)
		{
			excluirCliente(cliente,tlc,pedido,tlpe);
		}
		else
		if(resp == 19)
		{
			excluirPizza(pizza,tlpi,pedido,tlpe);
		}
		else
		if(resp==20)
		{
			excluirMoto(motoqueiro,tlmo,pedido,tlpe);
		}
		else
		if(resp == 21)
		{
			excluirPedido(pedido,tlpe);
		}
		else
		if(resp == 22)
		{
			menu2();
		}
		else
		if(resp ==23)
		{
			leDatas(pedido,tlpe);
		}
		else
		if(resp ==24)
		{
			gotoxy(41,7);
			printf("Digite a primeira letra de um nome:");
			gotoxy(77,7);
			fflush(stdin);
			scanf("%c",&letra);
			buscaLetra(cliente,tlc,letra);
		}
		else
		if(resp == 25)
		{
			gotoxy(41,7);
			printf("Digite o trecho de um nome:");
			gotoxy(69,7);
			fflush(stdin);
			gets(trecho);
			buscaTrecho(cliente,tlc,trecho);
		}
		else
		if(resp == 26)
		{
			rankingPizza(pedido,tlpe,ranking,tlpi,tlr);
			mostrarRanking(ranking,tlr);
		}
		else
		if(resp == 27)
		{
			gastoCliente(pedido,tlpe,gastos,tlc,pizza,tlpi);
		}
		else
		if(resp == 28)
		{
			pizzaAndamento(pedido,tlpe);
		}
		else
		if(resp == 29)
		{
			pizzaCaminho(pedido,tlpe);
		}
		else
		if(resp == 30)
		{
			pizzaMaisPedida(tlpe,ranking,tlr,pedido,tlpi);
		}
		else
		if(resp == 31)
		{
			pizzaMenosPedida(tlpe,ranking,tlr,pedido,tlpi);
		}
		else
		if(resp ==32)
		{
			clienteMaisConsome(consumo,tlpe,pedido,tlc);
		}
		else
		if(resp == 33)
		{
			consomePizza(pedido,tlpe,tlc,consumo);
		}
		else
		if(resp == 34)
		{
			pizzaDia (tlpe,pedido,tlc,consumo,pizza,tlpi);
		}
		else
		if(resp == 35)
		{
			motoMaisExp(motoqueiro,tlmo);
		}
		else
		if(resp == 36)
		{
			motoMenosExp(motoqueiro,tlmo);
		}
		else
		if(resp == 37)
		{
			motoMaisEntrega(tlpe,entrega,pedido);
		}						
	}
	while(resp != 0);
	//FIM
	gotoxy(82,35);
	return 0;
}
