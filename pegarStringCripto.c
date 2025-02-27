#include <stdlib.h>
#include <stdio.h>
#include <cripto.h>

int main() {
    printf(c_c_e("wmic computersystem get manufacturer\n", 1));
    // printf(x_e_d("Erro ao executar comando WMIC\n",4));
    // printf(x_e_d("VMware\n",4));
    // printf(x_e_d("VirtualBox\n",4));
    // printf(x_e_d("QEMU\n",4));
    // printf(x_e_d("O sistema esta rodando em uma maquina virtual\n",4));
    // printf(x_e_d("Fabricante do sistema:\n", 4));
    // printf(x_e_d("etset\n"));
    return 0;
}