SELECT a.name, b.cnt
FROM dept a INNER JOIN (SELECT COALESCE(dept,3) as dept, 
                        COUNT(dept) as cnt
                        FROM teacher
                        GROUP BY dept) b ON a.id = b.dept;