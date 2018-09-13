#include <stdio.h>
#include <stdlib.h>

// Adiciona cada bit em ordem no vetor que representa 4bit's
void tratarInteiro(int entrada, int saida[]) {
    for (int i = 3; i >= 0; i--){
        saida[i] = entrada%10;
        entrada /= 10;
    }
}

// inicializa os 4bit's mais significativos com '0' (prufuto2[0] à produto2[3])
// adiciona o valor lido nos 4bit's menos significativos (produto2[4] à produto[7])
// inicializa o valor extra(utilizado para comparaçao) com 0 (produto2[8])
void tratarEntrada(int produto, int produto2[]){
    for( int i = 8; i >= 0; i--){
        if( i > 3 && i < 8){
            produto2[i] = produto%10;
            produto /= 10;
        }
        else
            produto2[i] = 0;
    }
}

// Converte o valor em binário de 4bit's para negativo
void complementoDeDois(int Mcand[], int McandInvertido[]){
    for(int i = 0; i < 4; i++){
        if(Mcand[i] == 1){
            McandInvertido[i] = 0;
        }
        else
            McandInvertido[i] = 1;
    }

    for (int i = 3; i >=0; i--){
        if (McandInvertido[i] == 1){
            McandInvertido[i] = 0;
        }
        else{
            McandInvertido[i] = 1;
            break;
        }

    }
}

// Soma dois valores binarios de 4bit's
// com os 4bit's mais significativos de 'produto2'
void soma(int McandInvertido[],int produto2[]){
    int vai = 0, ident;
    for (int i = 3; i >=0; i--){
        ident = vai + produto2[i] + McandInvertido[i];
        if (ident%2 == 0)
            produto2[i] = 0;
        else
            produto2[i] = 1;
        if (ident > 1)
            vai = 1;
        else
            vai = 0;
    }
}

// desloca um bit à direita(shift a direita)
void shift(int produto2[]){

    for (int i = 8; i > 0; i--){
        produto2[i] = produto2[i-1];
    }
}

// Imprime o resultado do produto
void imprimi(int produto2[]){
    for (int i = 0; i < 8; i++)
        printf("%d",produto2[i]);
}


int main()
{
    int produto, multiplicando, produto2[9], Mcand[4],McandInvertido[4];
    scanf("%d %d",&produto,&multiplicando);


    tratarEntrada(produto,produto2);
    tratarInteiro(multiplicando, Mcand);
    complementoDeDois(Mcand,McandInvertido);

    // Compara o bit menos significativo do produto2 com o bit extra
   for (int i=0; i < 4; i++){
        if(produto2[7] > produto2[8]){
            soma(McandInvertido,produto2);

        }

        else if(produto2[7] < produto2[8]){
            soma(Mcand,produto2);
        }
        shift(produto2);
    }



    imprimi(produto2);



    return 0;
}
