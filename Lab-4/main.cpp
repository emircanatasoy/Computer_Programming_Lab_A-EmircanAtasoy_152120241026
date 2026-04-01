#include <iostream>
#include <string>

using namespace std;

struct MoneyBundle {
    string serialNumber;
    string currencyType;
    int billCounts[3];
    MoneyBundle* next;
};

struct Customer {
    string customerName;
    string transactionType;
};

const int MAX_CUSTOMERS = 5;
Customer customerQueue[MAX_CUSTOMERS];
int qFront = -1;
int qRear = -1;
int qCount = 0;

MoneyBundle* stackTop = nullptr;

void receiveMoney(string serial, string currency, int b100, int b50, int b20) {
    MoneyBundle* newBundle = new MoneyBundle();
    newBundle->serialNumber = serial;
    newBundle->currencyType = currency;
    newBundle->billCounts[0] = b100;
    newBundle->billCounts[1] = b50;
    newBundle->billCounts[2] = b20;
    
    newBundle->next = stackTop;
    stackTop = newBundle;
    cout << "=> Kasa: Yeni para destesi eklendi (" << serial << ").\n";
}

void newCustomer(string name, string type) {
    if (qCount == MAX_CUSTOMERS) {
        cout << "=> Hata: Bekleme salonu dolu! Yeni musteri alinamiyor.\n";
        return;
    }
    
    if (qFront == -1) qFront = 0;
    
    qRear = (qRear + 1) % MAX_CUSTOMERS;
    customerQueue[qRear].customerName = name;
    customerQueue[qRear].transactionType = type;
    qCount++;
    
    cout << "=> Sira: " << name << " siraya eklendi.\n";
}

void processTransaction() {
    if (qCount == 0) {
        cout << "=> Islem yapilamadi: Sirada musteri yok!\n";
        return;
    }
    if (stackTop == nullptr) {
        cout << "=> Islem yapilamadi: Kasada para destesi kalmadi!\n";
        return;
    }
    
    Customer currentCustomer = customerQueue[qFront];
    MoneyBundle* currentMoney = stackTop;
    
    cout << "\n--- ISLEM GERCEKLESIYOR ---\n";
    cout << "Musteri: " << currentCustomer.customerName << " (" << currentCustomer.transactionType << ")\n";
    cout << "Kullanilan Para Destesi Seri No: " << currentMoney->serialNumber << " (" << currentMoney->currencyType << ")\n";
    cout << "Banknotlar -> 100'luk: " << currentMoney->billCounts[0] << ", 50'lik: " << currentMoney->billCounts[1] << ", 20'lik: " << currentMoney->billCounts[2] << "\n";
    cout << "---------------------------\n";
    qCount--;
    if (qCount == 0) {
        qFront = -1;
        qRear = -1;
    
    stackTop = stackTop->next;
    delete currentMoney;
}
void display() {
    cout << "\n=== KASA (Para Yigini - Stack) ===\n";
    if (stackTop == nullptr) {
        cout << "Kasa bos.\n";
        MoneyBundle* temp = stackTop;
        while (temp != nullptr) {
            cout << "[Seri: " << temp->serialNumber << " | Tur: " << temp->currencyType << "] -> ";
            temp = temp->next;
        cout << "NULL\n";
    }
    
    cout << "\n=== BEKLEME SALONU (Musteri Sirasi - Circular Queue) ===\n";
    if (qCount == 0) {
        cout << "Sira bos.\n";
    } else {
        for (int i = 0; i < qCount; i++) {
            cout << (i + 1) << ". " << customerQueue[index].customerName << " (" << customerQueue[index].transactionType << ")\n";
        }
    }
    cout << "========================================================\n\n";
}
void freeMemory() {
    while (stackTop != nullptr) {
        MoneyBundle* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }
}

int main() {
    int choice;
    string name, type, serial, currency;
    int b100, b50, b20;

    do {
        cout << "\n--- Banka Yonetim Sistemi ---\n";
        cout << "1. Kasaya Para Ekle (Push)\n";
        cout << "2. Yeni Musteri Ekle (Enqueue)\n";
        cout << "3. Islem Gerceklestir (Pop & Dequeue)\n";
        cout << "4. Durumu Goster (Display)\n";
        cout << "5. Cikis\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Seri No: ";
                cin >> serial;
                cout << "Para Turu (TL/USD vb.): ";
                cin >> currency;
                cout << "100'luk, 50'lik ve 20'lik banknot adetlerini aralikli girin: ";
                cin >> b100 >> b50 >> b20;
                receiveMoney(serial, currency, b100, b50, b20);
                break;
            case 2:
                cout << "Musteri Adi: ";
                cin.ignore();
                getline(cin, name);
                cout << "Islem Turu (Orn: Deposit/Withdraw): ";
                cin >> type;
                newCustomer(name, type);
                break;
            case 3:
                processTransaction();
                break;
            case 4:
                display();
                break;
            case 5:
                freeMemory();
                cout << "Sistem kapaniyor...\n";
                break;
            default:
                cout << "Gecersiz secim!\n";
        }
    } while (choice != 5);

    return 0;
}        cout << "Seciminiz: ";

            int index = (qFront + i) % MAX_CUSTOMERS;
        }
    } else {

    }
    

 
 
