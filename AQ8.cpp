#include <iostream>
#include <cstring>
using namespace std;


const int MAX_NAME_LENGTH = 100;


struct Node {
    char name[MAX_NAME_LENGTH];
    Node* next;
    
    Node(const char* nameValue) {
        strncpy(name, nameValue, MAX_NAME_LENGTH);
        name[MAX_NAME_LENGTH - 1] = '\0'; 
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        return length;
    }

    
    void addAtBeg(const char* name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    
    void append(const char* name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void addAtPOS(const char* name, int pos) {
        if (pos < 0 || pos > getLength()) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (pos == 0) {
            addAtBeg(name);
        } else {
            Node* newNode = new Node(name);
            Node* current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayMORE() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << ", Name: " << current->name;
            if (current->next != nullptr) {
                cout << ", Next Address: " << current->next;
            } else {
                cout << ", Next Address: nullptr";
            }
            cout << endl;
            current = current->next;
        }
    }


    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    
    void removePOS(int pos) {
        if (pos < 0 || pos >= getLength()) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (pos == 0) {
            removeFirst();
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    
    ~LinkedList() {
        while (head != nullptr) {
            removeFirst();
        }
    }
};

int main() {
    LinkedList list;

    
    list.addAtBeg("Alice");
    list.append("Bob");
    list.append("Charlie");
    list.addAtPOS("Dave", 2);
    cout << "List after adding elements: ";
    list.display();

    cout << "Length of list: " << list.getLength() << endl;

    cout << "Display more (address, name, next address):" << endl;
    list.displayMORE();

    list.removeFirst();
    cout << "List after removing first element: ";
    list.display();

    list.removeLast();
    cout << "List after removing last element: ";
    list.display();

    list.removePOS(1);
    cout << "List after removing element at position 1: ";
    list.display();

    return 0;
}