# Terrain Awareness and Warning System (TAWS)
[![C/C++ CI](https://github.com/andresdiazv/taws/actions/workflows/tests.yml/badge.svg)](https://github.com/andresdiazv/taws/actions/workflows/tests.yml)

A controlled flight into terrain (CFIT) occurs when a fully functional aircraft is unintentionally flown into the ground, often because the crew doesn't realize how close the terrain is. This project develops a Class B Terrain Awareness and Warning System prototype, based on FAA AC 23-18 (Federal Aviation Administration Advisory Circular Part 23 Airplane), that uses GPS, barometric altitude, and a Puerto Rico terrain database to warn pilots before impact.

### Class B TAWS Equipment:
A class of equipment that is defined in TSO C151a. As a minimum, it will provide alerts for the following circumstances:
- Reduced required terrain clearance. 
- Imminent terrain impact. 
- Premature descent. 
- Excessive rates of descent. 
- Negative climb rate or altitude loss after take-off. 
- Descent of the airplane to 500 feet above the terrain or nearest runway elevation (voice callout "Five Hundred") during a non-precision approach. 

Class B TAWS installation may provide a terrain awareness display that shows either the surrounding terrain or obstacles relative to the airplane, or both.


*Educational project; not certified for flight and not affiliated with any companies*

## Build and test

Requires `gcc` and `make`.

```bash
make test     # build and run the unit tests
make clean    # remove build output
```

## Resources used

- https://www.faa.gov/regulations_policies/advisory_circulars/index.cfm/go/document.information/documentid/22312: Acceptable means of obtaining FAA airworthiness approval for the installation of a TAWS that has been approved under Technical Standard Order (TSO)-C151a, TAWS, in a Part 23 airplane. I used this as a reference for the entire project.
- https://www.glasscockpitaviation.com/wp-content/uploads/2022/07/cessna-n54829-poh.pdf: CESSNA 172P (1982) will be the airplane we are testing with. Used as the source for the aircraft performance figures (speeds, climb rate, and service ceiling) in SCOPE.md Appendix A.
- https://ntrs.nasa.gov/citations/20170001761: NASA Systems Engineering Handbook. Used as a reference when building SCOPE.md
- https://makefiletutorial.com: learned about rules, targets, prerequisites, variables.
- https://github.com/ThrowTheSwitch/Unity: reference for unit testing in C.