SELECT a.stadium, count(*)
FROM game a RIGHT JOIN goal b ON a.id = b.matchid
GROUP BY a.stadium;