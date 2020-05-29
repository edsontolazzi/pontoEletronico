#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOME_TAM 30
#define SIZE 20

struct cadastro {
    int cod;
    char nome[30];
    char data[20];
    char cpf[20];
};
struct cadastro func[50];

struct ponto {
    char data[30][30];
    char hora[30][30];
    int pt;
};
struct ponto ponto[50];

struct pendencia {
    char data_pendencia[30][30];
    char hora_pendencia[30][30];
    char nome_pendencia[30][30];
    int pd;  
};
struct pendencia pend;

void employee_punch (int cod) {

    int o = 0;

    if(cod == 0) {
        printf("Este código não pode existir.\n");
        return;
    }
    if (func[cod].cod != cod) {
        printf("Este código não está cadastrado.\n");
        return;
    }
    
    char salvar;
    char sim = 's';
    char sim2 = 'S';

    struct pontofake {
    char data_fake[30];
    char hora_fake[10];
    };
    struct pontofake regist;

    while (o == 0) {
        printf("\nData: ");
        scanf("%s", regist.data_fake);
        getchar();
        if (strlen(regist.data_fake)<8) {
            printf("Você digitou uma data inválida.\n");
        } else {
            o++;
        }
    }
    o = 0;
    while (o == 0) {
        printf("Hora: ");
        scanf("%s", regist.hora_fake);
        getchar();
        if (strlen(regist.hora_fake)<3) {
            printf("Você digitou uma data inválida.\n");
        } else {
            o++;
        }
    }

    //FORMATACAO DATA
    if (regist.data_fake[2] == '/' || regist.data_fake[2] == '-' || regist.data_fake[2] == '.') {
        regist.data_fake[2] = regist.data_fake[3];
        regist.data_fake[3] = regist.data_fake[4];
    }
    if (regist.data_fake[5] == '/' || regist.data_fake[5] == '-' || regist.data_fake[5] == '.') {
        regist.data_fake[4] = regist.data_fake[6];
        regist.data_fake[5] = regist.data_fake[7];
        regist.data_fake[6] = regist.data_fake[8];
        regist.data_fake[7] = regist.data_fake[9];
        regist.data_fake[8] = '\0';
        regist.data_fake[9] = '\0';
    }
    regist.data_fake[13] = '\0';
    regist.data_fake[12] = '\0';
    regist.data_fake[11] = '\0';
    regist.data_fake[10] = '\0';
    regist.data_fake[9] = regist.data_fake[7];
    regist.data_fake[8] = regist.data_fake[6];
    regist.data_fake[7] = regist.data_fake[5];
    regist.data_fake[6] = regist.data_fake[4];
    regist.data_fake[5] = '/';
    regist.data_fake[4] = regist.data_fake[3];
    regist.data_fake[3] = regist.data_fake[2];
    regist.data_fake[2] = '/';
    regist.data_fake[1] = regist.data_fake[1];
    regist.data_fake[0] = regist.data_fake[0];

    //FORMATACAO HORA
    if (regist.hora_fake[3] == regist.hora_fake[8]) {
        regist.hora_fake[4] = regist.hora_fake[2];
        regist.hora_fake[3] = regist.hora_fake[1];
        regist.hora_fake[2] = ':';
        regist.hora_fake[1] = regist.hora_fake[0];
        regist.hora_fake[0] = '0'; 
        } else if (regist.hora_fake[4] == regist.hora_fake[8] && regist.hora_fake[0] == '0') {
            regist.hora_fake[4] = regist.hora_fake[3];
            regist.hora_fake[3] = regist.hora_fake[2];
            regist.hora_fake[2] = ':';
            regist.hora_fake[1] = regist.hora_fake[1];
            regist.hora_fake[0] = '0';
        } else if (regist.hora_fake[4] == regist.hora_fake[8]) {
            regist.hora_fake[4] = regist.hora_fake[3];
            regist.hora_fake[3] = regist.hora_fake[2];
            regist.hora_fake[2] = ':';
            regist.hora_fake[1] = regist.hora_fake[1];
            regist.hora_fake[0] = regist.hora_fake[0];
        }
        if (regist.hora_fake[2] == ':' && regist.hora_fake[1] == ':' ) {
        regist.hora_fake[4] = regist.hora_fake[4];
        regist.hora_fake[3] = regist.hora_fake[3];
        regist.hora_fake[2] = ':';
        regist.hora_fake[1] = regist.hora_fake[0];
        regist.hora_fake[0] = '0';
        }
        regist.hora_fake[8] = '\0';
        regist.hora_fake[7] = '\0';
        regist.hora_fake[6] = '\0';
        regist.hora_fake[5] = '\0';
        if ((regist.hora_fake[1] == '.' && regist.hora_fake[2] == ':') || (regist.hora_fake[1] == '-' && regist.hora_fake[2] == ':') || (regist.hora_fake[1] == '/' && regist.hora_fake[2] == ':') ) {
            regist.hora_fake[1] = regist.hora_fake[0];
            regist.hora_fake[0] = '0';
        }
        if (regist.hora_fake[2] == '.' || regist.hora_fake[2] == '-' || regist.hora_fake[2] == '/') {
            regist.hora_fake[2] = ':';
        }
        
        
    printf("\nid do funcionário: %d\n", cod);
    printf("Data: %s\n", regist.data_fake);
    printf("Hora: %s\n", regist.hora_fake);

    printf("\nDeseja registrar as informações? [s/n]\n");
    scanf("%c", &salvar);
    getchar();
    if (salvar == sim || salvar == sim2) {
        
        for (int i = 0; i < strlen(regist.data_fake); i++) {
        ponto[cod].data[ponto[cod].pt][i] = regist.data_fake[i];
        }
        for (int i = 0; i < strlen(regist.hora_fake); i++) {
        ponto[cod].hora[ponto[cod].pt][i] = regist.hora_fake[i];
        }
        ponto[cod].pt++;
        
        if (strcmp(regist.hora_fake, "07:55") == 0 ||
                                strcmp(regist.hora_fake, "07:56") == 0 ||
                                strcmp(regist.hora_fake, "07:57") == 0 ||
                                strcmp(regist.hora_fake, "07:58") == 0 ||
                                strcmp(regist.hora_fake, "07:59") == 0 ||
                                strcmp(regist.hora_fake, "08:00") == 0 ||
                                strcmp(regist.hora_fake, "08:01") == 0 ||
                                strcmp(regist.hora_fake, "08:02") == 0 ||
                                strcmp(regist.hora_fake, "08:03") == 0 ||
                                strcmp(regist.hora_fake, "08:04") == 0 ||
                                strcmp(regist.hora_fake, "08:05") == 0 ||
                                strcmp(regist.hora_fake, "11:55") == 0 ||
                                strcmp(regist.hora_fake, "11:56") == 0 ||
                                strcmp(regist.hora_fake, "11:57") == 0 ||
                                strcmp(regist.hora_fake, "11:58") == 0 ||
                                strcmp(regist.hora_fake, "11:59") == 0 ||
                                strcmp(regist.hora_fake, "12:00") == 0 ||
                                strcmp(regist.hora_fake, "12:01") == 0 ||
                                strcmp(regist.hora_fake, "12:02") == 0 ||
                                strcmp(regist.hora_fake, "12:03") == 0 ||
                                strcmp(regist.hora_fake, "12:04") == 0 ||
                                strcmp(regist.hora_fake, "12:05") == 0 ||
                                strcmp(regist.hora_fake, "13:25") == 0 ||
                                strcmp(regist.hora_fake, "13:26") == 0 ||
                                strcmp(regist.hora_fake, "13:27") == 0 ||
                                strcmp(regist.hora_fake, "13:28") == 0 ||
                                strcmp(regist.hora_fake, "13:29") == 0 ||
                                strcmp(regist.hora_fake, "13:30") == 0 ||
                                strcmp(regist.hora_fake, "13:31") == 0 ||
                                strcmp(regist.hora_fake, "13:32") == 0 ||
                                strcmp(regist.hora_fake, "13:33") == 0 ||
                                strcmp(regist.hora_fake, "13:34") == 0 ||
                                strcmp(regist.hora_fake, "13:35") == 0 ||
                                strcmp(regist.hora_fake, "17:25") == 0 ||
                                strcmp(regist.hora_fake, "17:26") == 0 ||
                                strcmp(regist.hora_fake, "17:27") == 0 ||
                                strcmp(regist.hora_fake, "17:28") == 0 ||
                                strcmp(regist.hora_fake, "17:29") == 0 ||
                                strcmp(regist.hora_fake, "17:30") == 0 ||
                                strcmp(regist.hora_fake, "17:31") == 0 ||
                                strcmp(regist.hora_fake, "17:32") == 0 ||
                                strcmp(regist.hora_fake, "17:33") == 0 ||
                                strcmp(regist.hora_fake, "17:34") == 0 ||
                                strcmp(regist.hora_fake, "17:35") == 0)
                                {
                                
                                } else {

            for (int i = 0; i < strlen(regist.data_fake); i++) {
                pend.data_pendencia[pend.pd][i] = regist.data_fake[i];    
            }
            for (int i = 0; i < strlen(regist.hora_fake); i++) {
                pend.hora_pendencia[pend.pd][i] = regist.hora_fake[i];
            }
            for (int i = 0; i < strlen(func[cod].nome); i++) {
                pend.nome_pendencia[pend.pd][i] = func[cod].nome[i];
            }
            pend.pd++;
        }
    } else {
        printf("Você decidiu não salvar este registro.\n\n"); 
    }
}

