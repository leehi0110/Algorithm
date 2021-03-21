SELECT b.title, COUNT(b.title)
FROM casting a RIGHT JOIN (SELECT *
                          FROM movie
                          WHERE yr = '1978') b ON a.movieid = b.id
GROUP BY b.title
ORDER BY COUNT(b.title) DESC, b.title;