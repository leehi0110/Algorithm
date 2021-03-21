SELECT d.title, e.name
FROM (SELECT *
      FROM (SELECT casting.movieid as mvid
            FROM actor INNER JOIN casting ON actor.id = casting.actorid
            WHERE actor.name = 'Julie Andrews') a INNER JOIN casting b ON a.mvid = b.movieid
      WHERE b.ord = 1) c LEFT JOIN movie d ON c.mvid = d.id LEFT JOIN actor e ON c.actorid = e.id;