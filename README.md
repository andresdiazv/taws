# Terrain Awareness and Warning System (TAWS)
[![C/C++ CI](https://github.com/andresdiazv/taws/actions/workflows/tests.yml/badge.svg)](https://github.com/andresdiazv/taws/actions/workflows/tests.yml)

Controlled flight into terrain (CFIT) occurs when a fully functional aircraft is unintentionally flown into the ground, often because the crew doesn't realize how close the terrain is. This project develops a Class B Terrain Awareness and Warning System prototype, based on FAA AC 23-18, that uses GPS, barometric altitude, and a Puerto Rico terrain database to warn pilots before impact.

*Educational project; not certified for flight and not affiliated with any companies*

## Build and test

Requires `gcc` and `make`.

```bash
make test     # build and run the unit tests
make clean    # remove build output
```

## Resources used

- https://makefiletutorial.com: learned about rules, targets, prerequisites, variables.
- https://github.com/ThrowTheSwitch/Unity: reference for unit testing in C.