#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

//�������� ������� �� N ���������, ������ �������� �� �����(������ ������ - ������)
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
    fscanf(file, "%d", &capacity); //������ �������
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->size = 0;

    //������ ��������� ��������
    int value;
    while (fscanf(file, "%d", &value) == 1) {
        queue->array[queue->size++] = value;
    }

    queue->capacity = queue->size; // ���������� ������ �������
    fclose(file);
    return queue;
}

//���������� �������� � �������
void addValue(PriorityQueue* queue, int value) {
    if (queue->size == queue->capacity) {
        // ���� ������� �����, ����������� �� ������
        queue->capacity *= 2;
        queue->array = realloc(queue->array, queue->capacity * sizeof(int));
        if (queue->array == NULL) {
            printf("������: ���������� ��������� ������ �������.\n");
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

    printf("������� %d �������� � �������.\n", value); // ��������� � ���������� ��������
}

//�������� �������� � ������������ ��������� �� �������
void deleteMax(PriorityQueue* queue) {
    if (queue->size == 0) {
        printf("������� �����, ���������� ������� ������������ �������.\n");
        return;
    }

    printf("������� %d ������ �� �������.\n", queue->array[queue->size - 1]);
    queue->size--;
}

//�������� �������� � ������������ ��������� �� �������
void deleteSelected(PriorityQueue* queue, int value) {
    int i = 0;
    while (i < queue->size && queue->array[i] != value) {
        i++;
    }

    if (i == queue->size) {
        printf("������� %d �� ������ � �������.\n", value);
        return;
    }

    printf("������� %d ������ �� �������.\n", value);
    for (int j = i; j < queue->size - 1; j++) {
        queue->array[j] = queue->array[j + 1];
    }

    queue->size--;
}

//����� �������� � ������������ ��������� � �������
int search(PriorityQueue* queue, int value) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->array[i] == value) {
            printf("������� %d ������ � ������� %d � �������.\n", value, i+1);
            return i;
        }
    }
    printf("������� %d �� ������ � �������.\n", value);
    return -1;
}

//��������� �������� ���������� �������� � �������
void changeSelected(PriorityQueue* queue, int oldValue, int newValue) {
    int index = search(queue, oldValue);
    if (index == -1) {
        printf("������� %d �� ������ � �������, ��������� ����������.\n", oldValue);
        return;
    }

    printf("�������� �������� %d �������� �� %d.\n", oldValue, newValue);
    queue->array[index] = newValue;
}

//����� ��������
void printQueue(PriorityQueue* queue) {
    printf("�������: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n\n");
}
