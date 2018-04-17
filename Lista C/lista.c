#include <stdio.h>
#include <stdlib.h>

int *lista;
int tamanho_total;
int tamanho_atual;
int indice = 0;

int* iniciar_lista(int length){
    int *temp;
    size_t size;
    size = sizeof(int) * (length > 0 ? length : 1);
    tamanho_total = size / sizeof(int);
    temp = (int*) malloc(size);
    return temp;
}

void inserir(int valor){
    if (full()){
        int temp[tamanho_total], i;
        for (i = 0; i < tamanho_total; i++){
            temp[i] = lista[i];
        }
        lista = iniciar_lista(tamanho_total * 2);
        for (i = 0; i < tamanho_total; i++){
            lista[i] = temp[i];
        }
    }

        // Insere
        lista[indice++] = valor;
        tamanho_atual++;

}

int tamanho(){
    return tamanho_atual;
}

int full(){
    if (tamanho_atual == tamanho_total){
        return 1;
    } else {
        return 0;
    }
}

int get(int index){
    if (index < 0 || index > tamanho_atual)
        return -1;
    else
        return lista[index];
}

int main(){
    int i;
    lista = iniciar_lista(10);
    tamanho_atual = 0;
    for (i = 0; i < 30; i++){
        inserir(i+1);
    }
    for (i = 0; i < tamanho(); i++){
        printf("%d\n", get(i));
    }

    printf("length %d", tamanho());
    return 0;
}
