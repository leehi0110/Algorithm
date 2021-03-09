SELECT a.team1, a.team2, b.player
FROM game a LEFT JOIN goal b ON a.id = b.matchid
WHERE player LIKE 'Mario%';