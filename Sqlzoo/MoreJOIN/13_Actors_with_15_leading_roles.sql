SELECT a.name
FROM actor a RIGHT JOIN (SELECT *
                         FROM casting
                         WHERE ord = 1) b ON a.id = b.actorid
GROUP BY a.name
HAVING COUNT(a.name) >= 15
ORDER BY a.name;
