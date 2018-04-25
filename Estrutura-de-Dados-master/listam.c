#include <stdio.h>
#include <stdlib.h>

struct list{
    int *valores;
    int tamanho;
    int cont;
};

typedef struct list lista;

lista* iniciarLista(lista* temp){
    //Se temp for null
    if (temp)
    temp = (lista*) malloc(sizeof(lista*));

    //Inicia a lista com o tamanho total 10
    free(temp);
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

int length(lista *listalink){
    if (listalink != NULL)
        return listalink->cont;
    else
        return -1;
}

void remover(lista *listalink, int pos){
    if (listalink == NULL)
        return;
        int i, j, *temp = (int*) malloc(sizeof(int) * listalink->tamanho);
        if (temp == NULL){
            printf("Nao foi possivel remover!\n");
            return;
        }
        for(i = 0, j = 0; i < listalink->cont; i++){
            if(i != pos){
                temp[j] = listalink->valores[i];
                j++;
            }
        }
        free(listalink->valores);
        listalink->valores = temp;
        listalink->cont--;
    }


int main(){
    lista *arr;
    arr = iniciarLista(arr);
    add(arr, 1);
    add(arr, 2);
    add(arr, 3);
    int i;
    for (i = 0; i < length(arr); i++){
        printf("%d\n", arr->valores[i]);
    }
    remover(arr, 0);
return 0;
}
