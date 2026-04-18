#pragma once
#include "ABettingStrategy.h"

/*
 * @brief Lưu trữ kết quả của một ván chơi
 *
 * Mỗi RoundRecord được tạo ra sau khi Table::play() hoàn tất một ván.
 * Danh sách các record được dùng để xuất CSV và phân tích chiến thuật.
 */
struct RoundRecord {
    Bet       bet;              /* Cược đặt trong ván đó (cửa Tài/Xỉu và số tiền) */
    BetResult result;           /* Kết quả ván: Win hoặc Lose */
    double    dCurrentBankroll; /* Số dư của người chơi sau khi ván kết thúc */
};
