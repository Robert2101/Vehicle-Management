# Ride Booking Application

## Overview
This project is a **C++ OOP-based Ride Booking System** that simulates functionalities similar to apps like Rapido or Ola. It allows users to book and manage rides for different vehicles, including buses, cars, and bikes. Each type of vehicle has unique attributes and booking processes, making the system modular and object-oriented.

---

## Features
- **Bus Booking:**
  - Book and manage reserved seats for buses.
  - Each bus includes details like driver name, number plate, timings, and route information.
- **Car Booking:**
  - Book cars for personal use without driver or timing constraints.
- **Bike Booking:**
  - Book bikes for quick transportation without driver or timing constraints.
  - Handles invalid input gracefully with error messages.
  
---

## Key Functionalities
1. **Menu-Driven Interface:** 
   - Users can select options to book buses, cars, or bikes, or exit the program.
2. **Modular Design:**
   - Classes `Bus`, `Car`, and `Bike` inherit from a base `Vehicle` class, ensuring clean and reusable code.
3. **Input Validation:**
   - Handles incorrect inputs and displays appropriate error messages.
4. **Efficient Booking System:**
   - Prevents double booking and maintains availability status for all vehicles.

---

## Technology Stack
- **Programming Language:** C++
- **Key Concepts:**
  - Object-Oriented Programming (Inheritance, Polymorphism)
  - Input validation and exception handling
  - Modular and reusable codebase

---

## File Structure
|– main.cpp         # Entry point of the application
|– Vehicle.h        # Header file containing the base Vehicle class
|– Bus.h / Bus.cpp  # Bus class implementation
|– Car.h / Car.cpp  # Car class implementation
|– Bike.h / Bike.cpp# Bike class implementation
|– README.md        # Project documentation

---

## How to Run the Project
1. Clone or download the repository.
2. Open the project in a C++ IDE (e.g., VS Code, CLion, Code::Blocks).
3. Compile and run `main.cpp`.
   ```bash
   g++ main.cpp Bus.cpp Car.cpp Bike.cpp -o RideBookingApp
   ./RideBookingApp
