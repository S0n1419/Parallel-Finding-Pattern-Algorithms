# Parallel Finding Pattern Algorithms

## Yêu cầu

- CMake 3.16 trở lên
- MSYS2 MinGW-w64 UCRT64 với `g++` và `mingw32-make`
- GCC có hỗ trợ OpenMP

Đảm bảo CMake và `C:\msys64\ucrt64\bin` đã có trong `PATH`. Nếu cài MSYS2 ở vị trí khác, hãy thay đường dẫn `g++` trong lệnh bên dưới cho phù hợp.

## Cấu hình và biên dịch trên Windows

Mở PowerShell tại thư mục gốc của dự án, sau đó chạy:

```powershell
cmake -S . -B build-mingw -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER="C:\msys64\ucrt64\bin\g++.exe"
cmake --build build-mingw
```

CMake sẽ cấu hình trình biên dịch và kiểm tra OpenMP. Nếu cấu hình hoặc biên dịch thành công, chương trình `main` sẽ nằm tại `build-mingw\main.exe`.

## Chạy chương trình

Từ thư mục gốc của dự án:

```powershell
.\build-mingw\main.exe
```

Sau khi thay đổi mã nguồn, biên dịch lại bằng `cmake --build build-mingw`. Nếu đổi trình biên dịch hoặc generator, hãy cấu hình vào một thư mục build mới vì CMake lưu lựa chọn đó trong cache.

## Thanh vien nhom

- Nghiem Hanh (NghiemHanh061105)
