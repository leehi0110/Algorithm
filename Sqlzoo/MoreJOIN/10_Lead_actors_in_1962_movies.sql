SELECT a.title, c.name
FROM movie a LEFT JOIN casting b ON a.id = b.movieid
LEFT JOIN actor c ON b.actorid = c.id
WHERE a.yr = 1962 AND b.ord = 1;