void employees_report () {

    int cont = 1;

    printf("\nRelatório de pendencias de registro\n");
    printf("   # | Marcação          | Funcionário\n");

    for (int i = 0; i < pend.pd; i++) {
        printf("   %d | %s %s  | %s\n", cont,   pend.data_pendencia[i], 
                                                pend.hora_pendencia[i],
                                                pend.nome_pendencia[i]);
        cont++;
    }
}

void employee_report (int cod) {

    int cont = 1;

    printf("\nDigite o id do funcionário: ");
    scanf("%d", &cod);
    if (func[cod].cod == 0) {
        printf("Este código não está cadastrado.\n");
        return;
    }
    getchar();
    printf("Nome: %s\n", func[cod].nome);
    printf("Admissão: %s\n", func[cod].data);
    printf("==== REGISTROS ====\n");
    printf("   # | Entrada          | Saída\n");

    for (int i = 0; i < (ponto[cod].pt); i+=2) {

        if (ponto[cod].data[i] != NULL) {
            printf("   %d | %s %s |", cont, ponto[cod].data[i], ponto[cod].hora[i]);
        }
        if (ponto[cod].data[i+1] != NULL) {
            printf(" %s %s\n",  ponto[cod].data[i+1], ponto[cod].hora[i+1]);
        }                                                                   
        cont++;
    }
    printf("\n");
}

