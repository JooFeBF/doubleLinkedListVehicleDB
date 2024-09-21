#include <iostream>
#include <conio.h>

#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27

using namespace std;

struct Node {
  int id;
  string name;
  Node* next;
  Node* prev;
};

void insert(Node* &head, Node* &tail, int id, string name) {
  Node* newNode = new Node;
  newNode->id = id;
  newNode->name = name;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
    head->next = head;
    head->prev = head;
  } else {
    head->next = newNode;
    newNode->prev = head;
    head = newNode;
    newNode->next = tail;
    tail->prev = newNode;
  }
}

void insertNodeByPosition(Node* &head, Node* &tail, int id, string name, int position) {
  Node* newNode = new Node;
  newNode->id = id;
  newNode->name = name;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (tail == NULL) {
    head = newNode;
    tail = newNode;
    head->next = head;
    head->prev = head;
  } else {
    Node* temp = head;
    for (int i = 0; i < position; i++) {
      temp = temp->prev;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
  }
}

void deleteNodeByPosition(Node* &head, Node* &tail, int position) {
  if (tail == NULL) {
    cout << "List is empty" << endl;
  } else {
    Node* temp = tail;
    for (int i = 0; i < position; i++) {
      temp = temp->prev;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
  }
}

void insertNodeAfterById (Node* &head, Node* &tail, int id, string name, int idAfter) {
  Node* newNode = new Node;
  newNode->id = id;
  newNode->name = name;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (tail == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    Node* temp = tail;
    while (temp->id != idAfter && temp != NULL && temp != head) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
  }
}

void deleteNodeAfterById (Node* &head, Node* &tail, int idAfter) {
  if (tail == NULL) {
    cout << "List is empty" << endl;
  } else {
    Node* temp = tail;
    while (temp->id != idAfter && temp != NULL && temp != head) {
      temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    delete temp2;
  }
}

void printListWithKeys(Node* tail) {
  if (tail == NULL) {
    cout << "List is empty" << endl;
  } else {
    Node* temp = tail;
    int key = 0;
    cout << temp->id << " " << temp-> name << endl;
    key = getch();
    while (key != ESC && key != ENTER && temp != NULL) {
      cout << temp->id << " " << temp->name << endl;
      key = getch();
      if (key == UP) {
        temp = temp->next;
      } else if (key == DOWN) {
        temp = temp->prev;
      }
    }
  }
}

int main () {
  Node* tail = NULL;
  Node* head = NULL;

  int option;

  do {
    cout << "1. Insert" << endl;
    cout << "2. Insert by position" << endl;
    cout << "3. Delete by position" << endl;
    cout << "4. Insert after by id" << endl;
    cout << "5. Delete after by id" << endl;
    cout << "6. Print list with keys" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option: ";
    cin >> option;

    switch (option) {
      case 1:
        { int id;
        string name;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        insert(head, tail, id, name);
        break; }
      case 2:
        { int id2;
        string name2;
        int position;
        cout << "Enter id: ";
        cin >> id2;
        cout << "Enter name: ";
        cin >> name2;
        cout << "Enter position: ";
        cin >> position;
        insertNodeByPosition(head, tail, id2, name2, position);
        break; }
      case 3:
        { int position2;
        cout << "Enter position: ";
        cin >> position2;
        deleteNodeByPosition(head, tail, position2);
        break; }
      case 4:
        { int id3;
        string name3;
        int idAfter;
        cout << "Enter id: ";
        cin >> id3;
        cout << "Enter name: ";
        cin >> name3;
        cout << "Enter id after: ";
        cin >> idAfter;
        insertNodeAfterById(head, tail, id3, name3, idAfter);
        break; }
      case 5:
        { int idAfter2;
        cout << "Enter id after: ";
        cin >> idAfter2;
        deleteNodeAfterById(head, tail, idAfter2);
        break; }
      case 6:
        { printListWithKeys(tail);
        break; }
      case 7:
        { cout << "Bye!" << endl;
        break; }
      default:
        { cout << "Invalid option" << endl;
        break; }
    }
  } while (option != 7);

}
