Template:
- **Built**:
- **Learned**:
- **Blocked / open**:
- **Reflection**:


2026-09-23:
- **Built**: units module (feet_to_meters) with three Unity tests, all passing.
- **Learned**: Compiling and linking are different steps. A header only declares that a function exists; the actual code lives in the .c file, and every .c file has to be passed to gcc or the linker reports "undefined reference." Also: Unity's double assertions need -DUNITY_INCLUDE_DOUBLE, and doubles need tolerance-based comparison rather than ==, because values like 0.3048 aren't exact in binary.
- **Blocked / open**: none. Next: negative-value test, meters_to_feet, Makefile.
- **Reflection**: First time writing tests. My day job is testing and troubleshooting, so this felt intuitive, and I'm now wondering why I never tested my earlier projects.