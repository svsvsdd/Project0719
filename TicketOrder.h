#pragma once
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include "Customer.h"
#include "Order.h"
#include "Ticket.h"

class TicketOrder
{
private:
    Ticket ticket;
    Order order;
    Customer customer;

public:
    TicketOrder();
    int AgeCalculation();
    TicketOrder(const Ticket& ticket, const Order& order, const Customer& customer);

    int calculateTotalPrice() const;
    void printOrderDetails() const;


    int daytime_price,
        nighttime_price, ticket_price, order_time, amount_ticket,
        age, age_yyMMdd, age_yy;
    
    const int 
                
        daytime_age_2 = 0,
        daytime_age_12 = 44000,
        daytime_age_18 = 47000,
        daytime_age_64 = 56000,
        daytime_age_over = 44000,
        nighttime_age_2 = 0,
        nighttime_age_12 = 37000,
        nighttime_age_18 = 40000,
        nighttime_age_64 = 46000,
        nighttime_age_over = 37000;


    float discount_price, total_price;
    std::string input_num, first_six_digits, seventh_digit;
};

