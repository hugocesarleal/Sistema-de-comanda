#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>

using namespace std;

string vetPag[3], vetBorda[10],  matSab[4][5],sabor;
double matP[3][4];
int fatia, vetBordaP[10], numeroSabor, numeroBorda;
float troco;

//Procedimento responsável por alimentar as matrizes e vetores
void alimentacao()
{
    matSab[0][0]="Calabresa", matSab[0][1]="Frango Catupiry", matSab[0][2]="Marguerita", matSab[0][3]="Bacon", matSab[0][4]="Mussarela", matSab[1][0]="Mafiosa", matSab[1][1]="4 queijos", matSab[1][2]="Peperone", matSab[1][3]="Lombinho", matSab[1][4]="Portuguesa", matSab[2][0]="Palmito", matSab[2][1]="Filé Mignon", matSab[2][2]="Atum", matSab[2][3]="Carne Seca", matSab[2][4]="Tomate Seco", matSab[3][0]="Oreo", matSab[3][1]="Confeti", matSab[3][2]="Brigadeiro", matSab[3][3]="Ovomaltine", matSab[3][4]="Sonho de Valsa";
    matP[0][0]=30, matP[0][1]=32, matP[0][2]=35, matP[0][3]=35, matP[1][0]=38, matP[1][1]=40, matP[1][2]=45, matP[1][3]=40, matP[2][0]=45, matP[2][1]=48, matP[2][2]=55, matP[2][3]=45;
    vetBorda[0]="Catupiry", vetBorda[1]="Cheedar", vetBorda[2]="Mista", vetBorda[3]="Bolinha", vetBorda[4]="Chocolate", vetBorda[5]="Pãozinho", vetBorda[6]="Vulcão", vetBorda[7]="Prestígio", vetBorda[8]="Confeti", vetBorda[9]="Ondinha";
    vetBordaP[0]=5, vetBordaP[1]=5, vetBordaP[2]=8, vetBordaP[3]=8, vetBordaP[4]=8, vetBordaP[5]=12, vetBordaP[6]=10, vetBordaP[7]=10, vetBordaP[8]=10, vetBordaP[9]=7;
    vetPag[0]="Dinheiro", vetPag[1]="Pix", vetPag[2]="Cartão";
}

//Função responsável por perguntar ao usuário se precisará de troco e quanto
double fTroco()
{

    double resposta;

    cout << "Vai precisar de troco? (Se sim, digite 1, se não, digite 0) " << endl;
    cin >> resposta ;

    system("cls");

    if(resposta==1)
    {
        cout << "Quanto? ";
        cin >> resposta;

        system("cls");

        return resposta;
    }
}

//Função responsável por perguntar ao usuário qual a forma de pagamento
string fPagamento()
{

    int numero;
    string resposta ;

    cout << "Qual a forma de pagamento ? " << endl ;
    cout << "1-Dinheiro   2-Pix   3-Cartão" << endl;
    cin >> numero ;

    system("cls");

    switch(numero)
    {
    case 1:
        resposta = "Dinheiro";
        break;
    case 2:
        resposta = "Pix";
        break;
    case 3:
        resposta = "Cartão";
        break;
    default: "Número inválido"
        ;
    }
    return resposta ;
}

//Função responsável por perguntar qual será a borda, calcular seu valor e fazer o retorno
int fBorda()
{

    alimentacao();

    int pBorda;
    string borda ;

    for(int i=0; i<5; i++)
    {
        cout << i+1 << "-" << vetBorda[i] << "   ";
    }

    cout << endl;

    for(int i=5; i<10; i++)
    {
        cout << i+1 << "-" << vetBorda[i] << "   ";
    }

    cout << "\n\nQual o sabor da borda ? ";
    cin >> numeroBorda ;

    system("cls");

    int cont=1;

    for(int i=0; i<10; i++)
    {
        cont=cont+1;
        if(numeroBorda==cont-1)
        {
            borda = vetBorda[i];
            pBorda = vetBordaP[i];
        }
    }
    return pBorda ;
}

