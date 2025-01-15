# Write your MySQL query statement below
SELECT M.employee_id,M.name,
COUNT(E.reports_to) AS reports_count,
ROUND(AVG(E.age)) AS average_age FROM Employees M 
JOIN Employees E ON M.employee_id=E.reports_to
GROUP BY employee_id
ORDER BY employee_id;