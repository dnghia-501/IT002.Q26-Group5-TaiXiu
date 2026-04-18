#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/*
 * @brief Khởi tạo CSVExporter với tên file đầu ra
 * @param filename Tên file CSV cần ghi
 */
CSVExporter::CSVExporter(const string& filename) : sFilename(filename) {}

/*
 * @brief Ghi toàn bộ danh sách kết quả các ván chơi ra file CSV
 *
 * Format mỗi dòng: Bet Side, Bet Amount, Result, Current Bankroll
 * Nếu không mở được file thì thoát im lặng.
 *
 * @param records Danh sách RoundRecord chứa thông tin từng ván
 */
void CSVExporter::exportToCSV(const vector<RoundRecord>& records) {
    ofstream file(sFilename);
    if (!file.is_open()) {
        return;
    }

    // Header
    file << "Bet Side,Bet Amount,Result,Current Bankroll\n";

    for (const auto& record : records) {
        file << (record.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << record.bet.dAmount                                  << ","
             << (record.result == BetResult::Win ? "Win" : "Lose") << ","
             << record.dCurrentBankroll                             << "\n";
    }

    file.close();
}
