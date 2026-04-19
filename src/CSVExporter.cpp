#include "../include/CSVExporter.h"
#include <fstream>

using namespace std;

/* QA: try wording again*/
/*
 * @brief Khởi tạo CSVExporter với tên file đầu ra
 *
 * @param filename Tên file CSV cần ghi
 */
CSVExporter::CSVExporter(const string &filename) : sFilename(filename) {}

/* QA: try wording again */
/*
 * @brief Ghi toàn bộ danh sách kết quả các ván chơi ra file CSV
 *
 * @param records Danh sách RoundRecord chứa thông tin từng ván
 */
void CSVExporter::exportToCSV(const vector<RoundRecord> &records) {
    ofstream file(sFilename);
    if (!file.is_open()) {
        return;
    }

    /*
     * QA: avoid space in each column's name
     * QA: add explanation for each column's name
     * */
    file << "Bet Side,Bet Amount,Result,Current Bankroll\n";

    for (const auto &record : records) {
        file << (record.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << record.bet.dAmount << ","
             << (record.result == BetResult::Win ? "Win" : "Lose") << ","
             << record.dCurrentBankroll << "\n";
    }

    file.close();
}
