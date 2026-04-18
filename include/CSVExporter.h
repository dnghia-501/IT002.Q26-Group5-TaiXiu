#pragma once
#include <string>
#include <vector>
#include "RoundRecord.h"

/*
 * @brief Xuất danh sách kết quả ván chơi ra file CSV
 *
 * Dùng sFilename thay vì filename để tránh shadow warning
 * khi tên tham số trùng tên member.
 */
class CSVExporter {
    std::string sFilename; /* Đường dẫn file CSV đầu ra */
public:
    /*
     * @brief Khởi tạo với tên file đầu ra
     * @param filename Đường dẫn/tên file CSV cần ghi
     */
    CSVExporter(const std::string& filename);

    /*
     * @brief Ghi toàn bộ danh sách RoundRecord ra file CSV
     * @param records Danh sách kết quả các ván chơi
     */
    void exportToCSV(const std::vector<RoundRecord>& records);
};
