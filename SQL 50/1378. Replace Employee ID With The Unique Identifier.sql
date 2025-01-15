# Write your MySQL query statement below
SELECT U.unique_id AS unique_id, E.name AS name
FROM Employees E LEFT JOIN EmployeeUNI U ON E.id = U.id;