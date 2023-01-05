// Libraries
#include "functions.h"

/******************************************************************************
 * check_arguments()
 *
 * Arguments: int argc
 * 			  char * argv[]
 * Returns: Não retorna erro se funcionar
 * Side-Effects: none
 *
 * Description: Verifica se os argumentos estão na forma correta
 *
 *****************************************************************************/
void check_arguments (int argc, char * argv[]){
	// Se passar
	if(argc != 3){
		printf("ERRO: Os argumentos não foram colocados na fora correta!\n");
		printf("Não se esqueça que o número de threads tem que ser um inteiro positivo.\n");
		printf("Por favor insira os argumentos da maneira apresenta abaixo como exemplo:\n");
		printf("./ap-paralelo-3 directoria-imagens numero-de-threads\n");
		exit(1);
	}
	
	DIR* dir = opendir(argv[1]);
	if (dir) {
		// Directory exists
		closedir(dir);
	} else if (ENOENT == errno) {
		// Directory does not exist
		printf("ERRO: Não foi possível encontrar a diretoria das imagens!\n");
		exit(1);
	} else {
		// opendir() failed for some other reason
		printf("ERRO: Não foi possível encontrar a diretoria das imagens!\n");
		exit(1);
	}

	if (atoi(argv[2]) <= 0){
		printf("ERRO: Por favor coloca um numero de threads que seja inteiro positivo!\n");
		exit(1);
	}
}

/******************************************************************************
 * read_image_file()
 *
 * Arguments: char * imagesDirectory
 * 			  char * fname
 * Returns: none
 * Side-Effects: none
 *
 * Description: Lê o ficheiro que contém o nome das imagens a serem tratadas. 
 * 				Retira o número de imagens válidas e um array que contém o nome dessas mesmas imagens
 *
 *****************************************************************************/
void read_image_file(char * imagesDirectory, char * fname){

	char * fullPath_to_file = (char * ) calloc (strlen(imagesDirectory)+1+strlen(fname)+1, sizeof(char));
	strcpy(fullPath_to_file,imagesDirectory);
	strcat(fullPath_to_file,"/");
	strcat(fullPath_to_file,fname);

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

	// Variaveis Globais vindas do main
	extern int numero_imagens_validas;
	extern int max_word_len;
	extern char ** images_array;

	// Contabiliza o número de imagens válidas
	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' &&  linha[0] != '\0' && strlen(linha) >= 5){
			// Colocar a extensao do ficheiro que podia ser .PNG em .png
			linha[strlen(linha)-1] = '\0';

			// Encontra a ultima ocorrencia de . na string e devolve o resto da string
			char * aux = strrchr(linha, '.');
			
			for (int j = 0; aux[j]!= '\0'; j++){
				aux[j] = tolower(aux[j]);
		   	}
	
			if (strcmp(aux, ".png") == 0){
				char * fullPath_to_image = (char * ) calloc (strlen(imagesDirectory)+1+strlen(linha)+1, sizeof(char));
				strcpy(fullPath_to_image,imagesDirectory);
				strcat(fullPath_to_image,"/");
				strcat(fullPath_to_image,linha);
				if(check_images(fullPath_to_image) == 1){
					numero_imagens_validas++;
					if(strlen(linha)-1 > max_word_len){
						max_word_len = strlen(linha)-1;
					}
				}
				free(fullPath_to_image);
			}
		}   
	}

	fclose(file);
	
	// Cria um array que contém o nome das imagens a serem tratadas
	images_array = calloc(numero_imagens_validas,sizeof(char *));
	
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

			if (strcmp(aux, ".png") == 0){
				char * fullPath_to_image = (char * ) calloc (strlen(imagesDirectory)+1+strlen(linha)+1, sizeof(char));
				strcpy(fullPath_to_image,imagesDirectory);
				strcat(fullPath_to_image,"/");
				strcat(fullPath_to_image,linha);
				if(check_images(fullPath_to_image) == 1){
					images_array[i] = calloc(sizeof(char), max_word_len+1);
					strcpy(images_array[i], linha);
					i++;	
				}
				free(fullPath_to_image);
			}
		}
	}

	fclose(file);
	free(fullPath_to_file);
}

/******************************************************************************
 * print_image_array()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: none
 * Side-Effects: none
 *
 * Description: Escreve no terminal o que images_array contém
 *
 *****************************************************************************/
void print_image_array(char ** images_array, int array_size){
	for (int i = 0; i < array_size; i++){
		printf("%s\n",images_array[i]);
	}
}

/******************************************************************************
 * free_image_array()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: none
 * Side-Effects: none
 *
 * Description: Dá free ao images_array
 *
 *****************************************************************************/
void free_image_array(char ** images_array, int array_size){
	for (int i = 0; i < array_size; i++){
		free(images_array[i]);
	}
	free(images_array);
}

/******************************************************************************
 * check_images()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: Devolve um inteiro com valor 1 se encontrar, caso contrário 0 
 * Side-Effects: none
 *
 * Description: Verifica se as imagens existem na pasta fornecida
 *
 *****************************************************************************/
int check_images(char * image_string){
	// Devolve 1 se encontrar, caso contrário 0
	if( access( image_string, F_OK ) != -1){
 		return 1;
	}else{
 		printf("%s nao encontrado\n", image_string);
		return 0;
	}
}

/******************************************************************************
 * create_directories()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: none
 * Side-Effects: none
 *
 * Description: Cria as respetivas diretorias
 *
 *****************************************************************************/
void create_directories(char * images_folder){
	
	char * fullPath_to_resize_dir_folder = (char * ) calloc (strlen(images_folder)+strlen(RESIZE_DIR)+1, sizeof(char));
	strcpy(fullPath_to_resize_dir_folder,images_folder);
	strcat(fullPath_to_resize_dir_folder,RESIZE_DIR);

	char * fullPath_to_resize_thumb_folder = (char * ) calloc (strlen(images_folder)+strlen(THUMB_DIR)+1, sizeof(char));
	strcpy(fullPath_to_resize_thumb_folder,images_folder);
	strcat(fullPath_to_resize_thumb_folder,THUMB_DIR);

	char * fullPath_to_resize_water_folder = (char * ) calloc (strlen(images_folder)+strlen(WATER_DIR)+1, sizeof(char));
	strcpy(fullPath_to_resize_water_folder,images_folder);
	strcat(fullPath_to_resize_water_folder,WATER_DIR);

	// creation of output directories
	if (create_directory(fullPath_to_resize_dir_folder) == 0){
		fprintf(stderr, "Impossible to create %s directory\n", fullPath_to_resize_dir_folder);
		exit(-1);
	}
	if (create_directory(fullPath_to_resize_thumb_folder) == 0){
		fprintf(stderr, "Impossible to create %s directory\n", fullPath_to_resize_thumb_folder);
		exit(-1);
	}
	if (create_directory(fullPath_to_resize_water_folder) == 0){
		fprintf(stderr, "Impossible to create %s directory\n", fullPath_to_resize_water_folder);
		exit(-1);
	}

	free(fullPath_to_resize_dir_folder);
	free(fullPath_to_resize_thumb_folder);
	free(fullPath_to_resize_water_folder);
}