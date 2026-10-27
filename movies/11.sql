-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT DISTINCT title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE stars.person_id =
        (SELECT id
         FROM people
         WHERE name = "Chadwick Boseman")
ORDER BY ratings.rating DESC
LIMIT 5;
