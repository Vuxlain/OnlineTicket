#include <iostream>
using namespace std;

int i = 0;
void addArr(string ticket, string arr[]) {
    arr[i] = ticket;
    i++;
}
void printArr(string arr[]) {
    for (int i = 0;i < 5;i++) {
        cout << arr[i];
    }
}

class Bus {
protected:
    string city1;
    string city2;
    string time;
    string seatNum;
    string date;
public:
    Bus();
    Bus(string city11, string city22,string date1, string time1, string seatNum1);
    ~Bus();
    string toString();
    friend class Ticket;
    friend class Plane;
};
Bus::Bus() {

};

Bus::Bus(string city11, string city22,string date1, string time1, string seatNum1) {
    city1 = city11;
    city2 = city22;
    date = date1;
    time = time1;
    seatNum = seatNum1;
}
Bus::~Bus() {

};
string Bus::toString() {
    return "\nNereden: " + city1 + "\nNereye: " + city2 + "\nTarih: "+date + "\nKalkis saati: " + time + "\nKoltuk numarasi: " + seatNum + "\n";
}
class Plane {
protected:
    string city1;
    string city2;
    string time;
    string seatNum;
    string date;
public:
    Plane();
    Plane(string city11, string city22, string date1, string time1, string seatNum1);
    ~Plane();
    string toString();
    friend class Ticket;
    friend class Bus;
};
Plane::Plane() {

};

Plane::Plane(string city11, string city22, string date1, string time1, string seatNum1) {
    city1 = city11;
    city2 = city22;
    date = date1;
    time = time1;
    seatNum = seatNum1;
}
Plane::~Plane() {

}
string Plane::toString() {
    return "\nNereden: " + city1 + "\nNereye: " + city2 + "\nTarih: " + date + "\nKalkis saati: " + time + "\nKoltuk numarasi: " + seatNum + "\n";
}

class Ticket :public Bus, Plane {
protected:
    string name;
    string lastName;


public:
    Ticket();
    Ticket(string name1, string lastName1);
    string myTicket(Bus& b, Plane& p, int& n);
    void buyTicket(Bus& bus);
    void buyTicket(Plane& pl);
    ~Ticket();
    friend void addArr(string ticket, string arr[]);

};
Ticket::Ticket() {

};
Ticket::Ticket(string name1, string lastName1) {
    name = name1;
    lastName = lastName1;
};
Ticket::~Ticket() {

};
void Ticket::buyTicket(Bus& bus) {
    cout << "* Kocaeli - istanbul - Ankara - Trabzon *" << endl;
    cout << "Nereden: " << endl;
    cin >> bus.city1;
    cout << "* Kocaeli - istanbul - Ankara - Trabzon *" << endl;
    cout << "Nereye: " << endl;
    cin >> bus.city2;
    cout << "Bilet Tarihi: "<<endl;
    cin >> bus.date;
    cout << "----------------------------" << endl;
    cout << "1 4 7 10 13 16 19 22 25" << endl;
    cout << "2 5 8 11 14 17 20 23 26" << endl;
    cout << "" << endl;
    cout << "3 6 9 12 15 18 21 24 27" << endl;
    cout << "----------------------------" << endl;
    cout << "Koltuk numarasi: " << endl;
    cin >> bus.seatNum;
    cout << "* 09:00-12:00-18:00-00:00 *" << endl;
    cout << "Hangi saatte: " << endl;
    cin >> bus.time;
}
void Ticket::buyTicket(Plane& pl) {
    cout << "* Kocaeli - istanbul - Ankara - Trabzon *" << endl;
    cout << "Nereden: " << endl;
    cin >> pl.city1;
    cout << "* Kocaeli - istanbul - Ankara - Trabzon *" << endl;
    cout << "Nereye: " << endl;
    cin >> pl.city2;
    cout << "Bilet Tarihi: "<< endl;
    cin >> pl.date;
    cout << "--------------------------------" << endl;
    cout << "1 5 9  13 17 21 25 29 33 37" << endl;
    cout << "2 6 10 14 18 22 26 30 34 38" << endl;
    cout << "" << endl;
    cout << "3 7 11 15 19 23 27 31 35 39" << endl;
    cout << "4 8 12 16 20 24 28 32 36 40" << endl;
    cout << "--------------------------------" << endl;
    cout << "Koltuk numarasi: " << endl;
    cin >> pl.seatNum;
    cout << "* 09:00-12:00-18:00-00:00 *" << endl;
    cout << "Hangi saatte: " << endl;
    cin >> pl.time;
}
string Ticket::myTicket(Bus& b, Plane& p, int& n) {
    if (n == 0) {
        return "Bilet sahibi: " + name + " " + lastName + b.toString();
    }
    else if (n == 1) {
        return "Bilet sahibi: " + name + " " + lastName + p.toString();
    }
}
void Menu(string& name, string& lastName, int& b, string arr[], Bus& m, Plane& p) {

    int n;
    Ticket t(name, lastName);

    cout << "   Yapmak istediginiz islemi seciniz." << endl;
    cout << "1-Bilet Almak." << endl;
    cout << "2-Biletlerim." << endl;
    cout << "0-Cikis." << endl;
    cin >> n;

    switch (n) {
    case 1:
        if (b == 0) {
            t.buyTicket(m);
            addArr(m.toString(), arr);
        }
        else if (b == 1) {
            t.buyTicket(p);
            addArr(p.toString(), arr);
        }
        Menu(name, lastName, b, arr, m, p);
        break;
    case 2:
        printArr(arr);
        Menu(name, lastName, b, arr, m, p);
        break;
    case 3:
        Menu(name, lastName, b, arr, m, p);
        break;
    default:
        cout << "Program Kapaniyor..." << endl;
    }
}


int main()
{
    string arr[5];
    string name, lastName;
    int a, b;
    Bus m;
    Plane p;
    cout << "       Online Otobus Ucak Bileti Satiþ Sistemi" << endl;
    cout << "Isim: " << endl;
    cin >> name;
    cout << "Soyisim: " << endl;
    cin >> lastName;
    cout << "   Yapmak istediginiz islemi seciniz." << endl;
    cout << "1-Otobus Bileti." << endl;
    cout << "2-Ucak Bileti." << endl;
    cin >> a;
    switch (a) {
    case 1:
        b = 0;
        Menu(name, lastName, b, arr, m, p);
        break;
    case 2:
        b = 1;
        Menu(name, lastName, b, arr, m, p);
        break;
    default:
        cout << "Gecersiz Deger.";
    }
}


