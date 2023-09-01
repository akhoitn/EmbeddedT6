#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

class Room
{
private:
    int roomNumber;
    bool isBooked;
    bool cleaned;

public:
    Room(int number)
    {
        roomNumber = number;
        isBooked = false;
        cleaned = true;
    };
    int getRoomNumber()
    {
        return roomNumber;
    }
    bool isAvailable()
    {
        return !isBooked && cleaned;
    };
    void bookRoom()
    {
        isBooked = true;
    };
    void checkIn()
    {
        cleaned = false;
        isBooked = true;
    };
    void checkOut()
    {
        cleaned = true;
        isBooked = false;
    };
};
/////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int day;
    int month;
    int year;
} typeDate;

typedef struct
{
    int second;
    int minute;
    int hour;
} typeTime;

typedef enum
{
    IN,
    OUT
} typeStatus;

typedef struct
{
    typeTime time;
    typeDate date;
    typeStatus status;
} bookingHistory;

class Customer
{
private:
    int idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistorys;

public:
    Customer(string customerName, string CustomerPhone, string customerAddress, int customerIdRoom);
    void addBookingHistory(bookingHistory bookingDetails);
    void displayBookingHistory();

    string getname()
    {
        return name;
    };

    int getIdRoom()
    {
        return idRoom;
    };

    string getPhoneNumber()
    {
        return phoneNumber;
    };

    string getAddress()
    {
        return address;
    };

    void setId(int id)
    {
        idRoom = id;
    };
    void setName(string customerName)
    {
        name = customerName;
    }

    void setAddress(string customerAddress)
    {
        address = customerAddress;
    }

    void setPhone(string customerPhone)
    {
        phoneNumber = customerPhone;
    }
};

Customer::Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom)
{
    this->idRoom = customerIdRoom;
    this->name = customerName;
    this->phoneNumber = customerPhone;
    this->address = customerAddress;
}

void Customer::addBookingHistory(bookingHistory bookingDetails)
{
    bookingHistorys.push_back(bookingDetails);
}

//////////////////////////////////////////////////////////
class CustomerManager
{
private:
    vector<Customer> databaseCustomers;

public:
    void addCustomer(Customer &customer);
    void editIdRoomCustomer(vector<Room> &databaseRoom, int idRoom_Current, int idRoom);
    void editNameCustomer(vector<Room> &databaseRoom, int idRoom_Current, string name);
    void editPhoneCustomer(vector<Room> &databaseRoom, int idRoom_Current, string phoneNumber);
    void editAddressCustomer(vector<Room> &databaseRoom, int idRoom_Current, string address);
    void deleteCustomer(int index);
    vector<Customer> &getDatabaseCustomers();
};

void CustomerManager::addCustomer(Customer &customer)
{
    databaseCustomers.push_back(customer);
};

void CustomerManager::deleteCustomer(int index)
{
    databaseCustomers.erase(databaseCustomers.begin() + index);
};

void CustomerManager::editIdRoomCustomer(vector<Room> &databaseRoom, int idRoom_Current, int idRoom)
{

    for (int i = 0; i < databaseRoom.size(); i++)
    {
        if (databaseRoom[i].getRoomNumber() == idRoom_Current)
            databaseRoom[i].checkOut();
        if (databaseRoom[i].getRoomNumber() == idRoom)
            databaseRoom[i].bookRoom();
    }

    for (int i = 0; i < databaseCustomers.size(); i++)
    {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
        {
            databaseCustomers[i].setId(idRoom);
        }
    }
};

void CustomerManager::editNameCustomer(vector<Room> &databaseRoom, int idRoom_Current, string name)
{

    for (int i = 0; i < databaseCustomers.size(); i++)
    {
        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
            databaseCustomers[i].setName(name);
    }
};

void CustomerManager::editPhoneCustomer(vector<Room> &databaseRoom, int idRoom_Current, string phoneNumber)
{

    for (int i = 0; i < databaseCustomers.size(); i++)
    {

        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
            databaseCustomers[i].setPhone(phoneNumber);
    }
};
void CustomerManager::editAddressCustomer(vector<Room> &databaseRoom, int idRoom_Current, string address)
{

    for (int i = 0; i < databaseCustomers.size(); i++)
    {

        if (databaseCustomers[i].getIdRoom() == idRoom_Current)
            databaseCustomers[i].setAddress(address);
    }
};

