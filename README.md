# Embedded-Interview



<details>

## <summary>COMPILER</summary>



Quá trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ mà máy tính có thể hiểu được và quá trình này chia làm 4 giai đoạn:

1. Giai đoạn tiền xử lý (pre-processor): file (.c .h .hpp .cpp) khi đi qua giai đoạn này sẽ biến thành file (.i) (preprocessed source). Tại đây sẽ các source của thư viện include trong main.c sẽ được đem vào, xóa bỏ comment, thay thế các đoạn chương trình, các biến mà marco định nghĩa.
- `Cú pháp: gcc -E main.c -o main.i`
2. Giai đoạn Compiler: file (.i) khi qua giai đoạn này sẽ thành (.s) (Assembly code). Giai đoạn này sẽ dich ngôn ngữ bậc cao sang ngôn ngữ Assembly (Mỗi vi điều khiển sẽ có cách code Assembly khác nhau, chỉ có 1 số tiêu chuẩn giống nhau, còn lại khác nhiều).
- `Cú pháp: gcc main.i -S -o main.s`
3. Giai đoạn Assembler: file (.s) sẽ thành (.o/ .obj) và libraries. Giai đoạn này sẽ tạo ra các file hệ thống ( âm thanh, đa phương tiện, icon).
- `Cú pháp: gcc -c main.s -o main.o`
4. Giai đoạn Linker: file (.o) thành (.exe) (executable). Thực tế file (.exe) là 1 file nén gồm file source, file âm thanh, file hình ảnh, file thư viện nếu ứng dụng đó có. Chủ yếu giai đoạn này sẽ sắp xếp các file trên vào trong 1 file.



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



<details>

## <summary>POINTER</summary>

### 1. Normal Pointer
- Con trỏ bth chỉ trỏ lưu được giá trị của địa chỉ cùng kiểu dữ liệu. 
- Cách khai báo: 
    * Int value = 1; 0x01
    * Int *ptr = 0x01;
    * &value = 0x01;
    * *0x01 = 1;
    * Printf(“Dia chi: %p”, ptr); = printf (“Dia chi: %p”, &a);

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/28436e18-a94e-4255-b248-93bfb4f8a201">
</p>

### 2. Void Pointer
- Có thể trỏ tới tất cả địa chỉ của các đối tượng khác ( khác kiểu dữ liệu).
- Chỉ trỏ tới địa chỉ dữ liệu thôi, mún hiển thị giá trị của đối tượng thì ta phải ép kiểu cùng kiểu với kiểu dữ liệu của đối tượng.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/d2dfeb7f-f3c3-4a46-99b5-f2e510342959">
</p>

### 3. Null Pointer
- Khi ta khai báo 1 con trỏ mà không gán địa chỉ cho nó, nó sẽ trỏ tới 1 địa chỉ rác nào đó. Lúc ta thay đổi giá trị cho nó thì chương trình sẽ bị lỗi.
- Khi nào dùng con trỏ Null: khi ta khai báo 1 con trỏ mà ta ch sử dụng thì ta gán nó bằng Null hoặc khi sử dụng con trỏ xong và không muốn sử dụng nó nữa thì phải gán nó về con trỏ Null.

### 4. Function Pointer
- Là con trỏ trỏ đến vị trí của hàm. Nó có thể trỏ tới những hàm có kiểu trả về là kiểu void và tham số truyền vào của nó là kiểu int int or int char tùy vào hàm trỏ tới.
- Cách khai báo: void (*ptr)(int, int)  

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/6a08e506-b668-4972-af6d-82f43ca8c415">
</p>

### 5. Pointer to Pointer
- Là 1 con trỏ lưu địa chỉ của Pointer khác.
- Kích thước con trỏ phụ thuộc vào kiến thức vi xử lí: máy tính xử dụng vi xử lí 64bit (8byte), 32 bit (4 byte)...

<details>

## <summary>Memory Layout</summary>

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/277d905a-1347-49d5-b917-c6318804c1c5">
</p>

### 1. Text
- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
- Chứa khai báo hằng số trong chương trình (.rodata) (chỉ đọc chứ không cho sửa đổi).
- Khi ta viết chương trình file .hex, nạp cho vi điều khiển, file hex nạp vào bộ nhớ FLASH, khi chương trình chạy sẽ copy chương trình ở bộ nhớ Flash, dán vào bộ nhớ RAM ( lưu ở phân vùng Text)

### 2. Data
- Quyền truy cập là read-write.
- Chứa biến toàn cục or biến static (bao gồm static toàn cục và cục bộ) với giá trị khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình.

### 3. BSS
- Quyền truy cập là read-write.
- Chứa biến toàn cục or biến static (bao gồm static toàn cục và cục bộ) với giá trị khởi tạo bằng không or không khởi tạo.
- Được giải phóng khi kết thúc chương trình. 

### 4. Stack
- Quyền truy cập là read-write.
- Được sử dụng cấp phát cho biến local, input parameter của hàm,…
- Sẽ được giải phóng khi ra khỏi block code/hàm.

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/a5e533e1-a739-4001-b19f-c8055b75521f">
</p>

  - Lưu ý: Khi nào ta chỉ muốn đọc thông tin giá trị truyền vào thì ta dùng khai báo biến, còn ta muốn thay đổi giá trị biến ta truyền vào thì ta dùng khai báo con trỏ.

### 5. Heap
- Quyền truy cập là read-write.
- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,…
- Sẽ được giải phóng khi gọi hàm free,…

### 6. Dynamic & Static Array
####  Static Array:
   <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/8cfd495d-7e83-4e54-ab57-4c1b62fa7e17">  
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/aa23c6af-35ea-479d-b913-7fdc88f18bc7">
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/9068cbb8-3138-42e2-8d6a-a480676decc9">
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/6f50299e-3f3c-4a7d-8bf5-3a9af05e72a9">
  </p>

  - Khi khai báo thì mảng sẽ có kích thước cố định.
  - Bản chất của mảng array là những địa chỉ liền kề với nhau, nên khi có địa chỉ đầu tiên ta sẽ có thể biết những địa chỉ tiếp theo
  - Tùy theo kiểu dữ liệu thì địa chỉ liền kề sẽ khác nhau. Như ví dụ trên: khi kiểu dữ liệu là uint8_t (1 byte) thì các địa chỉ sẽ cách nhau 1 byte, còn uint16_t (2 byte) thì sẽ cách 2 byte,....
#### Dynamic Array:
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/d819920d-779c-47cc-9cb8-730eee8fc323">
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/75a7c3b8-5601-46ee-8829-923be985effe">
  </p>

  - là mảng và kích thước có thể thay đổi được
  - Trả lại địa chỉ đầu tiên được lưu vào con trỏ *array
  - Malloc để tạo mảng, Realloc để thay đổi kích thước mảng.

  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/515fa9d9-05c6-46a3-a579-7c39123ceacf">
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/dc8bd287-6a40-44c9-94dc-22be53a7ca66">
  </p>

  - Giải thích: Static array thì lưu ở Stack nên khi chạy hết ct thì sẽ tự thu hồi vùng nhớ, nên khi gọi lần 2 thì sẽ dùng lại vùng nhớ kia trên RAM. Còn Dynamic array thì lưu trên vùng nhớ Heap, không tự thu hồi vùng nhớ nên khi gọi lại lần 2 thì vùng nhớ kia đã sử dụng rồi nên phải dùng vùng nhớ khác.
  - Do đó khi dùng Dynamic array thì phải nhớ giải phóng vùng nhớ. Dùng free(array) thì sẽ dùng lại được vùng nhớ cũ.
