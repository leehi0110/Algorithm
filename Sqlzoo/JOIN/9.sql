SELECT b.teamname, count(*)
FROM goal a LEFT JOIN eteam b ON a.teamid = b.id
GROUP BY b.teamname;