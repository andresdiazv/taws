# Interface Control Document

**Project:** Class B Terrain Awareness and Warning System (TAWS) prototype\
**Document:** TAWS-ICD\
**Version:** 0.1\
**Last updated:** 2026-09-30

---

## 1. Purpose of this document

This document defines exactly what data goes into the TAWS: every field, its units, its range, how often it arrives, and what counts as invalid. Anything that sends data to the TAWS, whether FlightGear, a test file, or a real sensor driver, must follow it.

---

## 2. Scope

This document covers the data the TAWS receives. It does not cover the wiring inside the unit or the speaker and display outputs. What the project will and will not build is defined in [SCOPE.md](SCOPE.md).

---

## 3. Referenced documents

| Reference | Notes |
|---|---|
| [SCOPE.md](SCOPE.md) | Assumptions A-2 to A-7 set the ranges in this document |
| [CONOPS.md](CONOPS.md) | Section 5.3 lists the inputs |
| [REQUIREMENTS.md](../requirements/REQUIREMENTS.md) | Requirements that depend on this data |
| [TBD.md](TBD.md) | Open items raised in this document |

---

## 4. Interfaces

| ID | From | To | Carries |
|---|---|---|---|
| IF-1 | FlightGear | The unit, over a serial connection | Flight data during hardware in the loop testing |
| IF-2 | Flight data file | The TAWS software, on a computer | The same flight data, for replay testing |
| IF-3 | Settings file on the memory card | The unit, at power-up | Settings such as the terrain ahead variant |

IF-1 and IF-2 use the same format, so a file recorded from IF-1 can be replayed through IF-2 without changes.

---

## 5. Flight data (IF-1 and IF-2)

### 5.1 Format

- Plain text, one record per line, fields separated by commas (CSV).
- The first line of a file is a header with the field names in the order of section 5.3.
- Numbers use a decimal point. Latitude and longitude use 6 decimal places (about 0.1 meter). Other values use up to 2.
- Units are aviation units (feet, knots, degrees), so values can be checked directly against the requirements. Pressure is the one exception: it is sent in hectopascals (hPa), exactly as the sensor measures it.

### 5.2 Rate

- 5 records per second, one every 0.2 seconds.
- The TAWS runs one cycle for each record, so each cycle must finish within 0.2 seconds.

### 5.3 Fields

| Field | Description | Units | Range | Invalid when |
|---|---|---|---|---|
| time | Time of this record, from the start of the recording | seconds | 0 or more | Not greater than the previous record's time |
| gps_time | Time the satellite data in this record was measured | seconds | 0 to time | Older than 1 second (see 5.5) |
| latitude | Satellite position, positive north | degrees | -90 to 90 | Outside range, or gps_valid is 0 |
| longitude | Satellite position, positive east (Puerto Rico is negative) | degrees | -180 to 180 | Outside range, or gps_valid is 0 |
| gps_altitude | Satellite altitude above mean sea level | feet | Same as TBD-125 | Outside range, or gps_valid is 0 |
| ground_speed | Speed over the ground | knots | 0 to 200 | Outside range, or gps_valid is 0 |
| track | Direction of travel over the ground, from true north | degrees | 0 to less than 360 | Outside range, or gps_valid is 0 |
| gps_valid | Whether the receiver reports a good position | none | 0 or 1 | Any other value |
| pressure_time | Time the pressure in this record was measured | seconds | 0 to time | Older than 1 second (see 5.5) |
| pressure | Pressure sensor reading | hPa | Converts to a pressure altitude inside TBD-125 | Outside range, or pressure_valid is 0 |
| pressure_valid | Whether the pressure sensor reports a good reading | none | 0 or 1 | Any other value |

The ground speed range covers the 40 to 180 knots in SCOPE.md A-2, plus 0 on the ground, with margin.

**Why each field is needed**

| Field | Needed for | Where |
|---|---|---|
| time | Putting records in order and measuring how old each sensor's data is | Section 5.5; TAWS-SYS-800 |
| gps_time | Catching a frozen or silent receiver | TAWS-SYS-720; CONOPS.md OS-250 |
| latitude, longitude | Looking up terrain height below the airplane, finding the nearest runway, and knowing when the airplane leaves the map | TAWS-SYS-410, 1430; CONOPS.md OS-230 |
| gps_altitude | Correcting pressure altitude, since the unit has no QNH input | TAWS-SYS-1400; SCOPE.md A-7 |
| ground_speed | Deciding on ground or airborne, and projecting the flight path ahead | CONOPS.md section 5.5 (TBD-107); SCOPE.md F-4 |
| track | Projecting the flight path ahead to check for terrain | SCOPE.md F-4 |
| gps_valid | Knowing when the position cannot be trusted | TAWS-SYS-700, 710 |
| pressure_time | Catching a frozen or silent pressure sensor | TAWS-SYS-750; CONOPS.md OS-270 |
| pressure | Pressure altitude and descent rate | TAWS-SYS-1410, 1440 |
| pressure_valid | Knowing when the pressure reading cannot be trusted | TAWS-SYS-770, 780 |

### 5.4 Missing and invalid data

- **Satellite data:** if gps_valid is 0, or any satellite field is outside its range, the satellite position is invalid (TAWS-SYS-700, 710).
- **Pressure data:** if pressure_valid is 0, or pressure is outside its range, the pressure altitude is invalid (TAWS-SYS-760 to 780).
- **Unreadable record:** a line with the wrong number of fields, or a field that is not a number, is thrown away. The data age keeps growing, so repeated bad records are caught by the stale data check.

To inject a fault in a test file, set a valid flag to 0, put a value outside its range, or stop a sensor's time from advancing.

### 5.5 Stale data

- Satellite data is stale when time minus gps_time is more than 1 second (TAWS-SYS-720).
- Pressure data is stale when time minus pressure_time is more than 1 second (TAWS-SYS-750).

At 5 records per second, 1 second is 5 missed updates in a row. One or two late messages do not cause a failure.

### 5.6 Example

A Cessna cruising south at 3,500 ft and 110 knots:

```
time,gps_time,latitude,longitude,gps_altitude,ground_speed,track,gps_valid,pressure_time,pressure,pressure_valid
0.0,0.0,18.200000,-66.500000,3500.0,110.0,180.0,1,0.0,891.50,1
0.2,0.2,18.199898,-66.500000,3500.0,110.0,180.0,1,0.2,891.50,1
0.4,0.4,18.199796,-66.500000,3500.0,110.0,180.0,1,0.4,891.50,1
```

A frozen receiver would look the same, except gps_time would stay at 0.4 while time keeps increasing.

---

## 6. Settings file (IF-3)

### 6.1 Format

- Plain text, one setting per line, written as key=value, for example `flta_variant=A`.
- Lines starting with `#` are comments.
- An unknown key, or a value that is not allowed, is ignored and the default is used.
- If the file is missing, every setting uses its default.

### 6.2 Settings

| Setting | Allowed values | Default if missing | Used by |
|---|---|---|---|
| flta_variant | A or B | A | TAWS-SYS-530, 540 |

---

## 7. Open items

Open items raised in this document are kept in [TBD.md](TBD.md).

---

## 8. Revision history

| Version | Date | Description |
|---|---|---|
| 0.1 | 2026-09-30 | Initial draft: CSV flight data at 5 records per second in aviation units, with raw pressure, per-sensor times, valid flags, range checks, and a 1 second stale limit. Settings file as key=value lines. |
