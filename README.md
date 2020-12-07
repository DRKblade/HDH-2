# Đồ án 2: LINUX KERNEL MODULE
Module này sẽ tạo một character device driver để các tiến trình trong userspace đọc số ngẫu nhiên.

## Hướng dẫn sử dụng
1. Trong thư mục này, chạy lệnh `make` để build chương trình.
2. Chạy lệnh `make install` để cài đặt module. Khi đó, có thể đọc file `/dev/rand` dưới dạng nhị phân để nhận số ngẫu nhiên
3. Để chạy chương trình đọc được viết sẵn, chạy `make test` để build.
4. Chạy `./build/test`, chương trình sẽ in ra các số ngẫu nhiên từ module.
