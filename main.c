#include <stdio.h>
#include "priority_queue.h"

int main() {
    SetConsoleOutputCP(1251);
    PriorityQueue* queue;

    // Создание очереди из файла
    queue = createQueueFromFile("input.txt");

    if (queue == NULL) {
        printf("Не удалось создать очередь из файла.\n");
        return 1;
    }
    printQueue(queue);

    addValue(queue, 10);
    addValue(queue, 20);
    addValue(queue, 5);
    printQueue(queue);

    deleteMax(queue);
    deleteSelected(queue, 20);
    printQueue(queue);

    search(queue, 20);
    printQueue(queue);

    changeSelected(queue, 10, 15);
    printQueue(queue);

    free(queue->array);
    free(queue);

    return 0;
}
