# Write your MySQL query statement below
DELETE D1 FROM Person D1,Person D2 WHERE D1.email=D2.email AND D1.id>D2.id;