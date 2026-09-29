Template:
- **Built**:
- **Learned**:
- **Blocked / open**:
- **Reflection**:

## Future Improvements
- [ ] Add variables to the Makefile so future changes are easier. (added 2026-09-25)

2026-09-28
- **Built**: Wrote docs/CONOPS.md (v0.1): the current situation without a TAWS, the proposed system, operating states, the alerts a pilot hears and sees, and 14 operational scenarios covering normal flights, hazards, and failures, with a table showing which functions each scenario exercises. Created docs/TBD.md as the single list of open decisions for the whole project. Updated SCOPE.md to v0.2: a speaker with an audio module replaces the buzzer so alerts can be spoken, section 5.4 now lists where flight data files come from, and success criterion 7 points to a coverage TBD instead of a verification plan. Restructured REQUIREMENTS.md (v0.2) to follow a standard systems engineering layout. Split TAWS-SYS-700 into two requirements (700 inhibits terrain alerts, 710 announces the system is unavailable) and rewrote TAWS-SYS-400 to match F-3, adding the runway elevation reference. Both now cite ConOps scenarios as sources. Added TBD-113 (code coverage target) and TBD-114 (when the 500 foot callout is armed). All the documents now point to each other, so they connect like a system and each piece of information lives in one place.
- **Learned**: To think from the perspective of a pilot and what they would actually experience: what they hear, what they see, and what they are expected to do. Learned about use cases, which here are the operational scenarios. A scenario does not have to be a full flight from airport to airport; most are a slice of a flight that tests one thing. Also learned where FlightGear fits: the TAWS only sees numbers, so most tests use scripted or modified data files, and FlightGear is for realistic recordings, hardware-in-the-loop, and the demo. Failure cases need fault injection, meaning good data broken on purpose, because the simulator always sends good data. A requirement with two actions has to be split, because otherwise it can half pass and half fail, and there is no way to record that. Citing a scenario in the Source field builds a chain from AC 23-18 to scenario to requirement to test, so every requirement can be traced back to why it exists.
- **Blocked / open**: TBD-109 (exact wording of the pull-up and terrain messages), TBD-110 (unavailable message), and TBD-114 (when the 500 foot callout is armed). TBD-103 (descent rate) still needs measuring.
- **Next**: Write the knots_to_meters_per_second tests. Draft the first requirements for F-1, F-3, F-8, and F-10 with a short hazard table. Write the interface control document before making any flight data files.
- **Reflection**: Writing the ConOps changed how I see the project. Instead of thinking about code, I had to think about the person in the airplane and what could go wrong for them. Updating the other documents at the same time showed me that documentation is also a system: if one document changes, the others have to stay connected.

2026-09-27
- **Built**: Wrote docs/SCOPE.md (v0.1): problem statement, goal, assumptions, in and out of scope, known limitations, success criteria, constraints, risks, definitions, references, open items, and an appendix of Cessna 172P performance figures pulled from the Pilot's Operating Handbook. Added the airport database and premature descent alerting back into scope once I learned real Class B systems include them. Set up FlightGear with the 172P over Puerto Rico.
- **Learned**: A scope document is mostly about what you are *not* building, and every exclusion needs a reason. Assumptions drive almost every number later, so each one should trace to a source (the POH for speeds and ceiling, AC 23-18 paragraphs for the Class B functions). The system uses ground speed, not airspeed, because the GPS reports it and wind changes how fast you actually reach terrain.
- **Blocked / open**: TBD-103 (maximum descent rate) needs measuring in FlightGear. First attempt, the plane spiraled because nothing was flying it. Fix: start paused with --enable-freeze, center controls with numpad 5, and engage the KAP 140 autopilot (Autopilot, then ALT) right after unpausing. TBD-106 (update rate) stays open until requirements.
- **Next**: Measure descent rates in FlightGear, write docs/conops.md, extract the Class B lines from AC 23-18 into the requirements file, and draft the first ten requirements.
- **Reflection**: Documentation writing and reading is difficult but I understand why it is needed. I learned a lot from reading the different documents on AC 23-18, Cessna 172P, and other related documents. Writing the SCOPE.md took many hours and showed me how to scan documents and grab the information I need. This document sets me up for the future when I have to code the rest of the system so I don't stray away from the scope of the project.

2026-09-25
- **Built**: A Makefile, and a GitHub Actions workflow that uses the Makefile to run the tests.
- **Learned**: How a Makefile works: rules, targets, and requirements.
- **Blocked / open**: None.
- **Reflection**: Realized I need a place to track things I want to improve later, so I added a Future Improvements section to this log.

2026-09-24:
- **Built**: Added speed conversions between knots and meters per second, and switched all my conversion numbers to full precision instead of rounded values. Updated the tests to match, and everything passes. The core unit conversions are basically done.
- **Learned**: Rounding numbers early can quietly cause wrong answers later, which matters a lot in a project like this. Once I stopped rounding (for example, using 3.2808398950131235 feet per meter instead of 3.28084), my tests failed because my expected values weren't as precise as the new results. Now I use Python in the terminal to calculate expected values and paste them straight into my tests. Much better than doing it on my phone calculator.
- **Blocked / open**: None. Next: Makefile and GitHub Actions so the tests run automatically.
- **Reflection**: I finally get why clear variable names matter. I was stuck for a while on two speed constants because their names made it hard to tell which way each conversion went. The tests caught it: I worked out the answer by hand, the test failed, and renaming the variables made everything click.

2026-09-23:
- **Built**: units module (feet_to_meters) with three Unity tests, all passing.
- **Learned**: Compiling and linking are different steps. A header only declares that a function exists; the actual code lives in the .c file, and every .c file has to be passed to gcc or the linker reports "undefined reference." Also: Unity's double assertions need -DUNITY_INCLUDE_DOUBLE, and doubles need tolerance-based comparison rather than ==, because values like 0.3048 aren't exact in binary.
- **Blocked / open**: none. Next: negative-value test, meters_to_feet, Makefile.
- **Reflection**: First time writing tests. My day job is testing and troubleshooting, so this felt intuitive, and I'm now wondering why I never tested my earlier projects.