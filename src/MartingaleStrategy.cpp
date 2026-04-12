#include "MartingaleStrategy.h"
#include <cstdlib>
/*
cstdlib: Dùng cho hàm rand()
*/

/*
Cài đặt giá trị ban đầu khi vừa gọi chiến thuật
*/
MartingaleStrategy::MartingaleStrategy(double baseBet)
{
    this->baseBet = baseBet;
    this->currentBet = baseBet;
}

/*
Logic tính tiền cược cho ván tiếp theo
*/
double MartingaleStrategy::calculateNextBetAmount(bool lastBetWon)
{
    if (lastBetWon)
    {
        /*
        Nếu ván trước THẮNG: Đã gỡ vốn thành công, quay về mức cược nhỏ nhất
        */
        currentBet = baseBet;
    }
    else
    {
        /*
        Nếu ván trước THUA: Nhân đôi tiền cược để gỡ lại
        */
        currentBet *= 2;
    }

    return currentBet;
}

/*
Hàm quyết định chọn cửa Tài hay Xỉu
*/
int MartingaleStrategy::determineBetSide()
{
    /*
    Trò chơi được thiết lập tỷ lệ 50/50, việc chọn cửa nào không ảnh hưởng đến xác suất
    Nên ở đây cho phép chọn ngẫu nhiên: 0 (Xỉu) hoặc 1 (Tài)
    */
    return rand() % 2;
}

/*
Hàm reset toàn bộ chiến thuật về trạng thái ban đầu
*/
void MartingaleStrategy::resetStrategy()
{
    currentBet = baseBet;
}