#include <stdio.h>
#include <stdlib.h>

int *lista;
int tamanho_total;
int tamanho_atual = 0;
int indice = 0;

int* iniciar_lista(){
    int *temp;
    size_t size;
    size = sizeof(int) * 10;
    tamanho_total = size / sizeof(int);
    temp = (int*) malloc(size);
    return temp;
}

void add(int valor){
    if (full()){
        tamanho_total *= 2;
        lista = (int*) realloc(lista, sizeof(int) * tamanho_total);
    }

        // Insere
        lista[indice++] = valor;
        tamanho_atual++;

}

void addat(int valor, int index){
    if (index < 0 || index >= tamanho_atual)
        return;
    lista[index] = valor;
}

int full(){
    if (tamanho_atual == tamanho_total){
        return 1;
    } else {
        return 0;
    }
}

void remover(int index){
    if (index < 0 || index >= tamanho_atual)
        return;

    int i, j, *newarr = (int*) malloc(sizeof(int) * tamanho_atual * 2);
    for (i = 0, j = 0; i < tamanho_atual; i++){
        if (i != index){
            newarr[j] = lista[i];
            j++;
        }
    }
    free(lista);
    lista = newarr;
    tamanho_atual--;
}

int get(int index){
    if (index < 0 || index >= tamanho_atual)
        return -1;
    else
        return lista[index];
}

void get_all(){
    int i;
    for (i = 0; i < tamanho_atual; i++){
        printf("%d\n", get(i));
    }
}

int main(){
    int i;
    lista = iniciar_lista();
    for (i = 0; i < 101; i++){
        add(i+1);
    }

    get_all();

    remover(0);

    printf("\nlength %d", tamanho_atual);
    free(lista);
    return 0;
}
