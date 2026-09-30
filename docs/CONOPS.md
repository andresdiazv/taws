# Concept of Operations

**Project:** Class B Terrain Awareness and Warning System (TAWS) prototype\
**Document:** TAWS-CONOPS\
**Version:** 0.3\
**Last updated:** 2026-09-30

---

## 1. Purpose of this document

The purpose of this document is to describe the characteristics of the TAWS from the viewpoint of a pilot that would use a system like this. 

---

## 2. Scope

This document covers a small piston airplane (the Cessna 172P) flying over the main island of Puerto Rico, using the three airports in the database: Ponce (TJPS), San Juan (TJSJ), and Ceiba (TJRV). These are simple choices that test different situations: Ponce has the Cordillera Central to the north, Ceiba has the Sierra de Luquillo to the northwest, and San Juan sits on flat ground by the coast. It describes what the pilot sees and hears in normal flight, in hazardous flight, and when the system fails. What the project will and will not build is defined in [SCOPE.md](SCOPE.md).

---

## 3. Referenced documents

| Reference | Notes |
|---|---|
| [SCOPE.md](SCOPE.md)| Referenced in the Scope section of this document. |
| [TBD.md](TBD.md) | Open items raised in this document. |
| FAA Advisory Circular 23-18 | Source of the Class B functions, alert types, and alert priority order. |
| FAA TSO-C151c, Appendix 1, effective 6/27/12 | Source of the aural alert wording (Table 4-1, Class B). |

---

## 4. Current situation

### 4.1 Operational environment

Most Puerto Rico airports sit near the coast. The Cordillera Central rises above 4,000 feet only a few miles inland, and the Sierra de Luquillo rises in the northeast near San Juan and Ceiba. Tropical weather can bring low clouds that hide the mountains with little warning. Small airplanes often fly low here, below the clouds, between the coast and the interior.

### 4.2 Current means of terrain awareness

In an airplane like the Cessna 172P, the pilot avoids terrain by:

- Looking outside.
- Reading altitude from the barometric altimeter, which shows height above sea level, not height above the ground.
- Comparing that altitude against terrain heights printed on paper or electronic charts.
- In some cases, using a tablet app that shows terrain. These apps are not certified and are not required.

### 4.3 Shortcomings

- The altimeter does not show how close the ground is, only how high the airplane is above sea level.
- Nothing warns the pilot about terrain *ahead*. The pilot must notice it.
- When clouds hide the mountains, looking outside no longer works, and a busy or disoriented pilot may not check the charts in time.
- Certified TAWS equipment is not required for this airplane and costs a lot compared to the value of the airplane, so most do not carry it.

These gaps lead to controlled flight into terrain (CFIT).

---

## 5. Proposed system

### 5.1 Overview

The TAWS is a small unit that knows where the airplane is, how high it is, and what the terrain around it looks like. It stays quiet during normal flight. When the airplane is headed toward terrain, descending too fast, or too low for where it is, it gives the pilot a spoken message and a text message on a small display. A caution tells the pilot to pay attention. A warning tells the pilot to act now. If the unit cannot trust its own data, it says so instead of staying silent.

### 5.2 Users and stakeholders

| Stakeholder | Role | What they need from the system |
|---|---|---|
| Pilot | Primary user | Clear, timely alerts. No alerts when nothing is wrong. A clear signal when the system is not working. |
| Developer and tester | Builds and verifies the system | Repeatable tests and data that shows every requirement is met. |

### 5.3 System context

| Type | Item | Provides or receives |
|---|---|---|
| Input | Satellite navigation receiver | Position, ground speed, track, satellite altitude |
| Input | Barometric pressure sensor | Pressure altitude |
| Input | FlightGear simulator (testing only) | Replaces both sensors with simulated data over a serial connection |
| Stored data | Terrain map (memory card) | Ground height at each position in Puerto Rico |
| Stored data | Airport database (memory card) | Runway positions, elevations, and headings for TJPS, TJSJ, and TJRV |
| Stored data | Settings file (memory card) | Terrain ahead wording variant (A or B) |
| Output | Small color display | Alert text in amber (caution) or red (warning), and system status |
| Output | Speaker with audio playback module | Spoken alert messages, played from recorded audio files |

