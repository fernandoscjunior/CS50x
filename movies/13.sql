-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT name
FROM people
JOIN stars ON stars.person_id = people.id
WHERE stars.movie_id in
        (SELECT id
         FROM movies
         JOIN stars ON stars.movie_id = movies.id
         WHERE stars.person_id =
                 (SELECT id
                  FROM people
                  WHERE name = "Kevin Bacon"
                      AND birth = 1958))
    AND stars.person_id !=
        (SELECT id
         FROM people
         WHERE name = "Kevin Bacon");