vector<Customer> &CustomerManager::getDatabaseCustomers()
{
    return databaseCustomers;
}

////////////////////////////////////////////////////////////////////////////////////////

class User
{
private:
    string USERNAME;
    string PASSWORD;

public:
    User(string username = "coder", string password = "code");
    string getUserName()
    {
        return USERNAME;
    };
    string getPassword()
    {
        return PASSWORD;
    }
    void setUserName(string inputUsername)
    {
        USERNAME = inputUsername;
    };
    void setPassword(string inputUsername)
    {
        PASSWORD = inputUsername;
    };
    bool authenticate(string inputUsername, string inputPassword)
    {
        bool checkSignUp = (inputUsername == USERNAME && inputPassword == PASSWORD);
        return checkSignUp;
    };
};

User::User(string username, string password)
{
    this->USERNAME = username;
    this->PASSWORD = password;
}

/////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    BAGGAGE_STAFF,
    GARDENER
} JobPosition;

typedef struct
{
    typeTime time;
    typeDate date;
    typeStatus status;
} Schedule;

class Employee
{
private:
    int id;
    string name;
    string phoneNumber;
    JobPosition position;
    Schedule shedule;

public:
    Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee);

    string getName()
    {
        return name;
    };
    void setName(string nameEmployee)
    {
        name = nameEmployee;
    };

    void setPhoneNumber(string phoneNumberEmmployee)
    {
        phoneNumber = phoneNumberEmmployee;
    };
    string getphoneNumber()
    {
        return phoneNumber;
    };

    void setPosition(JobPosition positionEmployee)
    {
        position = positionEmployee;
    }
    JobPosition getPosition()
    {
        return position;
    };

    int getIdEmployee()
    {
        return id;
    }
};

Employee::Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee)
{

    static int idEmployee = 100;
    this->id = idEmployee;
    idEmployee++;

    this->name = nameEmployee;
    this->phoneNumber = phoneNumberEmployee;
    this->position = positionEmployee;
    this->shedule = scheduleEmployee;
};

/////////////////////////////////////////////////////////////////////////

class EmployeeManager
{
private:
    vector<Employee> databaseEmployee;

public:
    void addEmployee(Employee employee);
    void deleteEmployee(int index);
    void editNameEmployee(vector<Employee> &databaseEmployee, int idEmployee, string name);
    void editPhoneEmployee(vector<Employee> &databaseEmployee, int idEmployee, string phoneNumber);
    void editPositionEmployee(vector<Employee> &databaseEmployee, JobPosition position);
    bool getAuthenticate(string inputPassword, string inputUsername);
    vector<Employee> &getDatabaseEmployee();
};

void EmployeeManager::addEmployee(Employee employee_)
{
    databaseEmployee.push_back(employee_);
};

void EmployeeManager::deleteEmployee(int index)
{
    databaseEmployee.erase(databaseEmployee.begin() + index);
};

void EmployeeManager::editNameEmployee(vector<Employee> &databaseEmployee, int idEmployee, string name)
{
    for (int i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getName() == name)
            databaseEmployee[i].setName(name);
    }
};

void EmployeeManager::editPhoneEmployee(vector<Employee> &databaseEmployee, int idEmployee, string phoneNumber)
{
    for (int i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
            databaseEmployee[i].setPhoneNumber(phoneNumber);
    }
}

vector<Employee> &EmployeeManager::getDatabaseEmployee()
{
    return databaseEmployee;
}
/////////////////////////////////////////////////////////////////////////////

class SecurityManagement
{
private:
    User user;
    vector<User> databaseUser;
    bool checkSignup;

public:
    void addUser(string inputUsername, string inputPassword);
    void eraseUser(string inputUsername);
    void editUser(string inputUserName, string inputPassword);
    void setPasswordManager(string inputPassword)
    {
        user.setPassword(inputPassword);
    };
    bool getCheckSignup(string inputUserName, string inputPassword)
    {
        if (user.authenticate(inputUserName, inputPassword))
            return true;
        else
            return false;
    };
    vector<User> &getDatabaseUser()
    {
        return databaseUser;
    };
};

