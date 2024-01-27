#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define MAX_ATENDI 999
#define CPF 15
typedef struct  {
    char nome[50],tiposetor[30],cpf[CPF];
    int opAt;
}Cadastro;//ficha cadastro
void limpabuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void soliAtendimento(Cadastro cad[],int *qtdcad){
    if(*qtdcad < MAX_ATENDI){
        int op;
        printf("\nDigite seu nome: ");
        fgets(cad[*qtdcad].nome, sizeof(cad[*qtdcad].nome), stdin);
        cad[*qtdcad].nome[strcspn(cad[*qtdcad].nome, "\n")] = '\0';
        fflush(stdin);
        printf("\nDigite seu CPF(Apenas números): ");
        fgets(cad[*qtdcad].cpf, sizeof(cad[*qtdcad].cpf), stdin);
        cad[*qtdcad].cpf[strcspn(cad[*qtdcad].cpf, "\n")] = '\0';
        fflush(stdin);
        do{//Menu de opções
            printf("\nEscolha o setor de atendimento desejado:\n1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa Fisica\n4 - Gerente Pessoa Jurídica\n");
            printf("Escolha sua opção:  ");
            scanf("%d", &op);
            cad[*qtdcad].opAt = op;
            limpabuffer();
            switch(op){
                case 1: strcpy(cad[*qtdcad].tiposetor, "1 - Abertura de Conta");
                    break;
                case 2: strcpy(cad[*qtdcad].tiposetor, "2 - Caixa");
                    break;
                case 3: strcpy(cad[*qtdcad].tiposetor, "3 - Gerente Pessoa Física");
                    break;
                case 4: strcpy(cad[*qtdcad].tiposetor, "4 - Gerente Pessoa Jurídica");
                    break;
                default:
                    printf("\nOpção Inválida\n");
                    system("pause");
                    system("cls");
                    break;
            }
        }while (op < 1 || op > 4);
        (*qtdcad)++;
    }else {
        printf("Limite máximo de atendimentos alcançado!\n");
    }
}
void atendiregis(Cadastro cad[], int *qtdcad){
    int i;
    char cpfformatado[CPF];
    if(*qtdcad > 0){
        printf("\n\nEsses são todos os atendimentos registrados!\n");
        for(i=0; i < *qtdcad; i++){
            snprintf(cpfformatado, 15, "%3.3s.%3.3s.%3.3s-%2.2s", cad[i].cpf, cad[i].cpf + 3, cad[i].cpf + 6, cad[i].cpf + 9);
            printf("\nNome: %s\n", cad[i].nome);
            printf("CPF: %s\n", cpfformatado);
            printf("Tipo Atendimento: %s\n", cad[i].tiposetor);
            printf("==============================================\n");
        }
    }else
        printf("\nNenhum atendimento registrado.\n");
}
void atendiporsetor(Cadastro cad[], int  *qtdcad){
    setlocale(LC_ALL,"Portuguese");
    char cpfformatado[CPF];
    int i,op;
    do{
        system("cls");
        printf("Qual setor deseja listar os atendimentos?\n1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa Fisica\n4 - Gerente Pessoa Jurídica\n5 - Sair\n");
        printf("Escolha sua opção:  ");
        scanf("%d", &op);
        limpabuffer();
        if(op >= 1 && op <= 4 ){
            int acha = 0;
            for(i=0; i < *qtdcad; i++){
                if( op==cad[i].opAt){
                    snprintf(cpfformatado, 15, "%3.3s.%3.3s.%3.3s-%2.2s", cad[i].cpf, cad[i].cpf + 3, cad[i].cpf + 6, cad[i].cpf + 9);
                    printf("\nNome: %s\n", cad[i].nome);
                    printf("CPF: %s\n", cpfformatado);
                    printf("Tipo Atendimento: %s\n", cad[i].tiposetor);
                    printf("==============================================\n");
                    acha = 1;
                }
            }if(acha == 1)
                system("pause");
            if(acha == 0){
                printf("\nNão foi encontrado cadastro nesse setor, escolha outra opção.\n\n");
                system("pause");
            }
        }else if(op<1 || op>5){
            printf("\nOpção inválida\n\n");
            system("pause");
        }
    }while(op != 5 );
    fflush(stdin);
}
int main(){
    int opcao,qtdAtendimento = 0;
    Cadastro cad[MAX_ATENDI];
    setlocale(LC_ALL,"Portuguese");
    do {
        system("cls");
        printf("Bem-vindo ao sistema de atendimento:\n1 - Solicitar Atendimento\n2 - Listar Atendimentos Registrados\n3 - Listar Atendimento por Setor\n4 - Sair\n");
        printf("\nEscolha um Atendimento:  ");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:fflush(stdin);
                soliAtendimento( cad, &qtdAtendimento);
                break;
            case 2:fflush(stdin);
                atendiregis(cad, &qtdAtendimento);
                break;
            case 3:fflush(stdin);
                atendiporsetor(cad, &qtdAtendimento);
                break;
            case 4:fflush(stdin);
                printf("Fim do programa, pressione Enter para Encerrar.\n");
                break;
            default:fflush(stdin);
                printf("\nOpção Inválida\n\n");
                break;
        }
        system("pause");
    } while (opcao != 4);
    return 0;
}