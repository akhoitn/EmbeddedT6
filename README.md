# Embedded-Interview

<details>

<summary>COMPILER</summary>
Quá trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ mà máy tính có thể hiểu được và quá trình này chia làm 4 giai đoạn:

1. Giai đoạn tiền xử lý (pre-processor): file (.c .h .hpp .cpp) khi đi qua giai đoạn này sẽ biến thành file (.i) (preprocessed source). Tại đây sẽ các source của thư viện include trong main.c sẽ được đem vào, xóa bỏ comment, thay thế các đoạn chương trình, các biến mà marco định nghĩa.

- `Cú pháp: gcc -E main.c -o main.i`

2. Giai đoạn Compiler: file (.i) khi qua giai đoạn này sẽ thành (.s) (Assembly code). Giai đoạn này sẽ dich ngôn ngữ bậc cao sang ngôn ngữ Assembly (Mỗi vi điều khiển sẽ có cách code Assembly khác nhau, chỉ có 1 số tiêu chuẩn giống nhau, còn lại khác nhiều).

- `Cú pháp: gcc main.i -S -o main.s`

3. Giai đoạn Assembler: file (.s) sẽ thành (.o/ .obj) và libraries. Giai đoạn này sẽ tạo ra các file hệ thống ( âm thanh, đa phương tiện, icon).

- `Cú pháp: gcc -c main.s -o main.o`

4. Giai đoạn Linker: file (.o) thành (.exe) (executable). Thực tế file (.exe) là 1 file nén gồm file source, file âm thanh, file hình ảnh, file thư viện nếu ứng dụng đó có. Chủ yếu giai đoạn này sẽ sắp xếp các file trên vào trong 1 file.

</details>

<details>
  
<summary>STRUCT_UNION</summary>

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

<details>

<summary>POINTER</summary>

### 1. Normal Pointer

- Con trỏ bth chỉ trỏ lưu được giá trị của địa chỉ cùng kiểu dữ liệu.
- Cách khai báo:
  - Int value = 1; 0x01
  - Int \*ptr = 0x01;
  - &value = 0x01;
  - \*0x01 = 1;
  - Printf(“Dia chi: %p”, ptr); = printf (“Dia chi: %p”, &a);

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
- Cách khai báo: void (\*ptr)(int, int)

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/6a08e506-b668-4972-af6d-82f43ca8c415">
</p>

### 5. Pointer to Pointer

- Là 1 con trỏ lưu địa chỉ của Pointer khác.
- Kích thước con trỏ phụ thuộc vào kiến thức vi xử lí: máy tính xử dụng vi xử lí 64bit (8byte), 32 bit (4 byte)...

</details>
 
<details>

<summary>MEMORY LAYOUT</summary>

<p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/277d905a-1347-49d5-b917-c6318804c1c5">
</p>

### 1. Text

- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
- Chứa khai báo hằng số trong chương trình (.rodata) (chỉ đọc chứ không cho sửa đổi).
- Khi ta viết chương trình file .hex, nạp cho vi điều khiển, file hex nạp vào bộ nhớ FLASH, khi chương trình chạy sẽ copy chương trình ở bộ nhớ Flash, dán vào bộ nhớ RAM ( lưu ở phân vùng Text)

### 2. Data (Initialized Data)

- Quyền truy cập là read-write.
- Chứa biến toàn cục or biến static (bao gồm static toàn cục và cục bộ) với giá trị khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình.

### 3. BSS (Uninitialized Data)

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

#### Static Array:

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
- Trả lại địa chỉ đầu tiên được lưu vào con trỏ \*array
- Malloc để tạo mảng, Realloc để thay đổi kích thước mảng.

  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/515fa9d9-05c6-46a3-a579-7c39123ceacf">
  </p>
  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/dc8bd287-6a40-44c9-94dc-22be53a7ca66">
  </p>

