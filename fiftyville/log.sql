-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2025 and that it took place on Humphrey Street.

-- I want to see more info about the crime, crime_scene_reports takes date and a place
SELECT *
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2025 AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- The reports tells that 3 witnesses mentioned the bakery, I will investigate the bakery security logs
SELECT *
FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2025;

-- Couldn't find anything relevant still

-- I will now investigate the interviews
SELECT *
FROM interviews
WHERE day = 28 AND month = 7 AND year = 2025;

-- | 161 | Ruth    | 2025 |     7 |  28 | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2025 |     7 |  28 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2025 |     7 |  28 | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

-- Now I can look back to the bakery security logs and search for someone leaving 10 minutes after the theft at 10:15
SELECT *
FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2025;

-- Cars that left between 1-20 minutes after the theft
-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55
-- 1106N58

-- I will now investigate crime scene reports on legget street
SELECT *
FROM crime_scene_reports
WHERE street = 'Leggett Street';

-- Nothing...

-- I will investigate atm_transactions
SELECT *
FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2025 AND atm_location = 'Leggett Street';

-- All account_number's of people that withdraw the day of the crime.
-- 28500762
-- 28296815
-- 76054385
-- 49610011
-- 16153065
-- 25506511
-- 81061156
-- 26013199

-- Will se what people match the license_plates
