-- Write your MySQL query statement below
select 
    case
        when -- if its last id and if its odd then don't change it
            id = (select max(id) from Seat) and mod(id,2)=1
            then id

        when 
            mod(id,2)=1 -- if odd then increase it by 1
            then id+1
        else
            id-1 -- else when its even decrease it by 1

    end as id,student
from Seat order by id;