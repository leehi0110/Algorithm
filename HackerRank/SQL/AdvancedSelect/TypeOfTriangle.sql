SELECT
  (CASE WHEN NOT (A+B>C AND A+C>B AND B+C>A) THEN 'Not A Triangle'
        WHEN A = B AND B = C AND C = A THEN 'Equilateral'
        WHEN A = B OR B = C OR C = A THEN 'Isosceles'
        else 'Scalene' END)
FROM TRIANGLES;