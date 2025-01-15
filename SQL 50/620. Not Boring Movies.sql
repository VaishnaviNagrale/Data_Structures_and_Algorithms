# Write your MySQL query statement below
SELECT * FROM Cinema WHERE description!='boring' AND MOD(id,2)!=0 ORDER BY rating DESC;