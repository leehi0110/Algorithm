SELECT a.mdate, b.teamname
FROM game a LEFT JOIN eteam b ON a.team1 = b.id
WHERE b.coach = 'Fernando Santos';