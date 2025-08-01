# Expense Tracker in C Language

**Project Overview**
The Expense Tracker is a mini-project developed in *c*language that helps users efficiently manage their finances. The program allows users to log expenses, categorize transactions, track total spending by category, and set reminders for bills. This project utilizes fundamental data structures to create a simple yet functional personal finance management tool.

**Features**
Add and Edit Expenses: Record expenses by specifying date, type, and amount, and make edits as needed.
Delete and Undo Last Entry: Easily remove expenses from the list, with an undo feature for the last entry.
Categorized Spending Summaries: Track spending by category and view a summary of expenses.
Bill Reminders: Store and prioritize upcoming bills to help users remember due dates.
User Feedback: Users can submit feedback on the app, which is stored in order of submission.

**Data Structures Used**
Array: Used to store a list of all expenses, allowing for efficient access and modification.
Stack: Used for the undo feature, enabling the removal of the last added expense in Last-In-First-Out (LIFO) order.
Queue: Manages user feedback submissions in First-In-First-Out (FIFO) order, ensuring that feedback is processed in order of arrival.
Structs: Defined for Expense and Feedback entries to group related fields and ensure organized data handling.

**Future Enhancements**
This project has potential for expansion into a full software or mobile app with additional features:
Visual Spending Analysis: Add charts and graphs to visualize spending patterns.
Bank Integration: Link accounts for automated expense tracking.
Budgeting Tools: Set and track budgets for different categories.
