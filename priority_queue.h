// Структура, представляющая очередь с приоритетом
typedef struct {
    int* array;     // Массив элементов
    int capacity;   // Вместимость (максимальное количество элементов)
    int size;       // Текущий размер очереди
} PriorityQueue;

// Создание очереди из N элементов, данные берутся из файла
PriorityQueue* createQueueFromFile(const char* filename);

// Добавление нового элемента в очередь
void addValue(PriorityQueue* queue, int value);

// Удаление элемента с максимальным значением из очереди
void deleteMax(PriorityQueue* queue);

// Удаление элемента с заданным значением из очереди
void deleteSelected(PriorityQueue* queue, int value);

// Поиск элемента с заданным значением в очереди
int search(PriorityQueue* queue, int value);

// Изменение значения выбранного элемента в очереди
void changeSelected(PriorityQueue* queue, int oldValue, int newValue);

void printQueue(PriorityQueue* queue);