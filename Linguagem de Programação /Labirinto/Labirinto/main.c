//
//  main.c
//  Labirinto
//
//  Created by Jhionan on 23/06/19.
//  Copyright © 2019 Jhionan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file;
    char fileName[30];
    
    printf("Digite o nome do arquivo para carregar:\n");
    gets(fileName);
    
    printf("Carregando %s",fileName);
    
    file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Deu erro ao abrir arquivo %s\n", fileName);
    }
    else {
        printf("Arquivo aberto com sucesso!\n");
    }
    
    
    return 0;
}
