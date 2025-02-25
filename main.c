#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct _PEB {
  BYTE                          Reserved1[2];
  BYTE                          BeingDebugged;
  BYTE                          Reserved2[1];
  PVOID                         Reserved3[2];
//  PPEB_LDR_DATA                 Ldr;
//  PRTL_USER_PROCESS_PARAMETERS  ProcessParameters;
  PVOID                         Reserved4[3];
  PVOID                         AtlThunkSListPtr;
  PVOID                         Reserved5;
  ULONG                         Reserved6;
  PVOID                         Reserved7;
  ULONG                         Reserved8;
  ULONG                         AtlThunkSListPtr32;
  PVOID                         Reserved9[45];
  BYTE                          Reserved10[96];
//  PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
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

// __attribute__((constructor))
// static void initialize_debug_scan() {
    //    TEB* teb;

    // __asm__ (
    //     "movl %%fs:0x18, %0;"   // Em sistemas de 32 bits, FS contém o offset do TEB na posição 0x18
    //     : "=r" (teb)             // O resultado vai para a variável teb
    // );
    // PEB* peb = (PEB*)teb->ProcessEnvironmentBlock;

    // // Checando o campo BeingDebugged no PEB
    // //printf("BeingDebugged: %d\n", peb->BeingDebugged);
    // if(peb->BeingDebugged == 1) {
    //     exit(1);
    // };
   if(IsDebuggerPresent()) {
       printf("IsDebuggerPresent true\n");
       exit(1);
   }
// }

int main() {
    
  //  if(IsDebuggerPresent()) {
  //      printf("Debugger detectado!");
  //     exit(1);
  //  }

//  void initialize_debug_scan() {
//       TEB* teb;

//    __asm__ (
//        "movl %%fs:0x18, %0;"   // Em sistemas de 32 bits, FS contém o offset do TEB na posição 0x18
//        : "=r" (teb)             // O resultado vai para a variável teb
//    );
//    PEB* peb = (PEB*)teb->ProcessEnvironmentBlock;

//    // Checando o campo BeingDebugged no PEB
//    printf("BeingDebugged: %d\n", peb->BeingDebugged);
//    if(peb->BeingDebugged == 1) {
//        exit(1);
//    };
// }
// initialize_debug_scan();

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
