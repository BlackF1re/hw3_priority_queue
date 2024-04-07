// ���������, �������������� ������� � �����������
typedef struct {
    int* array;     // ������ ���������
    int capacity;   // ����������� (������������ ���������� ���������)
    int size;       // ������� ������ �������
} PriorityQueue;

// �������� ������� �� N ���������, ������ ������� �� �����
PriorityQueue* createQueueFromFile(const char* filename);

// ���������� ������ �������� � �������
void addValue(PriorityQueue* queue, int value);

// �������� �������� � ������������ ��������� �� �������
void deleteMax(PriorityQueue* queue);

// �������� �������� � �������� ��������� �� �������
void deleteSelected(PriorityQueue* queue, int value);

// ����� �������� � �������� ��������� � �������
int search(PriorityQueue* queue, int value);

// ��������� �������� ���������� �������� � �������
void changeSelected(PriorityQueue* queue, int oldValue, int newValue);

void printQueue(PriorityQueue* queue);