### 5.4 Major functions

| ID | Function | In plain language |
|---|---|---|
| F-1 | Excessive rate of descent | "You are coming down too fast for how close the ground is." |
| F-2 | Altitude loss after takeoff | "You just took off and you are going down instead of up." |
| F-3 | Five hundred foot callout | "You are 500 feet above the ground or the runway." |
| F-4 | Forward looking terrain alerting | "There is terrain ahead on your current path." |
| F-5 | Premature descent alerting | "You are too low for how far you are from the runway." |
| F-6 | Airport proximity inhibition | Stays quiet during a normal landing at a known airport. |
| F-7 | Alert prioritization | If several things are wrong, says only the most urgent one. |
| F-8 | Health monitoring | Tells the pilot when the system cannot be trusted. |
| F-9 | Power-up self test | Checks itself when turned on and reports the result. |
| F-10 | On-ground inhibit | Stays quiet while taxiing and parked. |

### 5.5 Operating modes and states

| State | Description | Entered when | Exited when |
|---|---|---|---|
| Self test | Checks sensors, memory card, and outputs. If the airplane is already airborne, only the silent checks run. | Power is applied. | Test passes (to On ground or Airborne, using the rule below) or fails (to Unavailable). |
| On ground | All alerts inhibited. | Self test passes, or ground speed or height above terrain drops below its threshold. | Ground speed is above TBD-118 and height above terrain is above TBD-119. |
| Airborne | All alerting functions active. | Ground speed is above TBD-118 and height above terrain is above TBD-119. | Ground speed or height above terrain drops below its threshold, or data becomes invalid. |
| Unavailable | All alerts inhibited. Unavailable message shown. | Self test fails, or sensor or terrain data becomes invalid. | The failed data has been good for 5 seconds in a row. The message clears with no sound. A failed self test stays until the unit is restarted. |

### 5.6 Alerts seen by the pilot

Priority is the position in AC 23-18 Table 3, where 1 is the most urgent. Only the Class B TAWS entries are listed. When two alerts are active at once, only the one with the lower number is spoken. All aural wording is quoted from TSO-C151c Appendix 1 Table 4-1, Class B. The terrain ahead alerts show the default wording, Variant A; both variants are in section 5.7. Altitude loss after takeoff uses "Don't Sink" only, so "Too Low Terrain" always means premature descent. The display shows the spoken message in capitals, without repeats, for example "PULL UP" or "CAUTION TERRAIN". "Five Hundred" plays once per descent. "TAWS Unavailable" is spoken once, and the display keeps showing it until the system recovers.

| Priority | Alert | Type | Aural message | Visual indication | Expected pilot response |
|---|---|---|---|---|---|
| 2 | Excessive descent | Warning | "Pull-Up" | Red text | Climb immediately. |
| 3 | Terrain ahead | Warning | "Terrain, Terrain; Pull-Up, Pull-Up" | Red text | Climb immediately. |
| 6 | Terrain ahead | Caution | "Caution, Terrain; Caution, Terrain" | Amber text | Check position and altitude. Climb or turn away. |
| 7 | Premature descent | Caution | "Too Low Terrain" | Amber text | Stop descending until on the normal approach path. |
| 8 | Five hundred feet | Callout | "Five Hundred" | None | None. Awareness only. |
| 9 | Excessive descent | Caution | "Sink Rate" | Amber text | Reduce descent rate. |
| 10 | Altitude loss after takeoff | Caution | "Don't Sink" | Amber text | Establish a climb. |
| None | System unavailable | Status | "TAWS Unavailable" (once) | Unavailable message | Do not rely on the TAWS. Fly by other means. |

### 5.7 Terrain ahead wording variants

TSO-C151c Appendix 1 para 4.7 allows two wordings for the terrain ahead alerts. The alert logic is the same; only the words differ. The system uses Variant A unless Variant B is selected (TAWS-SYS-510 to 530).

