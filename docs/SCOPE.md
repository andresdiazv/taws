# Project Scope

**Project:** Class B Terrain Awareness and Warning System (TAWS) prototype
**Document:** TAWS-SCOPE
**Version:** 0.1
**Last updated:** 2026-09-27

---

## 1. Purpose of this document

This document defines what this project will build and what it will not build. It exists so that scope stays fixed while the work is in progress, and so that anyone reading the repository can tell in five minutes what the system is meant to do.

Anything not listed as in scope is out of scope by default.

---

## 2. Problem statement

Controlled Flight Into Terrain (CFIT) is an accident in which a working aircraft, under the control of a qualified crew, is flown into the ground, water, or an obstacle without the crew realizing it is about to happen. Terrain Awareness and Warning Systems (TAWS) prevent this by comparing the aircraft's satellite-derived position against a stored terrain map and warning the crew of terrain ahead, not just terrain below, as older radar-based systems did. However, U.S. regulations require TAWS only on turbine-powered airplanes with six or more passenger seats (14 CFR 91.223, described in FAA Advisory Circular 23-18 paragraph 5.a.(1)). Small piston aircraft such as the Cessna 172 are not required to carry it, and certified equipment is expensive relative to the value of the aircraft, so many fly with no forward-looking terrain alerting at all.

