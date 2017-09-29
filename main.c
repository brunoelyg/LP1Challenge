#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct contas{
    unsigned int numero_conta;
    float saldo;
    int agencia;
    char nome[100];
    int tipo_cliente; //1 - fisica 0 - juridica

    union{
        char cpf[12];
        char cnpj[15];
    }cadastro;

}conta;

typedef struct contaExtra
{
   conta conta;
   struct data data_criacao;

}nova_conta;

void desafio(conta cliente[], nova_conta extra[], int nc)
{
    int i, found=0;

    for(i=0; i<nc; i++)
    {
        extra[i].conta.numero_conta = cliente[i].numero_conta;
        extra[i].conta.saldo = cliente[i].saldo;
        extra[i].conta.agencia = cliente[i].agencia;
        strcpy(extra[i].conta.nome, cliente[i].nome);
        extra[i].conta.tipo_cliente = cliente[i].tipo_cliente;

        if(cliente[i].tipo_cliente == 1)
            strcpy(extra[i].conta.cadastro.cpf, cliente[i].cadastro.cpf);
        else
            strcpy(extra[i].conta.cadastro.cnpj, cliente[i].cadastro.cnpj);
    }

    for(i=0; i<nc; i++)
    {
        if(extra[i].data_criacao.mes >= 5 && extra[i].data_criacao.ano >= 2016)
        {
            if(extra[i].conta.saldo > 5000 && extra[i].conta.tipo_cliente == 2)
            {
                if(extra[i].conta.cadastro.cnpj[strlen(extra[i].conta.cadastro.cnpj)-1] == '1')
                {
                    printf("Conta: %d\n", extra[i].conta.numero_conta);
                    printf("Agencia: %d\n", extra[i].conta.agencia);
                    printf("Saldo: R$ %.2f\n", extra[i].conta.saldo);
                    printf("Nome: %s\n", extra[i].conta.nome);
                    printf("CNPJ: %s\n", extra[i].conta.cadastro.cnpj);
                    printf("Data de criacao: %d/%d/%d\n\n\n", extra[i].data_criacao.dia, extra[i].data_criacao.mes, extra[i].data_criacao.ano);
                    found++;
                }
            }
        }
    }

    if(!found)
        printf("Nao existe conta criada depois dessa data, que tenha esse saldo e CNPJ terminado em 1.");
}

void saque(conta cliente[], int i)
{
    float valor_saque;

    printf("Digite o valor que deseja sacar: ");
    scanf("%f", &valor_saque);

    if (cliente[i].saldo < valor_saque)
        printf("\n\nVoce nao tem saldo suficiente.");

    else
    {
        cliente[i].saldo = cliente[i].saldo - valor_saque;
        printf("\n\nConta: %d\n", cliente[i].numero_conta);
        printf("Agencia:%d\n", cliente[i].agencia);
        printf("Saldo atualizado: R$ %.2f\n", cliente[i].saldo);
        printf("Nome: %s\n", cliente[i].nome);

        if (cliente[i].tipo_cliente == 1)
            printf("CPF: %s\n", cliente[i].cadastro.cpf);
        else printf("CNPJ: %s\n", cliente[i].cadastro.cnpj);
    }
}

void deposito(conta cliente[], int i)
{
    float valor_deposito;

    printf("Digite o valor que deseja depositar: ");
    scanf("%f", &valor_deposito);

    cliente[i].saldo = cliente[i].saldo + valor_deposito;

    printf("\n\nConta: %d\n", cliente[i].numero_conta);
    printf("Agencia:%d\n", cliente[i].agencia);
    printf("Saldo atualizado: R$ %.2f\n", cliente[i].saldo);
    printf("Nome: %s\n", cliente[i].nome);

    if (cliente[i].tipo_cliente == 1)
        printf("CPF: %s\n", cliente[i].cadastro.cpf);
    else printf("CNPJ: %s\n", cliente[i].cadastro.cnpj);

}

void buscarAgencia(conta cliente[], int numero_contas, int busca_agencia)
{
    int i, foundag=0, foundcl=0;

    for(i=0; i<numero_contas; i++)
    {
        if(cliente[i].agencia == busca_agencia)
        {
            foundag++;

            if(cliente[i].nome[0] == 'A' || cliente[i].nome[0] == 'B' ||  cliente[i].nome[0] == 'C')
            {
                printf("Conta: %d\n", cliente[i].numero_conta);
                printf("Agencia: %d\n", cliente[i].agencia);
                printf("Saldo: R$ %.2f\n", cliente[i].saldo);
                printf("Nome: %s\n", cliente[i].nome);

                if (cliente[i].tipo_cliente == 1)
                    printf("CPF: %s\n", cliente[i].cadastro.cpf);
                else printf("CNPJ: %s\n", cliente[i].cadastro.cnpj);

                foundcl++;
            }
        }
    }

    if(!foundag)
    {
        printf("\n\nNumero de agencia invalido.");
        return;
    }

    if(!foundcl)
        printf("\n\nNao existe na agencia nenhum cliente cuja inicial do nome seja A, B ou C.");
}

int buscarConta(conta cliente[], int numero_contas, int busca_conta)
{
    int i;

    for(i=0; i<numero_contas; i++)
    {
        if(busca_conta == cliente[i].numero_conta)
        {
            return i;       //main recebe o indice do vetor e mostra na tela
        }
    }

    return -1;
}

