#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>


int movi (void);
int poupanca_funcao(void);
int deposita(void);
int menu(void);
int relatorio(void);
int contadigital(void);
int gerenciador(void);
int relatorio(void);
int sacar(void);
int relA(void);


FILE *poupanca_arquivo;
FILE *conta_arquivo;
FILE *jan;
FILE *fev;
FILE *mar;
FILE *abr;
FILE *mai;
FILE *jun;
FILE *jul;
FILE *ago;
FILE *set;
FILE *out;
FILE *nov;
FILE *dez;

double conta,poupanca_valor;


//O programa main realiza a verificação e criação dos arquivos utilizados no pragoma

int main() {


	conta_arquivo = fopen("conta.txt","r");
  
  

  //Caso não exista valor na "conta", é feito a criação de todos os arquivos nescessários.
	if (conta_arquivo == NULL){
    poupanca_arquivo = fopen("poupanca.txt","w");
    conta_arquivo = fopen("conta.txt","w");
		
  
    fclose(poupanca_arquivo);
    fclose(conta_arquivo);
	}
  
  else{
    //abro o arquivo poupanca.txt para capturar o valor do arquivo e salvar na variável "poupanca_valor" o mesmo é feito com a varável "conta"

    poupanca_arquivo = fopen("poupanca.txt","r+");

    fscanf(conta_arquivo,"%lf",&conta);
    fscanf(poupanca_arquivo,"%lf",&poupanca_valor);

		fclose(conta_arquivo);
    fclose(poupanca_arquivo);
	}

  // chama a função "menu", sendo menu principal do programa
  menu();
	
}





//MENU PRINCIPAL DO PROGRAMA
// Usuario tera acesso a uma conta digital e um gerenciador de investimentos.

int menu(){
  int indice;
  while(1){
  printf("------------------------------------ \n ");
  printf("       BEM VINDO AO BANK7        \n\n");
  printf("Escolha uma das opções abaixo: \n\n");
  printf("1 - Conta Digital \n");
  printf("2 - Gerenciador Financeiro \n");
  printf("3 - Sair do aplicativo \n");
  printf("------------------------------------ \n");

  scanf("%d",&indice);

  if(indice == 1){
    contadigital();
  }
  else if(indice ==2){
    gerenciador();
  }
  else if(indice == 3){
    //antes de finalizar o programa ele atualiza o arquivo com o valor da variável "conta" e a variável "poupanca_valor"

    conta_arquivo = fopen("conta.txt","w+");
    fprintf(conta_arquivo,"%lf",conta);

    poupanca_arquivo = fopen("poupanca.txt","w+");
    fprintf(poupanca_arquivo,"%lf",poupanca_valor);

    fclose(poupanca_arquivo);
    fclose(conta_arquivo);
    exit(0);
  }
  else{
    printf("\n\n");
    printf("ERRO!! \n");
    printf("Escolha uma das opcoes acima!! \n");
  }


  // fim do while menu principal
  
  }



}






//CONTA DIGITAL
// função para o menu da conta digital.
int contadigital(void){

  int indice;
  while(1){
  printf("\n \n \n");
  printf("            CONTA DIGITAL 1.0       \n");
  printf("------------------------------------ \n");
  printf("               MENU \n \n");
  printf("1 - Poupança \n");
  printf("2 - Depositar em sua conta \n");
  printf("3 - Sacar da sua conta \n");
  printf("4 - Voltar para o menu principal \n");
  printf("\n \n ");
  printf("O seu saldo atual é: R$%.2lf \n",conta);
  printf("------------------------------------ \n");
    
  scanf("%d",&indice);

  if(indice==1){
    poupanca_funcao();
  }
  else if (indice == 2){
      deposita();
  }
  else if (indice ==3){
     sacar();
  }
  else if(indice ==4){
      menu();
  }
  else{
    printf("\n\n");
    printf("ERRO!! \n");
    printf("Escolha uma das opcoes acima!! \n");
  }

    //Fim do while
  }
  

}








//GERENCIADOR FINANCEIRO 
//função para o menu do gerenciador financeiro.

