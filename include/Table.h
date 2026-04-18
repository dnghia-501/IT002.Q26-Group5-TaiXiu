#pragma once
#include <vector>
#include "Dice.h"
#include "House.h"
#include "Player.h"
#include "RoundRecord.h"

/*
 * @brief Bàn chơi — điều phối một ván Tài Xỉu giữa House và Player
 *
 * Table nhận Player bằng move semantics (Player&&) vì Player chứa
 * unique_ptr nên không thể copy.
 */
class Table {
private:
    std::vector<Dice>        dices;   /* 3 viên xúc xắc */
    House                    house;   /* Nhà cái (giữ luật và số dư) */
    Player                   player;  /* Người chơi */
    std::vector<RoundRecord> records; /* Lịch sử kết quả từng ván */

public:
    /*
     * @brief Khởi tạo bàn chơi
     * @param h House chứa thông số luật chơi
     * @param p Player — truyền bằng move vì Player không copyable
     */
    Table(const House& h, Player&& p);

    /* @brief Chơi 1 ván: tung xúc xắc, tính kết quả, cập nhật balance */
    void play();

    /* @brief Trả về danh sách kết quả tất cả ván đã chơi */
    const std::vector<RoundRecord>& getRecords() const;
};
