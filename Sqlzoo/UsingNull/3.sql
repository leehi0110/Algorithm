SELECT a.name, b.name
FROM teacher a LEFT JOIN dept b ON a.dept = b.id;