- Giải thích: Static array thì lưu ở Stack nên khi chạy hết ct thì sẽ tự thu hồi vùng nhớ, nên khi gọi lần 2 thì sẽ dùng lại vùng nhớ kia trên RAM. Còn Dynamic array thì lưu trên vùng nhớ Heap, không tự thu hồi vùng nhớ nên khi gọi lại lần 2 thì vùng nhớ kia đã sử dụng rồi nên phải dùng vùng nhớ khác.
- Do đó khi dùng Dynamic array thì phải nhớ giải phóng vùng nhớ. Dùng free(array) thì sẽ dùng lại được vùng nhớ cũ.

### 7. Stack & Heap summary

- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Kích thước vùng nhớ
  - Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
  - Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
- Đặc điểm vùng nhớ
  - Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
  - Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa ta phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.
- Vấn đề lỗi xảy ra đối với vùng nhớ:
  - Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
  - Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:
      <p align="center">
     <img src="https://github.com/akhoitn/Test-1/assets/128330556/e96eb8a3-0f7b-4470-8ffe-8ef1a0a2b60b">
     </p>
  - Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow) hoặc nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
  * Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:`int *array= (int*)malloc(128312319823018908)`

 </details>

<details>

<summary>STATIC_EXTERN_VOLATILE</summary>

### 1. Static

- Static cục bộ (Local): chỉ khởi tạo 1 lần duy nhất, tồn tại hết vòng đời của chương trình và giá trị có thể tích lũy được.
- Static toàn cục (Global): những biến, hàm, mảng chỉ có giá trị trong 1 file nó được khai báo bằng Static, các file khác không thể truy cập được.
  - Ứng dụng: Khi viết ct lớn sẽ có nhiều chương trình nhỏ, các hàm quá trình tạo ra ct đó phải là hàm Static, chỉ có nội bộ trong file, nếu ng khác muốn sử dụng thì chỉ đc phép nhập các giá trị và lấy kết quả. Quá trình xử lí tạo ra kết quả thì không được can thiệp.

### 2. Extern

- Nó là tham chiếu của 1 biến, 1 hàm cùng tên nào đó đã được định nghĩa bên ngoài. Nó chỉ được khai báo chứ không đc gán giá trị.
- Biến được tham chiếu sẽ ở cấp độ cao nhất là toàn cục. Và có thể nằm trong các file khác.
- Để sử dụng được biến toàn cục ở file khác, ta phải khai báo thêm từ khóa extern phía trước.
- Cách build: `gcc main.c "file muốn build" -o main` và chạy ct: `./main`

### 3. Volatile

- Compiler có chế độ tối ưu (optimizing) chương trình để tăng tốc độ của chương trình lên, sẽ bỏ qua các lệnh lặp, không thay đổi giá trị làm tốn tài nguyên. Nhưng trong 1 số trường hợp thì giá trị có thay đổi nhưng Compiler không nhận thấy và tối ưu lệnh đó khiến kết quả sai.
- Khi đó ta sẽ dùng keyword Voltatile: thông báo cho Compiler không được tối ưu biến or hàm có keyword đó.
- Ứng dụng: các lệnh, biến, hàm có thay đổi dữ liệu đột ngột or không biết trước.

  </details>

<details>

<summary>CLASS</summary>

### 1. Class

- Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có
  cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho
  những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
  - Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các
    phương thức (hàm thành phần hay method).
  - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
  - Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/47f366b4-fa86-4c17-a426-758ae6f42141">
    </p>

### 2. Access modifiers & properties declaration

- Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai
  báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.

  - Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực
    tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public
    nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể
    thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc
    tính.
  - Các thuộc tính private thường được sử dụng khi bạn không mong muốn
    người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về
    giá trị.
  - Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua
    các class kế thừa nó hoặc chính nó.
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/764c27e5-4f14-4735-b3a4-b7b09e3f8ab4">
    </p>
### 3. Method declaration
- Phương thức cũng giống như một hàm bình thường.
Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong 
lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/31534dbe-a22a-4425-9f71-c915630dd4c0">
    </p>
