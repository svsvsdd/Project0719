#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;


class Customer
{
    int resident_number, age;
    float discount_price;
};




class Ticket
{
    int ticket_price, order_time, discount_price, amount_ticket, total_price;
};


class Order
{
    int order_time;
};










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
        nighttime_price,

        ticket_price, order_time, amount_ticket,
        age, age_yyMMdd, age_yy,
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

int TicketOrder::AgeCalculation() {
    //�ֹι�ȣ�κ��� ����
    // 1-6��° �ڸ� ����
    std::string first_six_digits = input_num.substr(0, 6);

    // 7��° �ڸ� ����
    std::string seventh_digit = input_num.substr(6, 1);

    std::cout << "1-6��° �ڸ�: " << first_six_digits << std::endl;
    std::cout << "7��° �ڸ�: " << seventh_digit << std::endl;


    //int�� ��ȯ std::stoi
    int age_calc_1to6 = stoi(first_six_digits);
    int age_calc_7th = stoi(seventh_digit); //����,�������1 2 3 4  if age_calc_7th == 1 || age_calc_7th == 

    // ���� �ð� ���
    std::time_t now = std::time(nullptr);

    // std::time_t ������ ���� �ð��� std::tm ����ü�� ��ȯ
    std::tm* local_time = std::localtime(&now);

    // �⵵, ��, �Ͽ� �ش��ϴ� �κ��� �����Ͽ� ���ڿ��� �����
    std::stringstream ss;
    ss << std::put_time(local_time, "%Y%m%d"); // YYYYMMDD �������� ���
    std::string date_str = ss.str();

    // ���� yyMMdd �κи� �߶󳻱�
    std::string yyMMdd = date_str.substr(2);

    // int�� ��ȯ
    int yyMMdd_int = std::stoi(yyMMdd);

    // ��� ���
    std::cout << "yyMMdd: " << yyMMdd << std::endl;
    std::cout << "yyMMdd (int): " << yyMMdd_int << std::endl;

    if (age_calc_7th == 1 || age_calc_7th == 2) {
        age_yyMMdd = 1000000 + yyMMdd_int - age_calc_1to6;

    }
    else if (age_calc_7th == 3 || age_calc_7th == 4) {
        age_yyMMdd = yyMMdd_int - age_calc_1to6;
    }

    //age_yyMMDD -> age_yy ���·� ��ȯ
    std::string age_yy_str = std::to_string(age_yyMMdd).substr(0, 2); // �⵵ �κи� ����

    int age_yy = std::stoi(age_yy_str); // int�� ��ȯ

    std::cout << "age: " << age_yy << std::endl;

    //age_yy ���� ����
    if (ticket_price = daytime_price) {
        if (age_yy >= 0 && age_yy <= 2) {
            ticket_price = daytime_age_2;
        }
        else if (age_yy > 2 && age_yy <= 12) {
            ticket_price = daytime_age_12;
        }
        else if (age_yy > 12 && age_yy <= 18) {
            ticket_price = daytime_age_18;
        }
        else if (age_yy > 18 && age_yy <= 64) {
            ticket_price = daytime_age_64;
        }
        else if (age_yy > 64) {
            ticket_price = daytime_age_over;
        }
    }
    else {
        if (ticket_price = daytime_price) {
            if (age_yy >= 0 && age_yy <= 2) {
                ticket_price = daytime_age_2;
            }
            else if (age_yy > 2 && age_yy <= 12) {
                ticket_price = daytime_age_12;
            }
            else if (age_yy > 12 && age_yy <= 18) {
                ticket_price = daytime_age_18;
            }
            else if (age_yy > 18 && age_yy <= 64) {
                ticket_price = daytime_age_64;
            }
            else if (age_yy > 64) {
                ticket_price = daytime_age_over;
            }
        }
    }

    return 0;
}