void listarContas(conta cliente[], int numero_contas)
{
    int i;
    for (i=0; i < numero_contas; i++)
    {
        printf("Conta no. %d\n", cliente[i].numero_conta);
        printf("Agencia: %d\n", cliente[i].agencia);
        printf("Saldo: R$ %.2f\n", cliente[i].saldo);
        printf("Nome: %s\n", cliente[i].nome);

        if (cliente[i].tipo_cliente == 1)
            printf("CPF: %s\n\n\n", cliente[i].cadastro.cpf);
        else
            printf("CNPJ: %s\n\n\n", cliente[i].cadastro.cnpj);
    }
}

void inserirConta(conta cliente[], nova_conta extra[], int numero_contas)
{
    int i;

    for(i=0; i<numero_contas; i++)
    {
        cliente[i].numero_conta = (i+1)*10;
        printf("Conta no. %d", cliente[i].numero_conta);
        printf("\nDigite o saldo da conta: "); scanf("%f", &cliente[i].saldo);
        printf("\nDigite o numero da agencia: "); scanf("%d", &cliente[i].agencia);
        fflush(stdin);
        printf("\nDigite o nome do cliente: "); gets(cliente[i].nome);
        strupr(cliente[i].nome);
        printf("\nTipo do cliente:\n1. Pessoa fisica\n2. Pessoa juridica\nDigite a opcao: ");
        do
        {
            scanf("%d", &cliente[i].tipo_cliente);
            fflush(stdin);
            if(cliente[i].tipo_cliente == 1)
            {
                printf("\nDigite o CPF do cliente: "); gets(cliente[i].cadastro.cpf);
            }

            else if(cliente[i].tipo_cliente == 2)
            {
                printf("\nDigite o CNPJ do cliente: "); gets(cliente[i].cadastro.cnpj);
            }

            else printf("\nOpcao invalida. Digite novamente: ");

        }while(cliente[i].tipo_cliente != 1 && cliente[i].tipo_cliente != 2);

        printf("\nDigite a data de criacao da conta (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &extra[i].data_criacao.dia, &extra[i].data_criacao.mes, &extra[i].data_criacao.ano);

        system("cls");
    }
}

char menu()
{
    char op;

    printf("a. Inserir contas");
    printf("\nb. Listar contas");
    printf("\nc. Buscar cliente");
    printf("\nd. Buscar agencia");
    printf("\ne. Efetuar deposito");
    printf("\nf. Efetuar saque");
    printf("\ng. Buscar contas especificas (desafio)");
    printf("\nh. Encerrar programa");
    printf("\n\nDigite a opcao: ");

    op = getch();
    fflush(stdin);
    system("cls");

    return op;
}

int main()
{
    int nc;
    printf("Digite o numero de contas: "); scanf("%d", &nc);

    conta cliente[nc];
    nova_conta extra[nc];
    char opcao;
    int contasOk=0, busca_num, busca_res;

    do
    {
        system("cls");
        opcao = menu();

        switch(opcao)
        {
        case 'a':
            if(!contasOk)
            {
                inserirConta(cliente, extra, nc);
                contasOk++;
                printf("Contas inseridas com sucesso.");
            }

            else printf("Contas ja foram inseridas.");
        break;
        case 'b':
            if(contasOk)
                listarContas(cliente, nc);

            else printf("Contas ainda nao foram inseridas.");
        break;
        case 'c':
            if(contasOk)
            {
                printf("Digite o numero da conta: "); scanf("%d", &busca_num);
                busca_res = buscarConta(cliente, nc, busca_num);

                if(busca_res >= 0)
                {
                    printf("\n\nConta no. %d\n", cliente[busca_res].numero_conta);
                    printf("Agencia: %d\n", cliente[busca_res].agencia);
                    printf("Saldo: R$ %.2f\n", cliente[busca_res].saldo);
                    printf("Nome: %s\n", cliente[busca_res].nome);

                    if (cliente[busca_res].tipo_cliente == 1)
                        printf("CPF: %s\n", cliente[busca_res].cadastro.cpf);
                    else
                        printf("CNPJ: %s\n", cliente[busca_res].cadastro.cnpj);
                }

                else printf("\n\nNumero de conta inexistente.");
            }

            else printf("Contas ainda nao foram inseridas.");
        break;
        case 'd':
            if(contasOk)
            {
                printf("Digite o numero da agencia: "); scanf("%d", &busca_num);
                buscarAgencia(cliente, nc, busca_num);
            }

            else printf("Contas ainda nao foram inseridas.");
        break;
        case 'e':
            if(contasOk)
            {
                printf("Digite o numero da conta: "); scanf("%d", &busca_num);
                busca_res = buscarConta(cliente, nc, busca_num);

                if(busca_res >= 0)
                {
                    deposito(cliente, busca_res);
                }

                else printf("Numero de conta inexistente.");
            }

            else
                printf("Contas ainda nao foram inseridas.");
        break;
        case 'f':
            if(contasOk)
            {
                printf("Digite o numero da conta: "); scanf("%d", &busca_num);
                busca_res = buscarConta(cliente, nc, busca_num);

                if(busca_res >= 0)
                {
                    saque(cliente, busca_res);
                }

                else printf("Numero de conta inexistente.");
            }

            else
                printf("Contas ainda nao foram inseridas.");
        break;
        case 'g':
            if(contasOk)
            {
                desafio(cliente, extra, nc);
            }

            else
                printf("Contas ainda nao foram inseridas.");
        break;
        case 'h':
            return 0;
        default:
            printf("Opcao invalida.");
        break;
        }

        printf("\n\nPressione qualquer tecla para retornar ao menu...");
        getch();

    }while(opcao!='h');

    return 0;
}
