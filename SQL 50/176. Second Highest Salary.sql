# Write your MySQL query statement below
(SELECT DISTINCT salary AS SecondHighestSalary FROM Employee ORDER BY 
salary DESC LIMIT 1,1) UNION
(SELECT NULL) LIMIT 1;