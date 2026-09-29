# TAWS Class B System Requirements

| | |
|---|---|
| **Document** | TAWS-SRS |
| **Version** | 0.3 |
| **Status** | Draft |
| **Last updated** | 2026-09-29 |

## 1. Introduction

### 1.1 Purpose

This document defines the system requirements for the TAWS Class B prototype. It describes *what* the system must do, not *how* it does it. Scope and out-of-scope items are defined in [`docs/SCOPE.md`](../docs/SCOPE.md).

### 1.2 Scope

These requirements cover the Class B TAWS prototype for a Cessna 172P flying over the main island of Puerto Rico. The functions come from SCOPE.md section 5.1, and the situations the system must handle come from the scenarios in CONOPS.md section 6.

### 1.3 Referenced documents

| Reference | Notes |
|---|---|
| [docs/SCOPE.md](../docs/SCOPE.md) | Functions F-1 to F-10, assumptions, constraints |
| [docs/CONOPS.md](../docs/CONOPS.md) | Operational scenarios cited as requirement sources |
| FAA TSO-C151c, Appendix 1, effective 6/27/12 | Aural alert wording (para 4.9, Table 4-1), aural variant selection (para 4.7), visual alert colors (Table 4-1), excessive descent rate for Class B (para 3.4.a) |
| FAA TSO-C151c, Appendix 2 | Excessive descent rate envelopes (para 7.0, Figure 1) |
| [requirements/SOFTWARE.md](SOFTWARE.md) | Software requirements and approximate values derived from this document |

### 1.4 Definitions

*Terms are defined in SCOPE.md section 11. Add any new terms there, not here.*

## 2. How to write requirements (cheat-sheet for me)

### 2.1 EARS patterns

Every requirement uses one of these patterns.

| Pattern | Template | Use when |
|---|---|---|
| Ubiquitous | The TAWS shall \<response\>. | Always true |
| Event-driven | When \<trigger\>, the TAWS shall \<response\>. | Something happens |
| State-driven | While \<state\>, the TAWS shall \<response\>. | True during a condition |
| Unwanted behavior | If \<fault\>, then the TAWS shall \<response\>. | Failures and bad data |
| Optional feature | Where \<feature is included\>, the TAWS shall \<response\>. | Configurable features |

Patterns can be combined: *While \<state\>, when \<trigger\>, the TAWS shall \<response\>.*

### 2.2 Rules

- One "shall" per requirement. If you need "and," split it into two requirements.
- Every requirement must be verifiable. If you can't describe a pass/fail test, rewrite it.
- Use numbers, not adjectives. Avoid: *quickly, adequate, sufficient, user-friendly, as appropriate, minimize, etc.*
- State *what*, not *how*. "Shall annunciate within 1 s," not "shall use an interrupt to..."
- Use **TBD-NNN** for values you haven't decided yet, and log them in [`docs/TBD.md`](../docs/TBD.md).
- Never reuse or renumber IDs. Deleted requirements stay in the document with status `Deleted`.

### 2.3 Fields

| Field | Description |
|---|---|
| **ID** | `TAWS-SYS-NNN`. Each section owns a block of 100 (see table below). Number in steps of 10 so new requirements can be inserted. |
| **Statement** | The requirement, written in an EARS pattern |
| **Rationale** | Why it exists and why the numbers are what they are |
| **Source** | Where it came from: AC 23-18 paragraph, ConOps scenario, hazard assessment, or derived |
| **Verification** | Inspection, Analysis, Demonstration, or Test |
| **Status** | Draft, Reviewed, Approved, or Deleted |

**Verification methods:**

- **Inspection:** examine the design, code, or documents.
- **Analysis:** calculation, model, or simulation that shows compliance.
- **Demonstration:** operate the system and observe, without detailed measurement.
- **Test:** run a defined procedure and measure results against pass/fail criteria.

### 2.4 ID blocks

| Block | Section | Scope function |
|---|---|---|
| 000-099 | 4.1 Power-up self test | F-9 |
| 100-199 | 4.2 Operating modes and on-ground inhibit | F-10 |
| 200-299 | 4.3 Excessive rate of descent | F-1 |
| 300-399 | 4.4 Altitude loss after takeoff | F-2 |
| 400-499 | 4.5 Five hundred foot callout | F-3 |
| 500-599 | 4.6 Forward looking terrain alerting | F-4 |
| 600-699 | 4.7 Alert prioritization | F-7 |
| 700-799 | 4.8 Health monitoring and annunciation | F-8 |
| 800-899 | 5. Performance and timing | |
| 900-999 | 4.9 Premature descent alerting | F-5 |
| 1000-1099 | 4.10 Airport proximity inhibition | F-6 |
| 1100-1199 | 6. Interface requirements | |
| 1200-1299 | 7. Data requirements | |
| 1300-1399 | 8. Design constraints | |
| 1400-1499 | 4.11 Altitude, descent rate, and height above terrain | Supports F-1, F-3, and F-4 |

