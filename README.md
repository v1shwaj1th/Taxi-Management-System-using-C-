# Taxi Booking System (C++)

A menu-driven **Taxi Booking System** implemented in **C++ using Object-Oriented Programming** principles.  
This project simulates real-world taxi allocation based on **nearest availability, time constraints, and earnings optimization**.

---

## Problem Overview

- There are **N taxis**, all starting from point **A**
- Points are labeled **A to F**
- Distance between adjacent points: **15 km**
- Travel time between adjacent points: **1 hour**
- Time is **absolute** (e.g., 9, 10, 11 — not 9:30)

### Fare Rules
- ₹100 for the **first 5 km**
- ₹10 per km **after 5 km**
- Distance traveled by taxi **for pickup is free**
- Fare is charged **only for passenger travel**

---

## Taxi Allocation Rules

1. Assign the **nearest available taxi**
2. If multiple taxis are at the same distance:
   - Assign the taxi with **lower total earnings**
3. If **no taxi is free** at the requested pickup time:
   - Booking is **rejected**

---

## Features

- Menu-driven console application
- Supports **any number of taxis**
- Time-based taxi availability
- Nearest taxi selection logic
- Tie-breaking using total earnings
- Booking history maintained per taxi
- Displays taxi-wise earnings and trip details
- Clean OOPS design (Booking, Taxi, System)

---

## Class Design

### `Booking`
Stores individual trip details:
- Booking ID
- Customer ID
- Pickup & Drop points
- Pickup & Drop time
- Fare amount

### `Taxi`
Represents a taxi:
- Taxi ID
- Current location
- Total earnings
- Booking history
- Availability check

### `TaxiBookingSystem`
Controller class:
- Initializes taxis
- Handles booking logic
- Displays taxi details
- Manages customer IDs

---

## How to Compile & Run

### Compile
```bash
g++ main.cpp TaxiBookingSystem.cpp Taxi.cpp Booking.cpp
./taxi
