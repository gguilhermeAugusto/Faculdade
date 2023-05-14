#include <stdio.h>
#include <conio2.h>
#include <ctype.h>

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

void radius (float &mean_radius,int x,int y)
{
	gotoxy(x,y);
	printf("Media das distancias do centro aos pontos no perimetro (de 6.98 a 28.1): ");
	scanf("%f",&mean_radius);
	while(mean_radius<6.98 || mean_radius>28.1)
	{
		gotoxy(71,33);
		printf("Digite um valor valido!");
		gotoxy(x+73,y);
		printf("               ");
		gotoxy(x+73,y);
		scanf("%f",&mean_radius);
	}
	gotoxy(71,33);
	printf("                          ");
}

void texture (float &mean_texture,int x,int y)
{
	gotoxy(x,y);
	printf("Digite o desvio padrao dos valores em tons de cinza (de 9.71 a 39.3): ");
	scanf("%f",&mean_texture);
	while(mean_texture<9.71 || mean_texture>39.3)
	{
		gotoxy(71,33);
		printf("Digite um valor valido!");
		gotoxy(x+70,y);
		printf("               ");
		gotoxy(x+70,y);
		scanf("%f",&mean_texture);
	}
	gotoxy(71,33);
	printf("                          ");
}

void perimeter (float &mean_perimeter,int x,int y)
{
	gotoxy(x,y);
	printf("Digite o tamanho medio do tumor central (de 43.8 a 189): ");
	scanf("%f",&mean_perimeter);
	while(mean_perimeter<43.8 || mean_perimeter>189)
	{
		gotoxy(71,33);
		printf("Digite um valor valido!");
		gotoxy(x+57,y);
		printf("               ");
		gotoxy(x+57,y);
		scanf("%f",&mean_perimeter);
	}
	gotoxy(71,33);
	printf("                          ");
}

void area (float &mean_area,int x,int y)
{
	gotoxy(x,y);
	printf("Digite a area media do tumor central (de 144 a 2500): ");
	scanf("%f",&mean_area);
	while(mean_area<144 || mean_area>2500)
	{
		gotoxy(71,33);
		printf("Digite um valor valido!");
		gotoxy(x+54,y);
		printf("               ");
		gotoxy(x+54,11);
		scanf("%f",&mean_area);
	}
	gotoxy(71,33);
	printf("                          ");
}

void smoothness (float &mean_smoothness,int x,int y)
{
	gotoxy(x,y);
	printf("Digite a media da variacao local em comprimentos de raio (de 0.05 a 0.16): ");
	scanf("%f",&mean_smoothness);
	while(mean_smoothness<0.05 || mean_smoothness>0.16)
	{
		gotoxy(71,33);
		printf("Digite um valor valido!");
		gotoxy(x+75,y);
		printf("               ");
		gotoxy(x+75,y);
		scanf("%f",&mean_smoothness);
	}
	gotoxy(71,33);
	printf("                          ");
}

