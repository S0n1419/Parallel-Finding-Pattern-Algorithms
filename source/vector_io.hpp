#pragma once

#include <cmath>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace vector_io {

// Đọc một vectơ từ tệp văn bản.
// Định dạng: số đầu tiên là kích thước n (n > 0), theo sau là đúng n giá trị.
// Các giá trị có thể được ngăn cách bằng dấu cách hoặc xuống dòng.
// Ví dụ: 4\n1 2 3 4
inline std::vector<double> read_vector(const std::string& file_path) {
    std::ifstream file(file_path);

    // Kiểm tra tệp có tồn tại và có thể mở được hay không.
    if (!file.is_open()) {
        throw std::runtime_error("Không thể mở tệp dữ liệu: " + file_path);
    }

    // Đọc và kiểm tra kích thước vectơ.
    long long n = 0;
    if (!(file >> n) || n <= 0) {
        throw std::runtime_error("Kích thước vectơ không hợp lệ trong tệp: " + file_path);
    }

    // Đọc lần lượt n phần tử của vectơ.
    std::vector<double> values;
    for (long long i = 0; i < n; ++i) {
        double value = 0.0;
        if (!(file >> value) || !std::isfinite(value)) {
            throw std::runtime_error(
                "Thiếu hoặc sai dữ liệu tại phần tử thứ " +
                std::to_string(i + 1) + " trong tệp: " + file_path
            );
        }
        values.push_back(value);
    }

    // Không cho phép có dữ liệu thừa sau n phần tử.
    std::string extra;
    if (file >> extra) {
        throw std::runtime_error("Tệp chứa nhiều phần tử hơn kích thước đã khai báo: " + file_path);
    }
    if (file.bad()) {
        throw std::runtime_error("Có lỗi khi đọc tệp: " + file_path);
    }

    return values;
}

// Lưu hai vectơ đầu vào của bài toán tích vô hướng.
struct VectorPair {
    std::vector<double> a;
    std::vector<double> b;
};

// Đọc hai vectơ A, B và kiểm tra chúng có cùng số phần tử hay không.
inline VectorPair read_vector_pair(const std::string& path_a,
                                   const std::string& path_b) {
    VectorPair result{read_vector(path_a), read_vector(path_b)};

    // Chỉ có thể tính tích vô hướng khi hai vectơ cùng kích thước.
    if (result.a.size() != result.b.size()) {
        throw std::runtime_error(
            "Kích thước hai vectơ không khớp: A có " +
            std::to_string(result.a.size()) +
            " phần tử, B có " +
            std::to_string(result.b.size()) + " phần tử."
        );
    }

    return result;
}

}  // namespace vector_io
