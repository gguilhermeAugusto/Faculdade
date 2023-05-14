#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct TpClientes
{
	char nome[30],endereco[30],cidade[30],telefone[15],cep[15],exc;
};

struct TpPizzas
{
	int codigo;
	float preco;
	char nome[20],exc;
};

struct TpPedido
{
	int numPedido,codPizza,dia,mes,ano,situacao;
	char numTelefone[15],cpfMoto[12],exc;
};

struct TpMotoqueiro
{
	int dia,mes,ano;
	char nome[30],endereco[30],cpf[12],telefone[15],exc;
};

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
	gotoxy(5,17);
	printf("                              ");
	gotoxy(5,18);
	printf("                              ");
	gotoxy(5,19);
	printf("                              ");
	gotoxy(5,20);
	printf("                              ");
	gotoxy(5,21);
	printf("                              ");
	gotoxy(5,22);
	printf("                              ");
	gotoxy(5,23);
	printf("                              ");
	gotoxy(5,24);
	printf("                              ");
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
	
}

int buscaSentinela (FILE *ptr,int elemento)
{
	TpPedido pedido;
	pedido.numPedido = elemento;
	fseek(ptr,0,2);
	fwrite(&pedido,sizeof(TpPedido),1,ptr);
	fseek(ptr,0,0);
	fread(&pedido,sizeof(TpPedido),1,ptr);
	while(elemento!=pedido.numPedido)
		fread(&pedido,sizeof(TpPedido),1,ptr);
	if(!feof(ptr))
		return ftell(ptr)-sizeof(TpPedido);
	else
		return -1;
}

int buscaSeqInd (FILE *ptr, int elemento)
{
	TpPedido pedido;
	fseek(ptr,0,0);
	fread(&pedido,sizeof(TpPedido),1,ptr);
	while(!feof(ptr) && elemento>pedido.numPedido)
		fread(&pedido,sizeof(TpPedido),1,ptr);
	if(!feof(ptr) && elemento==pedido.numPedido)
		return ftell(ptr)-sizeof(TpPedido);
	else
		return -1;
}

int buscaBinaria (FILE *ptr,int elemento)
{
	TpPedido pedido;
	int qtde,inicio,meio,fim;
	fseek(ptr,0,2);
	qtde = ftell(ptr)/sizeof(TpPedido);
	inicio = 0;
	fim = qtde-1;
	meio = fim/2;
	fseek(ptr,meio*sizeof(TpPedido),0);
	fread(&pedido,sizeof(TpPedido),1,ptr);
	while(inicio<fim && elemento!= pedido.numPedido)
	{
		fseek(ptr,meio*sizeof(TpPedido),0);
		if(pedido.numPedido<elemento)
			inicio = meio+1;
		else
			fim = meio;
		meio = (inicio+fim)/2;
	}
	fseek(ptr,meio*sizeof(TpPedido),0);
	if(elemento == pedido.numPedido)
		return meio*sizeof(TpPedido);
	else
		return -1;
}

void InsDireta (FILE *ptr)
{
	int p,aux,qtde;
	TpPedido pedido,pedido2;
	fseek(ptr,0,2);
	qtde = ftell(ptr)/sizeof(TpPedido);
	p = qtde-1;
	fseek(ptr,p*sizeof(TpPedido),0);
	fread(&pedido,sizeof(TpPedido),1,ptr);
	fseek(ptr,(p-1)*sizeof(TpPedido),1);
	fread(&pedido2,sizeof(TpPedido),1,ptr);
	while(p>0 && pedido.numPedido<pedido2.numPedido)
	{
		fseek(ptr,p*sizeof(TpPedido),0);
		fwrite(&pedido2,sizeof(TpPedido),1,ptr);
		fseek(ptr,(p-1)*sizeof(TpPedido),0);
		fwrite(&pedido,sizeof(TpPedido),1,ptr);
		p--;
	}
}