| Variant | Caution | Warning |
|---|---|---|
| A (default) | "Caution, Terrain; Caution, Terrain" | "Terrain, Terrain; Pull-Up, Pull-Up" |
| B | "Terrain Ahead; Terrain Ahead" | "Terrain Ahead, Pull-Up; Terrain Ahead, Pull-Up" |

---

## 6. Operational scenarios

### 6.1 Scenario template

- **ID:** OS-NNN
- **Title:**
- **Phase of flight:**
- **Airport or area:**
- **Starting conditions:**
- **Sequence of events:**
- **Expected system behavior:**
- **End state:**
- **Functions exercised:**

### 6.2 Normal operations

#### OS-010: Normal flight from San Juan to Ponce

- **Phase of flight:** All
- **Airport or area:** TJSJ to TJPS, crossing the Cordillera Central
- **Starting conditions:** Airplane parked at TJSJ, unit powered off, clear weather.
- **Sequence of events:** Pilot powers on the unit, taxis, takes off, climbs, crosses the mountains well above the terrain, descends, and lands at TJPS.
- **Expected system behavior:** Self test passes. No alerts during taxi, takeoff, climb, or cruise. "Five Hundred" on approach. No terrain alerts during the landing.
- **End state:** Airplane parked at TJPS, no alerts given except the callout.
- **Functions exercised:** F-3, F-6, F-9, F-10

#### OS-020: Normal approach to Ceiba with terrain nearby

- **Phase of flight:** Approach and landing
- **Airport or area:** TJRV, with the Sierra de Luquillo to the northwest
- **Starting conditions:** Airplane airborne, lined up for a normal approach.
- **Sequence of events:** Pilot flies a normal descent to the runway and lands.
- **Expected system behavior:** "Five Hundred" on approach. No terrain alerts, even though high ground is nearby.
- **End state:** Airplane on the runway, no nuisance alerts.
- **Functions exercised:** F-3, F-6, F-10

#### OS-030: Crossing a ridge with safe clearance

- **Phase of flight:** Cruise
- **Airport or area:** Cordillera Central
- **Starting conditions:** Airplane in level flight, well above the highest terrain on its path.
- **Sequence of events:** Airplane flies straight across the ridge without changing altitude.
- **Expected system behavior:** No alerts.
- **End state:** Airplane past the ridge, no alerts given.
- **Functions exercised:** F-4

### 6.3 Hazardous situations

#### OS-110: Flying toward hidden mountains in low clouds

- **Phase of flight:** Cruise
- **Airport or area:** Departing TJPS, heading north toward the Cordillera Central
- **Starting conditions:** Airplane cruising low under a lowering cloud layer.
- **Sequence of events:** Clouds hide the mountains. The pilot continues north without climbing.
- **Expected system behavior:** "Caution, Terrain; Caution, Terrain" when terrain is predicted ahead. "Terrain, Terrain; Pull-Up, Pull-Up" if the pilot does not respond, at least 30 seconds before the projected impact (SCOPE.md section 8). Alerts stop once the pilot climbs clear.
- **End state:** Airplane above the terrain, alerts cleared.
- **Functions exercised:** F-4

#### OS-120: Descending too fast close to the ground

- **Phase of flight:** Descent
- **Airport or area:** Any
- **Starting conditions:** Airplane at low height above the terrain.
- **Sequence of events:** Pilot begins a steep descent.
- **Expected system behavior:** "Sink Rate," then "Pull-Up" if the descent continues.
- **End state:** Pilot reduces the descent rate and the alerts stop.
- **Functions exercised:** F-1

#### OS-130: Losing altitude after takeoff

- **Phase of flight:** Takeoff and initial climb
- **Airport or area:** TJSJ
- **Starting conditions:** Airplane just airborne and climbing.
- **Sequence of events:** Pilot is distracted and the airplane starts losing altitude.
- **Expected system behavior:** "Don't Sink."
- **End state:** Pilot establishes a climb and the alert stops.
- **Functions exercised:** F-2

#### OS-140: Descending too early on approach