void SecurityManagement::addUser(string inputUsername, string inputPassword)
{
    User user = {inputUsername, inputPassword};
    databaseUser.push_back(user);
}

void SecurityManagement::eraseUser(string inputUsername)
{
    for (auto i = databaseUser.begin(); i < databaseUser.end(); i++)
    {
        if (i->getUserName() == inputUsername)
            databaseUser.erase(i);
    }
}

void SecurityManagement::editUser(string inputUserName, string inputPassword)
{
    for (int i = 0; i < databaseUser.size(); i++)
    {
        if (databaseUser[i].getUserName() == inputUserName)
            databaseUser[i].setPassword(inputPassword);
    }
}

//////////////////////////////////////////////////////////////////////////////
typedef enum
{
    ON,
    OFF
} Status;

typedef struct
{
    string price;
    Status status;
} nhaHang;

class ServiceManager
{
private:
    nhaHang nhahang; // nên tạo ra 1 class nhà hàng thay vì dùng struct
public:
    void setNhaHang(Status status)
    {
        nhahang.status = status;
    }
    Status getStatus()
    {
        return nhahang.status;
    }
    void setPrice(string price)
    {
        nhahang.price = price;
    }
    string getPrice()
    {
        return nhahang.price;
    }
    nhaHang &getNhaHang()
    {
        return nhahang;
    }
};

///////////////////////////////////////////////////////////////////////////
void setQuantityRoom(vector<Room> &databaseRoom)
{
    cout << "--------------" << endl;
    int quantity;
    cout << "Enter the total number of rooms: ";
    cin >> quantity;

    for (int i = 0; i < quantity; i++)
    {
        Room room = {i};
        databaseRoom.push_back(room);
    }
}

void prinListRoom(vector<Room> &databaseRoom)
{
    cout << "\n\nLIST ROOM\nRoom:     ";
    for (int i = 0; i < databaseRoom.size(); i++)
    {
        cout << databaseRoom[i].getRoomNumber() << "  |  ";
    }

    cout << "\nStatus: ";
    for (int i = 0; i < databaseRoom.size(); i++)
    {
        if (databaseRoom[i].isAvailable() == true)
            cout << "  o  |";
        else
            cout << "  x  |";
    }
    cout << endl;
}

void bookRoom(vector<Room> &databaseRoom, CustomerManager &customermanager)
{

    prinListRoom(databaseRoom);

    cout << "\n\nEnter the number room: ";
    int idRoom = 0;
    cin >> idRoom;
    for (int i = 0; i < databaseRoom.size(); i++)
    {
        if (databaseRoom[i].getRoomNumber() == idRoom)
        {
            databaseRoom[i].bookRoom();
            databaseRoom[i].checkIn();

            string name;
            string phoneNumber;
            string address;

            cout << "Enter name: ";
            cin >> name;

            cout << "Enter phone number: ";
            cin >> phoneNumber;

            cout << "Enter address: ";
            cin >> address;

            int day = 0;
            int month = 0;
            int year = 0;
            cout << "day: ";
            cin >> day;
            cin.ignore();
            cout << "month: ";
            cin >> month;
            cin.ignore();
            cout << "year: ";
            cin >> year;
            cin.ignore();

            int second = 0;
            int minute = 0;
            int hour = 0;
            cout << "second: ";
            cin >> second;
            cin.ignore();
            cout << "minute: ";
            cin >> minute;
            cin.ignore();
            cout << "hourd: ";
            cin >> hour;
            cin.ignore();

            Customer customer = {name, phoneNumber, address, idRoom};

            bookingHistory history;
            history.time.second = second;
            history.time.minute = minute;
            history.time.hour = hour;

            history.date.day = day;
            history.date.month = month;
            history.date.year = year;

            customer.addBookingHistory(history);
            customermanager.addCustomer(customer);
        }
    }
}

