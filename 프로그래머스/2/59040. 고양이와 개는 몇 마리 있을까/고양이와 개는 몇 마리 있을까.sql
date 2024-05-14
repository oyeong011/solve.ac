-- 코드를 입력하세요
SELECT ANIMAL_TYPE, COUNT(*) as count
from animal_ins
where animal_type IN ('Cat', 'Dog')
group by animal_type
order by FIELD(animal_type, 'Cat', 'Dog')