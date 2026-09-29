# TBD Log

**Project:** Class B Terrain Awareness and Warning System (TAWS) prototype\
**Document:** TAWS-TBD\
**Last updated:** 2026-09-28

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
| TBD-106 | Update rate and the time budget allowed for one cycle | SCOPE.md section 8 | Requirements review |
| TBD-107 | How the system decides the airplane is airborne or on the ground | CONOPS.md section 5.5 | Requirements review |
| TBD-108 | How long data must be valid before leaving the Unavailable state | CONOPS.md section 5.5 | Requirements review |
| TBD-109 | Exact wording of the aural messages marked with an asterisk. AC 23-18 Table 3 names these alerts but does not give their words. | CONOPS.md section 5.6 | Requirements review |
| TBD-110 | Aural message, if any, for system unavailable | CONOPS.md section 5.6 | Requirements review |
| TBD-111 | Maximum time the satellite position can be invalid before terrain alerts are inhibited | REQUIREMENTS.md TAWS-SYS-700 | Requirements review |
| TBD-112 | Maximum time to annunciate that the TAWS is unavailable | REQUIREMENTS.md TAWS-SYS-710 | Requirements review |
| TBD-113 | Code coverage target, including the type of coverage measured (for example, statement or branch coverage) | SCOPE.md section 8 | Requirements review |
| TBD-114 | When the five hundred foot callout is armed, and which reference (terrain or runway elevation) applies when both are available | REQUIREMENTS.md TAWS-SYS-400 | Requirements review |

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
