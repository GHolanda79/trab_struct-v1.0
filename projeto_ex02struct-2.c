#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
	int dia;
	int mes;
	int ano;
} DATA;

typedef struct{
	char ddd[4];
	char numero[11];	
} TELEFONE;

typedef struct{
	char rua[30];
	int numero;
	char complemento[30];
	char bairro[30];
	char cep[10];
	char cidade[30];
	char estado[30];
	char pais[40];
} ENDERECO;

typedef struct{
	char nome[40];
	char email[50];
	TELEFONE telefone;
	DATA data_nasc;
	ENDERECO endereco;
} PESSOA;

void adicionarPessoa(PESSOA *x){
	fflush(stdin);
	printf("Nome: ");
	gets(x->nome);
	fflush(stdin);
	printf("E-mail: ");
	gets(x->email);
	fflush(stdin);
	printf("\nTelefone: \n");
	printf("DDD: ");
	gets(x->telefone.ddd);
	fflush(stdin);
	printf("Número: ");
	gets(x->telefone.numero);
	fflush(stdin);
	printf("Data de nascimento(dd mm aaaa): ");
	scanf("%d %d %d", &x->data_nasc.dia, &x->data_nasc.mes, &x->data_nasc.ano);
	fflush(stdin);
	printf("\nEndereço:\n");
	printf("Rua: ");
	gets(x->endereco.rua);
	fflush(stdin);
	printf("Número: ");
	scanf("%d", &x->endereco.numero);
	fflush(stdin);
	printf("Complemento: ");
	gets(x->endereco.complemento);
	fflush(stdin);
	printf("Bairro: ");
	gets(x->endereco.bairro);
	fflush(stdin);
	printf("CEP: ");
	gets(x->endereco.cep);
	fflush(stdin);
	printf("Cidade: ");
	gets(x->endereco.cidade);
	fflush(stdin);
	printf("Estado: ");
	gets(x->endereco.estado);
	fflush(stdin);
	printf("País: ");
	gets(x->endereco.pais);
	fflush(stdin);
	printf("\n\n");
}

void mostrarPessoa(PESSOA x){
	printf("\n----------------------------------------\n");
    printf("Nome: %s\n", x.nome);
    printf("E-mail: %s\n", x.email);
    printf("Data de nascimento: %d/%d/%d\n", x.data_nasc.dia, x.data_nasc.mes, x.data_nasc.ano);
    printf("Número de telefone: (%s) %s\n", x.telefone.ddd, x.telefone.numero);
    printf("\nEndereço: \n");
    printf("Rua: %s\n", x.endereco.rua);
    printf("Número: %d\n", x.endereco.numero);
    printf("Complemento: %s\n", x.endereco.complemento);
    printf("Bairro: %s\n", x.endereco.bairro);
    printf("Cidade: %s\n", x.endereco.cidade);
    printf("Estado: %s\n", x.endereco.estado);
    printf("País: %s\n", x.endereco.pais);
    printf("-----------------------------------------\n\n");
}

void mostrarContato(PESSOA x){
	printf("\n---------------------------\n");
	printf("Nome: %s\n", x.nome);
	printf("Telefone: (%s) %s\n", x.telefone.ddd, x.telefone.numero);
	printf("E-mail: %s\n", x.email);
	printf("-----------------------------\n");
}

char *buscaNome(PESSOA x){
	char *primeiro_nome = strtok(x.nome, " ");
	/*printf("Primeiro nome: %s\n", primeiro_nome);*/
	return primeiro_nome;
}


void main(){
	setlocale(LC_ALL,"portuguese");
	PESSOA agenda[100], aux[10];
	char busca_nome[30], exclui_nome[30];
	int i = 0, j, k, q, num, opcao, m = 0, n, h, d, t=1, s=2;
	
	do {
		printf("\n-----------------MENU--------------------\n");
		printf("1 - Adicionar contato:\n");
		printf("2 - Mostrar todos os contatos:\n");
		printf("3 - Imprime nome, telefone e e-mail de todos os contatos:\n");
		printf("4 - Buscar contato por nome: \n");
		printf("5 - Excluir contato: \n");
		printf("6 - Busca por mês de aniversário: \n");
		printf("7 - Busca por mês e dia de aniversário: \n");
		printf("Crtl + C para fechar o programa\n");
		printf("--------------------------------------------\n");
		
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		printf("\n\n\n");
		
		switch(opcao){
			case 1: 
				adicionarPessoa(&agenda[i]); i++; printf("--------Contato adicionado!!-------\n\n");
				for(k=0; k<i;k++){
					for(q=0;q<i;q++){
						if(strcmp(agenda[k].nome, agenda[q].nome) < 0){
							aux[0] = agenda[k];
							agenda[k] = agenda[q];
							agenda[q] = aux[0];
						}
					}; 
				}; break;
				
			case 2: 
				printf("----------------CONTATOS----------------");
				for(j=0;j<i;j++){ mostrarPessoa(agenda[j]); printf("\n\n");}
				break;
				
			case 3: 
				printf("----------------CONTATOS----------------");
				for(j=0;j<i;j++){ mostrarContato(agenda[j]); }; printf("\n\n"); break;
				
			case 4:
				printf("Nome: ");
				scanf("%s", busca_nome);
				for(j=0;j<i;j++){
					if(strcmp(busca_nome, buscaNome(agenda[j])) == 0){
						mostrarPessoa(agenda[j]);
					}
				};
				break;
			
			case 5: 
				printf("Informe um nome para excluir contato: ");
				fflush(stdin);
				gets(busca_nome);
				fflush(stdin);
				
				for(j=0;j<i;j++){
					if(strcmp(busca_nome, agenda[j].nome) == 0){
						printf("Contato removido\n");
						agenda[j] = agenda[j+1];
						for(t=1;t<i; s++, t++){
							agenda[j+t] = agenda[j+s];
						}
						i--;
						break;	
					} else {
						printf("Nao há nenhum contato com este nome!\n");
					}
				}; break;	
				
			case 6:
				printf("Informe o mes de aniversário:");
				scanf("%d", &m);
				for(j=0;j<i;j++){
					if(m == agenda[j].data_nasc.mes){
						mostrarPessoa(agenda[j]);
					} else {
						printf("Náo há nenhum contato com aniversário neste mês.\n");
					};
				};
				break;
				
			case 7:
				printf("Informe o dia e mês de aniversário: ");
				scanf("%d %d", &d, &m);
				
				for(j=0;j<i;j++){
					if(d == agenda[j].data_nasc.dia && m == agenda[j].data_nasc.mes){
						mostrarPessoa(agenda[j]);
					} else {
						printf("Náo há nenhum contato com essa data de aniversário.\n");
					}
				};
				break;
				
			default: printf("Valor invalido\n"); break;
		};
	} while(1);
}