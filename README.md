
# 🛒 Supermarket Management System

A console-based Supermarket Management System developed in C as a first-semester Programming Fundamentals project at FAST-NUCES, Karachi.

The system simplifies supermarket operations by managing inventory, processing customer orders, generating bills, tracking customer loyalty, and maintaining sales records.

## ✨ Features

### Inventory Management
- Add new products
- View available products
- Search products by ID
- Update product prices and quantities
- Delete products
- Low-stock alerts

### Billing System
- Purchase multiple products
- Check stock availability
- Calculate customer bills
- Apply eligible discounts
- Automatically update inventory after purchases

### Customer Loyalty System
- Generate unique customer loyalty IDs
- Maintain customer records
- Provide a 5% discount on purchases of Rs. 5,000 or more

### Sales Reporting
- Calculate total revenue
- Track total transactions
- Display total items sold

### File Handling
- Permanent storage of product records
- Customer information storage
- Sales record management
- Automatic loading and saving of data

## 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- Git and GitHub
- Windows Batch Scripting

## 📚 Programming Concepts Applied

- Structures
- Arrays
- Pointers
- Functions
- File Handling
- String Manipulation
- Conditional Statements and Loops
- Modular Programming
- Header Files

## 📂 Project Structure

```text
Supermarket-Management-System/
│
├── main.c          # Main menu and program control
├── common.h        # Shared structures and declarations
├── inventory.c     # Inventory management
├── billing.c       # Billing and order processing
├── reports.c       # Sales reports and customer loyalty
├── products.txt    # Product records
├── customers.txt   # Customer records
├── sales.txt       # Sales records
├── run.bat         # Automated compilation and execution
└── README.md       # Project documentation
```

## 🚀 How to Run

### Requirements

- GCC compiler installed
- Windows operating system for the batch file

### Method 1: Automatic Execution (Windows)

1. Download or clone this repository.
2. Extract the project folder.
3. Double-click `run.bat`.
4. The project will automatically compile and execute.

### Method 2: Manual Compilation

Open the terminal inside the project directory and run:

```bash
gcc main.c inventory.c billing.c reports.c -o supermarket.exe
```

Run the executable in PowerShell:

```powershell
.\supermarket.exe
```

## 👥 Team Members

| Name | Contribution |
|------|--------------|
| Naresh Kumar | Inventory Management and File Handling |
| Abbas Ali | Billing and Customer Order Processing |
| Munesh Kumar | Sales Reporting and Customer Loyalty |

## 🎓 Academic Information

- University: FAST-NUCES, Karachi
- Degree: BS Computer Science
- Semester: 1st Semester
- Course: Programming Fundamentals
- Year: 2026

## 💡 Learning Outcomes

This project helped us apply fundamental programming concepts to a practical management system. It also improved our understanding of modular programming, persistent data storage, debugging, version control, and team collaboration.

## 🔮 Future Improvements

- Graphical User Interface (GUI)
- Database integration
- Administrator authentication
- Barcode-based product searching
- Advanced sales analytics
- Improved input validation

---

Developed as part of our Computer Science journey at FAST-NUCES.