int gerenciador(void){
int indice;
while(1){
printf("\n \n \n");
printf("     GERENCIADO FINANCEIRO 1.0       \n");
printf("------------------------------------ \n");
printf("                MENU                \n\n");
printf("1 - Cadastro de entradas e saidas \n");
printf("2 - Relatório mensal \n");
printf("3 - Relatório anual \n");
printf("4 - Voltar para o menu principal \n\n");

printf("Escolha uma opção: \n");
scanf("%d",&indice);

if(indice == 1){
  movi();
}
else if(indice == 2){
    relatorio();
}
else if(indice == 3){
  relA();
}
else if(indice == 4){
  menu();
}
else{
    printf("\n\n");
    printf("ERRO!! \n");
    printf("Escolha uma das opcoes acima!! \n");
}

// fim do while
}

}






//GERENCIADOR
// Função para acrescentar valores para o relatorio do gerenciador
int movi (void){
	
	double valor;
	char categoria[15];
	char data[8];
	char descr[25];
  int mes;


  printf("Digite a data: (dd/mm/aa)\n");
  scanf("%s",data);
 
  if(((data[3])-48) !=0 && ((data[3]-48)==1)){
    if(((data[4])-48)==1){
      mes = 11;
    }
    else if(((data[4])-48)==2){
      mes = 12;
    }
    else if(((data[4])-48)==0){
      mes = 10;
    }
  }
  else if(((data[3])-48)==0){
    mes = ((data[4]) - 48);
  }else{
    printf("\nMês inválido.\n");
    printf("Tente novamente\n\n");
    gerenciador();
  }
  

  printf("Digite o valor:\n");
  scanf("%lf",&valor);
  
  printf("Qual a categoria?\n");
  scanf("%s",categoria);
  
  printf("Descrição do gasto:\n");
  scanf("%s[^\n]", descr);

  if(mes == 1){
    jan = fopen("jan.txt","a+");
    fprintf(jan,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(jan,"%c",data[x]);
    }
    fprintf(jan,"\n");
    fprintf(jan,"%2.lf \n",valor);
    fprintf(jan,"%s \n",descr);
    fclose(jan);
  }
  else if(mes == 2){
    fev = fopen("fev.txt","a+");
    fprintf(fev,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(fev,"%c",data[x]);
    }
    fprintf(fev,"\n");
    fprintf(fev,"%2.lf \n",valor);
    fprintf(fev,"%s \n",descr);
    fclose(fev);
  }
  else if(mes == 3){
    mar = fopen("mar.txt","a+");
    fprintf(mar,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(mar,"%c",data[x]);
    }
    fprintf(mar,"\n");
    fprintf(mar,"%2.lf \n",valor);
    fprintf(mar,"%s \n",descr);
    fclose(mar);
  }
  else if(mes == 4){
    abr = fopen("abr.txt","a+");
    fprintf(abr,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(abr,"%c",data[x]);
    }
    fprintf(abr,"\n");
    fprintf(abr,"%2.lf \n",valor);
    fprintf(abr,"%s \n",descr);
    fclose(abr);
  }
  else if(mes == 5){
    mai = fopen("mai.txt","a+");
    fprintf(mai,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(mai,"%c",data[x]);
    }
    fprintf(mai,"\n");
    fprintf(mai,"%2.lf \n",valor);
    fprintf(mai,"%s \n",descr);
    fclose(mai);
  }
  else if(mes == 6){
    jun = fopen("jun.txt","a+");
    fprintf(jun,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(jun,"%c",data[x]);
    }
    fprintf(jun,"\n");
    fprintf(jun,"%2.lf \n",valor);
    fprintf(jun,"%s \n",descr);
    fclose(jun);
  }
  else if(mes == 7){
    jul = fopen("jul.txt","a+");
    fprintf(jul,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(jul,"%c",data[x]);
    }
    fprintf(jul,"\n");
    fprintf(jul,"%2.lf \n",valor);
    fprintf(jul,"%s \n",descr);
    fclose(jul);
  }
  else if(mes == 8){
    ago = fopen("ago.txt","a+");
    fprintf(ago,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(ago,"%c",data[x]);
    }
    fprintf(ago,"\n");
    fprintf(ago,"%2.lf \n",valor);
    fprintf(ago,"%s \n",descr);
    fclose(ago);
  }
  else if(mes == 9){
    set = fopen("set.txt","a+");
    fprintf(set,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(set,"%c",data[x]);
    }
    fprintf(set,"\n");
    fprintf(set,"%2.lf \n",valor);
    fprintf(set,"%s \n",descr);
    fclose(set);
  }
  else if(mes == 10){
    out = fopen("out.txt","a+");
    fprintf(out,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(out,"%c",data[x]);
    }
    fprintf(out,"\n");
    fprintf(out,"%2.lf \n",valor);
    fprintf(out,"%s \n",descr);
    fclose(out);
  }
  else if(mes == 11){
    nov = fopen("nov.txt","a+");
    fprintf(nov,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(nov,"%c",data[x]);
    }
    fprintf(nov,"\n");
    fprintf(nov,"%2.lf \n",valor);
    fprintf(nov,"%s \n",descr);
    fclose(nov);
  }
  else if(mes == 12){
    dez = fopen("dez.txt","a+");
    fprintf(dez,"%s \n",categoria);
    for(int x=0;x<8;x++){
      fprintf(dez,"%c",data[x]);
    }
    fprintf(dez,"\n");
    fprintf(dez,"%2.lf \n",valor);
    fprintf(dez,"%s \n",descr);
    fclose(dez);
  }

  printf("\n \n");
  printf("Realizado o cadastro com sucesso!! \n\n");
  
  return 0;

  
 
}





