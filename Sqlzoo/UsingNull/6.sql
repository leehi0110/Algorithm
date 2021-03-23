SELECT a.name, COALESCE(b.name, 'None')
FROM teacher a LEFT JOIN dept b ON a.dept = b.id;