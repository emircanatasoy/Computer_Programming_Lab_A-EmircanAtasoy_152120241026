#include <iostream>
#include <string>

using namespace std;

struct Node {
    string songTitle;
    Node* next;
};

void addSong(Node*& head, string title) {
    Node* newNode = new Node();
    newNode->songTitle = title;
    newNode->next = head;
    head = newNode;
    cout << "=> \"" << title << "\" playlist'e eklendi!\n";
}

void searchSong(Node* head, string title) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->songTitle == title) {
            cout << "=> \"" << title << "\" playlist'te BULUNDU!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "=> \"" << title << "\" playlist'te BULUNAMADI.\n";
}

void listSongs(Node* head) {
    if (head == nullptr) {
        cout << "=> Playlist su an bos.\n";
        return;
    }
    cout << "\n--- Playlist ---\n";
    Node* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << count << ". " << temp->songTitle << "\n";
        temp = temp->next;
        count++;
    }
    cout << "----------------\n";
}

int main() {
    Node* head = nullptr;
    int choice;
    string songName;

    do {
        cout << "\n=== Music Playlist Menu ===\n";
        cout << "1. Add\n";
        cout << "2. Search\n";
        cout << "3. List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter song title to add: ";
                getline(cin, songName);
                addSong(head, songName);
                break;
            case 2:
                cout << "Enter song title to search: ";
                getline(cin, songName);
                searchSong(head, songName);
                break;
            case 3:
                listSongs(head);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


