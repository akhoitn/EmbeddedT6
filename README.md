# Embedded-Interview
<details>

## <summary>COMPILER</summary>

Quá trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ mà máy tính có thể hiểu được và quá trình này chia làm 4 giai đoạn:

1. Giai đoạn tiền xử lý (pre-processor): file (.c .h .hpp .cpp) khi đi qua giai đoạn này sẽ biến thành file (.i) (preprocessed source). Tại đây sẽ các source của thư viện include trong main.c sẽ được đem vào, xóa bỏ comment, thay thế các đoạn chương trình, các biến mà marco định nghĩa.
- Cú pháp: gcc -E main.c -o main.i
2. Giai đoạn Compiler: file (.i) khi qua giai đoạn này sẽ thành (.s) (Assembly code). Giai đoạn này sẽ dich ngôn ngữ bậc cao sang ngôn ngữ Assembly (Mỗi vi điều khiển sẽ có cách code Assembly khác nhau, chỉ có 1 số tiêu chuẩn giống nhau, còn lại khác nhiều).
- Cú pháp: gcc main.i -S -o main.s
3. Giai đoạn Assembler: file (.s) sẽ thành (.o/ .obj) và libraries. Giai đoạn này sẽ tạo ra các file hệ thống ( âm thanh, đa phương tiện, icon).
- Cú pháp: gcc -c main.s -o main.o
4. Giai đoạn Linker: file (.o) thành (.exe) (executable). Thực tế file (.exe) là 1 file nén gồm file source, file âm thanh, file hình ảnh, file thư viện nếu ứng dụng đó có. Chủ yếu giai đoạn này sẽ sắp xếp các file trên vào trong 1 file.
<details>

<details>

## <summary>STRUCT_UNION</summary>

### 1. Struct
- Sizeof của Struct bằng tổng các member cộng lại (+ padding nếu có).
- Địa chỉ của Struct sẽ bằng địa chỉ của member đầu tiên và các member còn lại sẽ có địa chỉ riêng của chúng nên chúng có thể lưu giá trị độc lập với nhau.
- Khi nào dùng Struct: Struct cùng một thời điểm ta có thể chọn cùng lúc nhiều member.
- Tùy cách sắp xếp các member trong Struct ta sẽ có sizeof khác nhau, chúng ta nên sắp xếp 1 cách thông minh để không tốn tài nguyên:

   * Đây tiết kiệm tài nguyên.
<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/77714d49-3cae-4862-bf51-9597a67abfdb">
</p> 

   * Đây là lãng phí tài nguyên
<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/271d4a47-36fa-443b-b69f-c42e563a9e5d">
</p> 

### 2. Union
- Sizeof của Union là kích thước của member lớn nhất.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/866bfa76-1864-4724-888e-2d149704a005">
</p> 

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/9b2fc738-255b-4339-8a7c-1c7168855723">
</p> 

- Địa chỉ của Union và các member là dùng chung nên nếu gán giá trị vào thì các member sẽ có giá trị giống nhau.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/0d274e6d-1281-4f41-86f6-b1ddcddb9363">
</p>

- Khi nào dùng Union: Union có rất nhiều member và tại 1 thời điểm mình chỉ sử dụng 1 member trong đó thôi thì ta sẽ dùng Union (ví dụ: Khi mua lap, ta sẽ có nhiều hãng để lựa chọn, nhưng ta chỉ có thể chọn 1 hãng để mua).

</details>