TicketOrder::TicketOrder() {
    cout << "1. �ְ���" << endl;
    cout << "2. �߰���" << endl;

    for (;;) {
        cin >> input_num;
        if (input_num == "1") {
            ticket_price = daytime_price;
            break;
        }
        else if (input_num == "2") {
            ticket_price = nighttime_price;
            break;
        }
        else {
            cout << "�ٽ� �Է��ϼ���" << endl;
        }
    }


    //�ֹι�ȣ �Է�
    cout << "�ֹι�ȣ�� �Է��ϼ���" << endl;
    for (;;) {
        cin >> input_num;
        if (input_num.length() == 13) {
            //age��� �Լ� ȣ��
            TicketOrder::AgeCalculation();
            cout << "�ֹι�ȣ: " << input_num << endl;
            break;
        }
        else {
            cout << "�ֹι�ȣ�� �ٽ� �Է��ϼ���" << endl;
        }
    }


    //�ֹ�����
    cout << "�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)" << endl;
    for (;;) {
        cin >> input_num;
        //int�� ��ȯ std::stoi
        amount_ticket = stoi(input_num);

        if (amount_ticket > 0 && amount_ticket < 11) {
            //�������� ���   
            total_price = ticket_price * amount_ticket;

            cout << ticket_price << endl;

            cout << total_price << endl;
            break;
        }
        else {
            cout << "������ �ٽ� �Է��ϼ���" << endl;
        }
    }


    //������ �Է�
    cout << "�������� �����ϼ���" << endl;
    cout << "1. ���� (���� ���� �ڵ� ó��" << endl;
    cout << "2. �����" << endl;
    cout << "3. ����������" << endl;
    cout << "4. ���ڳ�" << endl;
    cout << "5. �ӻ��" << endl;

    for (;;) {
        cin >> input_num;
        if (input_num == "1") {
            cout << "1. ���� (���� ���� �ڵ� ó��" << endl;
            //������ �Լ� 
            discount_price = 1.0;
            total_price = total_price * discount_price;
            cout << total_price << endl;

            break;
        }
        else if (input_num == "2") {
            cout << "2. �����" << endl;
            //������ �Լ�
            discount_price = 0.6;
            total_price = total_price * discount_price;
            cout << total_price << endl;

            break;
        }
        else if (input_num == "3") {
            cout << "3. ����������" << endl;
            //������ �Լ�
            discount_price = 0.5;
            total_price = total_price * discount_price;
            cout << total_price << endl;

            break;
        }
        else if (input_num == "4") {
            cout << "4. ���ڳ�" << endl;
            //������ �Լ�
            discount_price = 0.8;
            total_price = total_price * discount_price;
            cout << total_price << endl;

            break;
        }
        else if (input_num == "5") {
            cout << "5. �ӻ��" << endl;
            //������ �Լ�
            discount_price = 0.85;
            total_price = total_price * discount_price;
            cout << total_price << endl;

            break;
        }
        else {
            cout << "�ٽ� �Է��ϼ���" << endl;
        }
    }



    //���� ������ @@�Դϴ�
    cout << "���� ������ " << total_price << "��" << endl;




}


/*--------------------
*
* class TicketOrder {
private:
    // ��� ���� ����
    Customer customer;
    Ticket ticket;
    Order order;

public:
    // ������
    TicketOrder();

    // �ֹι�ȣ �Է� �� �ʱ�ȭ
    void enterResidentID();

    // ���� ���
    int calculateAge() const;

    // �ְ�/�߰� Ƽ�� ����
    void determineTicketType();

    // �ֹ� ���� ���
    void printOrderDetails() const;

    // �ʿ��� �ٸ� ��� �Լ���...
};




int main() {
    TicketOrder ticketOrder;
    ticketOrder.enterResidentID();
    ticketOrder.calculateAge();
    ticketOrder.determineTicketType();
    ticketOrder.printOrderDetails();

    // �߰����� �۾� ����...

    return 0;
}

---------------------------
*/


int main()
{
    TicketOrder();


}