F-5 and F-6 take the later blocks because they are implemented last (SCOPE.md section 5.1).

---

## 3. System overview

### 3.1 System context

The TAWS reads position, ground speed, and altitude from a satellite navigation receiver and a pressure sensor, or from FlightGear during testing. It looks up terrain and runway data on a memory card, and alerts the pilot through a speaker and a small color display. The full list of inputs and outputs is in CONOPS.md section 5.3.

### 3.2 Operating modes and states

The TAWS is always in one of four states: Self test, On ground, Airborne, or Unavailable. What each state means and what moves the system between them is in CONOPS.md section 5.5. Requirements in this document use these state names.

---

## 4. Functional requirements

### 4.1 Power-up self test (000-099)

### TAWS-SYS-010
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### TAWS-SYS-030
- **Statement:** When the TAWS powers up while the airplane is airborne, the TAWS shall skip the parts of the self test that use the speaker or the display.
- **Rationale:** A self test that plays alert sounds or shows alert text in flight could distract the pilot or be mistaken for a real alert. The silent checks, such as reading the memory card and the sensors, still run. The airborne rule is in CONOPS.md section 5.5.
- **Source:** SCOPE.md F-9; CONOPS.md OS-260
- **Verification:** Test
- **Status:** Draft

### 4.2 Operating modes and on-ground inhibit (100-199)

### TAWS-SYS-100
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.3 Excessive rate of descent (200-299)

### TAWS-SYS-200
- **Statement:** While the height above terrain is above 100 feet, when the descent rate and height above terrain are inside the "Sink Rate" caution envelope of TSO-C151c Appendix 2 Figure 1, the TAWS shall annunciate the aural message "Sink Rate."
- **Rationale:** Warns the pilot that the descent is too fast for the height above the ground, while there is still time to correct it. Appendix 2 para 7.0 is used instead of the RTCA DO-161A Mode 1 envelope, which the note under para 7.0 also allows, because DO-161A is not public (SCOPE.md C-5). Height above terrain is altitude minus terrain map elevation (Appendix 1 para 3.4.a). Approximate breakpoints for testing are in [SOFTWARE.md](SOFTWARE.md).
- **Source:** TSO-C151c Appendix 1 para 3.4.a; Appendix 2 para 7.0 and Figure 1; CONOPS.md OS-120
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-210
- **Statement:** While the height above terrain is above 100 feet, when the descent rate and height above terrain are inside the "Pull-Up" warning envelope of TSO-C151c Appendix 2 Figure 1, the TAWS shall annunciate the aural message "Pull-Up."
- **Rationale:** Tells the pilot to climb immediately because terrain impact is close. The same source choice as TAWS-SYS-200 applies. Approximate breakpoints for testing are in [SOFTWARE.md](SOFTWARE.md).
- **Source:** TSO-C151c Appendix 1 para 3.4.a; Appendix 2 para 7.0 and Figure 1; CONOPS.md OS-120, OS-150
- **Verification:** Test
- **Status:** Draft

### 4.4 Altitude loss after takeoff (300-399)

### TAWS-SYS-300
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### TAWS-SYS-310
- **Statement:** The TAWS shall arm the altitude loss after takeoff alert only when the state changes from On ground to Airborne.
- **Rationale:** "After takeoff" only makes sense if the unit saw the takeoff. After a restart in the air, the alert stays off until the next real takeoff.
- **Source:** CONOPS.md OS-130, OS-260
- **Verification:** Test
- **Status:** Draft

### 4.5 Five hundred foot callout (400-499)

### TAWS-SYS-400
- **Statement:** When the aircraft descends through 500 feet above the terrain, the TAWS shall annunciate the aural message "Five Hundred."
- **Rationale:** Gives the pilot a height-awareness cue during descent and approach, when terrain proximity is most likely to go unnoticed. Required for Class B equipment. This part uses only the terrain map, so it can be built before the airport database.
- **Source:** AC 23-18 paragraph 6.b(1)(c); CONOPS.md OS-010, OS-020
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-410
- **Statement:** When the aircraft descends through 500 feet above the nearest runway elevation, the TAWS shall annunciate the aural message "Five Hundred."
- **Rationale:** Completes the Class B callout, which uses terrain or runway elevation. This part needs the airport database, so it is built with F-5 and F-6 (SCOPE.md section 5.1).
- **Source:** AC 23-18 paragraph 6.b(1)(c); CONOPS.md OS-010, OS-020
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-420
- **Statement:** After annunciating "Five Hundred," the TAWS shall not annunciate it again until the height above terrain has risen above TBD-120 feet.
- **Rationale:** The callout plays once per descent, from whichever of TAWS-SYS-400 or 410 is reached first. This stops repeated callouts over rolling terrain or in bumpy air, which would be nuisance alerts.
- **Source:** Derived; SCOPE.md section 8, criteria 5 and 6
- **Verification:** Test
- **Status:** Draft