void ordenaBolha (FILE *ptr)
{
	TpPedido pedido,pedido2;
	int qtde,a;
	fseek(ptr,0,2);
	qtde = ftell(ptr)/sizeof(TpPedido);
	while(qtde>0)
	{
		for(a=0;a<qtde-1;a++)
		{
			fseek(ptr,a*sizeof(TpPedido),0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			fseek(ptr,(a+1)*sizeof(TpPedido),1);
			fread(&pedido2,sizeof(TpPedido),1,ptr);
			if(pedido.numPedido>pedido2.numPedido)
			{
				fseek(ptr,a*sizeof(TpPedido),0);
				fwrite(&pedido2,sizeof(TpPedido),1,ptr);
				fseek(ptr,(a+1)*sizeof(TpPedido),0);
				fwrite(&pedido,sizeof(TpPedido),1,ptr);
			}
		}
		qtde--;
	}
}

int posicaoMaior (FILE *ptr,int qtde)
{
	int posMaior,maior,i;
	TpPedido pedido;
	fseek(ptr,0,0);
	fread(&pedido,sizeof(TpPedido),1,ptr);
	maior = pedido.numPedido;
	posMaior = 0;
	for(i=1;i<qtde;i++)
	{
		fseek(ptr,i*sizeof(TpPedido),0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		if(maior<pedido.numPedido)
		{
			maior = pedido.numPedido;
			posMaior = i;
		}
	}
	return posMaior;
}

void selecaoDireta (FILE *ptr)
{
	TpPedido pedido,pedido2;
	int posMaior,qtde;
	fseek(ptr,0,2);
	qtde = ftell(ptr)/sizeof(TpPedido);
	while(qtde>0)
	{
		posMaior = posicaoMaior(ptr,qtde);
		if(posMaior<qtde-1)
		{
			fseek(ptr,(qtde-1)*sizeof(TpPedido),0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			fseek(ptr,posMaior*sizeof(TpPedido),0);
			fread(&pedido2,sizeof(TpPedido),1,ptr);
			fseek(ptr,(qtde-1)*sizeof(TpPedido),0);
			fwrite(&pedido2,sizeof(TpPedido),1,ptr);
			fseek(ptr,posMaior*sizeof(TpPedido),1);
			fwrite(&pedido,sizeof(TpPedido),1,ptr);
		}
		qtde--;
	}
}

int buscaTel (FILE *ptr,char tel[])
{
	TpClientes cliente;
	fseek(ptr,0,0);
	fread(&cliente,sizeof(TpClientes),1,ptr);
	while(!feof(ptr) && strcmp(cliente.telefone,tel)!=0)
		fread(&cliente,sizeof(TpClientes),1,ptr);
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(TpClientes);
	}
	else
	{
		return -1;
	}
}

void cadastroTel ()
{
	TpClientes cliente;
	FILE *ptr = fopen("Cliente.dat","ab+");
	gotoxy(41,7);
	printf("Digite o telefone do Cliente: ");
	fflush(stdin);
	gotoxy(71,7);
	gets(cliente.telefone);
	if(buscaTel(ptr,cliente.telefone)==-1)
	{
		gotoxy(41,8);
		printf("Digite o nome do cliente: ");
		fflush(stdin);
		gotoxy(67,8);
		gets(cliente.nome);
		gotoxy(41,9);
		printf("Digite o endereco do cliente: ");
		fflush(stdin);
		gotoxy(71,9);
		gets(cliente.endereco);
		gotoxy(41,10);
		printf("Digite a cidade do cliente: ");
		fflush(stdin);
		gotoxy(69,10);
		gets(cliente.cidade);
		gotoxy(41,11);
		printf("Digite o CEP do cliente: ");
		gotoxy(66,11);
		fflush(stdin);
		gets(cliente.cep);
		cliente.exc = 'A';
		fwrite(&cliente,sizeof(TpClientes),1,ptr);
		gotoxy(41,13);
		printf("Cadastro Realizado!");
		getch();
	}
	else
	{
		gotoxy(41,9);
		printf("Cliente ja cadastrado!");
		getch();
	}
	fclose(ptr);
}

int buscaCod (FILE *ptr,int cod)
{
	TpPizzas pizza;
	fseek(ptr,0,0);
	fread(&pizza,sizeof(TpPizzas),1,ptr);
	while(!feof(ptr) && pizza.codigo!= cod)
		fread(&pizza,sizeof(TpPizzas),1,ptr);
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(TpPizzas);
	}
	else
	{
		return -1;
	}
}

void cadastroCod ()
{
	TpPizzas pizza;
	FILE *ptr = fopen("Pizza.dat","ab+");
	gotoxy(41,7);
	printf("Digite o codigo da pizza: ");
	gotoxy(67,7);
	scanf("%d",&pizza.codigo);
	if(buscaCod(ptr,pizza.codigo)==-1)
	{
		gotoxy(41,8);
		printf("Digite o nome da pizza: ");
		fflush(stdin);
		gotoxy(65,8);
		gets(pizza.nome);
		gotoxy(41,9);
		printf("Digite o valor da pizza: ");
		scanf("%f",&pizza.preco);
		pizza.exc = 'A';
		fwrite(&pizza,sizeof(TpPizzas),1,ptr);
		gotoxy(41,10);
		printf("Cadastro Realizado!");
		getch();
	}
	else
	{
		gotoxy(41,9);
		printf("Pizza ja cadastrada!");
		getch();
	}
	fclose(ptr);
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

int buscaCPF (FILE *ptr,char cpf[])
{
	TpMotoqueiro moto;
	fseek(ptr,0,0);
	fread(&moto,sizeof(TpMotoqueiro),1,ptr);
	while(!feof(ptr) && strcmp(moto.cpf,cpf)!=0)
		fread(&moto,sizeof(TpMotoqueiro),1,ptr);
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(TpMotoqueiro);
	}
	else
	{
		return -1;
	}
}

void cadastroCPF()
{
	TpMotoqueiro moto;
	FILE *ptr = fopen("Moto.dat","ab+");
	gotoxy(41,7);
	printf("Digite o CPF do motoqueiro: ");
	fflush(stdin);
	gotoxy(69,7);
	gets(moto.cpf);
	validaCPF(moto.cpf);
	if(validaCPF(moto.cpf))
	{
		if(buscaCPF(ptr,moto.cpf)==-1)
		{
			gotoxy(41,8);
			printf("Digite o nome do motoqueiro: ");
			fflush(stdin);
			gotoxy(70,8);
			gets(moto.nome);
			gotoxy(41,9);
			printf("Digite o endereco do motoqueiro: ");
			fflush(stdin);
			gotoxy(74,9);
			gets(moto.endereco);
			gotoxy(41,10);
			printf("Digite o telefone do motoqueiro: ");
			fflush(stdin);
			gotoxy(74,10);
			gets(moto.telefone);
			gotoxy(41,11);
			printf("Digite a data de admissao: ");
			gotoxy(68,11);
			scanf("%d %d %d",&moto.dia,&moto.mes,&moto.ano);
			moto.exc='A';
			fwrite(&moto,sizeof(TpMotoqueiro),1,ptr);
			gotoxy(41,13);
			printf("Cadastro Realizado!");
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
	fclose(ptr);
}

void inserirCliente ()
{
	//inserir clientes
	FILE *ptra = fopen("Cliente.dat","ab+");
	TpClientes cliente;
	char tel[15];
	strcpy(tel,"1163423312");
	if(buscaTel(ptra,tel)==-1)
	{
		strcpy(cliente.telefone,"1163423312");
		strcpy(cliente.nome,"Mariana");
		strcpy(cliente.endereco,"Avenida dos Nacionalistas");
		strcpy(cliente.cidade,"Sao Paulo");
		strcpy(cliente.cep,"0131000");
		cliente.exc='A';
		fwrite(&cliente,sizeof(TpClientes),1,ptra);
		gotoxy(41,7);
		printf("cliente 1 inserido");
	}
	else
	{
		gotoxy(41,7);
		printf("cliente 1 nao pode ser inserido");
	}
	fclose(ptra);
	FILE *ptrb = fopen("Cliente.dat","ab+");
	strcpy(tel,"1182695524");
	if(buscaTel(ptrb,tel)==-1)
	{
		strcpy(cliente.telefone,"1182695524");
		strcpy(cliente.nome,"Daniela");
		strcpy(cliente.endereco,"Rua Francisco Lettiere");
		strcpy(cliente.cidade,"Sao Paulo");
		strcpy(cliente.cep,"05655070");
		cliente.exc='A';
		fwrite(&cliente,sizeof(TpClientes),1,ptrb);
		gotoxy(41,8);
		printf("cliente 2 inserido");
	}
	else
	{
		gotoxy(41,8);
		printf("cliente 2 nao pode ser inserido");
	}
	fclose(ptrb);
	FILE *ptrc = fopen("Cliente.dat","ab+");
	strcpy(tel,"1172677941");
	if(buscaTel(ptrc,tel)==-1)
	{
		strcpy(cliente.telefone,"1172677941");
		strcpy(cliente.nome,"Raul");
		strcpy(cliente.endereco,"Praca Serra dos Tapes");
		strcpy(cliente.cidade,"Sao Paulo");
		strcpy(cliente.cep,"03615020");
		cliente.exc = 'A';
		fwrite(&cliente,sizeof(TpClientes),1,ptrc);
		gotoxy(41,9);
		printf("cliente 3 inserido");
	}
	else
	{
		gotoxy(41,9);
		printf("cliente 3 nao pode ser inserido");
	}
	fclose(ptrc);
}
void inserirPizza ()
{
	//inserir pizza
	TpPizzas pizza;
	FILE *ptra = fopen("Pizza.dat","ab+");
	if(buscaCod(ptra,1)==-1)
	{
		pizza.codigo = 1;
		strcpy(pizza.nome,"Calabresa");
		pizza.preco = 50;
		pizza.exc='A';
		fwrite(&pizza,sizeof(TpPizzas),1,ptra);
		gotoxy(41,10);
		printf("pizza 1 inserida");
	}
	else
	{
		gotoxy(41,10);
		printf("pizza 1 nao pode ser inserida");
	}
	fclose(ptra);
	FILE *ptrb = fopen("Pizza.dat","ab+");
	if(buscaCod(ptrb,2)==-1)
	{
		pizza.codigo = 2;
		strcpy(pizza.nome,"Portuguesa");
		pizza.preco = 50;
		pizza.exc='A';
		fwrite(&pizza,sizeof(TpPizzas),1,ptrb);
		gotoxy(41,11);
		printf("pizza 2 inserida");
	}
	else
	{
		gotoxy(41,11);
		printf("pizza 2 nao pode ser inserida");
	}
	fclose(ptrb);
	FILE *ptrc = fopen("Pizza.dat","ab+");
	if(buscaCod(ptrc,3)==-1)
	{
		pizza.codigo = 3;
		strcpy(pizza.nome,"Marguerita");
		pizza.preco = 50;
		pizza.exc='A';
		fwrite(&pizza,sizeof(TpPizzas),1,ptrc);
		gotoxy(41,12);
		printf("pizza 3 inserida");
	}
	else
	{
		gotoxy(41,12);
		printf("pizza 3 nao pode ser inserida");
	}
	fclose(ptrc);
}
void inserirMoto ()
{
	//inserir motoqueiro
	FILE *ptra = fopen("Moto.dat","ab+");
	TpMotoqueiro moto;
	char cpf[15];
	strcpy(cpf,"19350097885");
	if(buscaCPF(ptra,cpf)==-1)
	{
		strcpy(moto.cpf,"19350097885");
		strcpy(moto.nome,"Caio");
		strcpy(moto.endereco,"Avenida Gustavo Adolfo");
		strcpy(moto.telefone,"1198470576");
		moto.dia = 03;
		moto.mes = 06;
		moto.ano = 2020;
		moto.exc='A';
		fwrite(&moto,sizeof(TpMotoqueiro),1,ptra);
		gotoxy(41,13);
		printf("motoqueiro 1 inserido");
	}
	else
	{
		gotoxy(41,13);
		printf("motoqueiro 1 nao pode ser inserido");
	}
	fclose(ptra);
	FILE *ptrb = fopen("Moto.dat","ab+");
	strcpy(cpf,"51245796844");
	if(buscaCPF(ptrb,cpf)==-1)
	{
		strcpy(moto.cpf,"51245796844");
		strcpy(moto.nome,"Vitor");
		strcpy(moto.endereco,"Rua Serra de Maracaju");
		strcpy(moto.telefone,"1199465679");
		moto.dia = 25;
		moto.mes = 04;
		moto.ano = 2019;
		moto.exc='A';
		fwrite(&moto,sizeof(TpMotoqueiro),1,ptrb);
		gotoxy(41,14);
		printf("motoqueiro 2 inserido");
	}
	else
	{
		gotoxy(41,14);
		printf("motoqueiro 2 nao pode ser inserido");
	}
	fclose(ptrb);
	FILE *ptrc = fopen("Moto.dat","ab+");
	strcpy(cpf,"31591775809");
	if(buscaCPF(ptrc,cpf)==-1)
	{
		strcpy(moto.cpf,"31591775809");
		strcpy(moto.nome,"Mateus");
		strcpy(moto.endereco,"Rua Gaivota 9");
		strcpy(moto.telefone,"1198101017");
		moto.dia = 15;
		moto.mes = 11;
		moto.ano = 2019;
		moto.exc='A';
		fwrite(&moto,sizeof(TpMotoqueiro),1,ptrc);
		gotoxy(41,15);
		printf("motoqueiro 3 inserido");
	}
	else
	{
		gotoxy(41,15);
		printf("motoqueiro 3 nao pode ser inserido");
	}
	fclose(ptrc);
}

int buscaPedido (FILE *ptr,int num)
{
	TpPedido aux;
	fseek(ptr,0,0);
	fread(&aux,sizeof(TpPedido),1,ptr);
	while(!feof(ptr) && aux.numPedido!=num)
		fread(&aux,sizeof(TpPedido),1,ptr);
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(TpPedido);
	}
	else
	{
		return -1;
	}
}

void inserirPedido ()
{
	FILE *ptra = fopen("Pedido.dat","ab+");
	TpPedido pedido;
	if(buscaPedido(ptra,1)==-1)
	{
		pedido.numPedido = 1;
		strcpy(pedido.numTelefone,"1163423312");
		pedido.codPizza = 1;
		strcpy(pedido.cpfMoto,"19350097885");
		pedido.situacao = 1;
		pedido.dia = 10;
		pedido.mes = 04;
		pedido.ano = 2022;
		pedido.exc='A';
		fwrite(&pedido,sizeof(TpPedido),1,ptra);
		gotoxy(41,16);
		printf("Pedido 1 inserido");
	}
	else
	{
		gotoxy(41,16);
		printf("Pedido 1 nao pode ser inserido");
	}
	fclose(ptra);
	FILE *ptrb = fopen("Pedido.dat","ab+");
	if(buscaPedido(ptrb,2)==-1)
	{
		pedido.numPedido = 2;
		strcpy(pedido.numTelefone,"1182695524");
		pedido.codPizza = 2;
		strcpy(pedido.cpfMoto,"51245796844");
		pedido.situacao = 2;
		pedido.dia = 27;
		pedido.mes = 9;
		pedido.ano = 2022;
		pedido.exc='A';
		fwrite(&pedido,sizeof(TpPedido),1,ptrb);
		gotoxy(41,17);
		printf("Pedido 2 inserido");
	}
	else
	{
		gotoxy(41,17);
		printf("Pedido 2 nao pode ser inserido");
	}
	fclose(ptrb);
	FILE *ptrc = fopen("Pedido.dat","ab+");
	if(buscaPedido(ptrc,3)==-1)
	{
		pedido.numPedido = 3;
		strcpy(pedido.numTelefone,"1172677941");
		pedido.codPizza = 3;
		strcpy(pedido.cpfMoto,"31591775809");
		pedido.situacao = 3;
		pedido.dia = 29;
		pedido.mes = 12;
		pedido.ano = 2022;
		pedido.exc='A';
		fwrite(&pedido,sizeof(TpPedido),1,ptrc);
		gotoxy(41,18);
		printf("Pedido 3 inserido");
	}
	else
	{
		gotoxy(41,18);
		printf("Pedido 3 nao pode ser inserido");
	}
	fclose(ptrc);
}

void fazerPedido ()
{
	FILE *ptr = fopen("Pedido.dat","ab+");
	FILE *ptrc = fopen("Cliente.dat","rb");
	FILE *ptrp = fopen("Pizza.dat","rb");
	FILE *ptrm = fopen("Moto.dat","rb");
	int pos,posc,posp,posm;
	if(ptrc == NULL || ptrp == NULL || ptrm == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR UM ARQUIVO!");
		getch();
	}
	else
	{
		TpPedido pedido;
		TpClientes cliente;
		TpPizzas pizza;
		TpMotoqueiro moto;
		gotoxy(41,7);
		printf("Digite o numero do pedido: ");
		gotoxy(68,7);
		scanf("%d",&pedido.numPedido);
		pos = buscaPedido(ptr,pedido.numPedido);
		if(pos==-1)
		{
			fseek(ptr,pos,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			if(pedido.exc!='A')
			{
				gotoxy(41,8);
				printf("Digite o telefone do cliente: ");
				gotoxy(71,8);
				fflush(stdin);
				gets(cliente.telefone);
				posc = buscaTel(ptrc,cliente.telefone);
				if(posc>-1)
				{
					fseek(ptrc,posc,0);
					fread(&cliente,sizeof(TpClientes),1,ptrc);
					if(cliente.exc=='A')
					{
						strcpy(pedido.numTelefone,cliente.telefone);
						gotoxy(41,9);
						printf("Digite o codigo da pizza: ");
						gotoxy(67,9);
						scanf("%d",&pizza.codigo);
						posp = buscaCod(ptrp,pizza.codigo);
						if(posp>-1)
						{
							fseek(ptrp,posp,0);
							fread(&pizza,sizeof(TpPizzas),1,ptrp);
							if(pizza.exc=='A')
							{
								pedido.codPizza = pizza.codigo;
								gotoxy(41,10);
								printf("Digite o CPF do motoqueiro: ");
								gotoxy(69,10);
								fflush(stdin);
								gets(moto.cpf);
								if(validaCPF(moto.cpf)==1)
								{
									posm = buscaCPF(ptrm,moto.cpf);
									if(posm>-1)
									{
										fseek(ptrm,posm,0);
										fread(&moto,sizeof(TpMotoqueiro),1,ptrm);
										if(moto.exc=='A')
										{
											strcpy(pedido.cpfMoto,moto.cpf);
											gotoxy(41,11);
											printf("Digite a situacao do pedido: ");
											gotoxy(70,11);
											scanf("%d",&pedido.situacao);
											gotoxy(41,12);
											printf("Digite a data do pedido: ");
											gotoxy(66,12);
											scanf("%d %d %d",&pedido.dia,&pedido.mes,&pedido.ano);
											pedido.exc='A';
											fwrite(&pedido,sizeof(TpPedido),1,ptr);
											gotoxy(41,14);
											printf("Pedido realizado!");
											getch();
										}
										else
										{
											gotoxy(41,12);
											printf("Motoqueiro nao encontrado!");
											getch();
										}
									}
									else
									{
										gotoxy(41,12);
										printf("Motoqueiro nao encontrado!");
										getch();
									}
								}
								else
								{
									gotoxy(41,12);
									printf("CPF invalido!");
									getch();
								}
							}
							else
							{
								gotoxy(41,11);
								printf("Pizza nao encontrada!");
								getch();
							}
						}
						else
						{
							gotoxy(41,11);
							printf("Pizza nao encontrada!");
							getch();
						}
					}
					else
					{
						gotoxy(41,10);
						printf("Cliente nao encontrado!");
						getch();
					}
				}
				else
				{
					gotoxy(41,10);
					printf("Cliente nao encontrado!");
					getch();
				}
			}
			else
			{
				gotoxy(41,9);
				printf("Pedido ja cadastrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Pedido ja cadastrado!");
			getch();
		}
		
		fclose(ptr);
		fclose(ptrc);
		fclose(ptrp);
		fclose(ptrm);
	}
}

void consultaCliente ()
{
	FILE *ptr = fopen("Cliente.dat","rb");
	TpClientes cliente;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptr,0,0);
		fread(&cliente,sizeof(TpClientes),1,ptr);
		while(!feof(ptr))
		{
			if(cliente.exc=='A')
			{
				gotoxy(41,7);
				printf("Telefone: %s",cliente.telefone);
				gotoxy(41,8);
				printf("Nome: %s",cliente.nome);
				gotoxy(41,9);
				printf("Endereco: %s",cliente.endereco);
				gotoxy(41,10);
				printf("Cidade: %s",cliente.cidade);
				gotoxy(41,11);
				printf("CEP: %s",cliente.cep);
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
			fread(&cliente,sizeof(TpClientes),1,ptr);
		}
		fclose(ptr);
	}
}

void consultaPizza ()
{
	FILE *ptr = fopen ("Pizza.dat","rb");
	TpPizzas pizza;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptr,0,0);
		fread(&pizza,sizeof(TpPizzas),1,ptr);
		while(!feof(ptr))
		{
			if(pizza.exc=='A')
			{
				gotoxy(41,7);
				printf("Codigo: %d",pizza.codigo);
				gotoxy(41,8);
				printf("Nome: %s",pizza.nome);
				gotoxy(41,9);
				printf("Preco: %.2f",pizza.preco);
				getch();
				gotoxy(41,7);
				printf("                                                    ");
				gotoxy(41,8);
				printf("                                                    ");
				gotoxy(41,9);
				printf("                                                    ");
			}
			fread(&pizza,sizeof(TpPizzas),1,ptr);
		}
		fclose(ptr);
	}
}

void consultaMoto ()
{
	FILE *ptr = fopen("Moto.dat","rb");
	TpMotoqueiro moto;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptr,0,0);
		fread(&moto,sizeof(TpMotoqueiro),1,ptr);
		while(!feof(ptr))
		{
			if(moto.exc == 'A')
			{
				gotoxy(41,7);
				printf("CPF: %s",moto.cpf);
				gotoxy(41,8);
				printf("Nome: %s",moto.nome);
				gotoxy(41,9);
				printf("Endereco: %s",moto.endereco);
				gotoxy(41,10);
				printf("Tell: %s",moto.telefone);
				gotoxy(41,11);
				printf("Admissao: %d/%d/%d",moto.dia,moto.mes,moto.ano);
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
			fread(&moto,sizeof(TpMotoqueiro),1,ptr);
		}
		fclose(ptr);
	}
}

