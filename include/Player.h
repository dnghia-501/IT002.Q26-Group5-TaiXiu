#pragma once
#include <memory>
#include "Actor.h"
#include "ABettingStrategy.h"

/*
 * @brief Người chơi — nắm giữ chiến thuật cược và số dư
 *
 * Player kế thừa Actor để dùng chung dBalance và updateBalance().
 * Chiến thuật được lưu dưới dạng unique_ptr để đa hình (polymorphism).
 *
 * Player không thể copy (vì unique_ptr), nên dùng move constructor
 * khi truyền vào Table.
 */
class Player : public Actor
{
private:
    std::unique_ptr<ABettingStrategy> strategy;   /* Chiến thuật đang dùng */
    Bet                               currentBet; /* Cược của ván hiện tại */

public:
    /* @brief Khởi tạo người chơi với vốn ban đầu */
    Player(double initialBalance);

    /* Move constructor — bắt buộc vì Actor có virtual destructor
       nên compiler không tự sinh move constructor */
    Player(Player&&) = default;

    /* @brief Gán chiến thuật cược cho người chơi */
    void setStrategy(std::unique_ptr<ABettingStrategy> newStrategy);

    /*
     * @brief Tính và cập nhật cược cho ván tiếp theo
     * @param prevResult Kết quả ván vừa chơi (Win/Lose)
     */
    void placeBet(BetResult const& prevResult);

    /* @brief Lấy thông tin cược hiện tại */
    Bet getCurrentBet() const;
};
