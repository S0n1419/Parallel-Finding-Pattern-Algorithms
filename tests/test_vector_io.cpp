#include <exception>
#include <iostream>
#include "source/vector_io.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // Thiết lập UTF-8 để Terminal Windows hiển thị dấu tiếng Việt.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    try {
        // Đọc hai tệp dữ liệu mẫu.
        auto [a, b] = vector_io::read_vector_pair(
            "examples/A.txt",
            "examples/B.txt"
        );

        // Thông báo kết quả và in từng cặp phần tử để kiểm tra.
        std::cout << "Đọc dữ liệu thành công! Kích thước vectơ n = "
                  << a.size() << '\n';
        for (std::size_t i = 0; i < a.size(); ++i) {
            std::cout << "Phần tử thứ " << (i + 1)
                      << ": A[" << i << "] = " << a[i]
                      << ", B[" << i << "] = " << b[i] << '\n';
        }
        return 0;
    } catch (const std::exception& e) {
        // Hiển thị lỗi và kết thúc chương trình nếu dữ liệu không hợp lệ.
        std::cerr << "Lỗi đọc dữ liệu: " << e.what() << '\n';
        return 1;
    }
}