void consultaPedido ()
{
	FILE *ptr = fopen("Pedido.dat","rb");
	TpPedido pedido;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			if(pedido.exc == 'A')
			{
				gotoxy(41,7);
				printf("Numero: %d",pedido.numPedido);
				gotoxy(41,8);
				printf("Telefone Cliente: %s",pedido.numTelefone);
				gotoxy(41,9);
				printf("Cod Pizza: %d",pedido.codPizza);
				gotoxy(41,10);
				printf("CPF Motoqueiro: %s",pedido.cpfMoto);
				gotoxy(41,11);
				printf("Situacao: %d",pedido.situacao);
				gotoxy(41,12);
				printf("Data do pedido: %d/%d/%d",pedido.dia,pedido.mes,pedido.ano);
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
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		fclose(ptr);
	}
}

void alterarDadosCliente ()
{
	FILE *ptr = fopen("Cliente.dat","rb+");
	TpClientes cliente;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente: ");
		gotoxy(71,7);
		fflush(stdin);
		gets(cliente.telefone);
		pos = buscaTel(ptr,cliente.telefone);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&cliente,sizeof(TpClientes),1,ptr);
			if(cliente.exc == 'A')
			{
				gotoxy(41,8);
				printf("Digite o nome do cliente: ");
				gotoxy(67,8);
				fflush(stdin);
				gets(cliente.nome);
				gotoxy(41,9);
				printf("Digite o endereco do cliente: ");
				gotoxy(71,9);
				fflush(stdin);
				gets(cliente.endereco);
				gotoxy(41,10);
				printf("Digite a cidade do cliente: ");
				gotoxy(69,10);
				fflush(stdin);
				gets(cliente.cidade);
				gotoxy(41,11);
				printf("Digite o CEP do cliente: ");
				gotoxy(66,11);
				fflush(stdin);
				gets(cliente.cep);
				fseek(ptr,pos,0);
				fwrite(&cliente,sizeof(TpClientes),1,ptr);
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
			gotoxy(41,9);
			printf("Cliente nao encontrado!");
			getch();
		}
		fclose(ptr);
	}
}

