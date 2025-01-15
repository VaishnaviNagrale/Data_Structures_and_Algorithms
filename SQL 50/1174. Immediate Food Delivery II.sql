# Write your MySQL query statement below
SELECT 
ROUND(SUM(c=o)/COUNT(*)*100,2) 
AS immediate_percentage 
FROM (
    SELECT customer_id, MIN(order_date) AS o,MIN(customer_pref_delivery_date) AS c
    FROM Delivery GROUP BY customer_id
) AS D;