SELECT a.id, a.name
FROM stops a INNER JOIN route b ON a.id = b.stop
WHERE b.num = '4' AND b.company = 'LRT';