void reservationManager(vector<Room> &databaseRoom, CustomerManager &customermanager)
{

back:

    cout << "1. Watch the list" << endl;
    cout << "2. Book room" << endl;
    cout << "0. Return" << endl;
    cout << "Pls choice number: ";
    int key = 0;
    cin >> key;
    // 1 xem danh sách
    // 2 đặt phòng
    switch (key)
    {
    case 1:
        prinListRoom(databaseRoom);
        goto back;
        break;
    case 2:
        bookRoom(databaseRoom, customermanager);
        goto back;
        break;
    case 0:
        return;
        break;
    default:
        cout << "Warning.Again";
        break;
    }
}
void prinCustomerInfor(vector<Customer> &databaseCustomers)
{

    for (int i = 0; i < databaseCustomers.size(); i++)
    {
        cout << endl;
        cout << "Information of customers\n|\tIDRoom\t|\tName\t|\tPhone\t|\tAddress\t|\n";
        printf("|\t%d\t|", databaseCustomers[i].getIdRoom());
        cout << "\t" << databaseCustomers[i].getname() << "\t|";
        cout << "\t" << databaseCustomers[i].getPhoneNumber() << "\t|";
        cout << "\t" << databaseCustomers[i].getAddress() << "\t|";
    }
}

void delCustomer(vector<Room> &databaseRoom, CustomerManager &customermanager, vector<Customer> &databaseCustomers)
{
    cout << endl;
    int id = 0;
    cout << "Enter id room: ";
    cin >> id;
    customermanager.deleteCustomer(id);
}

void idRoomEdit(vector<Room> &databaseRoom, CustomerManager &customermanager, int idRoom_Current)
{

    prinCustomerInfor(customermanager.getDatabaseCustomers());
    prinListRoom(databaseRoom);
    cout << "Enter the number want to change: ";
    int idRoom = 0;
    cin >> idRoom;
    customermanager.editIdRoomCustomer(databaseRoom, idRoom_Current, idRoom);
    cout << "Enter 0 to return";
}

void nameEdit(vector<Room> &databaseRoom, CustomerManager &customermanager, int idRoom_Current)
{
    cout << endl;
    cout << "Enter number room:";
    cin >> idRoom_Current;
    cout << "Enter name want to change:";
    string name;
    cin >> name;
    customermanager.editNameCustomer(databaseRoom, idRoom_Current, name);

    cout << "Enter 0 to return";
    cout << endl;
}

void phoneEdit(vector<Room> &databaseRoom, CustomerManager &customermanager, int idRoom_Current)
{

    cout << endl;
    cout << "Enter number room:";
    cin >> idRoom_Current;
    cout << "Enter phone want to change:";
    string phoneNumber;
    cin >> phoneNumber;
    customermanager.editPhoneCustomer(databaseRoom, idRoom_Current, phoneNumber);

    cout << "Enter 0 to return";
    cout << endl;
}

void addressEdit(vector<Room> &databaseRoom, CustomerManager &customermanager, int idRoom_Current)
{

    cout << endl;
    cout << "Enter number room:";
    cin >> idRoom_Current;
    cout << "Enter address want to change:";
    string address;
    cin >> address;
    customermanager.editAddressCustomer(databaseRoom, idRoom_Current, address);

    cout << "Enter 0 to return";
    cout << endl;
}

void customerEdit(vector<Room> &databaseRoom, CustomerManager &customermanager, int idRoom_Current)
{
back:
    cout << "\n1: edit idRoom\n2: edit name\n3: edit phone\n4: edit address\n0: Return ....\nPls choice: ";
    int key = 0;
    cin >> key;

    switch (key)
    {
    case 1:
        idRoomEdit(databaseRoom, customermanager, idRoom_Current);
        // customermanager.displayCustomerInfor();
        prinCustomerInfor(customermanager.getDatabaseCustomers());
        prinListRoom(databaseRoom);
        goto back;
        break;
    case 0:
        return;
        break;
    case 2:
        prinCustomerInfor(customermanager.getDatabaseCustomers());
        nameEdit(databaseRoom, customermanager, idRoom_Current);
        goto back;
        break;
    case 3:
        prinCustomerInfor(customermanager.getDatabaseCustomers());
        phoneEdit(databaseRoom, customermanager, idRoom_Current);
        goto back;
        break;
    case 4:
        prinCustomerInfor(customermanager.getDatabaseCustomers());
        addressEdit(databaseRoom, customermanager, idRoom_Current);
        goto back;
        break;
    default:
        cout << "Warning. Again" << endl;
        break;
    }
}

