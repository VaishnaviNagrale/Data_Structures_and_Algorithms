# Write your MySQL query statement below
SELECT ROUND(SUM(DATEDIFF(A2.event_date,A1.D1)=1)/COUNT(DISTINCT A2.player_id),2)
AS fraction 
FROM(
    SELECT player_id,MIN(event_date) AS D1 FROM Activity GROUP BY player_id
)
AS A1
INNER JOIN Activity A2 ON A1.player_id=A2.player_id;