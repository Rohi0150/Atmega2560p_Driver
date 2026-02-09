# ATmega2560 Drivers and Programs 

Driver implementations and example programs for the ATmega2560 microcontroller focusing on peripheral interfacing and low-level hardware control.

## Repository Structure

### Drivers

The [Drivers](./Drivers) folder contains low-level driver implementations for ATmega2560 peripherals:

- [GPIO](./Drivers/GPIO) - General Purpose Input/Output operations
- [IOMAP](./Drivers/IOMAP) - Input/Output mapping configurations
- [7SEG](./Drivers/7SEG) - Seven Segment Display driver
- [Keypad](./Drivers/Keypad) - Matrix keypad interface driver

These drivers provide hardware abstraction for easier peripheral control.

### Examples

The [Examples](./Examples) folder contains sample programs showing how to use the drivers:

- Basic peripheral usage examples
- Reference code for common tasks
- Driver testing utilities
- Working implementations for different use cases

## Getting Started

1. Clone the repository
2. Check out the [Examples](./Examples) folder for sample code
3. Use drivers from the [Drivers](./Drivers) folder in your code
4. Compile and upload to ATmega2560 hardware or test using Wokwi simulator

## Implementation Examples

- [Calculator](./Calculator) - Calculator with keypad and 7-segment display
- [Headers](./Headers) - ATmega2560p register definitions
- [Keypad](./Keypad) - Numeric keypad (0-9) interface
- [LED_PROGRAMS](./LED_PROGRAMS) - LED control programs
- [LIFT](./LIFT) - Multi-floor elevator control system
- [Locker](./Locker) - Password-based digital lock

## Technical Skills

Written in C with focus on:
- Embedded C programming
- Hardware abstraction layer design
- Peripheral driver development
- Interrupt handling
- Register-level programming
- Memory-mapped I/O

**Development Tools:**
- AVR-GCC Compiler
- AVRDUDE Programmer
- Wokwi Simulator
- Git

---

Thank you for reading.