### 4.6 Forward looking terrain alerting (500-599)

### TAWS-SYS-500
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### TAWS-SYS-510
- **Statement:** The TAWS shall provide the forward looking terrain alerting caution and warning aural messages in both the Variant A and the Variant B wording of TSO-C151c Appendix 1 Table 4-1, Class B.
- **Rationale:** The TSO allows either wording. Supporting both lets the unit match the wording a pilot is used to.
- **Source:** TSO-C151c Appendix 1 para 4.7 and Table 4-1; CONOPS.md section 5.6
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-520
- **Statement:** The TAWS shall allow the forward looking terrain alerting aural wording to be selected as either Variant A or Variant B.
- **Rationale:** TSO-C151c requires the variant to be selectable.
- **Source:** TSO-C151c Appendix 1 para 4.7
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-530
- **Statement:** While no forward looking terrain alerting variant has been selected, the TAWS shall use Variant A.
- **Rationale:** In Variant A the caution starts with "Caution" and the warning ends with "Pull-Up", so the pilot can tell them apart from the first word. In Variant B both start with "Terrain Ahead." Variant A also uses the same "Pull-Up" as the excessive descent warning.
- **Source:** Derived from TSO-C151c Appendix 1 Table 4-1; CONOPS.md OS-110, OS-160
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-540
- **Statement:** When the TAWS powers up, the TAWS shall read the selected terrain ahead variant from the settings file on the memory card.
- **Rationale:** The unit has no buttons, so a settings file is the simplest way to select the variant. If the file is missing, TAWS-SYS-530 applies and Variant A is used.
- **Source:** Derived from TAWS-SYS-520; CONOPS.md section 5.3
- **Verification:** Test
- **Status:** Draft

### 4.7 Alert prioritization (600-699)

### TAWS-SYS-600
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### TAWS-SYS-610
- **Statement:** When the TAWS issues an aural caution or warning, the TAWS shall display a visual message consistent with the aural message.
- **Rationale:** The pilot may not hear an aural alert in a noisy cockpit. The visual message confirms which alert is active. This unit shows the message as text on a small color display (SCOPE.md section 5.3). The text is the spoken message in capitals, without repeats (CONOPS.md section 5.6).
- **Source:** TSO-C151c Appendix 1 Table 4-1; CONOPS.md section 5.6
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-620
- **Statement:** While a caution is active, the TAWS shall display its visual message in amber.
- **Rationale:** Amber is the standard color for a caution, so the pilot knows attention is needed but not immediate action.
- **Source:** TSO-C151c Appendix 1 Table 4-1
- **Verification:** Inspection
- **Status:** Draft

### TAWS-SYS-630
- **Statement:** While a warning is active, the TAWS shall display its visual message in red.
- **Rationale:** Red is the standard color for a warning, so the pilot knows immediate action is needed.
- **Source:** TSO-C151c Appendix 1 Table 4-1
- **Verification:** Inspection
- **Status:** Draft

### TAWS-SYS-640
- **Statement:** When the condition for an active alert is no longer true, the TAWS shall stop the alert once any spoken message already playing has finished.
- **Rationale:** The pilot needs to know the hazard is over. Letting the current phrase finish avoids cutting a word in half. A hold time can be added later if testing shows alerts switching on and off near a boundary.
- **Source:** CONOPS.md OS-110, OS-120, OS-160
- **Verification:** Test
- **Status:** Draft

### 4.8 Health monitoring and annunciation (700-799)

### TAWS-SYS-700
- **Statement:** If the satellite position is invalid for more than TBD-111 seconds, then the TAWS shall inhibit terrain alerts.
- **Rationale:** Without a valid position, terrain lookups are unreliable. Alerts based on a wrong position could be false or missed.
- **Source:** AC 23-18, paragraph to be confirmed (terrain functions must be disabled and annunciated when the position source is degraded); CONOPS.md OS-210
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-710
- **Statement:** If the satellite position is invalid for more than TBD-111 seconds, then the TAWS shall annunciate that it is unavailable within TBD-112 seconds.
- **Rationale:** A silent failure could lead the pilot to believe they are protected when they are not. The unit says "TAWS Unavailable" once and keeps an unavailable message on the display (CONOPS.md section 5.6).
- **Source:** AC 23-18, paragraph to be confirmed (terrain functions must be disabled and annunciated when the position source is degraded); CONOPS.md OS-210
- **Verification:** Test
- **Status:** Draft

