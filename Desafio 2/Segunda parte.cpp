#include <stdio.h>
#include <cstdlib> // Para incluir a função atoi

int main() {
    FILE *arquivo;
    arquivo = fopen("producao.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int maquina1 = 0, maquina2 = 0, maquina3 = 0, maquina4 = 0;
    int maquina, dia_anterior = 0, explosivos_dia = 0;
    char dia[11]; // Definindo dia como uma string

    FILE *relatorio;
    relatorio = fopen("explosivos.md", "w");

    fprintf(relatorio, "# Relatório de Produção de Explosivos\n\n");
    fprintf(relatorio, "| Data       | Máquina 1 | Máquina 2 | Máquina 3 | Máquina 4 | Total     |\n");
    fprintf(relatorio, "|------------|-----------|-----------|-----------|-----------|-----------|\n");

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%[^;];%*[^;];%d", dia, &maquina);

        if (atoi(dia) != dia_anterior && explosivos_dia > 0) {
            fprintf(relatorio, "| %d | %d | %d | %d | %d | %d |\n", dia_anterior, maquina1, maquina2, maquina3, maquina4, explosivos_dia);
            explosivos_dia = 0;
        }

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
                printf("Máquina inválida.\n");
                break;
        }

        dia_anterior = atoi(dia);
        explosivos_dia++;
    }

    fprintf(relatorio, "| %d | %d | %d | %d | %d | %d |\n", dia_anterior, maquina1, maquina2, maquina3, maquina4, explosivos_dia);

    fclose(arquivo);
    fclose(relatorio);

    printf("Relatório gerado com sucesso.\n");

    return 0;
}