- **Phase of flight:** Approach
- **Airport or area:** TJRV
- **Starting conditions:** Airplane inbound to the runway, still several miles out.
- **Sequence of events:** Pilot descends early and ends up well below the normal approach path.
- **Expected system behavior:** "Too Low Terrain."
- **End state:** Pilot levels off until back on the normal path, and the alert stops.
- **Functions exercised:** F-5

#### OS-150: Two hazards at once

- **Phase of flight:** Descent
- **Airport or area:** Near high terrain
- **Starting conditions:** Airplane descending fast toward a ridge.
- **Sequence of events:** Excessive descent and terrain ahead conditions happen at the same time.
- **Expected system behavior:** Only the highest priority alert is given, following AC 23-18 Table 3. For example, if both warnings are active, the excessive descent warning (priority 2) is spoken and the terrain ahead warning (priority 3) is not.
- **End state:** Pilot climbs and all alerts stop.
- **Functions exercised:** F-1, F-4, F-7

#### OS-160: Turning away after a caution

- **Phase of flight:** Cruise
- **Airport or area:** Heading toward the Sierra de Luquillo
- **Starting conditions:** Airplane in level flight toward terrain higher than its altitude.
- **Sequence of events:** "Caution, Terrain; Caution, Terrain" is given. The pilot turns away before a warning.
- **Expected system behavior:** The caution stops once the new path is clear of terrain. No warning is given.
- **End state:** Airplane flying away from the terrain, no alerts active.
- **Functions exercised:** F-4

### 6.4 Degraded and failure conditions

#### OS-210: Satellite position lost in flight

- **Phase of flight:** Cruise
- **Airport or area:** Any
- **Starting conditions:** Airplane cruising, system working.
- **Sequence of events:** The satellite navigation receiver stops giving a valid position.
- **Expected system behavior:** All alerts are inhibited right away. Within 2 seconds, "TAWS Unavailable" is spoken once, and the unavailable message stays on the display.
- **End state:** Pilot knows the TAWS cannot be trusted and flies by other means.
- **Functions exercised:** F-8

#### OS-220: Self test fails at power-up

- **Phase of flight:** On ground
- **Airport or area:** Any
- **Starting conditions:** Memory card missing or unreadable.
- **Sequence of events:** Pilot powers on the unit.
- **Expected system behavior:** Self test fails. The display shows which check failed, such as "MEMORY CARD". The unit goes to Unavailable and says "TAWS Unavailable" once.
- **End state:** Pilot knows before takeoff that the TAWS is not working.
- **Functions exercised:** F-8, F-9

#### OS-230: Flying outside the mapped area

- **Phase of flight:** Cruise
- **Airport or area:** Departing TJRV toward Vieques
- **Starting conditions:** Airplane airborne over the main island, system working.
- **Sequence of events:** Airplane leaves the area covered by the terrain map.
- **Expected system behavior:** Terrain data unavailable. Terrain alerting inhibited and annunciated.
- **End state:** Pilot knows terrain protection has ended.
- **Functions exercised:** F-8

#### OS-240: Landing at an airport not in the database

- **Phase of flight:** Approach and landing
- **Airport or area:** Aguadilla (TJBQ)
- **Starting conditions:** Airplane on a normal approach.
- **Sequence of events:** Pilot descends toward a runway the system does not know about.
- **Expected system behavior:** Terrain alerts may occur, because the landing looks like a descent into the ground. This is a known limitation (SCOPE.md section 7, item 5).
- **End state:** Airplane lands. The alerts are expected and documented.
- **Functions exercised:** F-1, F-4

#### OS-250: Sensor data stops changing

- **Phase of flight:** Cruise
- **Airport or area:** Any
- **Starting conditions:** Airplane cruising, system working.
- **Sequence of events:** The satellite navigation receiver stops updating. Its last message still looks valid, but it keeps getting older.
- **Expected system behavior:** The system sees the data is too old and treats the position as invalid. From there it behaves as in OS-210.
- **End state:** Pilot knows the TAWS cannot be trusted.
- **Functions exercised:** F-8

#### OS-260: Unit restarts in flight

