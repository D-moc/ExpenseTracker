# 💰 Expense Tracker in C Language

## 📌 Project Overview
The **Expense Tracker** is a mini-project developed in **C language** that helps users efficiently manage their finances.  
It allows users to log expenses, categorize transactions, track spending by category, and set reminders for bills.  
This project leverages **fundamental data structures** to build a simple yet functional personal finance management tool.  

---

## ✨ Features
- **Add & Edit Expenses** → Record expenses with date, type, and amount. Edit entries when needed.  
- **Delete & Undo Last Entry** → Remove expenses with an **undo feature** for the most recent entry.  
- **Categorized Spending Summaries** → Track and view expenses by category.  
- **Bill Reminders** → Store and prioritize upcoming bills with due dates.  
- **User Feedback** → Collect and store user feedback in the order submitted.  

---

## 🛠️ Data Structures Used
- **Array** → Stores a list of all expenses for efficient access & modification.  
- **Stack** → Powers the **Undo** feature (Last-In-First-Out).  
- **Queue** → Manages feedback submissions (First-In-First-Out).  
- **Structs** → Define `Expense` and `Feedback` entries for organized data handling.  

---

## 🚀 Future Enhancements
This project has potential for expansion into a full-featured software or mobile app with:  
- 📊 **Visual Spending Analysis** → Charts & graphs to show spending patterns.  
- 🏦 **Bank Integration** → Automated expense tracking by linking accounts.  
- 🎯 **Budgeting Tools** → Set, track, and analyze budgets across categories.  

---

## ⚡ How to Run
1. Compile the program:  
   ```bash
   gcc ExpenseTracker.c -o ExpenseTracker
