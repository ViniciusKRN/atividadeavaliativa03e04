

//Alberane, eu fiz essa atividade junto do Allison Freittas


#include <stdio.h>
#include <stdlib.h>

#define NARRAY 7   // Mosta o tamanho da matriz
#define NBUCKET 6  // Número de baldes/caçambas
#define INTERVAL 10  // Capacidade de cada caçamba/balde

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void impcacambas(struct Node *list);
int getBaldeIndex(int value);

// Função de Classificação
void BucketSort(int arr[]) {
  int i, j;
  struct Node **baldes;

  //Crie baldes/caçambas e aloque o tamanho da memória
  baldes = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // inicia caçambas vazias
  for (i = 0; i < NBUCKET; ++i) {
    baldes[i] = NULL;
  }

  // preenche as caçambas com os elementos
  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getBaldeIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = baldes[pos];
    baldes[pos] = current;
  }

  // imprima as caçambas juntos com seus elementos
  for (i = 0; i < NBUCKET; i++) {
    printf("Baldes[%d]: ", i);
    impcacambas(baldes[i]);
    printf("\n");
  }

  // Ordena os elementos de cada caçamba
  for (i = 0; i < NBUCKET; ++i) {
    baldes[i] = InsertionSort(baldes[i]);
  }

  printf("-------------\n");
  printf("Baldes após a tiragem\n");
  for (i = 0; i < NBUCKET; i++) {
    printf("Baldes[%d]: ", i);
    impcacambas(baldes[i]);
    printf("\n");
  }

  // coloca os elementos ordenados
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = baldes[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

// Função que encontrei para ordenar os elementos de cada balde
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBaldeIndex(int value) {
  return value / INTERVAL;
}

void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// imprime as caçambas
void impcacambas(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

// Driver code
int main(void) {
  int array[NARRAY] = {42, 32, 33, 52, 37, 47, 51};

  printf("Matriz inicial: ");
  print(array);
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Matriz Classificada: ");
  print(array);
  return 0;
}