SELECT a.player, a.teamid, b.coach, a.gtime
FROM goal a LEFT JOIN eteam b ON a.teamid = b.id
WHERE a.gtime <= 10;