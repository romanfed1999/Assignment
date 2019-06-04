#include <stdlib.h>
#include <stdio.h>

char buf[150][150];

void print_nonzero_rows(char *matrix)
{
    int i, j, k=0;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(*(matrix+(4*(k+j)))=='0'){
                break;
                }
            }
        if(j==4){
            for(j=0; j<4; j++){
                printf("%s ", (matrix+(4*(k+j))));
                }
                printf("\n");
            }
        k+=4;
        }
    }
    
void print_nonzero_diagonals(char *matrix){
    int i, j, l=0, k=0;
    for(i=0; i<4; i++){
            for(j=4-i; j>0; j--){
                    if(*(matrix+(4*(k+i))) == '0'){
                        break;
                        }
                    k+=5;
                }
            k=0;
            if(j==0){
                for(j=4-i; j>0; j--){
                    if(*(matrix+(4*(k+i))) != '0'){
                        printf("%s ", (matrix+(4*(k+i))));
                        }
                    k+=5;
                }
                printf("\n");
                }
            k=0;
        }
    for(i=4; i<=12; i+=4){
        for(j=4-l; j>0; j--){
                    if(*(matrix+(4*(k+i))) == '0'){
                        break;
                        }
                    k+=5;
                }
            k=0;
            if(j==0){
                for(j=4-l; j>0; j--){
                    if(*(matrix+(4*(k+i))) != '0'){
                        printf("%s ", (matrix+(4*(k+i))));
                        }
                    k+=5;
                }
                printf("\n");
                }
            k=0;
            l++;
        }
    }

char* split_char(char* arr, unsigned int arr_size){
    char *numbers = calloc(4*16, sizeof(char));
    int i, j=0, k=0;
    for(i=0; i<arr_size; i++){
        if(arr[i]!=','&&arr[i]!='\n'){
            numbers[k*4+j] = arr[i];
            j++;
        }
        else{
            numbers[k*4+j] = '\0';
            j=0;
            k++;
            }
        }
    return numbers;
    }

char* matrix_to_char(char* path){
    FILE *file;
    size_t nread;

    file = fopen(path, "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0);
        if (ferror(file)) {
            exit(0);
        }
        fclose(file);
    }
    return buf;
}

int main(int argc, char* argv[]){
    printf("Given matrix:\n%s", matrix_to_char(argv[1]));
    char* matrix = split_char(matrix_to_char(argv[1]), 50);
    printf("\n");
    print_nonzero_rows(matrix);
    print_nonzero_diagonals(matrix);
    return 0;
    }