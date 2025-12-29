# KeyFort_v1

## Description
**KeyFort_v1** is a C program that evaluates the strength of a password and provides suggestions to make it stronger.  
It checks password length, character variety (lowercase, uppercase, digits, special characters), repetitions, and sequential patterns.  
A visual strength bar is displayed to easily see password security.

## Features
- Password strength rating: Weak → Strong  
- Visual strength bar  
- Feedback on character composition  
- Tips for improving weak passwords  
- Supports passwords of 5 to 18 characters  

## Requirements
- GCC or any standard C compiler  
- Compatible with Windows, Linux, or macOS  

## How to Compile and Run
1. Open terminal or command prompt in the project folder.  
2. Compile the program:
   ```bash
   gcc KeyFort_v1.c -o KeyFort_v1
Run the executable:
  # On Linux/macOS
  ./KeyFort_v1

  # On Windows
  KeyFort_v1.exe
