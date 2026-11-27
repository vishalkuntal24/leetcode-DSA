# Write your MySQL query statement below

select a1.player_id as player_id , a1.event_date as first_login
from Activity a1 

where a1.event_date = ( 
                        select min(event_date)
                        from activity a2 
                        where a1.player_id=a2.player_id
)
