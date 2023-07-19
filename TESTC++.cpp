#include <iostream>
#include <ctime>

using namespace std;

class TicketOrder
{
private:
    const int BABY_PRICE = 0;
    const int ADULT_DAY_PRICE = 56000;
    const int ADULT_NIGHT_PRICE = 46000;
    const int TEEN_DAY_PRICE = 47000;
    const int TEEN_NIGHT_PRICE = 40000;
    const int CHILD_DAY_PRICE = 44000;
    const int CHILD_NIGHT_PRICE = 37000;
    const int OLD_DAY_PRICE = 44000;
    const int OLD_NIGHT_PRICE = 37000;

    const long long int FULL_DIGIT = 10000000000000;
    const long long int FULL_DIGIT_MIN = 10000000000;
    const long long int SEVEN_DIGIT = 1000000;

    const int TWO_DIGIT = 100;
    const int ONE_DIGIT = 10;
    const int OLD_GENERATION = 1900;
    const int NEW_GENERATION = 2000;
    const int MALE_OLD = 1;
    const int FEMALE_OLD = 2;
    const int MALE_NEW = 3;
    const int FEMALE_NEW = 4;
    const int BEFORE_BIRTH = 2;
    const int AFTER_BIRTH = 1;

    const int MIN_BABY = 1;
    const int MIN_CHILD = 3;
    const int MIN_TEEN = 13;
    const int MIN_ADULT = 19;
    const int MAX_CHILD = 12;
    const int MAX_TEEN = 18;
    const int MAX_ADULT = 64;

    const int BABY = 1;
    const int CHILD = 2;
    const int TEEN = 3;
    const int ADULT = 4;
    const int OLD = 5;

    const float DISABLE_DISCOUNT_RATE = 0.6;
    const float MERIT_DISCOUNT_RATE = 0.5;
    const float MULTICHILD_DISCOUNT_RATE = 0.8;
    const float PREGNANT_DISCOUNT_RATE = 0.85;

    const int MAX_COUNT = 10;
    const int MIN_COUNT = 1;

    int totalPrice;
    int position;
    int filePosition;
    int orderList[100][5];

public:
    TicketOrder()
    {
        totalPrice = 0;
        position = 0;
        filePosition = 0;
        memset(orderList, 0, sizeof(orderList));
    }