void alterarDadosPizza ()
{
	FILE *ptr = fopen("Pizza.dat","rb+");
	TpPizzas pizza;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza: ");
		gotoxy(67,7);
		scanf("%d",&pizza.codigo);
		pos = buscaCod(ptr,pizza.codigo);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pizza,sizeof(TpPizzas),1,ptr);
			if(pizza.exc=='A')
			{
				gotoxy(41,8);
				printf("Digite o nome da pizza: ");
				gotoxy(65,8);
				fflush(stdin);
				gets(pizza.nome);
				gotoxy(41,9);
				printf("Digite o preco da pizza: ");
				gotoxy(66,9);
				scanf("%f",&pizza.preco);
				fseek(ptr,pos,0);
				fwrite(&pizza,sizeof(TpPizzas),1,ptr);
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
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
		
		fclose(ptr);
	}
}

void alterarDadosMoto ()
{
	FILE *ptr = fopen("Moto.dat","rb+");
	TpMotoqueiro moto;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();	
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro: ");
		gotoxy(69,7);
		fflush(stdin);
		gets(moto.cpf);
		if(validaCPF(moto.cpf)==1)
		{
			pos = buscaCPF(ptr,moto.cpf);
			if(pos>-1)
			{
				fseek(ptr,pos,0);
				fread(&moto,sizeof(TpMotoqueiro),1,ptr);
				if(moto.exc=='A')
				{
					gotoxy(41,8);
					printf("Digite o nome do motoqueiro:");
					gotoxy(70,8);
					fflush(stdin);
					gets(moto.nome);
					gotoxy(41,9);
					printf("Digite o endereco do motoqueiro:");
					gotoxy(74,9);
					fflush(stdin);
					gets(moto.endereco);
					gotoxy(41,10);
					printf("Digite o telefone do motoqueiro:");
					gotoxy(74,10);
					fflush(stdin);
					gets(moto.telefone);
					gotoxy(41,11);
					printf("Digite a data de admissao:");
					gotoxy(68,11);
					scanf("%d %d %d",&moto.dia,&moto.mes,&moto.ano);
					fseek(ptr,pos,0);
					fwrite(&moto,sizeof(TpMotoqueiro),1,ptr);
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
		fclose(ptr);
	}
}

void alterarDadosPedido ()
{
	FILE *ptr = fopen("Pedido.dat","rb+");
	TpPedido pedido;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido: ");
		gotoxy(68,7);
		scanf("%d",&pedido.numPedido);
		pos = buscaPedido(ptr,pedido.numPedido);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			if(pedido.exc=='A')
			{
				gotoxy(41,8);
				printf("Digite a situacao do pedido:");
				gotoxy(70,8);
				scanf("%d",&pedido.situacao);
				gotoxy(41,9);
				printf("Digite a data do pedido:");
				gotoxy(66,9);
				scanf("%d %d %d",&pedido.dia,&pedido.mes,&pedido.ano);
				fseek(ptr,pos,0);
				fwrite(&pedido,sizeof(TpPedido),1,ptr);
				gotoxy(41,10);
				printf("Dados Atualizados!");
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
			gotoxy(41,9);
			printf("Pedido nao encontrado!");
			getch();
		}
		fclose(ptr);
	}
}

void buscaClienteTel ()
{
	FILE *ptr = fopen("Cliente.dat","rb");
	TpClientes cliente;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente: ");
		gotoxy(71,7);
		fflush(stdin);
		gets(cliente.telefone);
		pos = buscaTel(ptr,cliente.telefone);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&cliente,sizeof(TpClientes),1,ptr);
			if(cliente.exc=='A')
			{
				gotoxy(41,9);
				printf("Telefone: %s",cliente.telefone);
				gotoxy(41,10);
				printf("Nome: %s",cliente.nome);
				gotoxy(41,11);
				printf("Endereco: %s",cliente.endereco);
				gotoxy(41,12);
				printf("Cidade: %s",cliente.cidade);
				gotoxy(41,13);
				printf("CEP: %s",cliente.cep);
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
			gotoxy(41,9);
			printf("Cliente nao encontrado!");
			getch();
		}
		fclose(ptr);
	}
}

