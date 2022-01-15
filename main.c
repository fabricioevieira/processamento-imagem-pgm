#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void showMenu();
bool returnMenu();

int** openFile(FILE* pgmimg, int** matrix, int* width, int* height, int* maxgray);

void imageThresholding(int** matrix, int width, int height);
void negative(int** matrix, int width, int height);
void histogram(int** matrix, int width, int height, int maxgray);

int main(){
    int option;
    FILE* pgmimg;
    int width, height, maxgray;
    int **matrix;

    matrix = openFile(pgmimg, matrix, &width, &height, &maxgray);
    
    if (matrix == 0){
        return 0;
    }

    do{
        showMenu();
        scanf("%d", &option);
        getchar();

        switch(option){
        case 1:
            imageThresholding(matrix, width, height);
            if(!returnMenu())
                return 0;
            break;
        case 2:
            negative(matrix, width, height);
            if(!returnMenu())
                return 0;
            break;
        case 3:
            histogram(matrix, width, height, maxgray);
            if(!returnMenu())
                return 0;
            break;
        case 4:
            printf("Finalizando o programa...");
            break;        
        default:
            printf("Opcao invalida!");
            break;
        }
    }while(option != 4);

    for(int i = 0; i < height; i++){
        free(matrix[i]);
    }
    free(matrix);

    fclose(pgmimg);

    return 0;
}

//Exibe o menu
void showMenu(){
    printf("\n=============== MENU ===============\n");
    printf("[1] - Limiarizacao\n");
    printf("[2] - Negativo\n");
    printf("[3] - Histograma\n");
    printf("[4] - Finalizar Aplicacao\n\n");
    //printf("=====================================\n");
}

//Exibe mansagem para retornar ao menu
bool returnMenu(){
    char option;
    printf("Deseja retornar ao menu ? [S/N]\n");
    do{
        scanf(" %c", &option);
        switch(option){
        case 'N':
        case 'n':
            return false;
            break;
        case 'S':
        case 's':
            return true;
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }while(1);
}

//Abre a imagem PGM e declara a matriz atribuindo o conteudo do arquivo
int ** openFile(FILE* pgmimg, int** matrix, int* width, int* height, int* maxgray){
    char type[3];
    int i ,j;

    //Caminho da imagem fornecida como exemplo para o projeto
    pgmimg = fopen("files/exemplo.pgm", "rb");

    if(pgmimg == NULL){
        printf("Erro ao abrir imagem");
        getchar();
        return 0;
    }

    fscanf(pgmimg, "%s", &type);

    if(strcmp(type, "P2") != 0){
        printf("ERRO: Aquivo não suportado");
        return 0;
    }

    fscanf(pgmimg, "%d %d", width, height);
    fscanf(pgmimg, "%d", maxgray);

    matrix = malloc(sizeof(int*)*(*width));
    for(i = 0; i < *height; i++){
        matrix[i] = (int*)malloc(sizeof(int*)*(*height));
    }

    for(i = 0; i < *height; i++){
        for(j = 0; j < *width; j++){
            fscanf(pgmimg, "%d", &matrix[i][j]);
        }
    }

    return matrix;
}

//Limiarizacao da imagem
void imageThresholding(int** matrix, int width, int height){
    int** tempmatrix;
    const int limiter = 150;
    FILE* img;

    img = fopen("files/imagemlimiarizada.pgm", "wb");

    if(img == NULL){
        printf("Erro ao abrir imagem");
        getchar();
        return 0;
    }

    fprintf(img, "P2\n%d %d\n255\n", width, height);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(matrix[i][j] > limiter){
                fprintf(img, "%d ", 255);
            }
            else{
                fprintf(img, "%d ", 0);
            }
        }
        fprintf(img, "\n");
    }
    fclose(img);

    printf("\nImagem criada com sucesso!\n"); 
}

//Negativa a imagem
void negative(int** matrix, int width, int height){
    int** tempmatrix;
    FILE* img;

    img = fopen("files/imagemnegativa.pgm", "wb");

    if(img == NULL){
        printf("Erro ao abrir imagem");
        getchar();
        return 0;
    }

    fprintf(img, "P2\n%d %d\n255\n", width, height);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            fprintf(img, "%d ", (255 - matrix[i][j]));
        }
        fprintf(img, "\n");
    }
    fclose(img);

    printf("\nImagem criada com sucesso!\n");
}

//Gera um histograma da imagem
void histogram(int** matrix, int width, int height, int maxgray){
    int* hist;
    FILE* img;
    char str[50] = "TESTE UM DOI TRES";

    img = fopen("files/histograma.txt", "w");

    if(img == NULL){
        printf("Erro ao abrir imagem");
        getchar();
        return 0;
    }

    hist = malloc(sizeof(int)*maxgray);
    
    for(int i = 0; i <= maxgray; i++){
        hist[i] = 0;
    }

    //fprintf(img, "indice\t \tquantidade\n");

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            hist[(matrix[i][j])]++;
        }
    }

    for(int i = 0; i <= maxgray; i++){
        fprintf(img, "%d - %d\n", i, hist[i]);
    }
    printf("\nHistograma criado sucesso!\n");

    fclose(img);

    free(hist);
}