#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    
   if(IsDebuggerPresent()) {
       printf("Debugger detectado!");
      exit(1);
   }

    char buffer[128];
    FILE *fp;

    // Executa o comando WMIC que retorna o fabricante da máquina
    fp = popen("wmic computersystem get manufacturer", "r");
    if (fp == NULL) {
        perror("Erro ao executar comando WMIC");
        return 1;
    }

    // Lê a saída do comando
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Verifica se o fabricante é uma VM comum
        if (strstr(buffer, "VMware") != NULL || strstr(buffer, "VirtualBox") != NULL || strstr(buffer, "QEMU") != NULL) {
            printf("O sistema esta rodando em uma maquina virtual.\n");
            exit(1);
        } else {
            printf("Fabricante do sistema: %s", buffer);
        }
    }

    fclose(fp);
    getchar();
    return 0;
}
