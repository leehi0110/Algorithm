SELECT e.name
FROM casting c RIGHT JOIN (SELECT b.movieid as mvid
                          FROM actor a RIGHT JOIN casting b ON a.id = b.actorid
                          WHERE a.name = 'Art Garfunkel') d ON c.movieid = d.mvid
                          LEFT JOIN actor e ON c.actorid = e.id
                          WHERE name != 'Art Garfunkel';