# TBD Log

**Project:** Class B Terrain Awareness and Warning System (TAWS) prototype\
**Document:** TAWS-TBD\
**Last updated:** 2026-09-30

---

## 1. Purpose of this document

This is the single list of open decisions for the whole project. A TBD (to be determined) is a value or question that has not been decided yet. Other documents refer to a TBD by its ID only and do not keep their own list.

## 2. Rules

- IDs are `TBD-NNN`, numbered in order. Never reuse or renumber an ID.
- When a TBD is resolved, move it to section 4 with its answer and date. Update every document that refers to it.
- "Raised in" names the document where the TBD first appears.

---

## 3. Open

| ID | Description | Raised in | Resolve by |
|---|---|---|---|
| TBD-103 | Maximum descent rate the system must handle, to be confirmed by flying and measuring descents in the simulator | SCOPE.md A-4 | Requirements review |
| TBD-113 | Code coverage target, including the type of coverage measured (for example, statement or branch coverage) | SCOPE.md section 8 | Requirements review |
| TBD-117 | Excessive descent envelope breakpoints are my estimates from the image of TSO-C151c Appendix 2 Figure 1. Check them against a clean copy, and decide how the boundary runs between the 100 ft floor and the 200 ft start point. | SOFTWARE.md section 3.1 | Before coding F-1 |
| TBD-118 | Ground speed above which the airplane can be judged airborne. Must be above a fast taxi, and below the ground speed at 100 ft on climb-out and on approach, including a strong headwind. The POH gives 55 KIAS rotation and 70 to 80 KIAS climb. Measure with a FlightGear takeoff and landing. | TBD-107 resolution | Before coding F-10 |
| TBD-119 | Height above terrain above which the airplane can be judged airborne. Larger than the expected altitude error near the ground. TSO-C151c Appendix 1 para 10.4 gives 100 ft above field elevation as an example. Measure with a FlightGear takeoff and landing. | TBD-107 resolution | Before coding F-10 |
| TBD-120 | Height above terrain the airplane must climb above before the "Five Hundred" callout can play again | REQUIREMENTS.md TAWS-SYS-420 | Before coding F-3 |
| TBD-121 | Maximum delay in the calculated descent rate, caused by smoothing | REQUIREMENTS.md TAWS-SYS-1420 | Before coding F-1 |
| TBD-122 | Time over which the difference between pressure altitude and satellite altitude is averaged for the altitude correction | REQUIREMENTS.md TAWS-SYS-1400 | Before coding F-1 |
| TBD-125 | Range of pressure altitude accepted as valid. Must cover everything in SCOPE.md A-3, with margin. | REQUIREMENTS.md TAWS-SYS-760 | Before coding F-8 |

---

## 4. Resolved

Resolved items are kept here so the history of each decision is visible.

| ID | Description | Resolution | Date |
|---|---|---|---|
| TBD-100 | Minimum warning time before projected impact | 30 seconds | 2026-09-27 |
| TBD-101 | Number of normal flights used to measure nuisance alerts | 20 flights | 2026-09-27 |
| TBD-102 | Acceptable nuisance alerts | None while cruising; at most one per ten approaches | 2026-09-27 |
| TBD-104 | Airports included in the database | TJPS, TJSJ, TJRV | 2026-09-27 |
| TBD-105 | Number of simulated approaches used for nuisance measurement | 10 approaches | 2026-09-27 |
| TBD-109 | Exact wording of the excessive descent warning and terrain ahead aural messages | Quoted from TSO-C151c Appendix 1 Table 4-1, Class B, into CONOPS.md section 5.6. Both terrain ahead variants are supported (TAWS-SYS-510 to 530). AC 23-18 Table 3 gives names and priority only, so it is not the source for wording. | 2026-09-29 |
| TBD-107 | How the system decides the airplane is airborne or on the ground | Airborne when ground speed is above TBD-118 and height above terrain is above TBD-119. On ground otherwise. No time delay for now; add one if testing shows the state switching back and forth near the thresholds. | 2026-09-29 |
| TBD-110 | Aural message, if any, for system unavailable | "TAWS Unavailable", spoken once. The display keeps showing an unavailable message until the system recovers. The TSO gives no wording, so this wording is my own. | 2026-09-29 |
| TBD-114 | When the five hundred foot callout is armed, and which reference applies when both are available | Plays once per descent, from whichever reference is reached first. It plays again only after the airplane climbs above TBD-120 (TAWS-SYS-400 to 420). | 2026-09-29 |
| TBD-115 | Altitude loss after takeoff (Mode 3) wording: "Don't Sink", "Too Low Terrain", or both | "Don't Sink" only. AC 23-18 Table 3 names Mode 3 as "Don't Sink", and this keeps "Too Low Terrain" unique to premature descent so the pilot can tell the alerts apart. | 2026-09-29 |
| TBD-116 | Text shown on the display for each alert | The spoken message in capitals, without repeats. For example "PULL UP", "SINK RATE", "CAUTION TERRAIN", "TERRAIN PULL UP". To be checked against the visual column of TSO-C151c Table 4-1. | 2026-09-29 |
| TBD-111 | Maximum time the satellite position can be invalid before alerts are inhibited | Zero. Alerts are inhibited as soon as the position is invalid, because TSO-C151c Appendix 1 para 5.6 says a faulted source must not be used (TAWS-SYS-700). | 2026-09-30 |
| TBD-112 | Maximum time to annunciate that the TAWS is unavailable | 2 seconds. Neither the AC nor the TSO sets a time, so this is my own value (TAWS-SYS-710). | 2026-09-30 |
| TBD-108 | How long data must be valid before leaving the Unavailable state | 5 seconds in a row. Stops an unstable signal from switching alerts on and off. The message clears with no sound (TAWS-SYS-790). | 2026-09-30 |
| TBD-106 | Update rate and the time budget allowed for one cycle | 5 cycles per second, one per flight data record. Each cycle must finish within 0.2 seconds (ICD.md section 5.2, TAWS-SYS-800 and 810). | 2026-09-30 |
| TBD-123 | Maximum age of the newest satellite navigation data before it is treated as stale | 1 second, which is 5 missed updates (ICD.md section 5.5, TAWS-SYS-720). | 2026-09-30 |
| TBD-124 | Maximum age of the newest pressure sensor reading before it is treated as stale | 1 second, the same as satellite data (ICD.md section 5.5, TAWS-SYS-750). | 2026-09-30 |
