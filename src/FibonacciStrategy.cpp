#include "FibonacciStrategy.h"
#include <cstdlib>

/*
Hàm khởi tạo
*/
FibonacciStrategy::FibonacciStrategy(double baseBet)
{
    this->baseBet = baseBet;
    this->currentIndex = 0;
    /*
    Vị trí đầu tiên trong dãy (hệ số 1)
    */
}

/*
Hàm tính số Fibonacci bằng vòng lặp
*/
int FibonacciStrategy::getFibonacciMultiplier(int n)
{
    if (n <= 0)
        return 1;
    if (n == 1)
        return 1;

    int a = 1, b = 1, c = 2;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

/*
Logic cốt lõi: Tính tiền cược ván tiếp theo
*/
double FibonacciStrategy::calculateNextBetAmount(bool lastBetWon)
{
    if (lastBetWon)
    {
        /*
        Ván trước THẮNG: Lùi lại 2 bước trong dãy số
        */
        currentIndex -= 2;
        if (currentIndex < 0)
        {
            currentIndex = 0;
            /*
            Không được lùi quá vạch xuất phát
            */
        }
    }
    else
    {
        /*
        Ván trước THUA: Tiến lên 1 bước trong dãy số
        */
        currentIndex++;
    }

    /*
    Tiền cược = Tiền gốc * Hệ số Fibonacci ở vị trí hiện tại
    */
    return baseBet * getFibonacciMultiplier(currentIndex);
}

/*
Hàm quyết định chọn cửa Tài hay Xỉu (0 là Xỉu, 1 là Tài)
*/
int FibonacciStrategy::determineBetSide()
{
    return rand() % 2;
}

/*
Hàm reset chiến thuật
*/
void FibonacciStrategy::resetStrategy()
{
    currentIndex = 0;
}