void customerManager(vector<Room> &databaseRoom, CustomerManager &customermanager, vector<Customer> &databaseCustomers)
{

    prinCustomerInfor(customermanager.getDatabaseCustomers());

    cout << "\nNhap idRoom: ";
    int idRoom_Current = 0;
    cin >> idRoom_Current;
back:
    cout << "\n1: edit\n2: delete\n3: Display customer\n0: Return....\nPls choice: ";

    int key = 0;
    cin >> key;
    switch (key)
    {
    case 1:
        customerEdit(databaseRoom, customermanager, idRoom_Current);
        goto back;
        break;
    case 0:
        return;
        break;
    case 2:
        delCustomer(databaseRoom, customermanager, databaseCustomers);
        goto back;
        break;
    case 3:
        prinCustomerInfor(customermanager.getDatabaseCustomers());
        goto back;
        break;
    default:
        cout << "Warning.Again" << endl;
        break;
    }
}

void addEmployee(EmployeeManager &employeemanager)
{

    string name;
    string phoneNumber;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone: ";
    cin >> phoneNumber;

    JobPosition position;
    cout << "Choice position\n0: janitor\n1: reception\n2: laundry_staff\n3: baggage_staff\n4: gardener ....\n";
    int key = 0;
    cin >> key;
    switch (key)
    {
    case 0:
        position = JANITOR;
        break;
    case 1:
        position = RECEPTIONIST;
        break;
    case 2:
        position = LAUNDRY_STAFF;
        break;
    case 3:
        position = BAGGAGE_STAFF;
        break;
    case 4:
        position = GARDENER;
        break;
    default:
        cout << "Warning.Again" << endl;
        break;
    }

    int day = 0;
    int month = 0;
    int year = 0;
    cout << "day: ";
    cin >> day;
    cin.ignore();
    cout << "month: ";
    cin >> month;
    cin.ignore();
    cout << "year: ";
    cin >> year;
    cin.ignore();
    Schedule schedule;
    schedule.date = {day, month, year};

    int second = 0;
    int minute = 0;
    int hour = 0;
    cout << "second: ";
    cin >> second;
    cin.ignore();
    cout << "minute: ";
    cin >> minute;
    cin.ignore();
    cout << "hourd: ";
    cin >> hour;
    cin.ignore();
    schedule.time = {second, minute, hour};

    Employee employee = {name, phoneNumber, position, schedule};
    employeemanager.addEmployee(employee);
}
void prinEmployeeInfor(vector<Employee> &databaseEmployee)
{

    for (int i = 0; i < databaseEmployee.size(); i++)
    {
        cout << endl;
        cout << "Information of the employe\n|\tID\t|\tName\t|\tPhone\t|\tPosition\t|\n";
        printf("|\t%d\t|", databaseEmployee[i].getIdEmployee());
        cout << "\t" << databaseEmployee[i].getName() << "\t|";
        cout << "\t" << databaseEmployee[i].getphoneNumber() << "\t|";

        int key;
        key = databaseEmployee[i].getPosition();
        switch (key)
        {
        case 0:
            cout << "\t"
                 << "JANITOR"
                 << "\t" << endl;
            break;
        case 1:
            cout << "\t"
                 << "RECEPTIONIST"
                 << "\t" << endl;
            break;
        case 2:
            cout << "\t"
                 << "LAUNDRY_STAFF"
                 << "\t" << endl;
            break;
        case 3:
            cout << "\t"
                 << "BAGGAGE_STAFF"
                 << "\t" << endl;
            break;
        case 4:
            cout << "\t"
                 << "GARDENER"
                 << "\t" << endl;
            break;
        default:
            break;
        }
    }
}
void editNameEmployee(vector<Employee> &databaseEmployee, EmployeeManager &employeemanager, int idEmployee)
{
    string name;
    cout << "Enter the name: ";
    cin >> name;
    employeemanager.editNameEmployee(databaseEmployee, idEmployee, name);
}

void editPhoneEmployee(vector<Employee> &databaseEmployee, EmployeeManager &employeemanager, int idEmployee)
{
    string phoneNumber;
    cout << "Enter the phone number: ";
    cin >> phoneNumber;
    employeemanager.editPhoneEmployee(databaseEmployee, idEmployee, phoneNumber);
}

