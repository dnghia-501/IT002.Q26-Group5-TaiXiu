#pragma once
#include "Table.h"
#include "CSVExporter.h"
#include "ABettingStrategy.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>

/*
 * @brief Hàm tạo chiến thuật — trả về một unique_ptr<ABettingStrategy> mới
 *
 * Dùng std::function để mỗi lần gọi factory() tạo ra một object chiến thuật
 * hoàn toàn mới (fresh state), tránh tái sử dụng state giữa các lần chạy.
 */
using StrategyFactory = std::function<std::unique_ptr<ABettingStrategy>()>;

/*
 * @brief Quản lý và chạy mô phỏng nhiều chiến thuật cược
 *
 * Mỗi chiến thuật được chạy độc lập với cùng seed srand(42)
 * để đảm bảo chuỗi xúc xắc giống nhau → so sánh công bằng.
 */
struct SimulationEngine {
    /*
     * @brief Khởi tạo engine mô phỏng
     * @param totalRounds     Số ván cần chạy cho mỗi chiến thuật
     * @param initialBankroll Vốn ban đầu của người chơi
     * @param baseBet         Mức cược tối thiểu
     * @param maxBet          Mức cược tối đa
     */
    SimulationEngine(int totalRounds, double initialBankroll,
                     double baseBet,  double maxBet);

    /*
     * @brief Đăng ký một chiến thuật vào danh sách mô phỏng
     * @param name    Tên chiến thuật (dùng trong CSV output)
     * @param factory Hàm tạo chiến thuật (lambda hoặc function)
     */
    void addStrategy(std::string const& name, StrategyFactory factory);

    /* @brief Chạy toàn bộ mô phỏng — mỗi chiến thuật dùng cùng seed xúc xắc */
    void run();

    /*
     * @brief Xuất kết quả tất cả chiến thuật ra 1 file CSV
     * @param filename Tên file CSV đầu ra
     * @return true nếu xuất thành công
     */
    bool exportCSV(std::string const& filename) const;

private:
    int    totalRounds;
    double initialBankroll;
    double baseBet;
    double maxBet;

    /* Danh sách các chiến thuật đã đăng ký: (tên, factory) */
    std::vector<std::pair<std::string, StrategyFactory>>          strategies;

    /* Kết quả sau khi run(): (tên chiến thuật, danh sách RoundRecord) */
    std::vector<std::pair<std::string, std::vector<RoundRecord>>> results;

    /*
     * @brief Chạy mô phỏng cho 1 chiến thuật
     * @param factory Hàm tạo chiến thuật
     * @return Danh sách RoundRecord của chiến thuật đó
     */
    std::vector<RoundRecord> runOne(StrategyFactory& factory);
};
