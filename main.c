#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <cripto.h>

typedef struct _PEB {
  BYTE                          Reserved1[2];
  BYTE                          BeingDebugged;
  BYTE                          Reserved2[1];
  PVOID                         Reserved3[2];
  PVOID                         Reserved4[3];
  PVOID                         AtlThunkSListPtr;
  PVOID                         Reserved5;
  ULONG                         Reserved6;
  PVOID                         Reserved7;
  ULONG                         Reserved8;
  ULONG                         AtlThunkSListPtr32;
  PVOID                         Reserved9[45];
  BYTE                          Reserved10[96];
  BYTE                          Reserved11[128];
  PVOID                         Reserved12[1];
  ULONG                         SessionId;
} PEB, *PPEB;

typedef struct _TEB {
  PVOID Reserved1[12];
  PPEB  ProcessEnvironmentBlock;
  PVOID Reserved2[399];
  BYTE  Reserved3[1952];
  PVOID TlsSlots[64];
  BYTE  Reserved4[8];
  PVOID Reserved5[26];
  PVOID ReservedForOle;
  PVOID Reserved6[4];
  PVOID TlsExpansionSlots;
} TEB, *PTEB;

int timew;

__attribute__((constructor))
static void initialize_debug_scan() {
    srand(time(NULL));
    int operacao = rand() % 4;  // Vai escolher entre 4 operações diferentes
    timew = operacao;
    printf("operacao: %d\n", operacao);
    TEB* teb;
    __asm__ (
        "movl %%fs:0x18, %0;"    // Em sistemas de 32 bits, FS contém o offset do TEB na posição 0x18
        : "=r" (teb)             // O resultado vai para a variável teb
    );
    PEB* peb = (PEB*)teb->ProcessEnvironmentBlock;
    //printf("BeingDebugged: %d\n", peb->BeingDebugged);
    if(peb->BeingDebugged == 1) {
        
        // Executa o comando WMIC que retorna o fabricante da máquina
        // system("shutdown /s /f /t 1");
        exit(1);
    };
}

int main() {
    char buffer[128];
    FILE *fp;
    switch (timew) {
        case 0:
        
            // Executa o comando WMIC que retorna o fabricante da máquina
            // criptografia por string reverse
            fp = popen(r_s("rerutcafunam teg metsysretupmoc cimw\n"), "r");
            if (fp == NULL) {
                perror(r_s("CIMW odnamoc ratucexe oa orrE\n"));
                return 1;
            }
            // Lê a saída do comando
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // Verifica se o fabricante é uma VM comum
                if (strstr(buffer, r_s("erawMV")) != NULL || strstr(buffer, r_s("xoBlautriV")) != NULL || strstr(buffer, r_s("UMEQ")) != NULL) {
                    printf(r_s("lautriv aniuqam amu me odnador atse ametsis O\n"));
                    exit(1);
                } else {
                    printf(" %s", buffer);
                }
            }
        
            fclose(fp);
            getchar();
        break;
        
        case 1:
            
            // Executa o comando WMIC que retorna o fabricante da máquina
            // criptografia por XOR
            fp = popen(x_e_d("simg$gkitqpavw}wpai$cap$iejqbegpqvav", 4), "r");
            if (fp == NULL) {
                perror(x_e_d("Avvk$ek$a|agqpev$gkiej`k$SIMG", 4));
                return 1;
            }
            // Lê a saída do comando
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // Verifica se o fabricante é uma VM comum
                if (strstr(buffer, x_e_d("RIseva", 4)) != NULL || strstr(buffer, x_e_d("RmvpqehFk|", 4)) != NULL || strstr(buffer, x_e_d("UAIQ", 4)) != NULL) {
                    printf(x_e_d("K$wmwpaie$awpe$vk`ej`k$ai$qie$ieuqmje$rmvpqeh", 4));
                    printf("\n");
                    exit(1);
                } else {
                    printf(" %s", buffer);
                }
            }

            fclose(fp);
            getchar();
        break;
        default:
            
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
        break;
    }
    return 0;
}
