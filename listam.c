#include <stdio.h>
#include <stdlib.h>

struct list{
    int *valores;
    int tamanho;
    int cont;
};

typedef struct list lista;

lista* iniciarLista(lista* temp){
    if (temp)
    temp = (lista*) malloc(sizeof(lista*));

    temp->valores = (int*) malloc(sizeof(int) * 10);
    temp->tamanho = 10;
    temp->cont = 0;
    return temp;
}

void add(lista *listalink, int e){
    if (listalink->cont == listalink->tamanho){
        listalink->tamanho *= 2;
        listalink->valores = (int*) realloc(listalink->valores, sizeof(int) * listalink->tamanho);
    }
    listalink->valores[listalink->cont++] = e;
}

int main(){
    lista *arr;
    arr = iniciarLista(arr);
    add(arr, 1);
    add(arr, 2);
    add(arr, 3);
    int i;
    for (i = 0; i < arr->cont; i++){
        printf("%d\n", arr->valores[i]);
    }
return 0;
}
