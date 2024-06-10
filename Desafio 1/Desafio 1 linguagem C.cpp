#include <stdio.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("producao.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int maquina1 = 0, maquina2 = 0, maquina3 = 0, maquina4 = 0;
    int maquina;

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%*[^;];%*[^;];%d", &maquina);

        switch (maquina) {
            case 1:
                maquina1++;
                break;
            case 2:
                maquina2++;
                break;
            case 3:
                maquina3++;
                break;
            case 4:
                maquina4++;
                break;
            default:
                printf("M�quina inv�lida.\n");
                break;
        }
    }

    fclose(arquivo);

    printf("Explosivos produzidos por m�quina:\n");
    printf("M�quina 1: %d\n", maquina1);
    printf("M�quina 2: %d\n", maquina2);
    printf("M�quina 3: %d\n", maquina3);
    printf("M�quina 4: %d\n", maquina4);

    return 0;
}

