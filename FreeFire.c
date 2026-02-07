#include <stdio.h>
#include <string.h>

#define  MAX_CHAR 20
#define MAX_ITENS 10

typedef struct {
	char name[MAX_CHAR];
	char type[MAX_CHAR];
	int amount;
} Item;

Item bag[MAX_ITENS];
int bag_total = 0;

void cleanBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);	
}

char captureInput()
{
	if(bag_total < MAX_ITENS)
	{
		printf("Nome do item: ");
		fgets(bag[bag_total].name, MAX_CHAR, stdin);
		bag[bag_total].name[strcspn(bag[bag_total].name , "\n")] = 0;
		
		printf("Tipo do item: ");
		fgets(bag[bag_total].type, MAX_CHAR, stdin);
		bag[bag_total].type[strcspn(bag[bag_total].type , "\n")] = 0;
		
		printf("Quantidade de item");
		scanf("%d", &bag[bag_total].amount, stdin);
		cleanBuffer();

		bag_total++;
		printf("Item Armazenado! \n");
	} else {
		printf("Mochila Cheia \n Tire algum item para substituir o espaço! \n");
	}
}

void listItems()
{
	printf("\n--- Itens na mochila! (%d/%d) ---\n",
		   bag_total, MAX_ITENS);
	for (int index = 0; index < bag_total; index++)
	{
		printf("%d. %s [%s] - Qtd: %d\n", index + 1, bag[index].name, bag[index].type, bag[index].amount);
	}
}

//Função remover um item do vetor
void removeItem() {
    if (bag_total == 0) {
        printf("A mochila ja esta vazia!\n");
        return;
    }

    int index;
    listItems();
    printf("\nDigite o numero do item que deseja remover: ");
    scanf("%d", &index);
    cleanBuffer();

    index = index - 1;

    if (index >= 0 && index < bag_total) {
        // Loop para deslocar os itens para a esquerda
        for (int i = index; i < bag_total - 1; i++) {
            bag[i] = bag[i + 1];
        }
        
        bag_total--; // Diminui o contador total de itens
        printf("Item removido com sucesso!\n");
    } else {
        printf("Indice invalido!\n");
    }
}


int main() {
    int choice;
    do {
        printf("\n1. Adicionar \n3.Remover \n2. Listar\n0. Sair\nEscolha: ");
        scanf("%d", &choice);
        cleanBuffer();

        if (choice == 1) captureInput();
        else if (choice == 2) listItems();
		else if (choice == 3) removeItem();
        
    } while (choice != 0);

    return 0;
}