void employee_list (int cod_cad) {

    printf("\nLista de funcionarios:\n");
    printf("==\n");
    for (int i = 1; i <= cod_cad; i++) {
        printf("id = %d\n", func[i].cod);
        printf("Nome: %s\n", func[i].nome);
        printf("Admissão: %s\n", func[i].data);
        printf("==\n");
    }
}

void employee_register (int cod_cad) {


    
    for (int i = 0; i < 50; i++) {
        if (func[i].cod == cod_cad && cod_cad == 0) {
            printf("Você não pode cadastrar um funcionário com código zero.\n");
            return;
        } else if (func[i].cod == cod_cad) {
            printf("Este código já está cadastrado.\n");
            return;
        }
    }

    char salvar;
    char sim = 's';
    char sim2 = 'S';
    int j = 0;

    typedef struct {
    char nomefake[30];
    char datafake[20];
    char cpffake[20];                 
    } cadfake;
            
    cadfake funcfake;

    printf("\nCódigo: %d\n", cod_cad);
    printf("Nome: ");
    scanf("%[^\n]s", funcfake.nomefake);
    getchar();
    printf("Data de admissão: ");
    scanf("%[^\n]s", funcfake.datafake);
    getchar();
    if (strlen(funcfake.datafake)<8) {
        printf("Você digitou uma data inválida.\n");
        return;
    }
    printf("CPF: ");
    scanf("%[^\n]s", funcfake.cpffake);
    getchar();
    if (strlen(funcfake.cpffake)<11) {
        printf("Você digitou um CPF inválido.\n");
        return;
    }
        
    //FORMATACAO DATA
    if (funcfake.datafake[2] == '/' || funcfake.datafake[2] == '-' || funcfake.datafake[2] == '.') {
        funcfake.datafake[2] = funcfake.datafake[3];
        funcfake.datafake[3] = funcfake.datafake[4];
    }
    if (funcfake.datafake[5] == '/' || funcfake.datafake[5] == '-' || funcfake.datafake[5] == '.') {
        funcfake.datafake[4] = funcfake.datafake[6];
        funcfake.datafake[5] = funcfake.datafake[7];
        funcfake.datafake[6] = funcfake.datafake[8];
        funcfake.datafake[7] = funcfake.datafake[9];
        funcfake.datafake[8] = '\0';
        funcfake.datafake[9] = '\0';
    }
    funcfake.datafake[13] = '\0';
    funcfake.datafake[12] = '\0';
    funcfake.datafake[11] = '\0';
    funcfake.datafake[10] = '\0';
    funcfake.datafake[9] = funcfake.datafake[7];
    funcfake.datafake[8] = funcfake.datafake[6];
    funcfake.datafake[7] = funcfake.datafake[5];
    funcfake.datafake[6] = funcfake.datafake[4];
    funcfake.datafake[5] = '/';
    funcfake.datafake[4] = funcfake.datafake[3];
    funcfake.datafake[3] = funcfake.datafake[2];
    funcfake.datafake[2] = '/';
    funcfake.datafake[1] = funcfake.datafake[1];
    funcfake.datafake[0] = funcfake.datafake[0];

    //FORMATACAO CPF
    if (funcfake.cpffake[3] == '/' || funcfake.cpffake[3] == '-' || funcfake.cpffake[3] == '.') {
        funcfake.cpffake[3] = funcfake.cpffake[4];
        funcfake.cpffake[4] = funcfake.cpffake[5];
        funcfake.cpffake[5] = funcfake.cpffake[6];
    }
    if (funcfake.cpffake[7] == '/' || funcfake.cpffake[7] == '-' || funcfake.cpffake[7] == '.') {
        funcfake.cpffake[6] = funcfake.cpffake[8];
        funcfake.cpffake[7] = funcfake.cpffake[9];
        funcfake.cpffake[8] = funcfake.cpffake[10];
    }
    if (funcfake.cpffake[11] == '/' || funcfake.cpffake[11] == '-' || funcfake.cpffake[11] == '.') {
        funcfake.cpffake[9] = funcfake.cpffake[12];
        funcfake.cpffake[10] = funcfake.cpffake[13];
        funcfake.cpffake[11] = funcfake.cpffake[18];
        funcfake.cpffake[12] = funcfake.cpffake[18];
        funcfake.cpffake[13] = funcfake.cpffake[18];
    }
    funcfake.cpffake[19] = '\0';
    funcfake.cpffake[18] = '\0';
    funcfake.cpffake[17] = '\0';
    funcfake.cpffake[16] = '\0';
    funcfake.cpffake[15] = '\0';
    funcfake.cpffake[14] = '\0';
    funcfake.cpffake[13] = funcfake.cpffake[10];
    funcfake.cpffake[12] = funcfake.cpffake[9];
    funcfake.cpffake[11] = '-';
    funcfake.cpffake[10] = funcfake.cpffake[8];
    funcfake.cpffake[9] = funcfake.cpffake[7];
    funcfake.cpffake[8] = funcfake.cpffake[6];
    funcfake.cpffake[7] = '.';
    funcfake.cpffake[6] = funcfake.cpffake[5];
    funcfake.cpffake[5] = funcfake.cpffake[4];
    funcfake.cpffake[4] = funcfake.cpffake[3];
    funcfake.cpffake[3] = '.';
    
    printf("\nDeseja salvar este cadastro? [s/n]\n");
    scanf("%c", &salvar);
    getchar();
    if (salvar == sim || salvar == sim2) {

        func[cod_cad].cod = cod_cad;
        for (int i = 0; i < NOME_TAM; i++) {
            func[cod_cad].nome[i] = funcfake.nomefake[i];
        }
        for (int i = 0; i < SIZE; i++) {
            func[cod_cad].data[i] = funcfake.datafake[i];    
        }
        for (int i = 0; i < SIZE; i++) {
            func[cod_cad].cpf[i] = funcfake.cpffake[i];    
        }

        printf("\nNome: %s\n", func[cod_cad].nome);
        printf("CPF: %s\n", func[cod_cad].cpf);
        printf("Data de admissao: %s\n", func[cod_cad].data);
        printf("Funcionário cadastrado com sucesso. ");
        printf("ID = [%d]\n\n", func[cod_cad].cod);
    } else {
        printf("Você decidiu não salvar este cadastro.\n\n"); 
    }
}