//CONTA DIGITAL
//Função para adicionar e visualizar poupança na conta digital
int poupanca_funcao(void){
  int indice;
    while(1){
    printf("------------------------------------ \n");
    printf("                POUPANCA              \n  \n");
    printf("1 - Aplicar na poupanca \n");
    printf("2 - Resgatar \n");
    printf("3 - Voltar para o menu \n");
    printf("\n\n");
    printf("O saldo atual poupanca: R$ %.2lf \n",poupanca_valor);
    printf("------------------------------------ \n");
    printf("\n");
   

    scanf("%d",&indice);

    if(indice==1){
      double valor;
      printf("Digite a quantidade que deseja aplicar \n");
      printf("R$: ");
      scanf("%lf",&valor);
      if(valor <= conta){
      printf("Parabens!!! \n");
      printf("O deposito de R$%.2lf caiu em sua conta poupança!!\n", valor);
      poupanca_valor += valor + (poupanca_valor * 0.010);
      conta -= valor;
      }
      else{
        printf(" \n \n");
        printf("ERRO \n");
        printf("Voce nao tem saldo suficiente!! \n");
        printf("------------------------------------ \n \n");
      }
      
    }
    else if (indice==2){
      double valor;
      printf("Digite a quantidade que deseja resgatar \n");
      printf("R$: ");
      scanf("%lf",&valor);
      if(valor<=poupanca_valor){
        printf("Resgate feito com sucesso!!! \n \n");
        poupanca_valor -= valor;
         conta += valor;
      }
      else{
        printf("\n\n");
        printf("ERRO \n");
        printf("Voce nao tem saldo suficiente!! \n");
        printf("------------------------------------ \n \n");
      }
    }

    else if(indice==3){
        return contadigital();
    }
    else{
    printf("\n\n");
    printf("ERRO!! \n");
    printf("Escolha uma das opcoes acima!! \n");
    }

    // fim do while poupança
    }

  
  

}





//CONTA DIGITAL
//Função para depositar dinheiro na conta
int deposita(void){
  double depositar =0;
  printf("------------------------------------ \n \n");
  printf("Digite a quantidade que deseja depositar: \n");
  printf("R$:");
  scanf("%lf",&depositar);

  if(depositar >=0){
  conta += depositar;
  

  printf("Parabens!!! \n");
  printf("O deposito de %.2lf caiu em sua conta!!\n", depositar);
  printf("------------------------------------ \n \n");

  return contadigital();
  }
  else{
    printf("\n\n");
    printf("ERRO!! \n");
    printf("Número inválido\n");
    deposita();
    }

  return 0;
}


