//Código da aula "Insertion Sort":
void insertionSort(int * lista, int tamanho){ //Como não tenho como saber o tamanho da lista através desse ponteiro, é necessário passar também o tamanho.
    int i, j;
    int atual;
    for(i = 1; i < tamanho; i++){
        j = i;
        atual = lista[i];
        //Procura da posição onde o elemento atual deve ser inserido à sua esquerda e abertura do espaço onde ele será inserido:
        while((j > 0) && (atual < lista[j-1])){ //Enquanto o atual for menor que o elemento da esquerda:
            lista[j] = lista[j-1]; //empurre esse elemento para a direita.
            j--;
        } //Achou a posição? Sai do while.
        lista[j] = atual; //O atual é inserido no espaço.
    }
}