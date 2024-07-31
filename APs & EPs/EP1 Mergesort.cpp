#include <stdio.h>
#include <stdlib.h>

struct candidato{
    char nome[30];
    int nota;
    int idade;
};

 void MergeAGE(struct candidato *A, int l,int r){
     struct candidato temp[r+1]; //declarando temp
     for(int i=l; i<=r; i++){
         temp[i] = A[i]; //copiando A -> temp
     }
     int m = (l+r)/2;
     int i1 = l;
     int i2 = m+1;
     for(int curr=l; curr<=r; curr++){
         if(i1>m) A[curr] = temp[i2++];
         else if(i2>r) A[curr] = temp[i1++];
         else if (temp[i1].idade >= temp[i2].idade) A[curr] = temp[i1++]  ;
         else A[curr] = temp[i2++];
     }

 }

void MergesortAGE(struct candidato *A, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        MergesortAGE(A, l, m);
        MergesortAGE(A, m+1, r);
        MergeAGE(A, l, r);
    }
}

 void MergeNOTA(struct candidato *A, int l,int r){
     struct candidato temp[r+1]; //declarando temp
     for(int i=l; i<=r; i++){
         temp[i] = A[i]; //copiando A -> temp
     }
     int m = (l+r)/2;
     int i1 = l;
     int i2 = m+1;
     for(int curr=l; curr<=r; curr++){
         if(i1>m) A[curr] = temp[i2++];
         else if(i2>r) A[curr] = temp[i1++];
         else if (temp[i1].nota >= temp[i2].nota) A[curr] = temp[i1++]  ;
         else A[curr] = temp[i2++];
     }

 }

void MergesortNOTA(struct candidato *A, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        MergesortNOTA(A, l, m);
        MergesortNOTA(A, m+1, r);
        MergeNOTA(A, l, r);
    }
}

int main() {
    int qtd_cargos;
    scanf("%i", &qtd_cargos); //recebe a quantidade de cargos
    for(int i=0; i<qtd_cargos; i++){ //para cada cargo ---
        int qtd_inscritos, qtd_vagas;
        scanf("%i", &qtd_inscritos); //recebe a qtd de inscritos
        scanf("%i", &qtd_vagas); //recebe a qtd de vagas
        struct candidato lista_de_candidatos[qtd_inscritos]; //declara array de estruturas
        for(int j=0; j<qtd_inscritos; j++){ //para cada candidato ---
            scanf("%s", lista_de_candidatos[j].nome); //recebe o seu nome
            scanf("%i", &lista_de_candidatos[j].nota); //recebe a sua nota
            scanf("%i", &lista_de_candidatos[j].idade); //recebe a sua idade
        }
        for(int t=qtd_inscritos; t<qtd_vagas; t++){
            lista_de_candidatos[t].nota = -1;
            lista_de_candidatos[t].idade = -1;
        }
        MergesortAGE(lista_de_candidatos, 0, qtd_inscritos-1); //ordena pela idade
        MergesortNOTA(lista_de_candidatos, 0, qtd_inscritos-1); //ordena pela nota
        printf("cargo %i:\n", i+1);
        for(int y=0; y<qtd_vagas; y++){
            if(lista_de_candidatos[y].nota == -1) {
                printf("x\n");
            }
            else printf("%s\n", lista_de_candidatos[y].nome);
        }

    }
}


