#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* prev;
    Node* next;
};

void addNode(Node** head, string data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void splitList(Node** head, int position)
{
    if (*head == nullptr)
    {
        cout << "Список порожній." << endl;
        return;
    }
    
    Node* current = *head;
    int count = 1;
    while (current != nullptr && count < position)
    {
        current = current->next;
        count++;
    }
    
    if (current == nullptr)
    {
        cout << "Недостатньо елементів у списку." << endl;
        return;
    }

    Node* secondHead = current;
    if (current->prev != nullptr)
    {
        current->prev->next = nullptr;
    }
    current->prev = nullptr;

    cout << "Перший список: ";
    printList(*head);
    cout << "Другий список: ";
    printList(secondHead);
}

int main()
{
    ifstream file("/Users/user/text12_8.txt");
    
    if (!file)
    {
        cerr << "Не вдалося відкрити файл." << endl;
        return 1;
    }
    
    Node* head = nullptr;
    string word;
    
    while (file >> word)
    {
        addNode(&head, word);
    }
    cout << "Створений список: ";
    printList(head);
    
    string searchWord;
    int position;
    
    cout << "Введіть слово: ";
    cin >> searchWord;
    cout << "Введіть порядковий номер: ";
    cin >> position;
    
    splitList(&head, position);

    return 0;
}
