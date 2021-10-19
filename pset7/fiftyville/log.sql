-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE day = 28 and street = "Chamberlin Street"; -- Query for extra information on the case and starting point
                                                 -- Also found out this happened at 10:15 which is part of our 3rd query

SELECT name, transcript
FROM interviews
WHERE day = 28 and month = 7; -- search for the 3 witnesses transcripts to gain information on our perpatrators

--Now we know courthouse parking lot was left within 10 minutes of theft, planning earliest flight out, told accomplice to purchase ticket,
--thief withdrew money earlier that morning at Fifer Street atm

SELECT license_plate
FROM courthouse_security_logs
WHERE day = 28 and month = 7 and hour = 10 and minute < 42;
-- Now we know the license plate within reason

SELECT person_id
FROM bank_accounts
WHERE account_number IN(
SELECT account_number
FROM atm_transactions
WHERE day = 28 and month = 7 and atm_location = "Fifer Street"
);
-- Know the account number of the perpatrator, next we convert this query to matchup with bank accounts
-- Join table of person_id in bank accounts with people (id) so we get names of suspects with bank accounts

SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE person_id IN(
SELECT person_id
FROM bank_accounts
WHERE account_number IN(
SELECT account_number
FROM atm_transactions
WHERE day = 28 and month = 7 and atm_location = "Fifer Street"
));

--This query combnines the one above, getting account numbers at the time of withdraw that we have pinpointed and references them
--with our people database, to get a list of people with the bank account numbers we've narrowed in on

--Prime list of suspects are Ernest, Robert, Russell, Roy, Bobby, Elizabeth, Danielle, Madison and Victoria

--SELECT duration -- this is the phone number as example: (219) 555-0139
--FROM phone_calls
--WHERE month = 7 and day = 28;

--Next we want to compare prime list of suspects to license plates to see if we get a license match, then list gets even smaller when
--looking for caller/receiver phone numbers and ticket purchase archive

SELECT name
FROM people
WHERE license_plate IN(
SELECT license_plate
FROM courthouse_security_logs
WHERE day = 28 and month = 7 and hour = 10 and minute < 42
);

--compare these with the above names to find that only 5 people are left that left the courthouse at the witnessed time, and
-- had transactions from the same atm on fifer street that day

SELECT receiver
FROM phone_calls
WHERE duration < 60 and caller IN (
SELECT phone_number
FROM people
WHERE name = "Ernst" or name = "Russell" or name = "Elizabeth" or name = "Danielle" or name = "Madison"
);

SELECT name, caller
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE receiver = "(676) 555-6554" or receiver = "(725) 555-3243";

--Phillip or James are one of the accomplices, can see two receivers popped up when one of those 5 were identified, now we need to find
--which of the 5 prime suspects are the match
-- two matches based on the receivers were Madison or Russell, Madison called James and Russell called Phillip
--SELECT phone_number
--FROM people
--WHERE name = "Madison" OR name = "Russell"

SELECT flight_id
FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE name = "Russell";

--Now we know flight id of either Madison + James flight or Russell + Phillip flights

SELECT month, day, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE id = 36;

SELECT city
FROM airports
WHERE id = 4 or id = 8;


--SOLUTION:
--MADISON + accomplice JAMES taking flight 36 out of town to LONDON with the Rubber Ducky
