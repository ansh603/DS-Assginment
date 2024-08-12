#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    int getLength() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void addAtBeg(char x) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }

    void append(char x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }

    void addAtPOS(char x, int pos) {
        if (pos == 0) {
            addAtBeg(x);
            return;
        }

        Node* new_node = new Node(x);
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void displayMORE() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << ", Value: " << current->data 
                 << ", Next Address: " << current->next << endl;
            current = current->next;
        }
    }

    void removeFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeLast() {
        if (head == nullptr)
            return;

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
        if (pos == 0) {
            removeFirst();
            return;
        }

        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            current = current->next;
        }

        Node* temp = current->next;
        if (temp != nullptr) {
            current->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList ll;
    ll.addAtBeg('a');
    ll.append('b');
    ll.append('c');
    ll.addAtPOS('d', 1);
    ll.display();         // Output: a -> d -> b -> c -> NULL
    ll.displayMORE();     // Output: Address, Value and Next Address details
    ll.removeFirst();
    ll.display();         // Output: d -> b -> c -> NULL
    ll.removeLast();
    ll.display();         // Output: d -> b -> NULL
    ll.removePOS(0);
    ll.display();         // Output: b -> NULL

    return 0;
}