The risk is greatest where terrain rises close to where aircraft fly low, especially when a pilot continues into poor weather and loses sight of the ground. Puerto Rico concentrates these conditions. Most airports sit near the coast, while the Cordillera Central (the mountain range that runs east to west through the island's interior) rises above 4,000 feet only a few miles inland, and tropical weather can bring low clouds that hide the mountains with little notice.

CFIT accidents are often not survivable, yet many are preventable with timely warning. This project addresses that gap by designing, building, and verifying a low-cost prototype that implements the core Class B TAWS alerting functions for a small general aviation airplane operating over Puerto Rico.

---

## 3. Goal

Design, build, and verify a prototype terrain alerting unit that:

1. Reads aircraft position, altitude, and ground speed from sensors or from a flight simulator.
2. Determines the aircraft's height above the terrain using a stored elevation map of Puerto Rico.
3. Determines the aircraft's position relative to the nearest runway using a stored airport database.
4. Issues audible and visual alerts when the aircraft is descending too quickly, losing altitude after takeoff, approaching terrain ahead, descending below the normal approach path, or passing 500 feet above the ground.
5. Detects when its own inputs are unreliable and announces that it is unavailable rather than failing silently.

---

## 4. Assumptions

These assumptions shape nearly every number in the requirements. If one changes, the requirements must be reviewed.

| # | Assumption |
|---|---|
| A-1 | The aircraft is a small piston-engine general aviation airplane. The test article is the Cessna 172P Skyhawk (1982) model as supplied with FlightGear 2024.1.7. |
| A-2 | Normal operating airspeed ranges from 60 knots indicated (approach, flaps 30) to 158 knots indicated (never exceed speed). See Appendix A for the source figures. Ground speed, which the system actually uses, is assumed to range from 40 to 180 knots to allow for wind. |
| A-3 | Normal operating altitude is below 10,000 feet above mean sea level. The aircraft's service ceiling is 13,000 feet (Appendix A). |
| A-4 | Vertical speed ranges from about −2,000 to +700 feet per minute in normal operation. The climb figure is from the Pilot's Operating Handbook (Appendix A); descent rates are to be confirmed by measurement (TBD-103). |
| A-5 | The operating area is the main island of Puerto Rico. Terrain outside that area is not covered. |
| A-6 | Position comes from a single satellite navigation receiver. There is no backup position source. |
| A-7 | Altitude comes from a barometric pressure sensor, blended with satellite altitude. There is no radio altimeter. |
| A-8 | The airport database covers three airports: Ponce (TJPS), San Juan (TJSJ), and Ceiba (TJRV). These were chosen because each presents a different terrain situation. The list is stored as data rather than written into the code, so more airports can be added later without changing the software. Private airstrips, heliports, and all other airports are absent. |
| A-9 | The unit runs on laboratory power (Universal Serial Bus, or USB) at room temperature. It is not designed for aircraft power, vibration, or temperature extremes. |
| A-10 | The unit is never installed in an aircraft or any other vehicle. Flight behavior is exercised using simulated inputs; the real sensors are exercised on the bench, stationary, at a known location. |

---

## 5. In scope

### 5.1 Alerting functions

The system implements the Class B functions described in Federal Aviation Administration (FAA) Advisory Circular 23-18 paragraph 6.b:

| ID | Function | Description |
|---|---|---|
| F-1 | Excessive rate of descent | Alerts when the aircraft is descending faster than is safe for its current height above the terrain. Caution first, then warning. |
| F-2 | Altitude loss after takeoff | Alerts when the aircraft loses altitude shortly after takeoff, when it should be climbing. |
| F-3 | Five hundred foot callout | Announces when the aircraft descends through 500 feet above the terrain or above the nearest runway elevation. |
| F-4 | Forward looking terrain alerting | Projects the flight path ahead, compares it against the stored terrain map, and alerts when the predicted clearance is too small or when terrain impact is predicted. Caution first, then warning. |
| F-5 | Premature descent alerting | Uses position and the airport database to determine whether the aircraft is hazardously below the normal approach path to the nearest runway, and alerts if so. |
| F-6 | Airport proximity inhibition | Suppresses terrain alerts that would otherwise occur during normal approach and landing at an airport in the database. |
| F-7 | Alert prioritization | When more than one alert condition is active, only the most urgent one is annunciated, following the Class B priority order in AC 23-18 Table 3. |
| F-8 | Health monitoring and annunciation | Detects invalid, stale, or out of range sensor data, inhibits terrain alerting, and annunciates that the system is unavailable. |
| F-9 | Power-up self test | Checks sensors, terrain map access, airport database access, and outputs at startup, and reports the result. Self test is disabled once the system considers itself airborne. |
| F-10 | On-ground inhibit | Suppresses alerts while the aircraft is on the ground so the unit is silent during taxi and parking. |

**Implementation order.** F-5 and F-6 depend on the airport database and are implemented last. If the schedule slips, they are the first candidates for deferral, which would return the system to a subset of Class B. Any such deferral is recorded here and in the verification report.

### 5.2 Engineering artifacts

| ID | Artifact |
|---|---|
| D-1 | This scope document |
| D-2 | Concept of operations describing each phase of flight and the scenarios the system must handle |
| D-3 | System requirements, each with a unique identifier, rationale, source, and verification method |
| D-4 | Software requirements derived from the system requirements |
| D-5 | Interface control document defining the data exchanged between the flight simulator and the unit |
| D-6 | Lightweight hazard assessment covering false alerts, missed alerts, and silent failures |
| D-7 | Unit tests, automated integration tests, and simulator-driven system tests |
| D-8 | Requirements verification matrix mapping every requirement to the test that proves it |
| D-9 | Verification report including code coverage results and known limitations |
| D-10 | Demonstration video and a repository that a stranger can clone and run |

### 5.3 Hardware and software

- One microcontroller board running the alerting software written in the C programming language.
- A satellite navigation receiver, a barometric pressure sensor, a memory card holding the terrain map and airport database, and indicator lights plus an audible alert device.
- A terrain map built from public United States Geological Survey (USGS) elevation data covering Puerto Rico.
- An airport database built from public FAA or equivalent open data, containing runway threshold positions, elevations, and headings for the airports defined in A-8.
- An automated test harness written in Python, driven by the FlightGear flight simulator.
- A reference model of the alerting logic written in MATLAB, used to generate expected results for the tests.

### 5.4 Verification approach

The system is verified at four levels, each reusing the tests from the level before it.

| Level | Description |
|---|---|
| Unit test | Each software module is tested alone on a development computer, with inputs chosen to exercise normal cases and invalid input. |
| Software in the loop | The complete alerting software runs on a development computer against recorded flight data, and its output is compared against the MATLAB reference model. |
| Hardware in the loop | The same software runs on the microcontroller board. FlightGear flies the aircraft and streams position, altitude, and speed to the board over the serial connection. The board runs the production software and produces real alerts; it cannot distinguish simulated inputs from live sensors. |
| Bench test with live sensors | The real satellite navigation receiver and barometric pressure sensor are run at a fixed, known location. Reported position is checked against a map, computed altitude against a nearby weather station, and the terrain lookup for that position against published elevation data. This confirms that the drivers, parsers, and terrain lookup work on live data rather than only on simulated data. |

Simulator runs are recorded to data files once and replayed during automated testing, so that test results are repeatable.

---

## 6. Out of scope

Each exclusion is deliberate. None of these is a gap to be filled later in this project.

| Excluded | Reason |
|---|---|
| Excessive closure rate to terrain | Not required for Class B equipment. |
| Flight into terrain when not in landing configuration | Requires landing gear and flap position inputs, which this system does not have. |
| Glideslope deviation alerting | Requires an instrument landing system receiver. |
| Windshear detection | Not a terrain function. |
| Obstacle alerting | Requires an obstacle database. Towers and buildings are not present in bare-earth elevation data. |
| Published instrument approach procedures | The premature descent function uses a straight nominal approach path to the runway, not published procedure data. |
| Airports outside the area defined in A-8 | Keeps the database small enough to build and verify by hand. |
| Terrain display | Not required for Class B equipment, and a display would roughly double the scope. |
| Certification or airworthiness approval | This is an educational project. It will never be installed or flown. |
| Environmental qualification, including vibration, temperature, and lightning testing | Requires laboratory equipment that is not available. |
| Airplane flight manual material and crew procedures | Only relevant to a system intended for installation. |
| Flight data recorder output | Not relevant to a prototype. |
| Cold weather altitude compensation | Puerto Rico does not experience the temperature extremes this feature addresses. Recorded as a limitation in section 7. |
| Automatic database updating | The terrain map and airport database are fixed at build time. Real equipment must accept updates; this prototype does not. |

---

## 7. Known limitations

These are honest statements about what the finished system will not do well. They belong in the final report as written.

1. **Bare-earth terrain data.** The elevation map describes the ground only. Towers, buildings, and other obstacles are absent, so the system cannot warn about them.
2. **Terrain map resolution.** Grid cells are roughly 10 meters across before processing, and coarser after the map is reduced in size. Narrow features such as sharp ridges may be represented imprecisely.
3. **Single position source.** If the satellite navigation receiver fails, the system has nothing to fall back on and can only announce that it is unavailable.
4. **Coverage limited to Puerto Rico.** Outside the mapped area the system reports that terrain data is unavailable and inhibits terrain alerting.
5. **Only three airports are known to the system.** Landing anywhere else will produce alerts, because a landing looks exactly like a descent toward the ground and the system has no way to know a runway is there.
6. **Static databases.** Terrain and airport data are snapshots taken on a recorded date. Runway changes, new construction, and terrain changes after that date are not reflected.
7. **Simplified approach model.** The premature descent function assumes a straight nominal descent path to the runway threshold. Aircraft flying a published procedure that differs from that path may receive nuisance alerts.
8. **No temperature compensation.** In very cold conditions barometric altitude reads higher than the true height, which would reduce the effective warning margin. This does not apply to the intended operating area.
9. **Alert threshold values are self-derived.** The published minimum performance standards that define the exact alerting curves are paid documents. Threshold values used here are derived from publicly available descriptions and are documented with their reasoning. They are not claimed to match any certified product.
10. **Live sensors are only tested while stationary.** The real receiver and pressure sensor are exercised at a fixed location, so the altitude and vertical speed estimator is never fed real sensor data while moving. Its behavior under real motion, including real noise and real signal loss, is verified only against simulated data.
11. **The nuisance alert figure is a sample, not a rate.** Twenty flights can show that the system behaves sensibly. They cannot prove how often it would misbehave over thousands of flight hours, which is what the advisory circular asks of real equipment. The figures in section 8 are a sanity check, not a claim about reliability.
12. **Not certified.** The system meets no regulatory standard and has undergone no formal approval of any kind.

---

## 8. Success criteria

The project is complete when all of the following are true:

1. Every system requirement has at least one automated test, and every test passes or is explicitly deferred with a written reason.
2. The unit runs the complete alerting chain on real hardware at its designed update rate (TBD-106), and the measured time taken by each cycle stays inside the documented budget.
3. A single command runs the full scenario suite against the hardware and produces a pass or fail report.
4. In simulation, terrain warnings occur at least 30 seconds before the projected point of impact. At 120 knots that is about one nautical mile of room, and enough time for this aircraft to climb roughly 350 feet, which clears the kind of ridge the system is meant to protect against.
5. Across 20 simulated flights flown normally, no nuisance alerts occur while cruising or en route.
6. Across 10 simulated approaches to airports in the database, at most one nuisance alert occurs. Every one that does occur is investigated, explained, and written up in the verification report.
7. Code coverage meets the target recorded in the verification plan.
8. The repository contains everything needed for another person to reproduce the results.

---

## 9. Constraints

| # | Constraint |
|---|---|
| C-1 | One engineer, working roughly 10 to 15 hours per week. |
| C-2 | Target duration of 8 to 10 months. |
| C-3 | Hardware budget of approximately 200 US dollars. |
| C-4 | Software must be free or low cost. No commercial verification tools are available. |
| C-5 | All source material must be publicly available. No proprietary or export controlled documents are used. |

---

## 10. Risks

| # | Risk | Response |
|---|---|---|
| R-1 | The terrain map is too large for the microcontroller's memory. | Store the map on a memory card and load only the tiles near the aircraft. Prove the approach early, in the terrain stage. |
| R-2 | Alert thresholds cannot be sourced from public documents. | Define thresholds independently, document the reasoning, and state clearly that they do not replicate any certified product. |
| R-3 | Simulator interface proves harder than expected. | Build and test the alerting logic against recorded data first, so the simulator link is not on the critical path. |
| R-4 | Scope grows during the project. | Every addition must trace to a requirement. Ideas without one go on the backlog. |
| R-5 | Available time drops below plan. | Stages are ordered so that stopping after any completed stage still leaves a coherent, demonstrable result. |
| R-6 | FlightGear terrain elevations differ from the USGS data used by the system, so simulated height above terrain disagrees with computed height. | Measure the difference early and record it. Treat the simulator's elevation as the reference during simulator testing, and the USGS data as the reference during ground testing. |
| R-7 | The airport database and premature descent function take longer than planned. | They are implemented last. If they cannot be completed, they are deferred and the deferral is recorded in section 5.1 and in the verification report. |

---

## 11. Definitions

| Term | Meaning |
|---|---|
| Above ground level (AGL) | Height measured from the ground directly below the aircraft. |
| Alert | Any visual or audible signal used to get the crew's attention or tell them something. |
| Caution | An alert requiring the crew's immediate attention. Corrective action will usually follow. |
| Warning | An alert requiring immediate action by the crew. |
| Controlled flight into terrain (CFIT) | An accident in which a working aircraft under crew control is flown into terrain, water, or an obstacle without adequate awareness. |
| Digital elevation model (DEM) | A grid of numbers giving the ground height at each location. |
| False alert | An alert that should never have happened, because the condition the system was designed to detect was not actually present. Usually caused by a fault or bad data. |
| Forward looking terrain alerting (FLTA) | A function that looks ahead along the projected flight path and alerts when terrain poses a threat. |
| Global navigation satellite system (GNSS) | The general term for satellite positioning systems, including the United States Global Positioning System (GPS). |
| Ground proximity warning system (GPWS) | The earlier generation of terrain warning equipment, which did not use a terrain map. |
| Ground speed | Speed measured relative to the ground, which includes the effect of wind. This is the speed the system uses. |
| Knots calibrated airspeed (KCAS) | Indicated airspeed corrected for instrument and installation error. |
| Knots indicated airspeed (KIAS) | Airspeed as shown on the aircraft's instrument. |
| Knots true airspeed (KTAS) | Airspeed corrected for altitude and temperature. |
| Mean sea level (MSL) | Altitude measured from average sea level rather than from the ground below. |
| Nuisance alert | An alert that is correct according to the system's own rules, but unhelpful, because the flight was proceeding normally and safely. Usually a sign that the rules need refining, not that something broke. |
| Premature descent alert (PDA) | An alert issued when the aircraft is hazardously below the normal approach path to the nearest runway. |
| Runway threshold | The beginning of the portion of the runway usable for landing, used here as the reference point for the approach path. |
| Terrain awareness and warning system (TAWS) | Equipment that warns the crew about hazardous terrain in time to avoid it. |
| Unit | The finished prototype: the microcontroller board, the sensors, the memory card, and the lights and sounder, together in one enclosure. |
| Update rate | How many times per second the software reads its sensors, recalculates, and decides whether to alert. |

---

## 12. References

| Reference | Notes |
|---|---|
| FAA Advisory Circular 23-18, *Installation of Terrain Awareness and Warning System (TAWS) Approved for Part 23 Airplanes*, 14 June 2000 | Primary source for the Class B function list, alert prioritization, and test approach. |
| 14 CFR 91.223, *Terrain awareness and warning system* | The rule that defines which aircraft must carry TAWS. |
| FAA Technical Standard Order TSO-C151 | The equipment standard referenced by the advisory circular. Later revisions exist. |
| *Cessna Model 172P Pilot's Operating Handbook and FAA Approved Airplane Flight Manual* | Source of the speed, climb, and ceiling figures in section 4. |
| USGS 3D Elevation Program elevation data | Public domain source of the terrain map. |
| FAA National Airspace System Resource (NASR) data, or equivalent open airport data | Source of runway positions, elevations, and headings. Record the snapshot date used. |
| FlightGear 2024.1.7 with the Cessna 172P aircraft model | Source of simulated flight data for testing. |

---

## 13. Open items

| ID | Description | Resolve by |
|---|---|---|
| TBD-103 | Maximum descent rate the system must handle, to be confirmed by flying and measuring descents in the simulator | Requirements review |
| TBD-106 | Update rate and the time budget allowed for one cycle | Requirements review |

Resolved items are kept here so the history of each decision is visible.

| ID | Description | Resolution | Date |
|---|---|---|---|
| TBD-100 | Minimum warning time before projected impact | 30 seconds | 2026-09-27 |
| TBD-101 | Number of normal flights used to measure nuisance alerts | 20 flights | 2026-09-27 |
| TBD-102 | Acceptable nuisance alerts | None while cruising; at most one per ten approaches | 2026-09-27 |
| TBD-104 | Airports included in the database | TJPS, TJSJ, TJRV | 2026-09-27 |
| TBD-105 | Number of simulated approaches used for nuisance measurement | 10 approaches | 2026-09-27 |

---

## 14. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | 2026-09-27 | Initial draft |

---

## Appendix A: Aircraft performance figures

All figures are taken from the *Cessna Model 172P Pilot's Operating Handbook and FAA Approved Airplane Flight Manual* for the test article named in A-1. They are recorded here so that every speed and altitude assumption in section 4 can be traced to a published source rather than to memory.

| Figure | Value | Where in the handbook |
|---|---|---|
| Never exceed speed (Vne) | 158 KIAS | Section 2, Airspeed Limitations |
| Maximum structural cruising speed (Vno) | 127 KIAS | Section 2, Airspeed Limitations |
| Maximum speed at sea level | 123 knots | Section 1, Specifications |
| Cruise, 75 percent power at 8,000 ft | 120 knots | Section 1, Specifications |
| Cruise speed range across the performance table | about 86 to 121 KTAS | Section 5, figure 5-8 |
| Stall speed, flaps down, power off | 46 KCAS | Section 1, Specifications |
| Stall speed, flaps up, power off | 51 KCAS | Section 1, Specifications |
| Normal approach speed, flaps 30 degrees | 60 to 70 KIAS | Section 4, Normal Procedures |
| Rate of climb at sea level | 700 feet per minute | Section 1, Specifications |
| Service ceiling | 13,000 ft | Section 1, Specifications |

**How these map to the assumptions.** A-2 takes its lower bound from the approach speed and its upper bound from the never exceed speed, which brackets everything the aircraft does in normal flight. A-3 takes its ceiling from the service ceiling. A-4 takes its climb figure from the rate of climb. The descent figure in A-4 has no published equivalent, which is why it remains open as TBD-103 and must be measured.

**Airspeed and ground speed are not the same.** Every figure above is airspeed, measured relative to the air. The system works from ground speed, measured relative to the ground. Wind adds to or subtracts from the aircraft's speed over the ground, so A-2 brackets ground speed more widely than the airspeed figures above.