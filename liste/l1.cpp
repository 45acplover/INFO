#include <iostream>
using namespace std;

// Struttura del nodo
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Inserimento in testa
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Inserimento in coda
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Eliminazione di un nodo
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Ricerca di un nodo
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Visualizzazione della lista
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Conteggio nodi senza contatore interno
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Rimozione duplicati da lista non ordinata
    void removeDuplicates() {
        Node* current = head;
        while (current) {
            Node* runner = current;
            while (runner->next) {
                if (runner->next->data == current->data) {
                    Node* toDelete = runner->next;
                    runner->next = runner->next->next;
                    delete toDelete;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtHead(30);
    list.insertAtTail(20);
    list.insertAtTail(40);
    
    cout << "Lista iniziale: ";
    list.display();
    
    cout << "Numero di nodi: " << list.countNodes() << endl;
    
    list.removeDuplicates();
    cout << "Lista dopo rimozione duplicati: ";
    list.display();
    
    return 0;
}