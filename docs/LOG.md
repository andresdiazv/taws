Template:
- **Built**:
- **Learned**:
- **Blocked / open**:
- **Reflection**:

2026-09-24
- **Built**: Added speed conversions between knots and meters per second, and switched all my conversion numbers to full precision instead of rounded values. Updated the tests to match, and everything passes. The core unit conversions are basically done.
- **Learned**: Rounding numbers early can quietly cause wrong answers later, which matters a lot in a project like this. Once I stopped rounding (for example, using 3.2808398950131235 feet per meter instead of 3.28084), my tests failed because my expected values weren't as precise as the new results. Now I use Python in the terminal to calculate expected values and paste them straight into my tests. Much better than doing it on my phone calculator.
- **Blocked / open**: None. Next: Makefile and GitHub Actions so the tests run automatically.
- **Reflection**: I finally get why clear variable names matter. I was stuck for a while on two speed constants because their names made it hard to tell which way each conversion went. The tests caught it: I worked out the answer by hand, the test failed, and renaming the variables made everything click.

2026-09-23:
- **Built**: units module (feet_to_meters) with three Unity tests, all passing.
- **Learned**: Compiling and linking are different steps. A header only declares that a function exists; the actual code lives in the .c file, and every .c file has to be passed to gcc or the linker reports "undefined reference." Also: Unity's double assertions need -DUNITY_INCLUDE_DOUBLE, and doubles need tolerance-based comparison rather than ==, because values like 0.3048 aren't exact in binary.
- **Blocked / open**: none. Next: negative-value test, meters_to_feet, Makefile.
- **Reflection**: First time writing tests. My day job is testing and troubleshooting, so this felt intuitive, and I'm now wondering why I never tested my earlier projects.