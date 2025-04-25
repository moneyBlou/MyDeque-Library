#include "mydeque.h" // Включаем заголовочный файл для доступа к определениям класса

#include <iostream> //  Для вывода содержимого очереди

// Реализация конструктора MyDequeNode
Node::Node(int value) : data(value), prev(nullptr), next(nullptr) {}
// Конструктор узла очереди: инициализирует данные и указатели на nullptr

// Реализация конструктора MyDeque
MyDeque::MyDeque() : head(nullptr), tail(nullptr), size(0) {}
// Конструктор очереди: инициализирует пустую очередь с head и tail равными nullptr, а size = 0

// Реализация деструктора MyDeque
MyDeque::~MyDeque() {
    clearMyDeque();
}
// Деструктор очереди: освобождает память, выделенную для всех узлов в очереди, чтобы избежать утечек памяти

// Реализация isEmpty
bool MyDeque::isEmpty() const {
    return size == 0;
}
// Проверяет, пуста ли очередь: возвращает true, если размер очереди равен 0

// Реализация getSize
int MyDeque::getSize() const {
    return size;
}
// Возвращает текущий размер очереди

// Реализация pushFront
void MyDeque::pushFront(int value) {
    Node* newNode = new Node(value); // Создаем новый узел

    if (isEmpty()) {
        // Если очередь пуста, новый узел становится и головой, и хвостом
        head = newNode;
        tail = newNode;
    } else {
        // Если очередь не пуста, вставляем новый узел в начало
        newNode->next = head;    // Указываем, что следующий узел нового узла - текущая голова
        head->prev = newNode;    // Указываем, что предыдущий узел текущей головы - новый узел
        head = newNode;          // Обновляем голову на новый узел
    }
    size++; // Увеличиваем размер очереди
}
// Добавляет элемент в начало очереди

// Реализация pushBack
void MyDeque::pushBack(int value) {
    Node* newNode = new Node(value); // Создаем новый узел

    if (isEmpty()) {
        // Если очередь пуста, новый узел становится и головой, и хвостом
        head = newNode;
        tail = newNode;
    } else {
        // Если очередь не пуста, вставляем новый узел в конец
        newNode->prev = tail;    // Указываем, что предыдущий узел нового узла - текущий хвост
        tail->next = newNode;    // Указываем, что следующий узел текущего хвоста - новый узел
        tail = newNode;          // Обновляем хвост на новый узел
    }
    size++; // Увеличиваем размер очереди
}
// Добавляет элемент в конец очереди

// Реализация popFront
void MyDeque::popFront() {
    if (isEmpty()) {
        // Бросаем исключение, если очередь пуста
        throw std::out_of_range("popFront() на пустой очереди");
    }

    Node* temp = head; // Сохраняем указатель на удаляемый узел

    if (head == tail) {
        // Если в очереди был только один элемент, обнуляем и голову, и хвост
        head = nullptr;
        tail = nullptr;
    } else {
        // Если в очереди больше одного элемента, удаляем первый элемент
        head = head->next;     // Обновляем голову на следующий узел
        head->prev = nullptr;  // Указываем, что у новой головы нет предыдущего элемента
    }

    delete temp;  // Освобождаем память, выделенную для удаленного узла
    size--;       // Уменьшаем размер очереди
}
// Удаляет элемент из начала очереди

// Реализация popBack
void MyDeque::popBack() {
    if (isEmpty()) {
        // Бросаем исключение, если очередь пуста
        throw std::out_of_range("popBack() на пустой очереди");
    }

    Node* temp = tail; // Сохраняем указатель на удаляемый узел

    if (head == tail) {
        // Если в очереди был только один элемент, обнуляем и голову, и хвост
        head = nullptr;
        tail = nullptr;
    } else {
        // Если в очереди больше одного элемента, удаляем последний элемент
        tail = tail->prev;     // Обновляем хвост на предыдущий узел
        tail->next = nullptr;  // Указываем, что у нового хвоста нет следующего элемента
    }

    delete temp;  // Освобождаем память, выделенную для удаленного узла
    size--;       // Уменьшаем размер очереди
}
// Удаляет элемент из конца очереди

// Реализация getFront
int MyDeque::getFront() const {
    if (isEmpty()) {
        // Бросаем исключение, если очередь пуста
        throw std::out_of_range("getFront() на пустой очереди");
    }
    return head->data; // Возвращаем данные из головы
}
// Возвращает значение первого элемента в очереди

// Реализация getBack
int MyDeque::getBack() const {
    if (isEmpty()) {
        // Бросаем исключение, если очередь пуста
        throw std::out_of_range("getBack() на пустой очереди");
    }
    return tail->data; // Возвращаем данные из хвоста
}
// Возвращает значение последнего элемента в очереди

// Реализация printMyDeque
void MyDeque::printMyDeque() const {
    Node* current = head; // Начинаем с головы очереди
    std::cout << "MyDeque: ";   // Выводим префикс

    while (current != nullptr) {
        // Пока не дошли до конца очереди
        std::cout << current->data << " "; // Выводим данные текущего узла
        current = current->next;           // Переходим к следующему узлу
    }

    std::cout << std::endl; // Выводим перевод строки
}
// Выводит все элементы очереди

// Реализация clearMyDeque
void MyDeque::clearMyDeque() {
    Node* current = head; // Начинаем с головы очереди

    while (current != nullptr) {
        // Пока не дошли до конца очереди
        Node* next = current->next; // Запоминаем следующий узел
        delete current;                    // Освобождаем память, выделенную для текущего узла
        current = next;                    // Переходим к следующему узлу
    }

    // Обнуляем указатели и размер очереди
    head = nullptr;
    tail = nullptr;
    size = 0;
}
// Удаляет все элементы из очереди и освобождает выделенную память
