-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0

SELECT DISTINCT people.name
FROM directors
JOIN ratings ON directors.movie_id = ratings.movie_id
JOIN people ON directors.person_id = people.id
WHERE ratings.rating >= 9.0;
