//Nome: Shanjit  Cognome: Singh  Matricola: 315575

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char * argv[]) {
    
    //dichiarazione variabile
    int a,i,t;
    char m[128];
    char k[128];
    char k_cas[128];
    char cripted[128];
    char encripted[128];
    char char_key[128];
    int len1,len2,len3;
    //richiesta chiave
    puts("inserire il testo da cifrare :\n");
    fgets(m,128,stdin);
    len1=strlen(m)-1;
    		//selezione tipo di chiave e controllo
		do
		{
		
			printf("selezionare 1 per inserire la chiave :\n");
			printf("selezionare 2 per generare la chiave :\n");
			scanf("%d",&a);
		
		}while (a != 1 && a != 2);
		while (getchar()!='\n');

    	//condizione per inserire la chiave
	if (a==1)
	{
		
		
		//richiesta chiave e controllo
		do{
			puts("inserisci la chiave : \n");
			fgets(k,128,stdin);
			len2=strlen(k)-1;
			printf("la chiave è: %s", k);
		}while (len2<len1);
		
		//esecuzione del oxr
		for(i=0;i<len2;i++)
			{
				
				char appoggio = m[i] ^ k[i];
				cripted[i]= appoggio;
				encripted[i] = cripted[i] ^ k[i];	
		
			}
		
			cripted[i] = '\0';
			//stampa della chiave criptata e decriptata e delle varie lunghezze della chiave e della stringa inserita
			printf("\n lunghezza della stringa : \n %ld", len1);
			printf("\n lunghezza della chiave : \n %ld", len2);
			printf("\n la stringa criptata : \n %s", cripted);
			printf("\n la stringa decriptata è: \n %s " ,encripted);
			
	}
	//condizione per la generazione casuale della chiave
	if(a==2)
	{
		
		srand(time(0));
		//generazione chiave casuale
		printf("la chiave generata casualmente è : \n");
			for(t = 0;  t != len1 ; t++)
				{
					k[t]= 32 + rand()%128;
					printf("%c", k_cas[t]=k[t]);
			
				}
		
		//esecuzione del xor
		for(i=0;i<strlen(m);i++)
		{
			char appoggio1 = m[i] ^ k_cas[i];
			cripted[i]= appoggio1;
			encripted[i] = cripted[i] ^ k_cas[i];
		}
		cripted[i] = '\0';
		
		//stampa frase criptata e la frase decriptata
		
		printf("\n stringa criptata : \n %s", cripted);
		printf("\n la stringa decriptata è: \n %s " ,encripted);
		
		
	}
	
	
	
	return 0;
}
