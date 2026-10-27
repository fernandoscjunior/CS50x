SELECT *
FROM people
JOIN bakery_security_logs as bsl ON bsl.license_plate = people.license_plate
WHERE 