//CONTA DIGITAL
//Função para realizar o saue no valor da conta
int sacar(void){

  double valor =0;
  while(1){
  printf("------------------------------------ \n \n");
  printf("Digite a quantidade que deseja sacar: \n");
  printf("R$:");
  scanf("%lf",&valor);

  if(valor<=conta && valor >=0){
    printf("Saque de R$%.2lf feito com sucesso!!! \n \n",valor);
    printf("------------------------------------ \n \n");
    conta-=valor;
    contadigital();
  }
  else{
  
    printf("\n\n");
    printf("ERRO \n");
    printf("Voce nao tem saldo suficiente!! \n");
    printf("------------------------------------ \n \n");
    contadigital();
   
  }

  }

}


//FUNCAO PARA GERAR O RELATORIO MENSAL

int relatorio(void){

    FILE *index;
    
    double valor;
  	char categoria[15];
  	char data[8];
  	char descr[25];
    int mes;

    printf("Gerar relatório de qual mês? (1 a 12)\n ");
    scanf("%d", &mes);

    index = fopen("index.html","w");
    fprintf(index,"<!DOCTYPE html> \n");
    fprintf(index,"<html lang=en>\n");
    fprintf(index,"<head> \n");
    fprintf(index,"<meta charset=UTF-8>\n");
    fprintf(index,"<title>Relatório Mensal</title> \n");
    fprintf(index,"<style> \n");

     
    fprintf(index,"#tabela{text-align: center; } body{background: lightskyblue; font-family: Comic Sans MS;} table{padding: 5px 10px; border: 8px forestgreen; padding: 10px 10px;}");
      
      

    fprintf(index,"\n</style> \n");
    fprintf(index,"</head> \n");
    fprintf(index,"<body> \n");
    fprintf(index,"<h1>RELATORIO MENSAL</h1> \n");

    
    if(mes == 1){
      jan = fopen("jan.txt","r");
      if(jan != NULL){
      fprintf(index,"<h2>JANEIRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(jan, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(jan);
    }else if(mes == 2){
      fev = fopen("fev.txt","r");
      if(fev != NULL){
      fprintf(index,"<h2>FEVEREIRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(fev, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(fev);
    }else if(mes == 3){
      mar = fopen("mar.txt","r");
      if(mar!=NULL){
      fprintf(index,"<h2>MARÇO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(mar, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(mar);
    }else if(mes == 4){
      abr = fopen("abr.txt","r");
      if(abr != NULL){
      fprintf(index,"<h2>ABRIL:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(abr, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(abr);
    }else if(mes == 5){
      mai = fopen("mai.txt","r");
      if(mai != NULL){
      fprintf(index,"<h2>MAIO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(mai, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(mai);
    }else if(mes == 6){
      jun = fopen("jun.txt","r");
      if(jun != NULL){
      fprintf(index,"<h2>JUNHO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(jun, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(jun);
    }else if(mes == 7){
      jul = fopen("jul.txt","r");
      if(jul != NULL){
      fprintf(index,"<h2>JULHO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(jul, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(jul);
    }else if(mes == 8){
      ago = fopen("ago.txt","r");
      if(ago !=NULL){
      fprintf(index,"<h2>AGOSTO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(ago, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(ago);
    }else if(mes == 9){
      set = fopen("set.txt","r");
      if(set !=NULL){
      fprintf(index,"<h2>SETEMBRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(set, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(set);
    }else if(mes == 10){
      out = fopen("out.txt","r");
      if(out !=NULL){
      fprintf(index,"<h2>OUTUBRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(out, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(out);
    }else if(mes==11){
      nov = fopen("nov.txt","r");
      if(nov != NULL){
      fprintf(index,"<h2>NOVEMBRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(nov, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(nov);
    }else if(mes == 12){
      dez = fopen("dez.txt","r");
      if(dez != NULL){
      fprintf(index,"<h2>DEZEMBRO:</h2>\n");
      fprintf(index,"<table width=50%% height=20%% border=1>\n");
      fprintf(index,"<tr id=tabela>\n");
      fprintf(index,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
      fprintf(index,"</tr> \n");

      while ( (fscanf(dez, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(index,"<tr id=tabela>\n");
        fprintf(index,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }

      }else{
        printf("\n");
        printf("Não existe dados cadastrados nesse mes!! \n \n");
        return gerenciador();
      }
      fclose(dez);
    }
    else{
      printf("\n");
      printf("Numero Incorreto!! \n\n");
      return relatorio();
    }
    printf("\n \n");
    printf("Relatorio gerado com sucesso!! \n \n");
    fprintf(index,"</tr> \n");
    fprintf(index,"</table> \n");
    fprintf(index,"</body> \n");
    fprintf(index,"</html> \n");
    fclose(index);
   

    return menu();
}



// FUNCAO PARA GERAR O RELATORIO ANUAL

int relA(){

    FILE *indexA;
  
    double valor;
  	char categoria[15];
  	char data[8];
  	char descr[25];


    indexA = fopen("indexA.html","w");
    fprintf(indexA,"<!DOCTYPE html> \n");
    fprintf(indexA,"<html lang=en>\n");
    fprintf(indexA,"<head> \n");
    fprintf(indexA,"<meta charset=UTF-8>\n");
    fprintf(indexA,"<title>Relatório Anual</title> \n");
    fprintf(indexA,"<style> \n");

     
    fprintf(indexA,"#tabela{text-align: center; } body{background: lightskyblue; font-family: Comic Sans MS;} table{padding: 5px 10px; border: 8px forestgreen; padding: 10px 10px;} td{width: 300px;}");
      
      

    fprintf(indexA,"\n</style> \n");
    fprintf(indexA,"</head> \n");
    fprintf(indexA,"<body> \n");
    fprintf(indexA,"<h1>RELATORIO ANUAL</h1> \n");


    jan = fopen("jan.txt","r");
    fev = fopen("fev.txt","r");
    mar = fopen("mar.txt","r");
    abr = fopen("abr.txt","r");
    mai = fopen("mai.txt","r");
    jun = fopen("jun.txt","r");
    jul = fopen("jul.txt","r");
    ago = fopen("ago.txt","r");
    set = fopen("set.txt","r");
    out = fopen("out.txt","r");
    nov = fopen("nov.txt","r");
    dez = fopen("dez.txt","r");

    fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
    fprintf(indexA,"<tr id=tabela>\n");
    fprintf(indexA,"<td height=60 > CATEGORIA </td> <td>  DATA  </td> <td>  VALOR  </td> <td> DESCRIÇÃO </td>");
    fprintf(indexA,"</tr> \n");
    


    if(jan != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>JANEIRO:</td></tr>\n");
      while ( (fscanf(jan, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(jan);
    }if(fev != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>FEVEREIRO:</td></tr>\n");
      while ( (fscanf(fev, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(fev);
    }if(mar != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>MARÇO:</td></tr>\n");
      while ( (fscanf(mar, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(mar);
    }if(abr != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>ABRIL:</td></tr>\n");
      while ( (fscanf(abr, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(abr);
    }if(mai != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>MAIO:</td></tr>\n");
      while ( (fscanf(mai, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(mai);
    }if(jun != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>JUNHO:</td></tr>\n");
      while ( (fscanf(jun, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(jun);
    }if(jul != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>JULHO:</td></tr>\n");
      while ( (fscanf(jul, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(jul);
    }if(ago != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>AGOSTO:</td></tr>\n");
      while ( (fscanf(ago, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(ago);
    }if(set != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>SETEMBRO:</td></tr>\n");
      while ( (fscanf(set, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(set);
    }if(out != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>OUTUBRO:</td></tr>\n");
      while ( (fscanf(out, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(out);
    }if(nov != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>NOVEMBRO:</td></tr>\n");
      while ( (fscanf(nov, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(nov);
    }if(dez != NULL){
      fprintf(indexA,"<table width=60%% height=20%% border=1>\n");
      fprintf(indexA,"<tr><td>DEZEMBRO:</td></tr>\n");
      while ( (fscanf(dez, "%s  %s %lf %s", data,categoria,&valor,descr) != EOF ) ){
        fprintf(indexA,"<tr id=tabela>\n");
        fprintf(indexA,"<td> %s </td> <td> %s </td> <td> %.2lf </td> <td> %s </td>",data,categoria,valor,descr);
      }
      fprintf(indexA,"</tr> \n");
      fclose(dez);
    }


    printf("\n \n");
    printf("Relatorio gerado com sucesso!! \n \n");
    fprintf(indexA,"</table> \n");
    fprintf(indexA,"</body> \n");
    fprintf(indexA,"</html> \n");
    fclose(indexA);

   

    return menu();
  
}