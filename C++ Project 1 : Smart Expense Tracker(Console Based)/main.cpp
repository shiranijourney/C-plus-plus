//
//  main.cpp
//  C++ Project 1 : Smart Expense Tracker(Console Based)
//
//  Created by shirani.
//

#include <iostream>
#include <string>
#include <vector>

//C++ Model
struct Expense {
    std::string name;
    std::string category;
    double amount;
};
/*
 ➣ This is User-defined types
 ➣ Modeling real-world data
 */



//Store many expenses (real-world need)

/*
 In real apps:

 ➣ expenses are dynamic

 ➣ number is unknown

 ➣ memory must be managed safely

 That’s why real C++ uses std::vector
 
 therefore add ➪ #include <vector>
 
 */


std::vector<Expense> expenses;

/*
 ➣ dynamic containers
 
 ➣ automatic memory management

 ➣ why arrays are rarely used directly
 
 */




//Add behavior using functions
//Add a new expense

void addExpense(std::vector<Expense>& expenses) {
    Expense e;

    std::cout << "Enter expense name: ";
    std::cin >> e.name;

    std::cout << "Enter amount: ";
    std::cin >> e.amount;

    std::cout << "Enter category: ";
    std::cin >> e.category;

    expenses.push_back(e);
}

/*
 ➣ passing by reference (&)

 ➣ user input

 ➣ modifying containers

 ➣ real data flow
 
 */



//Display stored data (core real-world skill)

void listExpenses(const std::vector<Expense>& expenses) {
    for (const Expense& e : expenses) {
        std::cout << e.name << " | "
                  << e.amount << " | "
                  << e.category << "\n";
    }
}

/*
 ➣ range-based for loop

 ➣ const correctness

 ➣ readable output

 ➣ modern C++ style
 */



//Add real logic (business logic)
//Total expenses:

double calculateTotal(const std::vector<Expense>& expenses) {
    double total = 0.0;

    for (const Expense& e : expenses) {
        total += e.amount;
    }

    return total;
}

/*
 ➣ accumulation logic

 ➣ return values

 ➣ real calculations

 ➣ separation of concerns
 */


//Menu-driven program

int main() {
    std::vector<Expense> expenses;
    int choice;

    while (true) {
        std::cout << "\n1. Add Expense\n";
        std::cout << "2. List Expenses\n";
        std::cout << "3. Show Total\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (choice == 1)
            addExpense(expenses);
        else if (choice == 2)
            listExpenses(expenses);
        else if (choice == 3)
            std::cout << "Total: " << calculateTotal(expenses) << "\n";
        else
            break;
    }
}

