//Função responsável por perguntar qual o sabor da pizza, calcular e retornar seu preço
double fSabores()
{

    alimentacao();

    string sabor;

    int cont=1;

    cout << "Escolha o sabor da pizza usando os números:\n\n";

    for(int cL=0; cL<4; cL++)
    {
        for(int cC=0; cC<5; cC++)
        {

            cout << cont << "-" << matSab[cL][cC] << "   ";
            cont = cont+1;
        }
        cout << endl;
    }

    cin >> numeroSabor;

    system("cls");

    int preco;

    cont=1;

    switch(fatia)
    {
    case 4:
        for(int cL=0; cL<4; cL++)
        {
            for(int cC=0; cC<5; cC++)
            {

                cont=cont+1;
                if(numeroSabor==cont-1)
                {
                    sabor = matSab[cL][cC];
                    preco=matP[0][cL];
                }
            }
        }
        break;
    case 6:
        for(int cL=0; cL<4; cL++)
        {
            for(int cC=0; cC<5; cC++)
            {

                cont=cont+1;
                if(numeroSabor==cont-1)
                {
                    sabor = matSab[cL][cC];
                    preco=matP[1][cL];
                }
            }
        }
        break;
    case 8:
        for(int cL=0; cL<4; cL++)
        {
            for(int cC=0; cC<5; cC++)
            {

                cont=cont+1;
                if(numeroSabor==cont-1)
                {
                    sabor = matSab[cL][cC];
                    preco=matP[2][cL];
                }
            }
        }
        break;
    default:
        cout<< "Erro match fatia";
    }
    return preco;
}

//Procedimento principal que pergunta o nome, endereço, telefone, quantas fatias terá a pizza, chama todas as funções anteriores
//Escreve todas as informações no arquivo Pedido.txt
//Lê e mostra o arquivo Pedido.txt