int arvore ()
{
	float mean_radius,mean_texture,mean_perimeter,mean_area,mean_smoothness;
	area(mean_area,40,11);
	if(mean_area>690.2)
	{
		texture(mean_texture,40,13);
		if(mean_texture>19.46)
		{
			return 0;
		}
		else
		{
			perimeter(mean_perimeter,40,15);
			if(mean_perimeter>108.40)
			{
				return 0;
			}
			else
			{
				radius(mean_radius,40,17);
				if(mean_radius>16.110)
				{
					return 1;
				}
				else
				{
					if(mean_texture>13.93)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
		}
	}
	else
	{
		smoothness(mean_smoothness,40,13);
		if(mean_smoothness<=0.09250)
		{
			return 1;
		}
		else
		{
			texture(mean_texture,40,15);
			if(mean_texture>20.02)
			{
				perimeter(mean_perimeter,40,17);
				if(mean_perimeter<=76.53)
				{
					return 1;
				}
				else
				{
					if(mean_smoothness>0.10120)
					{
						return 0;
					}
					else
					{
						radius(mean_radius,40,19);
						if(mean_radius>13.110)
						{
							return 0;
						}
						else
						{
							return 1;
						}
					}
				}
			}
			else
			{
				if(mean_area<=428.9)
				{
					return 1;
				}
				else
				{
					radius(mean_radius,40,17);
					if(mean_radius<=11.840)
					{
						return 0;
					}
					else
					{
						if(mean_smoothness<=0.09970)
						{
							return 1;
						}
						else
						{
							perimeter(mean_perimeter,40,19);
							if(mean_perimeter<=90.31)
							{
								return 1;
							}
							else
							{
								if(mean_texture>15.24)
								{
									return 0;
								}
								else
								{
									return 1;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main ()
{
	int diagnostico;
	char resp;
	//Tela Inicial
	tela(42,10,127,25,13);
	gotoxy(44,12);
	printf("Em todo o mundo, o cancer de mama e o tipo de cancer mais comum em mulheres e o ");
	gotoxy(44,13);
	printf("segundo mais alto em termos de taxas de mortalidade. ");
	gotoxy(44,14);
	printf("");
	gotoxy(44,15);
	printf("O diagnostico do cancer de mama e feito quando um nodulo e encontrado (pela propria"); 
	gotoxy(44,16);
	printf("pessoa ou por raio-x) ou quando uma mancha de calcio e vista (em um raio-x).");
	gotoxy(44,17);
	printf("");
	gotoxy(44,18);
	printf("Depois que um nodulo suspeito e encontrado, o medico realizara um diagnostico para");
	gotoxy(44,19);
	printf("determinar se e cancerigeno e, em caso afirmativo, se se espalhou para outras");
	gotoxy(44,20);
	printf("partes do corpo.");
	gotoxy(44,21);
	printf("");
	gotoxy(44,22);
	printf("Este conjunto de dados de cancer de mama foi obtido dos Hospitais da Universidade");
	gotoxy(44,23);
	printf("de Wisconsin, Madison, do Dr. William H. Wolberg.");
	getch();
	//INICIO
	do
	{
		clrscr();
		//Borda Principal
		tela(32,5,136,35,13);
		//Borda Introducao
		tela(67,6,101,8,13);
		//Introducao
		gotoxy(71,7);
		printf("Predicao de Cancer de Mama");
		//Borda Perguntas
		tela(38,10,130,31,13);
		//Perguntas
		diagnostico = arvore();
		if(diagnostico == 1)
		{
			gotoxy(80,33);
			printf("Maligno");
			//Borda Principal
			tela(32,5,136,35,12);
			//Borda Introducao
			tela(67,6,101,8,12);
			//Introducao
			gotoxy(71,7);
			printf("Predicao de Cancer de Mama");
			//Borda Perguntas
			tela(38,10,130,31,12);
		}
		else
		{
			gotoxy(80,33);
			printf("Benigno");
			//Borda Principal
			tela(32,5,136,35,9);
			//Borda Introducao
			tela(67,6,101,8,9);
			//Introducao
			gotoxy(71,7);
			printf("Predicao de Cancer de Mama");
			//Borda Perguntas
			tela(38,10,130,31,9);
		}
		gotoxy(40,29);
		printf("Deseja fazer outro diagnostico (S/N) ? ");
		fflush(stdin);
		scanf("%c",&resp);
		resp = toupper(resp);
		while(resp != 'S' && resp!= 'N')
		{
			gotoxy(40,30);
			printf("Digite uma opcao valida!");
			gotoxy(79,29);
			printf("          ");
			gotoxy(40,29);
			printf("Deseja fazer outro diagnostico (S/N) ? ");
			fflush(stdin);
			scanf("%c",&resp);
			resp = toupper(resp);
		}
	}while(resp == 'S');
	
	//FIM
	gotoxy(50,40);
	return 0;
}
