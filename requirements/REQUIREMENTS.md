# TAWS Class B System Requirements

| | |
|---|---|
| **Document** | TAWS-SRS |
| **Version** | 0.2 |
| **Status** | Draft |
| **Last updated** | 2026-09-28 |

## 1. Introduction

### 1.1 Purpose

This document defines the system requirements for the TAWS Class B prototype. It describes *what* the system must do, not *how* it does it. Scope and out-of-scope items are defined in [`docs/SCOPE.md`](../docs/SCOPE.md).

### 1.2 Scope

*One paragraph. Point to SCOPE.md and CONOPS.md rather than repeating them.*

### 1.3 Referenced documents

| Reference | Notes |
|---|---|
| [docs/SCOPE.md](../docs/SCOPE.md) | Functions F-1 to F-10, assumptions, constraints |
| [docs/CONOPS.md](../docs/CONOPS.md) | Operational scenarios cited as requirement sources |
| | |

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

F-5 and F-6 take the later blocks because they are implemented last (SCOPE.md section 5.1).

---

## 3. System overview

### 3.1 System context

*Short summary and a pointer to CONOPS.md section 5.3.*

### 3.2 Operating modes and states

*Short summary and a pointer to CONOPS.md section 5.5. Requirements in section 4.2 refer to these state names.*

---

## 4. Functional requirements

### 4.1 Power-up self test (000-099)

### TAWS-SYS-010
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
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
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.4 Altitude loss after takeoff (300-399)

### TAWS-SYS-300
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.5 Five hundred foot callout (400-499)

### TAWS-SYS-400
- **Statement:** When the aircraft descends through 500 feet above the terrain or 500 feet above the nearest runway elevation, the TAWS shall annunciate the aural message "Five hundred."
- **Rationale:** Gives the pilot a height-awareness cue during descent and approach, when terrain proximity is most likely to go unnoticed. Required for Class B equipment. The conditions that arm the callout are open (TBD-114).
- **Source:** AC 23-18 paragraph 6.b(1)(c); CONOPS.md OS-010, OS-020
- **Verification:** Test
- **Status:** Draft

### 4.6 Forward looking terrain alerting (500-599)

### TAWS-SYS-500
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.7 Alert prioritization (600-699)

### TAWS-SYS-600
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 4.8 Health monitoring and annunciation (700-799)

### TAWS-SYS-700
- **Statement:** If the GPS position is invalid for more than TBD-111 seconds, then the TAWS shall inhibit terrain alerts.
- **Rationale:** Without a valid position, terrain lookups are unreliable. Alerts based on a wrong position could be false or missed.
- **Source:** AC 23-18 (terrain functions must be disabled and annunciated when the position source is degraded); CONOPS.md OS-210
- **Verification:** Test
- **Status:** Draft

### TAWS-SYS-710
- **Statement:** If the GPS position is invalid for more than TBD-111 seconds, then the TAWS shall annunciate that it is unavailable within TBD-112 seconds.
- **Rationale:** A silent failure could lead the pilot to believe they are protected when they are not. The exact aural message is open (TBD-110).
- **Source:** AC 23-18 (terrain functions must be disabled and annunciated when the position source is degraded); CONOPS.md OS-210
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

*What the system receives and sends: position, altitude, and speed inputs; the simulator link; the lights and sounder. Detailed formats belong in the interface control document (SCOPE.md D-5).*

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
