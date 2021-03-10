SELECT b.player
FROM game a LEFT JOIN goal b ON a.id = b.matchid
WHERE a.stadium = 'National Stadium, Warsaw';