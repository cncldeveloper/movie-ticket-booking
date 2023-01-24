#include "Table.h"
using namespace std;

class MovieTicketSystem
{
private:
    int n;
    int m;
    vector< vector<string> > movieDataMatrix;
    vector< vector<string> > bookingDataMatrix;
    string id;
    string movie;
    string datetime;
    string price;
    string available;
    string customer;
    string mobile;

public:
    MovieTicketSystem() {
        File file1("data/movie-list.csv");
        File file2("data/booking.csv");

        this->movieDataMatrix = file1.getRecords();
        this->bookingDataMatrix = file2.getRecords();
    }

    void bookingTicket() {
        this->movieList();
    }

    void bookingList() {

        cout << "\n" << Style::getBlueColor( Style::getBold("BOOKING LIST") ) << endl << endl;
        int columWidth[] = {8, 30, 15, 35, 25, 15};
        string heading[] = {"ID", "CUSTOMER NAME", "PHONE", "MOVIE NAME", "DATE TIME", "PRICE"};

        Table table;
        table.setColumnWidth(columWidth);
        table.setColumnSize(6);
        table.setHeading(heading);
        table.setData(this->bookingDataMatrix);
        table.show();
    }
private:
    void movieList() {
        cout << "\n" << Style::getBlueColor( Style::getBold("MOVIE LIST") ) << endl << endl;

        int columWidth[] = {8, 35, 25, 15, 25};
        string heading[] = {"ID", "MOVIE NAME", "DATE TIME", "PRICE", "AVAILABLE"};

        Table table;
        table.setColumnWidth(columWidth);
        table.setColumnSize(5);
        table.setHeading(heading);
        table.setData(this->movieDataMatrix);
        table.show();

        cout << "\n";

        char next;

        do {
            this->chooseMovie();
            cout << "\tDO YOU WANT TO NEW BOOKING? [" << Style::getBlueColor( Style::getBold("y/n") ) << "]: ";
            cin >> next;
            cout << "\n";
        } while (next == 'Y' || next == 'y');
    }

    void chooseMovie() {
        int chooseMenu;
        bool notFound = true;

        cout << "SELECT ID: ";
        cin >> chooseMenu;


        for (this->n = 0; this->n < this->movieDataMatrix.size(); n++) {
            if (chooseMenu == stoi(this->movieDataMatrix[this->n][0])) {
                notFound = false;
                this->id = this->movieDataMatrix[this->n][0];
                this->movie = this->movieDataMatrix[this->n][1];
                this->datetime = this->movieDataMatrix[this->n][2];
                this->price = this->movieDataMatrix[this->n][3];
                this->available = this->movieDataMatrix[this->n][4];
                break;
            }
        }

        if (notFound == true) {
            cout << Style::getRedColor( Style::getBold("\tINVALID YOUR SELECTED ID") ) << endl;
        } else {
            cout << Style::getBlueColor( Style::getBold("TICKET DETAILS") ) << endl;

            cout << "\tID            : " << this->id << endl;
            cout << "\tMOVIE         : " << this->movie << endl;
            cout << "\tSHOW TIME     : " << this->datetime << endl;
            cout << "\tPRICE         : " << this->price;
            
            if (stoi(available) == 0) {
                cout << "\tAVILABLE      : " << Style::getRedColor(available) << endl;
                cout << "\n";
                cout << "\t" << Style::getRedColor( Style::getBold("TICKET NOT AVAILABLE") ) << endl;
            } else {
                cout << "\tAVILABLE      : " << Style::getGreenColor(available) << endl;
                this->booking();
            }
        }
    }

    void booking() {
        
        cin.ignore();
        cout << "\n\tCUSTOMER NAME : "; getline(cin, this->customer);
        cout << "\tMOBILE NUMBER : "; getline(cin, this->mobile);

        this->saveBooking();
    }

    string  getSitNumber() {
        this->bookingDataMatrix.size();
    }

    void saveBooking() {
        string record = this->id + ',' + this->customer + ',' + this->mobile + ',' + this->movie + ',' + this->datetime + ',' + this->price;
        File file("data/booking.csv");
        file.setRecord(record);

        cout << "\n";
        cout << "\tSIT NUMBER    : " << Style::getYellowColor(Style::getBold(getSitNumber())) << endl;
        cout << "\t" << Style::getGreenColor( Style::getBold("BOOKING COMPLETED") ) << endl;
    }
};