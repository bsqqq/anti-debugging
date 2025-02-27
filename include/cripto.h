#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função 1: XOR Encryption
char* x_e_d(const char *input, char key) {
    int length = strlen(input);
    char *result = (char *)malloc(length + 1);  // Aloca memória para a string resultante

    for (int i = 0; i < length; i++) {
        result[i] = input[i] ^ key;  // XOR bitwise com a chave
    }

    result[length] = '\0';  // Assegura que a string esteja terminada corretamente
    return result;
}

// Função 2: Caesar Cipher (Cifra de César)
char* c_c_e(const char *input, int shift) {
    int length = strlen(input);
    char *result = (char *)malloc(length + 1);  // Aloca memória para a string resultante

    for (int i = 0; i < length; i++) {
        if ('a' <= input[i] && input[i] <= 'z') {
            result[i] = ((input[i] - 'a' + shift) % 26) + 'a';  // Para letras minúsculas
        } else if ('A' <= input[i] && input[i] <= 'Z') {
            result[i] = ((input[i] - 'A' + shift) % 26) + 'A';  // Para letras maiúsculas
        } else {
            result[i] = input[i];  // Outros caracteres permanecem inalterados
        }
    }

    result[length] = '\0';  // Assegura que a string esteja terminada corretamente
    return result;
}

char* c_c_d(const char *input, int shift) {
    return c_c_e(input, -shift);  // Para descriptografar, basta inverter o shift
}

// Função 3: Shift Cipher (Cifra de Deslocamento)
char* s_c_e(const char *input, int shift) {
    int length = strlen(input);
    char *result = (char *)malloc(length + 1);  // Aloca memória para a string resultante

    for (int i = 0; i < length; i++) {
        result[i] = input[i] + shift;  // Desloca cada caractere
    }

    result[length] = '\0';  // Assegura que a string esteja terminada corretamente
    return result;
}

char* s_c_d(const char *input, int shift) {
    int length = strlen(input);
    char *result = (char *)malloc(length + 1);  // Aloca memória para a string resultante

    for (int i = 0; i < length; i++) {
        result[i] = input[i] - shift;  // Desfaz o deslocamento
    }

    result[length] = '\0';  // Assegura que a string esteja terminada corretamente
    return result;
}

// Função 4: Reversão de String
char* r_s(const char *input) {
    int length = strlen(input);
    char *result = (char *)malloc(length + 1);  // Aloca memória para a string resultante

    for (int i = 0; i < length; i++) {
        result[i] = input[length - 1 - i];  // Inverte os caracteres
    }

    result[length] = '\0';  // Assegura que a string esteja terminada corretamente
    return result;
}

#endif
