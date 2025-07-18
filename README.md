
# 🔌 DESCO Billing System in C

This is a simple command-line C program that simulates a billing system for DESCO (Dhaka Electric Supply Company). It allows you to:

- Register new electricity customers.
- Record their monthly electricity usage.
- Generate a detailed bill based on DESCO's real-life unit rates.

---

## ✅ Features

- 📋 Add customer information (name, address, phone).
- 📊 Save electricity usage per month.
- 🧾 Generate bills with month-wise consumption.
- 💰 Accurate calculation based on DESCO slab-wise unit rate.
- 📆 Supports all 12 months with clear menu navigation.

---

## ⚙️ Technologies

- Language: C
- No external libraries used
- Works on any standard C compiler (GCC, Turbo C, Code::Blocks, etc.)

---

## 💡 How It Works

1. **Add Customer**  
   Input name, address, and phone. Each customer gets a unique serial number.

2. **Save Monthly Usage**  
   Choose a customer and input the electricity usage (units) for a selected month.

3. **Generate Bill**  
   Select a customer and a month to generate the total bill.  
   The bill is calculated based on the following DESCO rate slabs:

   | Units             | Rate (Tk/unit) |
   |-------------------|----------------|
   | 0–75              | 5.26           |
   | 76–200            | 7.20           |
   | 201–300           | 7.59           |
   | 301–400           | 8.02           |
   | 401–600           | 12.67          |
   | 601+              | 14.61          |

---

## 🚀 How to Run

1. Compile the file:
   ```bash
   gcc desco_billing.c -o desco_billing
   ```

2. Run the program:
   ```bash
   ./desco_billing
   ```

---

## 🧑‍💻 Author

**Abdullah Al Sadik**  
Dept.of CSE @ United International University  
Passionate about building real-life systems using C & core programming concepts.
