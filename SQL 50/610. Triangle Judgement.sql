# Write your MySQL query statement below
SELECT x,y,z,
IF(x+y>z AND x+z>y AND y+z>X,'Yes','No') AS triangle FROM Triangle;