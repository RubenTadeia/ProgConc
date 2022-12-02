/* Libraries */
#include "functions.h"

/* Functions */
/* Function to check input arguments*/
void check_arguments (int argc, char * argv[]){
	// Se passar
	if(argc != 3){
		printf("ERRO: Os argumentos não foram colocados na fora correta!\n");
		printf("Não se esqueça que o número de threads tem que ser um inteiro positivo.\n");
		printf("Por favor insira os argumentos da maneira apresenta abaixo como exemplo:\n");
		printf("ap-paralelo-1 dir-1 4\n");
		exit(1);
	}
	
	DIR* dir = opendir(argv[1]);
	if (dir) {
		/* Directory exists. */
		closedir(dir);
	} else if (ENOENT == errno) {
		/* Directory does not exist. */
		printf("ERRO: Não foi possível encontrar a diretoria das imagens!\n");
		exit(1);
	} else {
		/* opendir() failed for some other reason. */
		printf("ERRO: Não foi possível encontrar a diretoria das imagens!\n");
		exit(1);
	}

	if (atoi(argv[2]) <= 0){
		printf("ERRO: Por favor coloca um numero de threads que seja inteiro positivo!\n");
		exit(1);
	}
}

/* Function to read input file of images*/
void read_image_file(char * imagesDirectory, char * fname){

	char * fullPath_to_file = (char * ) calloc (strlen(imagesDirectory)+1+strlen(fname)+1, sizeof(char));
	strcpy(fullPath_to_file,imagesDirectory);
	strcat(fullPath_to_file,"/");
	strcat(fullPath_to_file,fname);
	//printf("Full path to image = %s\n",fullPath_to_file);

	if( access( fullPath_to_file, F_OK ) != -1){
		printf("%s encontrado\n", fullPath_to_file);
	}else{
		printf("ERRO: %s nao encontrado. Por favor coloque-o na diretoria das imagens!\n", fname);
		exit(2);
	}	

	// Vamos iniciar a leitura do ficheiro
	char linha[100];
	FILE * file = fopen(fullPath_to_file, "r");
	if(file == NULL){
		perror("ERRO: Ao abrir o ficheiro");
		exit(2);
	}

	/* Variaveis */
	extern int nomes_validos_imagens;
	extern int max_word_len;
	extern char ** images_array;

	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' &&  linha[0] != '\0' && strlen(linha) >= 5){
			// Colocar a extensao do ficheiro que podia ser .PNG em .png
			linha[strlen(linha)-1] = '\0';

			// Encontra a ultima ocorrencia de . na string e devolve o resto da string
			char * aux = strrchr(linha, '.');
			
			for (int j = 0; aux[j]!= '\0'; j++){
				aux[j] = tolower(aux[j]);
		   	}
			//printf("Aux = %s\n",aux);
			if (strcmp(aux, ".png") == 0){
				// Este 
				nomes_validos_imagens++;
				if(strlen(linha)-1 > max_word_len){
					max_word_len = strlen(linha)-1;
				}
			}
		}   
	}

	fclose(file);
	//printf("Numero de imagens validas = %d\n",nomes_validos_imagens);
	
	images_array = calloc(nomes_validos_imagens,sizeof(char *));
	
	if (images_array == NULL){
		perror("malloc in images_array");
		exit(0);
	}
	max_word_len = max_word_len + 1;
	file = fopen(fullPath_to_file, "r");

	int i = 0;
	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' && linha[0] != '\0' && strlen(linha) >= 5){
			// Colocar a extensao do ficheiro que podia ser .PNG em .png
			linha[strlen(linha)-1] = '\0';
			
			// Encontra a ultima ocorrencia de . na string e devolve o resto da string
			char * aux = strrchr(linha, '.');

			for (int j = 0; aux[j]!= '\0'; j++){
				aux[j] = tolower(aux[j]);
		   	}
			//printf("Aux = %s\n",aux);
			if (strcmp(aux, ".png") == 0){
				images_array[i] = calloc(sizeof(char), max_word_len+1);
				strcpy(images_array[i], linha);
				i++;
			}
		}
	}

	// DEBUG: Aqui vou funcionar 
	//print_image_array (images_array,nomes_validos_imagens);

	fclose(file);
	free(fullPath_to_file);
}

/* Function to print image array */
void print_image_array(char ** images_array, int array_size){
	for (int i = 0; i < array_size; i++){
		printf("%s\n",images_array[i]);
	}
}

/* Function to free image array */
void free_image_array(char ** images_array, int array_size){
	for (int i = 0; i < array_size; i++){
		free(images_array[i]);
	}
	free(images_array);
}