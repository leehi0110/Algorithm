SELECT a.id, a.mdate, b.goals
FROM game a LEFT JOIN (SELECT matchid, COUNT(*) AS goals
                       FROM goal
                       GROUP BY matchid) b ON a.id = b.matchid
WHERE a.team1 = 'POL' OR a.team2 = 'POL';