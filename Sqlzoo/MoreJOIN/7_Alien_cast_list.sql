SELECT c.name
FROM movie a LEFT JOIN casting b ON a.id = b.movieid
LEFT JOIN actor c ON b.actorid = c.id
WHERE a.title = 'Alien';