- **Phase of flight:** Cruise
- **Airport or area:** Any
- **Starting conditions:** Airplane cruising, system working.
- **Sequence of events:** The unit loses power briefly and starts up again while the airplane is flying.
- **Expected system behavior:** Self test runs only the silent checks, with no test sounds or test text. The unit goes straight to Airborne. Altitude loss after takeoff stays off until the next real takeoff.
- **End state:** Unit protecting the flight again, without distracting the pilot.
- **Functions exercised:** F-2, F-9, F-10

#### OS-270: Pressure sensor fails in flight

- **Phase of flight:** Cruise
- **Airport or area:** Any
- **Starting conditions:** Airplane cruising, system working.
- **Sequence of events:** The pressure sensor stops updating, or starts sending readings no Cessna 172 could produce.
- **Expected system behavior:** All alerts are inhibited. Within 2 seconds, "TAWS Unavailable" is spoken once, and the unavailable message stays on the display. If the sensor recovers and stays good for 5 seconds, the message clears with no sound.
- **End state:** Pilot knows the TAWS cannot be trusted until the message clears.
- **Functions exercised:** F-8

---

## 7. Operations in this project

The unit is never installed in an aircraft (SCOPE.md A-10). Instead, each scenario in section 6 becomes one or more flight data files, and the unit is exercised in three ways:

1. **Replay on a computer.** The software runs against each file and gives a pass or fail result. Files are scripted, recorded from FlightGear, or modified copies of good files (SCOPE.md section 5.4).
2. **Simulator in the loop.** FlightGear flies the airplane and sends its data to the unit over a serial connection. The unit gives real alerts.
3. **Bench test.** The real sensors run at a fixed, known location to confirm they give correct data.

The sensor and unit failure scenarios (OS-210, OS-220, OS-250, and OS-270) are not flown. The simulator always sends good data, so these are tested with modified files or, for OS-220, by removing the memory card on the bench.

---

## 8. Scenario to function traceability

| Scenario | F-1 | F-2 | F-3 | F-4 | F-5 | F-6 | F-7 | F-8 | F-9 | F-10 |
|---|---|---|---|---|---|---|---|---|---|---|
| OS-010 | | | X | | | X | | | X | X |
| OS-020 | | | X | | | X | | | | X |
| OS-030 | | | | X | | | | | | |
| OS-110 | | | | X | | | | | | |
| OS-120 | X | | | | | | | | | |
| OS-130 | | X | | | | | | | | |
| OS-140 | | | | | X | | | | | |
| OS-150 | X | | | X | | | X | | | |
| OS-160 | | | | X | | | | | | |
| OS-210 | | | | | | | | X | | |
| OS-220 | | | | | | | | X | X | |
| OS-230 | | | | | | | | X | | |
| OS-240 | X | | | X | | | | | | |
| OS-250 | | | | | | | | X | | |
| OS-260 | | X | | | | | | | X | X |
| OS-270 | | | | | | | | X | | |

---

## 9. Open items

All items raised in this document (TBD-107 to TBD-110, TBD-115, and TBD-116) are resolved. They are kept in [TBD.md](TBD.md).

---

## 10. Definitions

*Terms are defined in SCOPE.md section 11. Add any new terms there, not here.*

---

## 11. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | 2026-09-28 | Initial draft |
| 0.2 | 2026-09-29 | Resolved TBD-109: section 5.6 and scenarios OS-110, OS-120, and OS-160 now use TSO-C151c wording for the excessive descent warning and terrain ahead alerts. Added TSO-C151c to referenced documents. Raised TBD-115. Replaced lights with a small color text display. Used TSO-C151c capitalization for all aural wording. Added section 5.7 for the terrain ahead variants. Raised TBD-116. Section 5.5 now states the on ground rule from TBD-107 and how self test works after a restart in the air. Resolved TBD-110, TBD-115, and TBD-116 in section 5.6. Added the settings file to section 5.3 and scenario OS-260. |
| 0.3 | 2026-09-30 | Updated the Unavailable state and scenarios OS-210, OS-220, and OS-250 to match the new self test, position loss, and stale data requirements. Added scenario OS-270 (pressure sensor fails) and the recovery rule for the Unavailable state. Any sensor failure now inhibits all alerts. |
