# Calculator Project

This repository contains the source code for a simple calculator implemented in C for an AVR microcontroller. The calculator is designed to interact with a 4x4 keypad and display results on a character LCD.

## Project Structure

The project is organized into several directories:

- **MCAL**: Microcontroller Abstraction Layer, containing low-level hardware abstraction functions.
  - **PORT**: Interface for port configurations.
  - **DIO**: Interface for digital I/O operations.

- **lib**: Library for standard data types.

- **Hall**: Higher-level modules.
  - **CLCD**: Interface for character LCD.
  - **KAYPAD**: Interface and configuration for the keypad.
- **App**: Application layer containing calculator logic.
  - **calc.h**: Header file defining the calculator state and interface.
  - **calc.c**: Source file containing the calculator logic and operations.
  - **main.c**: The main application source code for the calculator.
  
## Build and Flashing

The project can be built using an AVR toolchain. Make sure to configure the Makefile appropriately for your toolchain and programmer. You can then use the provided Makefile to build the project and flash it onto your AVR microcontroller.

```bash
make all
make flash
```

## Calculator Operation

The calculator supports basic arithmetic operations (+, -, *, /) and can handle positive and negative integer operands. It utilizes a 4x4 keypad for input and displays results on a character LCD. The code includes error handling for division by zero, displaying an error message on the LCD in such cases.

## Usage

1. Connect your AVR microcontroller to the keypad and LCD as per the defined interfaces.
2. Build and flash the calculator project onto your microcontroller.
3. Use the keypad to input numbers and operations, and view the results on the LCD.

## Error Handling

The calculator project includes a robust error-handling mechanism, especially for division by zero. If a division by zero is detected, an error message is displayed on the LCD, and the calculator state is cleared.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Feel free to contribute, report issues, or suggest improvements. Happy coding!