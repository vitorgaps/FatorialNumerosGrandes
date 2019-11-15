#include<stdio.h>

//Função que divide um numero em um vetor de 4 posições
void split(int numero,int vetor[4])
{
  for(int i=0;i<4;i++)
  	{
  	  vetor[i]=0;
  	}
  vetor[0]=numero%10;
  vetor[1]=(numero/10)%10;
  vetor[2]=(numero/100)%10;
  vetor[3]=numero/1000;
}

//Função que mostra o último número diferente de 0
int ultimoNumero(int vetor[])
{
  int ultimoNumero=0;
  for(int i=0;vetor[i]!=-1;i++)
  {
  	if(vetor[i]!=0 && vetor[i]!=-1)
    ultimoNumero=i;
  }
  return ultimoNumero;
}

//Função que multiplica dois numeros e divide entre unidade e dezena
void multiplica(int a,int b,int vetor[2])
{
	int multiplica;
	multiplica=a*b;
	vetor[0]=multiplica%10;
	vetor[1]=multiplica/10;
}

//Função que multiplica um numero pelo fatorial
void multiplicaTotal(int a,int fatorial[],int aux[])
{
   int i=0;
   int multiplicar[2]={0,0};
   for(int j=0;fatorial[i]!=-1;i++,j++)
     {
     	if(aux[j]==-1)
        aux[j]=0;
     	aux[j]+=multiplicar[1];
     	multiplica(a,fatorial[i],multiplicar);
        aux[j]+=multiplicar[0];        
     }
   aux[i]=multiplicar[1];   
}

//Função que coloca todos os elementos do vetor com o valor de -1
void limparVetor(int vetor[])
{
  for(int i=0;i<20000;i++)
   {
  	vetor[i]=-1;
   }   
}

//Função que verifica e substitui -1 por 0
int verificar(int a)
{
  if(a==-1)
  	return 0;
  else return a;
}

//Função que analisa se existem numeros com mais de um dígito no vetor
void ajustar(int vetor[])
{
  for(int i=0;i<20000;i++)
     {
       if(vetor[i]>9)
       {
         if(vetor[i+1]==-1)
       	  vetor[i+1]=vetor[i]/10;
         else
          vetor[i+1]+=vetor[i]/10;
          vetor[i]=vetor[i]%10;
       }       	 	
     }
}

//Função que calcula a fatorial
void fatorial(int numero)
{
  int fatorial[20000],aux1[20000],aux2[20000],aux3[20000],aux4[20000];
  int produto[4];
  split(numero,produto);
  
  limparVetor(fatorial); limparVetor(aux1); limparVetor(aux2); limparVetor(aux3); limparVetor(aux4);
  
  for(int i=0;i<4;i++)
  {
    fatorial[i]=produto[i];
  }

  numero-=1;
  for(int i=numero;i>1;i--)
  {
    split(i,produto);
    multiplicaTotal(produto[0],fatorial,aux1);
    multiplicaTotal(produto[1],fatorial,aux2);
    multiplicaTotal(produto[2],fatorial,aux3);
    multiplicaTotal(produto[3],fatorial,aux4);
    limparVetor(fatorial);

     fatorial[0]=aux1[0];
     fatorial[1]=aux1[1]+aux2[0];
     fatorial[2]=aux1[2]+aux2[1]+aux3[0];

     for(int i=0;aux4[i]!=-1;i++)
     {
     	fatorial[i+3]= verificar(aux1[i+3]) + verificar(aux2[i+2])+ verificar(aux3[i+1])+ verificar(aux4[i]); 
     }
   
   ajustar(fatorial);
   limparVetor(aux1);limparVetor(aux2);limparVetor(aux3);limparVetor(aux4);
  }
  for(int i=ultimoNumero(fatorial);i>=0;i--)
  {
  	printf("%d",fatorial[i]);
  }
}


int main()
{
	int numero;
	printf("Digite um numero inteiro: ");
	scanf("%d",&numero);
	printf("Resultado: ");
	fatorial(numero);
	printf("\n");
}
