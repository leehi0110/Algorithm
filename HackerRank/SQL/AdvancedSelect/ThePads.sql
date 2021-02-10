SELECT Name || '(' || SUBSTR(Occupation,0,1) || ')'
FROM OCCUPATIONS
ORDER BY Name;
SELECT 'There are a total of', COUNT(Occupation), lower(Occupation) || 's.'
FROM OCCUPATIONS
GROUP BY Occupation
ORDER BY COUNT(OCCUPATION), Occupation;