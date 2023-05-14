#include<stdio.h>
#include<conio2.h>
#include<math.h>
void ledecimal(int &decimal)
{
	printf("Digite o numero:\n");
	scanf("%d",&decimal);
}
void exibe(int numero)
{
	printf("%d",numero);
}
void decparabin(int decimal,int &binario)
{
	binario = 0;
	int a=0,b=1;
	while(decimal>0)
	{
		a = decimal%2;
		binario += a*b;
		b = b*10;
		decimal = decimal/2;
	}
}
int main()
{
	int valor, res;
	ledecimal(valor);
	decparabin(valor,res);
	exibe(res);
	return 0;
}
