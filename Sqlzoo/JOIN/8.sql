SELECT DISTINCT(b.player)
FROM (SELECT *
      FROM game
      WHERE team1 = 'GER' OR team2 = 'GER') AS a
      LEFT JOIN goal b ON a.id = b.matchid
WHERE b.teamid != 'GER';