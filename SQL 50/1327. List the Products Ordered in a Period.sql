# Write your MySQL query statement below
SELECT P.product_name,SUM(O.unit) AS unit FROM Products P LEFT JOIN Orders O 
ON P.product_id=O.product_id WHERE O.order_date BETWEEN 
'2020-02-01' AND '2020-02-29' GROUP BY O.product_id HAVING unit>=100;