int opcao (int menu) {

    printf("Menu do programa:\n");
    printf(" [1] Cadastrar um novo funcionário\n");
    printf(" [2] Listar funcionários cadastrados\n");
    printf(" [3] Exibir relatório de registro de ponto de um funcionário\n");
    printf(" [4] Exibir relatório de pendencias de registro\n");
    printf(" [5] Gravar registro do ponto\n");
    printf(" [0] Sair do programa\n");
    printf("Digite uma das opções: ");
    scanf("%d", &menu);
    getchar();

    return menu;
}

int main (void) {

    char sim = 's';
    char sim2 = 'S';
    int menu = 1;
    char salvar;
    int cod;
    int cod_cad;

    while (menu != 0) {
        menu = opcao (menu);
        if (menu == 0) {
            printf("Você saiu do programa.\n");

        } else if (menu == 1) {

            int i = 0;

            while (i < 50) {
            printf("Digite o código do funcionario: ");
            scanf("%d", &cod_cad);
            getchar();
            employee_register(cod_cad);

            printf("Deseja cadastrar um novo funcionário? [s/n]\n");
            scanf("%c", &salvar);
            getchar();
            if (salvar == sim || salvar == sim2) {
                } else {
                    i = i+50;
                    printf("\n");
                }
            }

        } else if (menu == 2) {

            employee_list(cod_cad);

        } else if (menu == 3) {
            
            employee_report(cod);

        } else if (menu == 4) {

            employees_report();

        }else if (menu == 5) {

            printf("Gravar registro do ponto\n");
            printf("Digite o id do funcionário: ");
            scanf("%d", &cod);
            getchar();
    
            employee_punch(cod);

        }else {
            printf("Você escolheu uma opção inválida. Tente novamente.");
        }
    }  
}