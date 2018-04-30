#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Recebe o vetor e o intervalo a ser ordenado
 **/

void merge_sort(int* vector, int begin, int end);
void merge(int* vector, int begin, int middle, int end);

void merge_sort(int* vector, int begin, int end){
    // Se o índice do fim for igual o do começo, entramos no caso base.
    // Onde logicamente, um array de uma posição está ordenado por natureza.
    if (begin == end) return;
    
    int middle = floor((begin + end) / 2);  // Estava tendo problemas com o arredondamento
                                            // Achei um vídeo que acho ser da UFPR, onde o floor é usado para
                                            // Arredondar para baixo
    // Caso o intervalo seja correspondente a um item
    // O merge sort não é chamado

    // divide da ESQUERDA middle/ MEIO
    merge_sort(vector, begin, middle);
    // dividde do MEIO middle/ DIREITA
    merge_sort(vector, (middle+1), end);
    // Faz uma espécie de insertion sort no "chunk"
    merge(vector, begin, middle, end);
}


/*
 * Faz uma espécie de insertion sort recursivo no intervalo desejado
 * Não é necessário retornar o vetor, já que no final vc estará manipulando
 * um ponteiro.
 * */

void merge(int* vector, int begin, int middle, int end){
    int size = (end-begin+1), hook = begin, hook2 = (middle+1), 
        k = 0, vect_end = 0, temp_end = 0, i = 0, j = 0;
	int* temp = (int*) malloc(sizeof(int) * size);
    for(i = 0; i < size; i++)
        if(!vect_end && !temp_end) { //Se o fim dos dois vetores não foi atingido (falso)
            
            if(vector[hook] < vector[hook2]) //Se o começo for maior que o final
                temp[i] = vector[hook++];    //Acrescenta um no pivô e define a posição atual (começo) como menor
            else                             //Muda a posição do maior valor no vetor
                temp[i] = vector[hook2++];   //Acrescenta um no pivô e define a  posição atual (fim) como menor

            if(hook > middle) vect_end = 1; //Define o final dos vetores caso
            if(hook2 > end) temp_end = 1;   //a posição do pivô seja maior que o final como verdade
        
        } else {

            if(!vect_end)   //Se o final nao for atingido
                temp[i] = vector[hook++];    //Copia o último valor e aumenta o primeiro pivo
            else
                temp[i] = vector[hook2++];   //Copia o ultimo valor e aumenta o segundo pivo
        
        }

    //Copio os valores do pivo temporário (ordenado) a partir da posição recolhida no protótipo
    for(j = 0, k = begin; j < size; j++, k++)
        vector[k] = temp[j];

    //Libero o espaço allocado
	free(temp);
}

/*
 * Imprime qualquer array para o usuário
 * */

void print_array(int* vector, int size) {
    
    int i;
    
    for(i = 0; i < size; i++) {
        printf("%d\n", vector[i]);
    }

}

int main(void) {
    
    int vect[] = {1, 39, 14, 0, 4};
    
    print_array(vect, 5);

    merge_sort(vect, 0, 4);
    
    puts("\nordenado: \n");
    print_array(vect, 5);

    return 0;
}
