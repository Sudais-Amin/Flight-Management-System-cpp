# Flight-Management-System-cpp

A console-based airline management system developed in C++ that simulates real-world flight booking operations. This project demonstrates fundamental programming concepts including data structures, file handling, and multi-user interface design.

## Project Overview

The Airline Reservation Management System provides a practical implementation of a flight booking platform with distinct interfaces for passengers and airline employees. The system maintains persistent data storage, manages seat availability in real-time, and generates booking confirmations for completed reservations.

This project was developed to gain hands-on experience in building real-world applications that address practical business requirements. The system architecture mirrors commercial airline reservation platforms by separating customer-facing operations from administrative functions.

## Features

### Passenger Interface
The passenger module enables customers to interact with the flight booking system through an intuitive menu-driven interface. Passengers can view comprehensive flight information including departure locations, destinations, scheduled dates and times, ticket pricing, and current seat availability. The booking process collects passenger information and processes reservations while automatically updating seat inventory. Upon successful booking, the system generates a personalized ticket file containing all relevant flight details and a unique booking identifier.

### Employee Interface
The administrative module provides airline staff with tools to manage the flight database through a password-protected interface. Employees can add new flights to the system by entering complete flight details including identification codes, route information, scheduling data, pricing, and seating capacity. The system also supports flight removal operations with safeguards to prevent accidental deletions. All administrative actions immediately update the persistent data storage to maintain system consistency.

### Data Management
The application implements file-based data persistence to ensure information survives between program sessions. Flight records are stored in a structured text format that the system reads during initialization and updates following any modifications. Each booking transaction generates an individual ticket file that serves as a confirmation record for passengers. The system tracks seat availability dynamically, preventing overbooking by validating capacity before confirming reservations.

## Technical Implementation

The system architecture utilizes a struct-based data model to organize flight information with fields for identification, routing, scheduling, pricing, and capacity tracking. File input and output operations provide persistent storage capabilities, with the flights.txt file serving as the primary data repository. The application reads this file during startup to populate the in-memory flight array and writes updates following any data modifications.

The user interface implements a hierarchical menu system that routes users to appropriate functional modules based on their role. Input validation throughout the application prevents common data entry errors and maintains system integrity. The authentication mechanism restricts access to administrative functions while keeping passenger operations publicly available.

## How to Run

### Prerequisites
A C++ compiler such as g++, MinGW, or any integrated development environment that supports C++ compilation is required to build and execute this program.

### Compilation
To compile the source code, navigate to the directory containing airline.cpp and execute the following command in your terminal or command prompt:

```
g++ airline.cpp -o airline
```

### Execution
After successful compilation, run the program using the appropriate command for your operating system. On Windows, execute airline.exe, while on Linux or macOS, use ./airline to launch the application.

### Employee Access
The administrative interface requires password authentication to prevent unauthorized access to management functions. For testing and demonstration purposes, the system accepts "amin" as a valid employee credential. In a production environment, this would be replaced with a secure authentication system.

## System Requirements

The application runs on any system with a standard C++ compiler and does not require external libraries beyond the standard C++ library. The program creates and manages text files in its working directory, so write permissions are necessary for proper operation.

## Technologies Used

This project was developed using C++ with standard library components for input/output operations, string manipulation, and file handling. The implementation relies on fundamental C++ concepts including structures for data organization, arrays for collection management, and functions for modular code design.

## Learning Outcomes

Developing this airline reservation system provided practical experience in translating real-world business requirements into functional software. The project reinforced understanding of data persistence mechanisms and the importance of maintaining consistency between in-memory data structures and permanent storage. Designing separate interfaces for different user roles highlighted considerations around access control and user experience design. Working through the complete development cycle from initial design through implementation and testing built confidence in approaching complex programming challenges systematically.

## Future Enhancements

Several improvements could extend the system's capabilities and align it more closely with commercial airline platforms. Implementing a database management system would provide more robust data storage with better query capabilities and concurrent access support. Adding search and filter functionality would help passengers find flights matching specific criteria such as destination, date range, or price limits. Expanding the booking system to support multiple passengers in a single reservation would better reflect real-world usage patterns. Incorporating a payment processing simulation would complete the transaction workflow. Developing a graphical user interface would improve accessibility for users less comfortable with console applications.

## Project Status

This project represents a first-semester academic exercise in C++ programming and software development fundamentals. While the system demonstrates core concepts effectively, it is intended primarily as a learning tool and portfolio piece rather than production software.

## Contributing

Feedback and suggestions for improvement are welcome. This project serves as a foundation for continued learning, and insights from experienced developers would be valuable for identifying areas of enhancement.

## License

This project is available as open source for educational purposes.