void employeeEdit(vector<Employee> &databaseEmployee, EmployeeManager &employeemanager, int idEmployee)
{

    cout << "\n1: edit name\n2: edit phone\n3: edit position\n4: display list employee\n0: Return....\n Your choice number: ";
    int key = 0;
    cin >> key;
    switch (key)
    {
    case 1:
        editNameEmployee(databaseEmployee, employeemanager, idEmployee);
        break;
    case 2:
        editPhoneEmployee(databaseEmployee, employeemanager, idEmployee);
        break;
    case 4:
        prinEmployeeInfor(employeemanager.getDatabaseEmployee());

        break;
    default:
        break;
    }
}
void delEmployee(EmployeeManager &employeemanager, vector<Employee> &databaseEmployee)
{

    cout << endl;
    int id = 0;
    cout << "Enter id of the employee: ";
    cin >> id;
    employeemanager.deleteEmployee(id);
}
void editOfEmployee(vector<Employee> &databaseEmployee, EmployeeManager &employeemanager, int idEmployee)
{
    int key = 0;
    cout << "\n1: edit phone\n2: edit address\n0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        string phoneNumber;
        cout << "Enter the phone number: ";
        cin >> phoneNumber;
        employeemanager.editPhoneEmployee(databaseEmployee, idEmployee, phoneNumber);
    }
    else
        return;
}
void editOfUser(vector<Employee> &databaseEmployee, EmployeeManager &employeemanager, int idEmployee)
{
    cout << "Enter your id: ";
    cin >> idEmployee;
    for (int i = 0; i < databaseEmployee.size(); i++)
    {
        if (databaseEmployee[i].getIdEmployee() == idEmployee)
        {
            editOfEmployee(databaseEmployee, employeemanager, idEmployee);
        }else cout << "not found";
    }
    
}

void emloyeeManager(EmployeeManager &employeemanager, SecurityManagement &securitymanagement, vector<Employee> &databaseEmployee)
{

    cout << "1: Manager\n2: Employee\n0: Return\nPls choice: ";
    int key1 = 0;
    cin >> key1;
    if (key1 == 1)
    {
        string username;
        string password;
        int checkUsername = 0;
        cout << "Enter user: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        bool checkSignup = securitymanagement.getCheckSignup(username, password);
        if (checkSignup == 0)
        {
            cout << "Signup error";
            return;
        };
    back:
        int idEmployee = 0;
        cout << "\n1: Add new employee\n2: edit employee\n3: delete employee\n4: Display list employee\n0: Return\n....";
        cout << "\nPls choice number: ";
        int key = 0;
        cin >> key;
        switch (key)
        {
        case 1:
            addEmployee(employeemanager);
            prinEmployeeInfor(employeemanager.getDatabaseEmployee());
            goto back;
            break;
        case 2:
            prinEmployeeInfor(employeemanager.getDatabaseEmployee());
            cout << "Enter the employee want to change: ";
            cin >> idEmployee;
            employeeEdit(databaseEmployee, employeemanager, idEmployee);
            goto back;
            break;
        case 3:
            prinEmployeeInfor(employeemanager.getDatabaseEmployee());
            delEmployee(employeemanager, databaseEmployee);
            goto back;
            break;
        case 4:
            prinEmployeeInfor(employeemanager.getDatabaseEmployee());
            goto back;
            break;
        case 0:
            return;
        default:
            break;
        }
    }
    else if(key1 == 2)
    {
        string username;
        string password;
        int checkUsername = 0;
        cout << "Enter user: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (int i = 0; i < securitymanagement.getDatabaseUser().size(); i++)
        {
            if (securitymanagement.getDatabaseUser()[i].getUserName() == username)
            {
                checkUsername++;
                if (securitymanagement.getDatabaseUser()[i].getPassword() == password)
                    break;
                else
                {
                    cout << "password is error !\n";
                    return;
                }
            }
        }
        if (checkUsername == 0)
        {
            cout << "username is error !\n";
            return;
        }
        int idEmployee;
        editOfUser(databaseEmployee, employeemanager, idEmployee);
        // int fix = 0;
        // int idEmployee = 0;
        // string phoneNumber =0;
        // cout << "Enter the id of the employee: ";
        // cin >> idEmployee;
        // for (int i = 0; i < databaseEmployee.size(); i++)
        // {
        //     if (databaseEmployee[i].getIdEmployee() == idEmployee)
        //     {
        //         cout << "\n1: edit address\n2: edit phone\n0: Return\nPls choice:";
        //         cin >> fix;
        //         if (fix == 1)
        //         {
        //             cout<<"Enter new phone number: "; cin >> phoneNumber;
        //             databaseEmployee[i].setPhoneNumber(phoneNumber);
        //         }
        //         else if(fix == 0) return;
        //     }
        // }
    }
    // else
    //     return;
 else if(key1 == 0) return;
}
void paymentManager(vector<Room> &databaseRoom, CustomerManager &customermanager)
{

    prinListRoom(databaseRoom);
    cout << "Nhap so phong muon thanh toan: ";
    int numberRoom = 0;
    cin >> numberRoom;

    cout << "1: Thanh toan truoc\n2: Thanh toan tra phong:\n...\nNhap lua chon: ";
    int key = 0;
    cin >> key;

    switch (key)
    {
    case 1:

    default:
        // payOnLeaving
        break;
    }
}

