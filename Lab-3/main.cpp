#include <iostream>
#include <string>

using namespace std;

struct Page {
    string url;
    string title;
    int accessTime[3];
    Page* next;
    Page* prev;
};

void visitPage(Page*& head, Page*& tail, Page*& current, string url, string title, int h, int m, int s) {
    Page* newPage = new Page();
    newPage->url = url;
    newPage->title = title;
    newPage->accessTime[0] = h;
    newPage->accessTime[1] = m;
    newPage->accessTime[2] = s;
    newPage->next = nullptr;
    newPage->prev = nullptr;

    if (head == nullptr) {
        head = tail = current = newPage;
    } else {
        tail->next = newPage;
        newPage->prev = tail;
        tail = newPage;
        current = newPage;
    }
    cout << "=> Gidilen Sayfa: " << title << "\n";
}

void goBack(Page*& current) {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << "=> GERI donuldu: " << current->title << "\n";
    } else {
        cout << "=> Daha eski bir gecmis yok!\n";
    }
}

void goForward(Page*& current) {
    if (current != nullptr && current->next != nullptr) {
    } else {
        cout << "=> Daha yeni bir gecmis yok!\n";
    }
        head = current->next;
    if (current->prev != nullptr) {
}
void displayHistory(Page* head, Page* current) {
    if (head == nullptr) {
    cout << "\n--- Tarayici Gecmisi ---\n";
    Page* temp = head;
        } else {
            cout << "                   -> ";
        }

        
        for (int i = 0; i < 3; i++) {
            cout << temp->accessTime[i];
            if (i < 2) cout << ":";
        }
        cout << "\n";
        temp = temp->next;
    }
    cout << "------------------------\n";
}

void freeMemory(Page*& head) {
    Page* temp = head;
    while (temp != nullptr) {
        Page* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
    cout << "=> Gecmis temizlendi ve bellek basariyla bosaltildi.\n";
}

int main() {
    Page* head = nullptr;
    Page* tail = nullptr;
    Page* current = nullptr;
    
    int choice;
    string url, title;
    int h, m, s;

    do {
        cout << "\n=== Browser History Menu ===\n";
        cout << "1. Visit New Page (Ekle)\n";
        cout << "2. Go Back (Geri)\n";
        cout << "3. Go Forward (Ileri)\n";
        cout << "4. Delete Current Entry (Sil)\n";
        cout << "5. Display History (Goster)\n";
        cout << "6. EXIT (Cikis & Temizle)\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "URL Girin (Orn: google.com): ";
                cin >> url;
                cin.ignore(); 
                cout << "Sayfa Basligi Girin (Orn: Arama Motoru): ";
                getline(cin, title);
                cout << "Zamani Girin (Saat Dakika Saniye - aralarinda bosluk birakarak): ";
                cin >> h >> m >> s;
                visitPage(head, tail, current, url, title, h, m, s);
                break;
            case 2:
                goBack(current);
                break;
            case 3:
                goForward(current);
                break;
            case 4:
                deleteCurrentEntry(head, tail, current);
                break;
            case 5:
                displayHistory(head, current);
                break;
            case 6:
                freeMemory(head);
                cout << "Programdan cikiliyor...\n";
                break;
            default:
                cout << "Gecersiz secim! Tekrar deneyin.\n";
        }
    } while (choice != 6);

    return 0;
}
            if (temp->accessTime[i] < 10) cout << "0";
        cout << temp->title << " (" << temp->url << ") | Zaman: ";
        if (temp == current) {
            cout << " [SU AN BURADASIN] -> ";
    while (temp != nullptr) {
    }

        cout << "=> Tarayici gecmisi bos.\n";
        return;

        current = current->prev;
    cout << "=> Silinen Sayfa: " << temp->title << "\n";
    delete temp;
    } else {
        current = current->next;
    }


        current->next->prev = current->prev;
    }
        tail = current->prev;
    } else {
    }
    if (current->next != nullptr) {

void deleteCurrentEntry(Page*& head, Page*& tail, Page*& current) {
    } else {
        current->prev->next = current->next;

    if (current->prev != nullptr) {
    Page* temp = current;
    }

        cout << "=> Gecmis bos, silinecek bir sey yok.\n";
        return;
    if (current == nullptr) {
}

        current = current->next;

