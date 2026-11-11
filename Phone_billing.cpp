#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MobileBill
{
private:
    int customerId;
    string name;
    int callMinutes;
    int sms;
    double dataGB;
    double planCharge;
    double extraCallCharge;
    double smsCharge;
    double dataCharge;
    double totalBill;

public:
    void getDetails()
    {
        cout << "Enter Customer ID: ";
        cin >> customerId;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Monthly Plan Charge: ";
        cin >> planCharge;

        cout << "Enter Extra Call Minutes: ";
        cin >> callMinutes;

        cout << "Enter Number of SMS: ";
        cin >> sms;

        cout << "Enter Extra Data Used (GB): ";
        cin >> dataGB;
    }

    void calculateBill()
    {
        // Extra call charge
        if (callMinutes <= 100)
            extraCallCharge = callMinutes * 0.50;
        else
            extraCallCharge = 100 * 0.50 +
                              (callMinutes - 100) * 0.75;

        // SMS charge
        if (sms <= 100)
            smsCharge = sms * 0.20;
        else
            smsCharge = 100 * 0.20 +
                        (sms - 100) * 0.30;

        // Data charge
        if (dataGB <= 2)
            dataCharge = dataGB * 50;
        else
            dataCharge = 2 * 50 +
                         (dataGB - 2) * 75;

        totalBill = planCharge + extraCallCharge +
                    smsCharge + dataCharge;
    }

    void displayBill()
    {
        cout << fixed << setprecision(2);

        cout << "\n===== MOBILE BILL =====\n";
        cout << "Customer ID       : " << customerId << endl;
        cout << "Customer Name     : " << name << endl;
        cout << "Plan Charge       : Rs. " << planCharge << endl;
        cout << "Extra Call Charge : Rs. " << extraCallCharge << endl;
        cout << "SMS Charge        : Rs. " << smsCharge << endl;
        cout << "Data Charge       : Rs. " << dataCharge << endl;
        cout << "-----------------------------\n";
        cout << "Total Bill        : Rs. " << totalBill << endl;
    }
};

int main()
{
    MobileBill m;

    m.getDetails();
    m.calculateBill();
    m.displayBill();

    return 0;
}
