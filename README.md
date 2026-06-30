# Warehouse Management System (WMS)
A Warehouse Management System developed in C++ as part of an introductory programming course.
The system simulates basic inventory and user management operations using fundamental programming concepts.
This system supports two types of users : **Admin** and **User**, each with different access levels.
Users can browse products, purchase items, and check their balance.
Admin users have additional cammands for managing inventory and user balances;however, some admin functionalities may require further improvements.
Inventory data is stored in a file and updated during program exection.

## Features
### User Features
- User authentication system
- View available products
- Purchase items
- Check account balance
- Help command for available actions

## Technical Details
- C++ programming language
- Usage of `struct` for data modeling
- File handling with `fstream`
- Menu-driven CLI application
- Static arrays for storage
- Basic role-based system(User/Admin)

## Data Storage
The system generates and updates `sole.txt` at runtime to store inventory data.

## Build & Run 
You can compile the project using g++:
```bash
g++ WMS.cpp -o wms
```
Then run the program:
### Linux / macOS:
```bash
./wms
```
### Windows:
```bash
wms.exe
```