### 4.9 Premature descent alerting (900-999)

### TAWS-SYS-900
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.10 Airport proximity inhibition (1000-1099)

### TAWS-SYS-1000
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.11 Altitude, descent rate, and height above terrain (1400-1499)

### TAWS-SYS-1400
- **Statement:** The TAWS shall correct pressure altitude using the average difference between pressure altitude and satellite altitude over the last TBD-122 seconds.
- **Rationale:** The pressure sensor measures altitude against standard pressure, not the local altimeter setting (QNH). The unit has no way for the pilot to enter QNH, so satellite altitude is used to correct it. Averaging smooths out the noise in satellite altitude.
- **Source:** TSO-C151c Appendix 1 para 3.4.a; SCOPE.md A-7
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-1410
- **Statement:** The TAWS shall calculate descent rate from the change in pressure altitude over time.
- **Rationale:** Neither sensor reports descent rate directly. Pressure altitude changes smoothly and quickly, which makes it a better source for rate than satellite altitude.
- **Source:** Derived from TAWS-SYS-200 and 210
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-1420
- **Statement:** The TAWS shall calculate descent rate with a delay of no more than TBD-121 seconds.
- **Rationale:** Smoothing the rate removes noise but makes it lag behind the real descent. A limit on the lag keeps alerts timely.
- **Source:** Derived from TAWS-SYS-200 and 210
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-1430
- **Statement:** The TAWS shall calculate height above terrain as corrected pressure altitude minus the terrain map elevation at the current position.
- **Rationale:** Every terrain alert depends on this one value, so it is defined once here. This matches the method in TSO-C151c Appendix 1 para 3.4.a.
- **Source:** TSO-C151c Appendix 1 para 3.4.a
- **Verification:** Test
- **Status:** Draft

---

## 5. Performance and timing (800-899)

*Update rate, time budget per cycle, time from condition to alert.*

### TAWS-SYS-800
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

---

## 6. Interface requirements (1100-1199)

*What the system receives and sends: position, altitude, and speed inputs; the simulator link; the display and speaker. Detailed formats belong in the interface control document (SCOPE.md D-5).*

### TAWS-SYS-1100
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

---

## 7. Data requirements (1200-1299)

*Terrain map and airport database: coverage, resolution, accuracy, and source.*

### TAWS-SYS-1200
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

---

## 8. Design constraints (1300-1399)

*Limits on how the system may be built, taken from SCOPE.md section 9: language, budget, public sources only.*

### TAWS-SYS-1300
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### TAWS-SYS-1310
- **Statement:** The TAWS aural alert wording shall match TSO-C151c Appendix 1 Table 4-1, Class B.
- **Rationale:** Matching TSO-C151c wording keeps the prototype consistent with real equipment. Any difference is recorded in the verification report.
- **Source:** TSO-C151c Appendix 1 para 4.9 and Table 4-1
- **Verification:** Inspection
- **Status:** Draft

---

## 9. Verification

*Pointer to the requirements verification matrix (SCOPE.md D-8). Each requirement's method is recorded in its own Verification field above.*

---

## 10. TBD log

All open and resolved items for the project are kept in [`docs/TBD.md`](../docs/TBD.md).

## 11. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | 2026-09-23 | Initial draft |
| 0.2 | 2026-09-28 | Restructured to a standard systems engineering layout. Split TAWS-SYS-700 into TAWS-SYS-700 and TAWS-SYS-710. Updated TAWS-SYS-400 to match F-3. Moved TBDs to docs/TBD.md. |
| 0.3 | 2026-09-29 | Resolved TBD-109 using TSO-C151c. Added TAWS-SYS-510 to 530 (terrain ahead aural variants), 610 to 630 (visual messages and colors), and 1310 (wording must match TSO-C151c). Updated TAWS-SYS-400 to TSO-C151c capitalization. TAWS-SYS-610 now uses a text display instead of lights. Added TAWS-SYS-200 and 210 (excessive descent caution and warning), citing TSO-C151c Appendix 2 Figure 1. Filled in sections 1.2, 3.1, and 3.2. TAWS-SYS-700 and 710 now say "satellite position" to match the other documents. Split the callout into TAWS-SYS-400 (terrain) and 410 (runway), and added 420 (once per descent). Added 030 (silent self test in the air), 310 (F-2 arms only on takeoff), 540 (settings file), 640 (alert stops), and 1400 to 1430 (altitude, descent rate, height above terrain). Shortened the 1310 rationale. |
