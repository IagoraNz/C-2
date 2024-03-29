#include "menus.h"
#include "../checks/checkin.c"
#include "../checks/checkout.c"
#include "../checks/valores_recebidos.c"
#include "../checks/valortotal.c"

int stringparaintch(const char str[]) {
    int result = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } 
        else{
            return -1;
        }
    }
    return result;
}

void menu_checks(){
    char opc[1];
    int input;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Check-in\n");
        printf("2 - Check-out\n");
        printf("3 - Valores Recebidos\n");
        printf("4 - Valores Totais\n");
        printf("0 - Voltar\n");
        do{
            printf("Digite a opcao desejada: ");
            scanf("%s", opc);

            input = stringparaintch(opc);

            if(input == -1 || input > 4 || input < 0){
                printf("Opcao invalida!\n");
                system("PAUSE");
                return menu_checks();
            }
        }while(input < 0 || input > 4);

        switch (input)
        {
        case 1:
            checkin();
            system("PAUSE");
            system("cls");
            break;
        case 2:
            checkout();
            system("PAUSE");
            system("cls");
            break;
        case 3:
            Valores_Recebidos();
            system("PAUSE");
            system("cls");
            break;
        case 4:
            Valor_total();
            system("PAUSE");
            system("cls");
            break;
        case 0:
            return;
        default:
            break;
        }
    }while(opc != 0);
}