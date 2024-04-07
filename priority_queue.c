#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

//создание очереди из N элементов, данные читаютс€ из файла(перва€ строка - размер)
PriorityQueue* createQueueFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (queue == NULL) {
        fclose(file);
        return NULL;
    }

    int capacity;
    fscanf(file, "%d", &capacity); //чтение размера
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->size = 0;

    //чтение остальных значений
    int value;
    while (fscanf(file, "%d", &value) == 1) {
        queue->array[queue->size++] = value;
    }

    queue->capacity = queue->size; // ќпредел€ем размер очереди
    fclose(file);
    return queue;
}

//добавление элемента в очередь
void addValue(PriorityQueue* queue, int value) {
    if (queue->size == queue->capacity) {
        // ≈сли очередь полна, увеличиваем ее размер
        queue->capacity *= 2;
        queue->array = realloc(queue->array, queue->capacity * sizeof(int));
        if (queue->array == NULL) {
            printf("ќшибка: невозможно увеличить размер очереди.\n");
            return;
        }
    }

    int i = queue->size - 1;
    while (i >= 0 && queue->array[i] > value) {
        queue->array[i + 1] = queue->array[i];
        i--;
    }

    queue->array[i + 1] = value;
    queue->size++;

    printf("Ёлемент %d добавлен в очередь.\n", value); // —ообщение о добавлении элемента
}

//удаление элемента с максимальным значением из очереди
void deleteMax(PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("ќчередь пуста, невозможно удалить максимальный элемент.\n");
        return;
    }

    printf("Ёлемент %d удален из очереди.\n", queue->array[queue->size - 1]);
    queue->size--;
}

//удаление элемента с определенным значением из очереди
void deleteSelected(PriorityQueue* queue, int value) {
    int i = 0;
    while (i < queue->size && queue->array[i] != value) {
        i++;
    }

    if (i == queue->size) {
        printf("Ёлемент %d не найден в очереди.\n", value);
        return;
    }

    printf("Ёлемент %d удален из очереди.\n", value);
    for (int j = i; j < queue->size - 1; j++) {
        queue->array[j] = queue->array[j + 1];
    }

    queue->size--;
}

//поиск элемента с определенным значением в очереди
int search(PriorityQueue* queue, int value) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->array[i] == value) {
            printf("Ёлемент %d найден в позиции %d в очереди.\n", value, i+1);
            return i;
        }
    }
    printf("Ёлемент %d не найден в очереди.\n", value);
    return -1;
}

//изменение значени€ выбранного элемента в очереди
void changeSelected(PriorityQueue* queue, int oldValue, int newValue) {
    int index = search(queue, oldValue);
    if (index == -1) {
        printf("Ёлемент %d не найден в очереди, изменение невозможно.\n", oldValue);
        return;
    }

    printf("«начение элемента %d изменено на %d.\n", oldValue, newValue);
    queue->array[index] = newValue;
}

//вывод оччереди
void printQueue(PriorityQueue* queue) {
    printf("ќчередь: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n\n");
}