    void run()
    {
        int isExit = 0;
        do
        {
            while (true)
            {
                int ticketSelect = inputTicketSelect();
                long long int customerIDNumber = inputCustomerIDNumber();
                int orderCount = inputOrderCount();
                int discountSelect = inputDiscountSelect();

                int priceResult = processIntegration(customerIDNumber, ticketSelect, discountSelect, orderCount);
                saveOrderList(ticketSelect, orderCount, priceResult, discountSelect);

                totalPrice += priceResult;

                pricePrint(priceResult);

                int continueSelect = orderContinue();

                if (continueSelect == 2)
                {
                    break;
                }
            }

            orderPrint(totalPrice);
            orderFilePrint(totalPrice);

            cout << "��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����): ";
            cin >> isExit;
            position = 0;
            totalPrice = 0;
        } while (isExit == 1);
    }

private:
    int inputTicketSelect()
    {
        int ticketSelect = 0;

        cout << "������ �����ϼ���." << endl;
        cout << "1. �ְ���" << endl;
        cout << "2. �߰���" << endl;

        while (true)
        {
            cin >> ticketSelect;
            if (ticketSelect == 1 || ticketSelect == 2)
            {
                break;
            }
            else
            {
                errorMessagePrint();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return ticketSelect;
    }

    long long int inputCustomerIDNumber()
    {
        long long int customerIDNumber = 0;

        cout << "�ֹι�ȣ�� �Է��ϼ���: " << endl;
        while (true)
        {
            cin >> customerIDNumber;
            if (customerIDNumber >= FULL_DIGIT_MIN && customerIDNumber < FULL_DIGIT)
            {
                break;
            }
            else
            {
                errorMessagePrint();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return customerIDNumber;
    }

    int inputOrderCount()
    {
        int orderCount = 0;

        cout << "�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)" << endl;
        while (true)
        {
            cin >> orderCount;
            if (orderCount <= MAX_COUNT && orderCount >= MIN_COUNT)
            {
                break;
            }
            else
            {
                errorMessagePrint();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return orderCount;
    }

    int inputDiscountSelect()
    {
        int discountSelect = 0;

        cout << "�������� �����ϼ���." << endl;
        cout << "1. ���� (���� ���� �ڵ�ó��)" << endl;
        cout << "2. �����" << endl;
        cout << "3. ����������" << endl;
        cout << "4. ���ڳ�" << endl;
        cout << "5. �ӻ��" << endl;

        while (true)
        {
            cin >> discountSelect;
            if (discountSelect >= 1 && discountSelect <= 5)
            {
                break;
            }
            else
            {
                errorMessagePrint();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return discountSelect;
    }

    void errorMessagePrint()
    {
        cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
    }

    int calcAge(long long int customerIDNumber)
    {
        // ������� ��� ����
        // ...

        return age;
    }

    int calcPriceProcess(int age, int ticketSelect)
    {
        // ���� ��� ����
        // ...

        return calcPrice;
    }

    int calcDiscount(int calcPrice, int discountSelect)
    {
        // ���� ��� ����
        // ...

        return calcPrice;
    }

    int calcPriceResult(int calcPrice, int orderCount)
    {
        // ���� �ݾ� ��� ����
        // ...

        return priceResult;
    }

    int processIntegration(long long int customerIDNumber, int ticketSelect, int discountSelect, int orderCount)
    {
        int age = calcAge(customerIDNumber);
        int calcPrice = calcPriceProcess(age, ticketSelect);
        int calcPriceWithDiscount = calcDiscount(calcPrice, discountSelect);
        int priceResult = calcPriceResult(calcPriceWithDiscount, orderCount);

        return priceResult;
    }

    void saveOrderList(int ticketSelect, int orderCount, int priceResult, int discountSelect)
    {
        orderList[position][0] = ticketSelect;
        orderList[position][1] = orderCount;
        orderList[position][2] = priceResult;
        orderList[position][3] = discountSelect;
        position++;
    }

    void pricePrint(int priceResult)
    {
        cout << "������ " << priceResult << " �� �Դϴ�." << endl;
        cout << "�����մϴ�." << endl << endl;
    }

    int orderContinue()
    {
        int continueSelect = 0;

        cout << "��� �߱� �Ͻðڽ��ϱ�?" << endl;
        cout << "1. Ƽ�� �߱�" << endl;
        cout << "2. ����" << endl;

        while (true)
        {
            cin >> continueSelect;
            if (continueSelect == 1 || continueSelect == 2)
            {
                break;
            }
            else
            {
                errorMessagePrint();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return continueSelect;
    }

    void orderPrint(int totalPrice)
    {
        cout << "Ƽ�� �߱��� �����մϴ�. �����մϴ�." << endl << endl;
        cout << "==================== �������� ====================" << endl;

        for (int index = 0; index < position; index++)
        {
            switch (orderList[index][0])
            {
            case 1:
                cout << "�ְ��� ";
                break;
            case 2:
                cout << "�߰��� ";
                break;
            default:
                break;
            }

            // ���� ���п� ���� ��� ó��
            // ...

            cout << "X " << orderList[index][1] << " ";
            cout << setw(8) << orderList[index][2] << "��\t";

            switch (orderList[index][3])
            {
            case 1:
                cout << "*������� ����" << endl;
                break;
            case 2:
                cout << "*����� �������" << endl;
                break;
            case 3:
                cout << "*���������� �������" << endl;
                break;
            case 4:
                cout << "*���ڳ� �������" << endl;
                break;
            case 5:
                cout << "*�ӻ�� �������" << endl;
                break;
            default:
                break;
            }
        }

        cout << endl;
        cout << "����� �Ѿ��� " << totalPrice << "�� �Դϴ�." << endl;
        cout << "==================================================" << endl;
        cout << endl;
    }

    void orderFilePrint(int totalPrice)
    {
        // �ֹ� ���� ���� ��� ����
        // ...
    }
};

int main()
{
    TicketOrder ticketOrder;
    ticketOrder.run();

    return 0;
}
