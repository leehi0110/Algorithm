SELECT c.name
FROM (SELECT *
      FROM movie
      WHERE title LIKE '%Casablanca%') a INNER JOIN casting b
ON a.id = b.movieid
INNER JOIN actor c ON a.id = b.movieid and b.actorid = c.id;

---------------------------------------------

SELECT c.name
FROM movie a INNER JOIN casting b ON a.id = b.movieid
INNER JOIN actor c ON a.id = b.movieid and b.actorid = c.id
WHERE a.title LIKE '%Casablanca%';