# TAWS Class B Software Requirements

| | |
|---|---|
| **Document** | TAWS-SWRS |
| **Version** | 0.1 |
| **Status** | Draft |
| **Last updated** | 2026-09-29 |

## 1. Purpose

This document breaks the system requirements in [REQUIREMENTS.md](REQUIREMENTS.md) down into what the software must do, including the numbers the code and tests use. Each software requirement names its parent system requirement.

## 2. Fields

Software requirements use the same fields and rules as REQUIREMENTS.md section 2, with two differences:

| Field | Description |
|---|---|
| **ID** | `TAWS-SW-NNN`. The number matches the block of the parent system requirement. |
| **Parent** | The system requirement this one comes from |

---

## 3. Excessive rate of descent (200-299)

### 3.1 Envelope breakpoints

I took these values from the image of TSO-C151c Appendix 2 Figure 1. They are my estimates, not exact values, and need to be checked against a clean copy of the figure (TBD-117).

| Point | "Sink Rate" caution boundary | "Pull-Up" warning boundary |
|---|---|---|
| Lower start | 1,600 FPM at 200 ft | 1,800 FPM at 200 ft |
| Bend | 6,000 FPM at 3,150 ft | 6,000 FPM at 2,500 ft |
| Upper end | 10,500 FPM at 5,000 ft | 10,500 FPM at 4,000 ft |

Both envelopes apply down to 100 ft above terrain (Appendix 2 para 7.0). How the boundary runs between 100 ft and the 200 ft start point is part of TBD-117.

### TAWS-SW-200
- **Statement:** The software shall treat the "Sink Rate" caution boundary as straight lines joining the caution breakpoints in section 3.1.
- **Parent:** TAWS-SYS-200
- **Rationale:** Straight lines between breakpoints are a simple, testable way to reproduce the figure.
- **Verification:** Test
- **Status:** Draft

### TAWS-SW-210
- **Statement:** The software shall treat the "Pull-Up" warning boundary as straight lines joining the warning breakpoints in section 3.1.
- **Parent:** TAWS-SYS-210
- **Rationale:** Same as TAWS-SW-200.
- **Verification:** Test
- **Status:** Draft

---

## 4. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | 2026-09-29 | Initial draft with excessive descent envelope breakpoints |
