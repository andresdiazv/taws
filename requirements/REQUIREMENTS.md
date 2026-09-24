# TAWS Class B — System Requirements

| | |
|---|---|
| **Document** | TAWS-SRS |
| **Version** | 0.1 |
| **Status** | Draft |
| **Last updated** | YYYY-MM-DD |

## 1. Purpose

This document defines the system requirements for the TAWS Class B prototype. It describes *what* the system must do, not *how* it does it. Scope and out-of-scope items are defined in [`docs/scope.md`](../docs/SCOPE.md).

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
- Use **TBD-NNN** for values you haven't decided yet, and log them in Section 9.
- Never reuse or renumber IDs. Deleted requirements stay in the document with status `Deleted`.

### 2.3 Fields

| Field | Description |
|---|---|
| **ID** | `TAWS-SYS-NNN`. Each section owns a block of 100 (see section headings). Number in steps of 10 so new requirements can be inserted. |
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

---

## 3. Power-up and self-test (000–099)

### TAWS-SYS-010
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

## 4. Operating modes (100–199)

### TAWS-SYS-100
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

## 5. Alerting functions

### 5.1 Excessive descent rate (200–299)

### TAWS-SYS-200
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 5.2 Altitude loss after takeoff (300–399)

### TAWS-SYS-300
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

### 5.3 Five hundred foot callout (400–499)

### TAWS-SYS-400
- **Statement:** When the aircraft's height above terrain decreases through 500 feet, the TAWS shall annunciate the aural message "Five hundred."
- **Rationale:** Gives the pilot a height-awareness cue during descent and approach, when terrain proximity is most likely to go unnoticed. Required for Class B equipment.
- **Source:** AC 23-18, Class B functional requirements (500 ft voice callout)
- **Verification:** Test
- **Status:** Draft

### 5.4 Forward-looking terrain alerting (500–599)

### TAWS-SYS-500
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

## 6. Alert prioritization (600–699)

### TAWS-SYS-600
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

## 7. Fault detection and annunciation (700–799)

### TAWS-SYS-700
- **Statement:** If the GPS position is invalid for more than TBD-001 seconds, then the TAWS shall inhibit terrain alerts and annunciate "TAWS unavailable" within TBD-002 seconds.
- **Rationale:** Without a valid position, terrain lookups are unreliable. A silent failure could lead the pilot to believe they are protected when they are not.
- **Source:** AC 23-18 (terrain functions must be disabled and annunciated when the position source is degraded)
- **Verification:** Test
- **Status:** Draft

## 8. Performance and timing (800–899)

### TAWS-SYS-800
- **Statement:**
- **Rationale:**
- **Source:**
- **Verification:**
- **Status:** Draft

---

## 9. TBD log

| TBD | Requirement | Description | Resolve by |
|---|---|---|---|
| TBD-001 | TAWS-SYS-700 | Maximum GPS-invalid duration before alerts are inhibited | SRR |
| TBD-002 | TAWS-SYS-700 | Maximum time to annunciate "TAWS unavailable" | SRR |

## 10. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | YYYY-MM-DD | Initial draft |