void pInicio()
{

    FILE *arq;

    int op = 1;
    char texto_linha[50];

    arq = fopen("Pedido.txt", "w");

    cout << "Qual o seu nome : ";
    fflush(stdin);
    cin >> texto_linha;
    fputs("Nome: ",arq);
    fputs(texto_linha, arq);
    fputs("\n", arq);

    system("cls");

    cout << "Qual o seu telefone : ";
    fflush(stdin);
    cin >> texto_linha;
    fputs("Telefone: ",arq);
    fputs(texto_linha, arq);
    fputs("\n", arq);

    system("cls");

    cout << "Qual o seu endereço : ";
    fflush(stdin);
    cin >> texto_linha;
    fputs("Endereço: ",arq);
    fputs(texto_linha, arq);
    fputs("\n", arq);

    system("cls");

    fputs("--------------------------------", arq);
    fputs("\n            Delivery            \n", arq);
    fputs("--------------------------------\n", arq);

    cout << "Quantas fatias você deseja ? ( 4 , 6 ou 8 )" << endl ;
    cin >> fatia;

    system("cls");

    switch(fatia)
    {
    case 4:
        fputs("Pizza Pequena 4 Fatias", arq);
        break;
    case 6:
        fputs("Pizza Média 6 Fatias", arq);
        break;
    case 8:
        fputs("Pizza Grande 8 Fatias", arq);
        break;
    default:
        fputs("Erro", arq);;
    }

    int precoPizza = fSabores();

    switch(precoPizza)
    {
    case 30:
        fputs("   R$30,00", arq);
        break;
    case 32:
        fputs("   R$32,00", arq);
        break;
    case 35:
        fputs("   R$35,00", arq);
        break;
    case 38:
        fputs("   R$38,00", arq);
        break;
    case 40:
        fputs("   R$40,00", arq);
        break;
    case 45:
        fputs("   R$45,00", arq);
        break;
    case 48:
        fputs("   R$48,00", arq);
        break;
    case 55:
        fputs("   R$55,00", arq);
        break;
    default:
        fputs("Erro", arq);
    }



    fputs("\n\nSabor\n", arq);

    switch(numeroSabor)
    {
    case 1:
        fputs("Calabresa", arq);
        break;
    case 2:
        fputs("Frango Catupiry", arq);
        break;
    case 3:
        fputs("Marguerita", arq);
        break;
    case 4:
        fputs("Bacon", arq);
        break;
    case 5:
        fputs("Mussarela", arq);
        break;
    case 6:
        fputs("Mafiosa", arq);
        break;
    case 7:
        fputs("4 Queijos", arq);
        break;
    case 8:
        fputs("Peperone", arq);
        break;
    case 9:
        fputs("Lombinho", arq);
        break;
    case 10:
        fputs("Portuguesa", arq);
        break;
    case 11:
        fputs("Palmito", arq);
        break;
    case 12:
        fputs("Filé Mignon", arq);
        break;
    case 13:
        fputs("Atum", arq);
        break;
    case 14:
        fputs("Carne Seca", arq);
        break;
    case 15:
        fputs("Tomate Seco", arq);
        break;
    case 16:
        fputs("Oreo", arq);
        break;
    case 17:
        fputs("Confeti", arq);
        break;
    case 18:
        fputs("Brigadeiro", arq);
        break;
    case 19:
        fputs("Ovomaltine", arq);
        break;
    case 20:
        fputs("Sonho de Valsa", arq);
        break;
    }
    fputs("\n\nSabor da Borda\n", arq);

    int precoBorda = fBorda() ;

    switch(numeroBorda)
    {
    case 1:
        fputs("Catupiry", arq);
        break;
    case 2:
        fputs("Cheedar", arq);
        break;
    case 3:
        fputs("Mista", arq);
        break;
    case 4:
        fputs("Bolinha", arq);
        break;
    case 5:
        fputs("Chocolate", arq);
        break;
    case 6:
        fputs("Pãozinho", arq);
        break;
    case 7:
        fputs("Vulcão", arq);
        break;
    case 8:
        fputs("Prestígio", arq);
        break;
    case 9:
        fputs("Confeti", arq);
        break;
    case 10:
        fputs("Ondinha", arq);
        break;
    }

    switch(precoBorda)
    {
    case 5:
        fputs("              R$5,00", arq);
        break;
    case 7:
        fputs("              R$7,00", arq);
        break;
    case 8:
        fputs("              R$8,00", arq);
        break;
    case 10:
        fputs("              R$10,00", arq);
        break;
    case 12:
        fputs("              R$12,00", arq);
        break;
    }

    char nota[50];

    cout << "O cliente possui alguma observação ? " << endl;
    cin >> nota ;

    system("cls");

    fputs("\n--------------------------------\n", arq);
    fputs("Observações: ", arq);
    fputs(nota, arq);
    fputs("\n--------------------------------\n", arq);

    float subTotal= precoPizza+precoBorda, total=precoPizza+precoBorda+3;

    string entrega = "3,00";
    int n = entrega.length();
    char entregaChar[n + 1];
    strcpy(entregaChar, entrega.c_str());

    char subTotalChar[16];
    sprintf(subTotalChar, "%.2f", subTotal);

    char totalChar[16];
    sprintf(totalChar, "%.2f", total);

    fputs("SubTotal:                ", arq);
    fputs(subTotalChar, arq);

    fputs("\nTaxa de entrega:          ", arq);
    fputs(entregaChar, arq);

    fputs("\nTotal:                   ", arq);
    fputs(totalChar, arq);

    fputs("\n--------------------------------\n", arq);

    fputs("Forma de pagamento:\n", arq);

    string pagamento = fPagamento() ;

    n = pagamento.length();
    char pagamentoChar[n + 1];
    strcpy(pagamentoChar, pagamento.c_str());

    fputs(pagamentoChar, arq);

    if(pagamento=="Dinheiro")
    {
        fputs("    troco  R$", arq);

        troco = fTroco();

        char trocoChar[16];
        sprintf(trocoChar, "%.3f", troco);
        fputs(trocoChar, arq);
    }

    fputs("~", arq);

    fclose(arq);

    cout << "Imprimindo...";
    sleep(2);

    system("cls");

    string ch;

    arq = fopen("Pedido.txt", "r");

    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else
    {
        while( (ch=fgetc(arq))!= "~" )
        {
            cout << ch;
        }
    }
    fclose(arq);
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    pInicio();

    return 0;
}
