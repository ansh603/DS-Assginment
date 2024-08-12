#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string mobileNumber;
    Contact* next;

    Contact(const string& n, const string& m) 
        : name(n), mobileNumber(m), next(nullptr) {}
};

class ContactList {
private:
    Contact* head;

public:
    ContactList() : head(nullptr) {}

    ~ContactList() {
        Contact* current = head;
        Contact* nextContact;

        while (current != nullptr) {
            nextContact = current->next;
            delete current;
            current = nextContact;
        }
    }

    void addContact(const std::string& name, const std::string& mobileNumber) {
        Contact* newContact = new Contact(name, mobileNumber);
        newContact->next = head;
        head = newContact;
        std::cout << "Contact added: " << name << " - " << mobileNumber << "\n";
    }

    void deleteContact(const string& name) {
        Contact* current = head;
        Contact* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Contact not found: " << name << "\n";
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "Contact deleted: " << name << "\n";
    }

    void displayContacts() const {
        Contact* current = head;
        if (current == nullptr) {
            cout << "Contact list is empty.\n";
            return;
        }

        while (current != nullptr) {
            cout << "Name: " << current->name << ", Mobile: " << current->mobileNumber << "\n";
            current = current->next;
        }
    }

    Contact* searchContact(string& name) const {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                std::cout << "Contact found: " << name << " - " << current->mobileNumber << "\n";
                return current;
            }
            current = current->next;
        }
        cout << "Contact not found: " << name << "\n";
        return nullptr;
    }
};

int main() {
    ContactList contact;
    contact.addContact("Aryamann", "89497");
    contact.addContact("Rohan", "74698");
    contact.addContact("Deepak", "65235");
    cout<<"All contacts are diaplayed"<<endl;
    contact.displayContacts();
    cout<<"Deleting A Contact-Deeoak"<<endl;
    contact.deleteContact("Deepak");
        cout<<"All contacts are diaplayed"<<endl;
    contact.displayContacts();
}