void addUser(SecurityManagement &securitymanagement)
{

    string username;
    string password;
back:
    cout << "\n_______Enter username, password_______\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    securitymanagement.addUser(username, password);
    cout << "_____successfully_____";

    int key = 0;
    cout << "\n1: Add user more\n0: Return\nPls choice:";
    cin >> key;
    if (key == 1)
    {
        goto back;
    }
    else if (key == 0)
        return;
}

void editPasswordOfManager(SecurityManagement &securitymanagement)
{

    string password;
    string passwordAgain;
back:
    while (1)
    {
        cout << "\nEnter new password: ";
        cin >> password;
        cout << "Password verification again: ";
        cin >> passwordAgain;
        if (passwordAgain == password)
            break;
        else
            cout << "\npassword again is error, enter again!";
    }

    securitymanagement.setPasswordManager(password);
    cout << "_____successfully_____\n\n";
    int key = 0;
    cout << "\n1: Change the password again\n 0: Return\nPls choice: ";
    cin >> key;
    if (key == 1)
    {
        goto back;
    }
    else if (key == 0)
        return;
}

void securityManagement(SecurityManagement &securitymanagement)
{
back:
    cout << "\n_______Enter username, password_______\n";
    string username;
    cout << "Enter username: ";
    cin >> username;
    string password;
    cout << "Enter password: ";
    cin >> password;

    bool checkSignup = securitymanagement.getCheckSignup(username, password);
    if (checkSignup == false)
    {
        cout << "password is error\n";
        return;
    }

turn:
    cout << "\n\n1: add user\n2: delete user\n3: edit password of user\n4: edit password of manager\n0: Return\nPls choice number: ";
    int key = 0;
    cin >> key;

    switch (key)
    {
    case 1:
        addUser(securitymanagement);
        goto turn;
        break;
    case 4:
        editPasswordOfManager(securitymanagement);
        break;
    case 0:
        return;
    default:
        break;
    }
}

int main()
{

    vector<Room> databaseRoom;
    CustomerManager customermanager;
    EmployeeManager employeemanager;
    vector<Employee> databaseEmployee;
    vector<Customer> databaseCustomers;
    SecurityManagement securitymanagement;
    setQuantityRoom(databaseRoom);

    while (1)
    {
        int key = 0;
        cout << "\n1: Reservation management\n2: Customer management\n"
             << "3: Employee management\n4: Service and utility management\n"
             << "5.....\n6: Security management\nNhap lua chon: ";

        cin >> key;
        switch (key)
        {
        case 1:
            reservationManager(databaseRoom, customermanager);
            prinListRoom(databaseRoom);
            break;
        case 2:
            customerManager(databaseRoom, customermanager, databaseCustomers);
            break;
        case 3:
            emloyeeManager(employeemanager, securitymanagement, databaseEmployee);
            break;
        case 4:
            // serviceManager(databaseRoom);
            break;
        case 5:
            // paymentManager(databaseRoom, customermanager);
            break;
        case 6:
            securityManagement(securitymanagement);
            break;
        default:
            break;
        }
    }
    return (0);
}