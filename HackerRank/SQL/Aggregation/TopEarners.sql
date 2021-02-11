SELECT (salary * months), COUNT(salary * months)
FROM Employee
WHERE (months * salary) = (SELECT MAX(salary * months)
                           FROM Employee)
GROUP BY (salary * months);

-- 타인의 풀이
SELECT *
FROM (
  SELECT months * salary, count(*)
  FROM Employee
  GROUP BY months * salary
  ORDER BY 1 desc
)
WHERE rownum = 1;