void buscaPizzaCod ()
{
	FILE *ptr = fopen("Pizza.dat","rb");
	TpPizzas pizza;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza: ");
		gotoxy(67,7);
		scanf("%d",&pizza.codigo);
		pos = buscaCod(ptr,pizza.codigo);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pizza,sizeof(TpPizzas),1,ptr);
			if(pizza.exc=='A')
			{
				gotoxy(41,9);
				printf("Codigo: %d",pizza.codigo);
				gotoxy(41,10);
				printf("Nome: %s",pizza.nome);
				gotoxy(41,11);
				printf("Preco: %.2f",pizza.preco);
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
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
		fclose(ptr);
	}
}

void buscaMotoCPF ()
{
	FILE *ptr = fopen("Moto.dat","rb");
	TpMotoqueiro moto;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro: ");
		gotoxy(69,7);
		fflush(stdin);
		gets(moto.cpf);
		if(validaCPF(moto.cpf)==1)
		{
			pos = buscaCPF(ptr,moto.cpf);
			if(pos>-1)
			{
				fseek(ptr,pos,0);
				fread(&moto,sizeof(TpMotoqueiro),1,ptr);
				if(moto.exc == 'A')
				{
					gotoxy(41,9);
					printf("CPF: %s",moto.cpf);
					gotoxy(41,10);
					printf("Nome: %s",moto.nome);
					gotoxy(41,11);
					printf("Endereco: %s",moto.endereco);
					gotoxy(41,12);
					printf("Tell: %s",moto.telefone);
					gotoxy(41,13);
					printf("Admissao: %d/%d/%d",moto.dia,moto.mes,moto.ano);
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
				printf("Motoqueiro nao encontrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Digite um CPF valido!");
			getch();
		}
		fclose(ptr);
	}
}

void buscaPedidoNum ()
{
	FILE *ptr = fopen("Pedido.dat","rb");
	TpPedido pedido;
	int pos;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido: ");
		gotoxy(68,7);
		scanf("%d",&pedido.numPedido);
		pos = buscaPedido(ptr,pedido.numPedido);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			if(pedido.exc=='A')
			{
				gotoxy(41,9);
				printf("Numero: %d",pedido.numPedido);
				gotoxy(41,10);
				printf("Telefone Cliente: %s",pedido.numTelefone);
				gotoxy(41,11);
				printf("Cod Pizza: %d",pedido.codPizza);
				gotoxy(41,12);
				printf("CPF Motoqueiro: %s",pedido.cpfMoto);
				gotoxy(41,13);
				printf("Situacao: %d",pedido.situacao);
				gotoxy(41,14);
				printf("Data do pedido: %d/%d/%d",pedido.dia,pedido.mes,pedido.ano);
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
			gotoxy(41,9);
			printf("Pedido nao encontrado!");
			getch();
		}
		fclose(ptr);
	}
}

int buscaExcluirCliente (FILE *ptr,char tell[])
{
	TpPedido pedido;
	fread(&pedido,sizeof(TpPedido),1,ptr);
	while(!feof(ptr) && strcmp(pedido.numTelefone,tell)!=0 && pedido.exc=='A') 
		fread(&pedido,sizeof(TpPedido),1,ptr);
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(TpPedido);
	}	
	else
	{
		return -1;
	}
}

