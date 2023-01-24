#include <iostream>
#include "Style.h"
#include "File.h"
#include "MovieTicketSystem.h"

using namespace std;

MovieTicketSystem movieTicketSystem;

int main()
{
    cout << "\033c";
    cout << Style::getRedColor( Style::getBold("--------------- WELCOME TO MOVIES TICKET BOOKING SYSTEM ---------------\n") ) << endl;

    int chooseMenu = 0;

    cout << "1. BOOKING TICKET" << endl;
    cout << "2. BOOKING LIST" << endl;
    cout << "3. LOGOUT" << endl;

    while (true) {
    
        cout << "\nCHOOSE MENU: ";
        cin >> chooseMenu;

        switch(chooseMenu) {
            case 1: 
                movieTicketSystem.bookingTicket();
            break;

            case 2:
                movieTicketSystem.bookingList();
            break;

            case 3:
            cout << Style::getRedColor( Style::getBold("\nLOGOUT...") ) << endl;
            return 0;
            break;

            default:
            cout << "CHOOSE MENU IS INVALID" << endl;
        }
    }

    return 0;
}