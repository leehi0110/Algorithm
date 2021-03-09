SELECT b.player, b.teamid, a.stadium, a.mdate
FROM game a LEFT JOIN goal b ON a.id = b.matchid
WHERE teamid = 'GER';