void excluirCliente ()
{
	FILE *ptr = fopen("Cliente.dat","rb+");
	FILE *ptrpe = fopen("Pedido.dat","rb+");
	TpClientes cliente;
	TpPedido pedido;
	int pos;
	char op;
	if(ptr == NULL || ptrpe == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR UM ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o telefone do cliente a ser excluido: ");
		gotoxy(86,7);
		fflush(stdin);
		gets(cliente.telefone);
		pos = buscaTel(ptr,cliente.telefone);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&cliente,sizeof(TpClientes),1,ptr);
			if(cliente.exc=='A')
			{
				gotoxy(41,9);
				printf("Telefone: %s",cliente.telefone);
				gotoxy(41,10);
				printf("Nome: %s",cliente.nome);
				gotoxy(41,11);
				printf("Endereco: %s",cliente.endereco);
				gotoxy(41,12);
				printf("Cidade: %s",cliente.cidade);
				gotoxy(41,13);
				printf("CEP: %s",cliente.cep);
				gotoxy(41,14);
				printf("Deseja excluir (S/N)? ");
				gotoxy(63,14);
				fflush(stdin);
				scanf("%c",&op);
				op = toupper(op);
				if(op == 'S')
				{
					cliente.exc = 'I';
					fseek(ptr,pos,0);
					fwrite(&cliente,sizeof(TpClientes),1,ptr);
					//
					pos = 0;
					fseek(ptrpe,0,0);
					fread(&pedido,sizeof(TpPedido),1,ptrpe);
					while(!feof(ptrpe))
					{
						if(strcmp(cliente.telefone,pedido.numTelefone)==0 && pedido.exc == 'A')
						{						
							pedido.exc='I';
							fseek(ptrpe,pos,0);
							fwrite(&pedido,sizeof(TpPedido),1,ptrpe);
						}
						pos = pos+sizeof(TpPedido);
						fseek(ptrpe,pos,0);
						fread(&pedido,sizeof(TpPedido),1,ptrpe);
					}
					//
					gotoxy(41,16);
					printf("Exclusao concluida!");
					getch();
				}
				else
				{
					gotoxy(41,16);
					printf("Operacao encerrada!");
					getch();
				}
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
			gotoxy(41,9);
			printf("Cliente nao encontrado!");
			getch();
		}
		fclose(ptr);
		fclose(ptrpe);
	}
}

void excluirPizza ()
{
	FILE *ptr = fopen("Pizza.dat","rb+");
	FILE * ptrpe = fopen("Pedido.dat","rb+");
	TpPizzas pizza;
	TpPedido pedido;
	int pos;
	char op;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o codigo da pizza a ser excluida: ");
		gotoxy(82,7);
		scanf("%d",&pizza.codigo);
		pos = buscaCod(ptr,pizza.codigo);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pizza,sizeof(TpPizzas),1,ptr);
			if(pizza.exc=='A')
			{
				gotoxy(41,9);
				printf("Codigo: %d",pizza.codigo);
				gotoxy(41,10);
				printf("Nome: %s",pizza.nome);
				gotoxy(41,11);
				printf("Preco: %.2f",pizza.preco);
				gotoxy(41,12);
				printf("Deseja excluir (S/N)? ");
				gotoxy(63,12);
				fflush(stdin);
				scanf("%c",&op);
				op = toupper(op);
				if(op == 'S')
				{
					pizza.exc='I';
					fseek(ptr,pos,0);
					fwrite(&pizza,sizeof(TpPizzas),1,ptr);
					//
					pos = 0;
					fseek(ptrpe,0,0);
					fread(&pedido,sizeof(TpPedido),1,ptrpe);
					while(!feof(ptrpe))
					{
						if(pizza.codigo == pedido.codPizza && pedido.exc=='A')
						{
							pedido.exc='I';
							fseek(ptrpe,pos,0);
							fwrite(&pedido,sizeof(TpPedido),1,ptrpe);
						}
						pos+=sizeof(TpPedido);
						fseek(ptrpe,pos,0);
						fread(&pedido,sizeof(TpPedido),1,ptrpe);
					}
					//
					gotoxy(41,14);
					printf("Exclusao concluida!");
					getch();
				}
				else
				{
					gotoxy(41,14);
					printf("Operacao encerrada!");
					getch();
				}
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
			gotoxy(41,9);
			printf("Pizza nao encontrada!");
			getch();
		}
		fclose(ptr);
		fclose(ptrpe);
	}
}

void excluirMoto ()
{
	FILE *ptr = fopen("Moto.dat","rb+");
	FILE *ptrpe = fopen("Pedido.dat","rb+");
	TpMotoqueiro moto;
	TpPedido pedido;
	int pos;
	char op;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o CPF do motoqueiro a ser excluido: ");
		gotoxy(84,7);
		fflush(stdin);
		gets(moto.cpf);
		pos = buscaCPF(ptr,moto.cpf);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&moto,sizeof(TpMotoqueiro),1,ptr);
			if(moto.exc=='A')
			{
				gotoxy(41,9);
				printf("CPF: %s",moto.cpf);
				gotoxy(41,10);
				printf("Nome: %s",moto.nome);
				gotoxy(41,11);
				printf("Endereco: %s",moto.endereco);
				gotoxy(41,12);
				printf("Tell: %s",moto.telefone);
				gotoxy(41,13);
				printf("Admissao: %d/%d/%d",moto.dia,moto.mes,moto.ano);
				gotoxy(41,14);
				printf("Deseja excluir (S/N)? ");
				gotoxy(63,14);
				fflush(stdin);
				scanf("%c",&op);
				op = toupper(op);
				if(op == 'S')
				{
					moto.exc = 'I';
					fseek(ptr,pos,0);
					fwrite(&moto,sizeof(TpMotoqueiro),1,ptr);
					//
					pos = 0;
					fseek(ptrpe,0,0);
					fread(&pedido,sizeof(TpPedido),1,ptrpe);
					while(!feof(ptrpe))
					{
						if(strcmp(pedido.cpfMoto,moto.cpf)==0 && pedido.exc=='A')
						{
							pedido.exc='I';
							fseek(ptrpe,pos,0);
							fwrite(&pedido,sizeof(TpPedido),1,ptrpe);
						}
						pos+=sizeof(TpPedido);
						fseek(ptrpe,pos,0);
						fread(&pedido,sizeof(TpPedido),1,ptrpe);
					}
					//
					gotoxy(41,16);
					printf("Exclusao concluida!");
					getch();
				}
				else
				{
					gotoxy(41,16);
					printf("Operacao encerrada!");
					getch();
				}
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
			printf("Motoqueiro nao encontrado!");
			getch();
		}
		
		fclose(ptr);
		fclose(ptrpe);
	}
}

