#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "TicketOrder.h"

using namespace std;

int TicketOrder::AgeCalculation() {
    //주민번호로부터 추출
    // 1-6번째 자리 추출
    std::string first_six_digits = input_num.substr(0, 6);

    // 7번째 자리 추출
    std::string seventh_digit = input_num.substr(6, 1);

    //std::cout << "1-6번째 자리: " << first_six_digits << std::endl;
    //std::cout << "7번째 자리: " << seventh_digit << std::endl;


    //int로 변환 std::stoi
    int age_calc_1to6 = stoi(first_six_digits);
    int age_calc_7th = stoi(seventh_digit); //남녀,연도계산1 2 3 4  if age_calc_7th == 1 || age_calc_7th == 

    // 현재 시간 얻기
    std::time_t now = std::time(nullptr);

    // std::time_t 형식의 현재 시간을 std::tm 구조체로 변환
    std::tm* local_time = std::localtime(&now);

    // 년도, 월, 일에 해당하는 부분을 추출하여 문자열로 만들기
    std::stringstream ss;
    ss << std::put_time(local_time, "%Y%m%d"); // YYYYMMDD 형식으로 출력
    std::string date_str = ss.str();

    // 뒤의 yyMMdd 부분만 잘라내기
    std::string yyMMdd = date_str.substr(2);

    // int로 변환
    int yyMMdd_int = std::stoi(yyMMdd);

    // 결과 출력
    //std::cout << "yyMMdd: " << yyMMdd << std::endl;
    //std::cout << "yyMMdd (int): " << yyMMdd_int << std::endl;

    if (age_calc_7th == 1 || age_calc_7th == 2) {
        age_yyMMdd = 1000000 + yyMMdd_int - age_calc_1to6;

    }
    else if (age_calc_7th == 3 || age_calc_7th == 4) {
        age_yyMMdd = yyMMdd_int - age_calc_1to6;
    }

    //age_yyMMDD -> age_yy 형태로 변환
    std::string age_yy_str = std::to_string(age_yyMMdd).substr(0, 2); // 년도 부분만 추출

    int age_yy = std::stoi(age_yy_str); // int로 변환

    std::cout << "나이: " << age_yy << std::endl;

    //age_yy 범위 지정
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
        if (ticket_price = nighttime_price) {
            if (age_yy >= 0 && age_yy <= 2) {
                ticket_price = nighttime_age_2;
            }
            else if (age_yy > 2 && age_yy <= 12) {
                ticket_price = nighttime_age_12;
            }
            else if (age_yy > 12 && age_yy <= 18) {
                ticket_price = nighttime_age_18;
            }
            else if (age_yy > 18 && age_yy <= 64) {
                ticket_price = nighttime_age_64;
            }
            else if (age_yy > 64) {
                ticket_price = nighttime_age_over;
            }
        }
    }

    return 0;
}




TicketOrder::TicketOrder() {
    cout << "1. 주간권" << endl;
    cout << "2. 야간권" << endl;

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
            cout << "다시 입력하세요" << endl;
        }
    }


    //주민번호 입력
    cout << "주민번호를 입력하세요" << endl;
    for (;;) {
        cin >> input_num;
        if (input_num.length() == 13) {
            //age계산 함수 호출
            TicketOrder::AgeCalculation();
            //cout << "주민번호: " << input_num << endl;
            break;
        }
        else {
            cout << "주민번호를 다시 입력하세요" << endl;
        }
    }


    //주문개수
    cout << "몇 개를 주문하시겠습니까? (최대 10개)" << endl;
    for (;;) {
        cin >> input_num;
        //int로 변환 std::stoi
        amount_ticket = stoi(input_num);

        if (amount_ticket > 0 && amount_ticket < 11) {
            //최종가격 계산   
            total_price = ticket_price * amount_ticket;

            //cout << ticket_price << endl;

            cout << total_price << endl;
            break;
        }
        else {
            cout << "수량을 다시 입력하세요" << endl;
        }
    }


    //우대사항 입력
    cout << "우대사항을 선택하세요" << endl;
    cout << "1. 없음 (나이 우대는 자동 처리" << endl;
    cout << "2. 장애인" << endl;
    cout << "3. 국가유공자" << endl;
    cout << "4. 다자녀" << endl;
    cout << "5. 임산부" << endl;

    for (;;) {
        cin >> input_num;
        if (input_num == "1") {
            cout << "1. 없음 (나이 우대는 자동 처리" << endl;
            //우대사항 함수 
            discount_price = 1.0;
            total_price = total_price * discount_price;
            //cout << total_price << endl;

            break;
        }
        else if (input_num == "2") {
            cout << "2. 장애인" << endl;
            //우대사항 함수
            discount_price = 0.6;
            total_price = total_price * discount_price;
            //cout << total_price << endl;

            break;
        }
        else if (input_num == "3") {
            cout << "3. 국가유공자" << endl;
            //우대사항 함수
            discount_price = 0.5;
            total_price = total_price * discount_price;
            //cout << total_price << endl;

            break;
        }
        else if (input_num == "4") {
            cout << "4. 다자녀" << endl;
            //우대사항 함수
            discount_price = 0.8;
            total_price = total_price * discount_price;
            //cout << total_price << endl;

            break;
        }
        else if (input_num == "5") {
            cout << "5. 임산부" << endl;
            //우대사항 함수
            discount_price = 0.85;
            total_price = total_price * discount_price;
            //cout << total_price << endl;

            break;
        }
        else {
            cout << "다시 입력하세요" << endl;
        }
    }



    //최종 가격은 @@입니다
    cout << "최종 가격은 " << total_price << "원 입니다." << endl;




}