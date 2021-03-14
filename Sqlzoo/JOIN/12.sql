SELECT a.id, a.mdate, b.goals
FROM game a RIGHT JOIN (SELECT matchid, COUNT(*) AS goals
                        FROM goal
                        WHERE teamid = 'GER'
                        GROUP BY matchid) b ON a.id = b.matchid;