# oop-second-sem
# Event Management System

## Overview

This project implements a simple Event Management System in C++. It allows for the management of users (Customers and Organizers), events, and ticket sales. The application provides functionalities to display user information, manage events, and handle ticket sales, including selling and returning tickets. Additionally, it supports saving and loading customer data from a text file.

## Features

- **User Management**:
  - Abstract class `User` with derived classes `Customer` and `Organizer`.
  - Each user has a name and contact information.

- **Event Management**:
  - Class `Event` to represent events with attributes such as event name, date, and location.

- **Ticket Management**:
  - Class `Ticket` to manage ticket sales, including selling and returning tickets.

- **File Management**:
  - Class `FileManager` to handle saving and loading customer data to/from a text file.

## Classes

### User
- **Attributes**:
  - `std::string name`
  - `std::string contact`
- **Methods**:
  - `virtual void displayInfo() = 0;` (Pure virtual function)

### Customer
- Inherits from `User`.
- **Methods**:
  - `void displayInfo() override;`

### Organizer
- Inherits from `User`.
- **Methods**:
  - `void displayInfo() override;`

### Event
- **Attributes**:
  - `std::string eventName`
  - `std::string date`
  - `std::string location`
- **Methods**:
  - `void displayEvent();`

### Ticket
- **Attributes**:
  - `Event event`
  - `double price`
  - `bool available`
- **Methods**:
  - `void sellTicket();`
  - `void returnTicket();`

### FileManager
- **Methods**:
  - `static void saveCustomerData(const std::vector<Customer>& customers);`
  - `static void loadCustomerData(std::vector<Customer>& customers);`

## Usage

1. **Compile the Program**:
   Use a C++ compiler to compile the source code. For example, using `g++`:
   ```bash
   g++ -o event_management event_management.cpp
   ```


