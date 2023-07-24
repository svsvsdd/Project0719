#pragma once
#include "Ticket.h"
#include "Order.h"
#include "Customer.h"

class TicketOrder
{
private:
	Ticket ticket;
	Order order;
	Customer customer;

public:
	TicketOrder();
	TicketOrder(const Ticket& ticket, const Order& order, const Customer& customer);

	int calculateTotalPrice() const;
	void printOrderDetails() const;


	int input_num,
		ticket_price, order_time, discount_price, amount_ticket, total_price;
};

