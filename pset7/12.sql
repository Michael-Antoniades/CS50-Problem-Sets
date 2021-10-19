SELECT title
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id
WHERE name = "Johnny Depp"
INTERSECT
SELECT title
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id
WHERE name = "Helena Bonham Carter"

