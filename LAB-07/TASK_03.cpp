#include <iostream>
using namespace std;

class Ticket {
protected:
    int id;
    string name;
    double cost;
    string travelDate;
    string place;

public:
    Ticket(int i, string n, double c, string d, string p)
        : id(i), name(n), cost(c), travelDate(d), place(p) {}

    virtual void reserve() {
        cout << "TICKET BOOKED FOR " << name << " TO " << place << " ON " << travelDate << "\n";
    }

    virtual void cancel() {
        cout << "TICKET ID " << id << " HAS BEEN CANCELLED\n";
    }

    virtual void showDetails() {
        cout << "TICKET ID: " << id << "\nPASSENGER: " << name << "\nPRICE: " << cost
             << "\nDATE: " << travelDate << "\nDESTINATION: " << place << "\n";
    }
};

class AirTicket : public Ticket {
    string airline;
    string flightID;
    string classType;

public:
    AirTicket(int i, string n, double c, string d, string p, string a, string f, string cl)
        : Ticket(i, n, c, d, p), airline(a), flightID(f), classType(cl) {}

    void showDetails() override {
        Ticket::showDetails();
        cout << "AIRLINE: " << airline << "\nFLIGHT NO: " << flightID << "\nSEAT CLASS: " << classType << "\n";
    }
};

class RailTicket : public Ticket {
    string trainID;
    string coach;
    string time;

public:
    RailTicket(int i, string n, double c, string d, string p, string t, string co, string tm)
        : Ticket(i, n, c, d, p), trainID(t), coach(co), time(tm) {}

    void reserve() override {
        cout << "AUTO-SEAT ASSIGNED FOR " << name << " ON TRAIN " << trainID << "\n";
    }
};

class BusPass : public Ticket {
    string company;
    int seatNo;

public:
    BusPass(int i, string n, double c, string d, string p, string comp, int seat)
        : Ticket(i, n, c, d, p), company(comp), seatNo(seat) {}

    void cancel() override {
        cout << "BUS TICKET " << id << " CANCELLED WITH LAST-MINUTE REFUND OPTION\n";
    }
};

class ShowTicket : public Ticket {
    string performer;
    string location;
    string seatKind;

public:
    ShowTicket(int i, string n, double c, string d, string p, string art, string loc, string sk)
        : Ticket(i, n, c, d, p), performer(art), location(loc), seatKind(sk) {}

    void showDetails() override {
        Ticket::showDetails();
        cout << "ARTIST: " << performer << "\nVENUE: " << location << "\nSEAT TYPE: " << seatKind << "\n";
    }
};

int main() {
    cout << "\n=== TRAVEL & ENTERTAINMENT BOOKING SYSTEM ===\n\n";

    AirTicket ft(101, "MEHAK NOOR", 86500, "2025-07-20", "ISLAMABAD", "EMIRATES", "EK612", "BUSINESS");
    ft.showDetails();

    RailTicket rt(202, "OMAR JAVAID", 4200, "2025-08-03", "MULTAN", "GR22", "ECONOMY", "07:45 AM");
    rt.reserve();

    BusPass bp(303, "FAIZA TARIQ", 1500, "2025-09-05", "QUETTA", "DAEWOO", 21);
    bp.cancel();

    ShowTicket st(404, "ZARA JAVED", 9000, "2025-10-10", "FAISALABAD", "ALI ZAFAR", "ALHAMRA HALL", "GOLD");
    st.showDetails();

    return 0;
}
