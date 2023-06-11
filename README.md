# Embedded-Interview
<details>

<summary>COMPILER</summary>

Quá trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ mà máy tính có thể hiểu được và quá trình này chia làm 4 giai đoạn:

1. Giai đoạn tiền xử lý (pre-processor): file (.c .h .hpp .cpp) khi đi qua giai đoạn này sẽ biến thành file (.i) (preprocessed source). Tại đây sẽ các source của thư viện include trong main.c sẽ được đem vào, xóa bỏ comment, thay thế các đoạn chương trình, các biến mà marco định nghĩa.
- Cú pháp: gcc -E main.c -o main.i
2. Giai đoạn Compiler: file (.i) khi qua giai đoạn này sẽ thành (.s) (Assembly code). Giai đoạn này sẽ dich ngôn ngữ bậc cao sang ngôn ngữ Assembly (Mỗi vi điều khiển sẽ có cách code Assembly khác nhau, chỉ có 1 số tiêu chuẩn giống nhau, còn lại khác nhiều).
- Cú pháp: gcc main.i -S -o main.s
3. Giai đoạn Assembler: file (.s) sẽ thành (.o/ .obj) và libraries. Giai đoạn này sẽ tạo ra các file hệ thống ( âm thanh, đa phương tiện, icon).
- Cú pháp: gcc -c main.s -o main.o
4. Giai đoạn Linker: file (.o) thành (.exe) (executable). Thực tế file (.exe) là 1 file nén gồm file source, file âm thanh, file hình ảnh, file thư viện nếu ứng dụng đó có. Chủ yếu giai đoạn này sẽ sắp xếp các file trên vào trong 1 file.

</details>