### 4. Constructor
- Giống như hàm, giống tên với class. Dùng để khởi tạo các tham số ban đầu.
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/408e95d9-0765-4bc3-9215-488f7dde3674">
    </p>
### 5. Static member
- Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn không mất đi.
- Đối với class, khai báo nhiều object mỗi thuộc tính của object sẽ khác nhau nhưng static member vẫn sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó.

</details>

<details>

<summary>OOP</summary>

### 1. 4 thuộc tính OOP:
Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ mà chúng ta cần 
nắm vững:
#### 1. Inheritance (Tính kế thừa)
- Một class có thể kế thừa các thuộc tính của class đã tồn tại trước đó.
- Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta 
  sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong 
  C++.
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/88414c8b-bd24-4648-a36c-85bcf9a8f73e">
    </p>
    <p align="center">
    <img src="https://github.com/akhoitn/Test-1/assets/128330556/180f19d3-3e9a-4b30-a752-3ffc3d5beadb">
    </p>
#### 2. Encapsulation (Tính đóng gói) 
- Không cho phép người sử dụng các đối tượng thay đổi property của một đối tượng.
- Chúng ta chỉ được phép trỏ tới các method mà ta qui định, không trỏ tới được property.
- Dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên 
  ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn 
  vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.
#### 3. Abstraction (Tính trừu tượng) 
- là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông 
  tin cần xử lý.
- Ta có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào
  đối tượng đó được các thao tác trong class.
#### 4. Polymorphism (Tính đa hình)
- Một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy 
  thuộc vào dữ liệu được xử lý.
</details>

<details>

<summary>TEMPLATE</summary>

- Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu    int, float, double, bool...
- Template trong C++ có 2 loại đó là function template & class template.
- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì 
phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu 
dữ liệu khác nhau.

  <p align="center">
  <img src="https://github.com/akhoitn/Test-1/assets/128330556/17fdf521-65d8-4bef-b983-388bf819a254">
  </p>

</details>

<details>

<summary>NAMESPACE</summary>

- Tình huống:
    - Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì vậy trình biên dịch chương trình sẽ báo lỗi.
- Định nghĩa:
    - Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

</details>

<details>

<summary>VIRTUAL FUNCTIONE</summary>

- Hàm ảo (virtual function) là một hàm thành viên trong lớp cha mà lớp con 
khi kế thừa cần phải định nghĩa lại.

- Hàm ảo được sử dụng trong lớp cha khi cần đảm bảo hàm ảo đó sẽ được định 
nghĩa lại trong lớp con. Việc này rất cần thiết trong trường hợp con trỏ có 
kiểu là lớp cha trỏ đến đối tượng của lớp con.

- Hàm ảo quan trọng thể hiện tính đa hình trong kế thừa (C++).

- Note: Con trỏ của lớp cha có thể chứa địa chỉ của đối tượng thuộc lớp con nhưng ngược lại thì không được

- Hàm ảo chỉ khác hàm bình thường khi được gọi từ một con trỏ.

- Khi nào sử dụng hàm ảo, ta sử dụng hàm ảo khi muốn ct sẽ cho sử dụng thuộc tính overriding(ghi đè) load lại method mới nhất. Thuộc tính này sẽ được gọi là overload.


</details>

<details>

<summary>VECTOR</summary>

- Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector.
- Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình
Modifiers
1. push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của 
đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.
ten-vector.push_back(ten-cua-phan-tu);
2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các 
giá trị cũ.
ten-vector.assign(int size, int value);
3. pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một 
vector.
4. insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ 
bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử 
được chèn vào trước vị trí được trỏ.
5. erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
6. emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
7. emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa 
vector, phần tử mới sẽ được thêm vào cuối vector
8. swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một 
vector khác cùng kiểu. Kích thước có thể khác nhau.
9. clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector

</details>