void excluirPedido ()
{
	FILE *ptr = fopen("Pedido.dat","rb+");
	TpPedido pedido;
	int pos;
	char op;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o numero do pedido a ser excluido: ");
		gotoxy(83,7);
		scanf("%d",&pedido.numPedido);
		pos = buscaPedido(ptr,pedido.numPedido);
		if(pos>-1)
		{
			fseek(ptr,pos,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			if(pedido.exc=='A')
			{
				gotoxy(41,9);
				printf("Numero: %d",pedido.numPedido);
				gotoxy(41,10);
				printf("Telefone Cliente: %s",pedido.numTelefone);
				gotoxy(41,11);
				printf("Cod Pizza: %d",pedido.codPizza);
				gotoxy(41,12);
				printf("CPF Motoqueiro: %s",pedido.cpfMoto);
				gotoxy(41,13);
				printf("Situacao: %d",pedido.situacao);
				gotoxy(41,14);
				printf("Data do pedido: %d/%d/%d",pedido.dia,pedido.mes,pedido.ano);
				gotoxy(41,15);
				printf("Deseja excluir (S/N)? ");
				gotoxy(63,15);
				fflush(stdin);
				scanf("%c",&op);
				op = toupper(op);
				if(op == 'S')
				{
					pedido.exc = 'I';
					fseek(ptr,pos,0);
					fwrite(&pedido,sizeof(TpPedido),1,ptr);
					gotoxy(41,17);
					printf("Exclusao concluida!");
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
				printf("Pedido nao encontrado!");
				getch();
			}
		}
		else
		{
			gotoxy(41,9);
			printf("Pedido nao encontrado!");
			getch();
		}
		fclose(ptr);
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

void leDatas ()
{
	FILE *ptr = fopen("Pedido.dat","rb");
	int dia1,mes1,ano1,dia2,mes2,ano2,qtde=0,i=11;
	TpPedido pedido;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite a data inicial: ");
		scanf("%d %d %d",&dia1,&mes1,&ano1);
		gotoxy(41,8);
		printf("Digite a data final: ");
		scanf("%d %d %d",&dia2,&mes2,&ano2);
		fseek(ptr,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			if(pedido.exc=='A')
			{
				if(datas(pedido.dia,pedido.mes,pedido.ano,dia1,mes1,ano1)==2)
				{
					if(datas(pedido.dia,pedido.mes,pedido.ano,dia2,mes2,ano2)==1)
					{
						qtde++;
					}
				}
			}
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		gotoxy(41,10);
		printf("Qtde de pizzas vendidas: %d",qtde);
		fseek(ptr,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			if(pedido.exc=='A')
			{
				if(datas(pedido.dia,pedido.mes,pedido.ano,dia1,mes1,ano1)==2)
				{
					if(datas(pedido.dia,pedido.mes,pedido.ano,dia2,mes2,ano2)==1)
					{
						gotoxy(41,i);
						printf("Motoqueiro: %s",pedido.cpfMoto);
						i++;
					}
				}
			}
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		getch();
		fclose(ptr);
	}
}

void leLetra ()
{
	FILE *ptr =fopen("Cliente.dat","rb");
	TpClientes cliente;
	char letra;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite a primeira letra de um cliente: ");
		fflush(stdin);
		scanf("%c",&letra);
		fread(&cliente,sizeof(TpClientes),1,ptr);
		while(!feof(ptr))
		{
			if(cliente.exc=='A')
			{
				if(cliente.nome[0] == letra)
				{
					gotoxy(41,9);
					printf("Telefone: %s",cliente.telefone);
					gotoxy(41,10);
					printf("Nome: %s",cliente.nome);
					gotoxy(41,11);
					printf("Endereco: %s",cliente.endereco);
					gotoxy(41,12);
					printf("Cidade: %s",cliente.cidade);
					gotoxy(41,13);
					printf("CEP: %s",cliente.cep);
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
			}
			fread(&cliente,sizeof(TpClientes),1,ptr);
		}
		fclose(ptr);
	}
}

void leTrecho ()
{
	char trecho[15];
	TpClientes cliente;
	FILE *ptr = fopen("Cliente.dat","rb");
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		gotoxy(41,7);
		printf("Digite o trecho do nome de um cliente: ");
		fflush(stdin);
		gets(trecho);
		fread(&cliente,sizeof(TpClientes),1,ptr);
		while(!feof(ptr))
		{
			if(cliente.exc=='A')
			{
				if(strstr(cliente.nome,trecho))
				{
					gotoxy(41,9);
					printf("Telefone: %s",cliente.telefone);
					gotoxy(41,10);
					printf("Nome: %s",cliente.nome);
					gotoxy(41,11);
					printf("Endereco: %s",cliente.endereco);
					gotoxy(41,12);
					printf("Cidade: %s",cliente.cidade);
					gotoxy(41,13);
					printf("CEP: %s",cliente.cep);
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
			}
			fread(&cliente,sizeof(TpClientes),1,ptr);
		}
		
		fclose(ptr);
	}
}

void rankingPizza ()
{
	FILE *ptr = fopen("Pedido.dat","rb");
	TpPedido pedido;
	int pos,qtde=0,cod,posA;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		pos = 0;
		fseek(ptr,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			cod = pedido.codPizza;
			posA = 0;
			fseek(ptr,0,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
			while(!feof(ptr))
			{
				if(cod == pedido.codPizza && pedido.exc=='A')
				{
					qtde++;
				}
				posA+=sizeof(TpPedido);
				fseek(ptr,posA,0);
				fread(&pedido,sizeof(TpPedido),1,ptr);
			}
			gotoxy(41,7);
			printf("Pizza: %d",cod);
			gotoxy(41,8);
			printf("Qtde: %d",qtde);
			getch();
			gotoxy(41,7);
			printf("               ");
			gotoxy(41,8);
			printf("               ");
			qtde=0;
			pos +=sizeof(TpPedido);
			fseek(ptr,pos,0);
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		fclose(ptr);
	}
}

void gastoCliente ()
{
	FILE *ptrpe = fopen("Pedido.dat","rb");
	FILE *ptrpi = fopen("Pizza.dat","rb");
	int cod,pos;
	float gasto=0;
	char tell[15];
	TpPedido pedido;
	TpPizzas pizza;
	if(ptrpe == NULL ||ptrpi == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR UM ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptrpe,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptrpe);
		while(!feof(ptrpe))
		{
			if(pedido.exc=='A')
			{
				strcpy(tell,pedido.numTelefone);
				cod = pedido.codPizza;
				pos = 0;
				fseek(ptrpi,0,0);
				fread(&pizza,sizeof(TpPizzas),1,ptrpi);
				while(!feof(ptrpi))
				{
					if(cod == pizza.codigo && pizza.exc=='A')
						gasto = pizza.preco;
					pos+=sizeof(TpPizzas);
					fseek(ptrpi,pos,0);
					fread(&pizza,sizeof(TpPizzas),1,ptrpi);
				}
				gotoxy(41,7);
				printf("Cliente: %s",tell);
				gotoxy(41,8);
				printf("Pizza: %d",cod);
				gotoxy(41,9);
				printf("Gasto: %.2f",gasto);
				getch();
				gotoxy(41,7);
				printf("                        ");
				gotoxy(41,8);
				printf("                        ");
				gotoxy(41,9);
				printf("                        ");
				gasto = 0;
			}
			fread(&pedido,sizeof(TpPedido),1,ptrpe);
		}
		fclose(ptrpe);
		fclose(ptrpi);
	}
}

void pizzaAndamento ()
{
	FILE *ptr = fopen("Pedido.dat","rb");
	TpPedido pedido;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptr,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			if(pedido.exc=='A')
			{
				if(pedido.situacao==1)
				{
					gotoxy(41,7);
					printf("Numero: %d",pedido.numPedido);
					gotoxy(41,8);
					printf("Telefone cliente: %s",pedido.numTelefone);
					gotoxy(41,9);
					printf("Cod pizza: %d",pedido.codPizza);
					gotoxy(41,10);
					printf("CPF motoqueiro: %s",pedido.cpfMoto);
					gotoxy(41,11);
					printf("Situacao: %d",pedido.situacao);
					gotoxy(41,12);
					printf("Data do pedido: %d/%d/%d",pedido.dia,pedido.mes,pedido.ano);
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
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		fclose(ptr);
	}
}

void pizzaCaminho ()
{
		FILE *ptr = fopen("Pedido.dat","rb");
	TpPedido pedido;
	if(ptr == NULL)
	{
		gotoxy(41,7);
		printf("ERRO AO ABRIR O ARQUIVO!");
		getch();
	}
	else
	{
		fseek(ptr,0,0);
		fread(&pedido,sizeof(TpPedido),1,ptr);
		while(!feof(ptr))
		{
			if(pedido.exc=='A')
			{
				if(pedido.situacao==2)
				{
					gotoxy(41,7);
					printf("Numero: %d",pedido.numPedido);
					gotoxy(41,8);
					printf("Telefone cliente: %s",pedido.numTelefone);
					gotoxy(41,9);
					printf("Cod pizza: %d",pedido.codPizza);
					gotoxy(41,10);
					printf("CPF motoqueiro: %s",pedido.cpfMoto);
					gotoxy(41,11);
					printf("Situacao: %d",pedido.situacao);
					gotoxy(41,12);
					printf("Data do pedido: %d/%d/%d",pedido.dia,pedido.mes,pedido.ano);
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
			fread(&pedido,sizeof(TpPedido),1,ptr);
		}
		fclose(ptr);
	}
}

void excFisicaCliente ()
{
	FILE *ptrO = fopen("Cliente.dat","rb");
	TpClientes cliente;
	if(ptrO!=NULL)
	{
		FILE *ptrTemp = fopen("Temp.dat","wb");
		fread(&cliente,sizeof(TpClientes),1,ptrO);
		while(!feof(ptrO))
		{
			if(cliente.exc=='A')
			{
				fwrite(&cliente,sizeof(TpClientes),1,ptrTemp);
			}
			fread(&cliente,sizeof(TpClientes),1,ptrO);
		}
		fclose(ptrO);
		fclose(ptrTemp);
		remove("Cliente.dat");
		rename("Temp.dat","Cliente.dat");
	}
	
}

void excFisicaPizza ()
{
	FILE *ptrO = fopen("Pizza.dat","rb");
	TpPizzas pizza;
	if(ptrO !=NULL)
	{
		FILE *ptrTemp = fopen("Temp.dat","wb");
		fread(&pizza,sizeof(TpPizzas),1,ptrO);
		while(!feof(ptrO))
		{
			if(pizza.exc=='A')
			{
				fwrite(&pizza,sizeof(TpPizzas),1,ptrTemp);
			}
			fread(&pizza,sizeof(TpPizzas),1,ptrO);
		}
		fclose(ptrO);
		fclose(ptrTemp);
		remove("Pizza.dat");
		rename("Temp.dat","Pizza.dat");
	}
	
}

void excFisicaMoto ()
{
	FILE *ptrO = fopen("Moto.dat","rb");
	TpMotoqueiro moto;
	if(ptrO != NULL)
	{
		FILE *ptrTemp = fopen("Temp.dat","wb");
		fread(&moto,sizeof(TpMotoqueiro),1,ptrO);
		while(!feof(ptrO))
		{
			if(moto.exc=='A')
			{
				fwrite(&moto,sizeof(TpMotoqueiro),1,ptrTemp);
			}
			fread(&moto,sizeof(TpMotoqueiro),1,ptrO);
		}
		fclose(ptrO);
		fclose(ptrTemp);
		remove("Moto.dat");
		rename("Temp.dat","Moto.dat");
	}
	
}

void excFisicaPedido ()
{
	FILE *ptrO = fopen("Pedido.dat","rb");
	TpPedido pedido;
	if(ptrO != NULL)
	{
		FILE *ptrTemp = fopen("Temp.dat","wb");
		fread(&pedido,sizeof(TpPedido),1,ptrO);
		while(!feof(ptrO))
		{
			if(pedido.exc=='A')
			{
				fwrite(&pedido,sizeof(TpPedido),1,ptrTemp);
			}
			fread(&pedido,sizeof(TpPedido),1,ptrO);
		}
		fclose(ptrO);
		fclose(ptrTemp);
		remove("Pedido.dat");
		rename("Temp.dat","Pedido.dat");
	}
}

int main ()
{
	int resp;
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
			cadastroTel();
		}
		else
		if(resp == 2)
		{
			cadastroCod();
		}
		else
		if(resp == 3)
		{
			cadastroCPF();
		}
		else
		if(resp == 4)
		{
			inserirCliente();
			inserirPizza();
			inserirMoto();
			inserirPedido();
			getch();
		}
		else
		if(resp == 5)
		{
			fazerPedido();
		}
		else
		if(resp == 6)
		{
			consultaCliente();
		}
		else
		if(resp == 7)
		{
			consultaPizza();
		}
		else
		if(resp == 8)
		{
			consultaMoto();
		}
		else
		if(resp == 9)
		{
			consultaPedido();
		}
		else
		if(resp == 10)
		{
			alterarDadosCliente();
		}
		else
		if(resp == 11)
		{
			alterarDadosPizza();
		}
		else
		if(resp == 12)
		{
			alterarDadosMoto();
		}
		else
		if(resp == 13)
		{
			alterarDadosPedido();
		}
		else
		if(resp == 14)
		{
			buscaClienteTel();
		}
		else
		if(resp == 15)
		{
			buscaPizzaCod();
		}
		else
		if(resp == 16)
		{
			buscaMotoCPF();
		}
		else
		if(resp == 17)
		{
			buscaPedidoNum();
		}
		else
		if(resp == 18)
		{
			excluirCliente();
		}
		else
		if(resp == 19)
		{
			excluirPizza();
		}
		else
		if(resp == 20)
		{
			excluirMoto();
		}
		else
		if(resp == 21)
		{
			excluirPedido();
		}
		else
		if(resp == 22)
		{
			menu2();
			getch();
		}
		else
		if(resp == 23)
		{
			leDatas();
		}
		else
		if(resp == 24)
		{
			leLetra();
		}
		else
		if(resp == 25)
		{
			leTrecho();
		}
		else
		if(resp == 26)
		{
			rankingPizza();
		}
		else
		if(resp == 27)
		{
			gastoCliente();
		}
		else
		if(resp == 28)
		{
			pizzaAndamento();
		}
		else
		if(resp == 29)
		{
			pizzaCaminho();
		}
	}while(resp!=0);
	excFisicaCliente();
	excFisicaPizza();
	excFisicaMoto();
	excFisicaCliente();
	//FIM
	gotoxy(82,35);
	return 0;
}
