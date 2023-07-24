#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "TicketOrder.h"

using namespace std;

TicketOrder::TicketOrder() {
    cout << "1. 주간권" << endl;
    cout << "2. 야간권" << endl;
    cin >> input_num;

    try {
        if (input_num == 1) {
            ticket_price = daytime_price;
        }
        else if (input_num == 2) {
            ticket_price = nighttime_price;
        }
    } catch (e) {
        cout << "다시 입력하세요" << endl;
        return 0;
    }
}

TicketOrder::TicketOrder(const Ticket& ticket, const Order& order, const Customer& customer)
    : ticket(ticket), order(order), customer(customer) {}

int TicketOrder::calculateTotalPrice() const {
    return ticket.getPrice() * order.getCount();
}

void TicketOrder::printOrderDetails() const {
    std::cout << "Ticket Type: " << ticket.getType() << std::endl;
    std::cout << "Ticket Price: " << ticket.getPrice() << std::endl;
    std::cout << "Order Count: " << order.getCount() << std::endl;
    std::cout << "Customer ID: " << customer.getId() << std::endl;
}