# ATmega2560 Drivers and Examples

Driver implementations and example programs for the ATmega2560 microcontroller focusing on peripheral interfacing and low-level hardware control.

## Repository Structure

### Drivers

The [Drivers](./Drivers) folder contains low-level driver implementations for ATmega2560 peripherals:

- [gpio.h](./Drivers/gpio.h) - General Purpose Input/Output operations
- [iomap.h](./Drivers/iomap.h) - Input/Output mapping configurations
- [7seg.h](./Drivers/7seg.h) - Seven Segment Display driver
- [keypad.h](./Drivers/keypad.h) - Matrix keypad interface driver

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

- [Calculator](./Examples/Atmega2560p-application-projects/Calculator) - Calculator with keypad and 7-segment display
- [Keypad](./Examples/BalajeeSir-Example-Programs/Keypad) - Numeric keypad (0-9) interface
- [LED_PROGRAMS](./Examples/BalajeeSir-Example-Programs/LED_PROGRAMS) - LED control programs
- [LIFT](./Examples/Atmega2560p-application-projects/LIFT) - Multi-floor elevator control system
- [Locker](./Examples/Atmega2560p-application-projects/Locker) - Password-based digital lock

## Technical Skills

Written in C with focus on:
- Embedded C programming
- Hardware abstraction layer design
- Register-level programming
- Memory-mapped I/O

**Development Tools:**
- Wokwi Simulator
- Git
- AVR-GCC Compiler
- AVRDUDE Programmer

---

Thank you for reading.
